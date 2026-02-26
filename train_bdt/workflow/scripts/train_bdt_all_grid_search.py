#!/usr/bin/env python
#
# Train BDT to separate the signal from all other backgrounds.
# Grid Search.
#
#!/usr/bin/env python
#
# Train BDT to separate the signal from all other backgrounds.
#
import argparse
import logging
import matplotlib.pyplot as plt
import pandas as pd
import xgboost as xgb
from sklearn.pipeline import make_pipeline

from utils import mygroupby, split_dataframe, scale_data, save_image
from utils import train_classifier, train_on_kfold, check_classifier

from data import load_complete_df

logging.basicConfig(level=logging.INFO)
log = logging.getLogger("train_bdt_all")

plt.rcParams["figure.figsize"] = [25, 8]

# Parsing the arguments
parser = argparse.ArgumentParser()
parser.add_argument("output", help="Output file to write", type=str)
parser.add_argument(
    "--nb-estimators", help="Number of iterations to train for", type=int, default=20
)
parser.add_argument(
    "--no-kfold", help="Run the check of the classifier", action='store_true', default=False
)
parser.add_argument(
    "--eventIndex", help="eventIndex to use (either 0 or 1)", default=None, type=int
)
args = parser.parse_args()

# Loading the data, limit to a specifc eventIndex if requested
log.info("Loading the data")
df = load_complete_df()
if args.eventIndex is not None:
    df = df.query(f"eventIndex == {args.eventIndex}").copy()

print("Data statistics")
print(mygroupby(df, "signal").to_string(index=False))

Xtrain, ytrain, Xtest, ytest = split_dataframe(df, test_size=0.2)
scaler, Xtrain_scaled, Xtest_scaled = scale_data(Xtrain, Xtest)

# Create the model
from sklearn.model_selection import GridSearchCV
ratio = len(ytrain[ytrain == 0]) / len(ytrain[ytrain == 1])
model = xgb.XGBClassifier(
    tree_method='gpu_hist',
    eval_metric="logloss",
    n_estimators=args.nb_estimators,
    eta=0.03,
    scale_pos_weight=ratio,
)

parameters = {
    "learning_rate": [0.005, 0.01, 0.1],
    "max_depth": [3, 6, 10, 100],
    "n_estimators": [
        100,
        200,
        500,
    ],
    'colsample_bytree': [0.3, 0.7],
    'gamma': [0, 10, 100]
}

# parameters = {
#     "learning_rate": [0.01],
#     "max_depth": [3, 6],
#     "n_estimators": [
#         100,
#     ],
#     'colsample_bytree': [0.3,],
#     'gamma': [0]
# }

grid_search = GridSearchCV(
    estimator=model,
    param_grid=parameters,
    scoring="roc_auc",
    n_jobs=2,
    cv=5,
    verbose=10,
    return_train_score=True,
)

grid_search.fit(Xtrain_scaled, ytrain)
results = pd.DataFrame(grid_search.cv_results_)

plt.figure(layout="constrained")
basecols = ["mean_test_score", "std_test_score", "rank_test_score",
            "mean_train_score", "std_train_score"]
cols = [c for c in results.columns if c.startswith("param_") or c in basecols]

plt.tick_params(axis="x", which="both", bottom=False, top=False, labelbottom=False)
plt.tick_params(axis="y", which="both", right=False, left=False, labelleft=False)
for pos in ["right", "top", "bottom", "left"]:
    plt.gca().spines[pos].set_visible(False)

pd.plotting.table(
    plt.gca(), results[cols].sort_values(["rank_test_score"]).head(15), loc="center"
)
df = results.copy()
results.to_csv(args.output + ".csv")

df.index = df["params"]
dfp = df[["params", "mean_test_score", "std_test_score", "mean_train_score", "std_train_score", "rank_test_score"]].sort_values(by="rank_test_score").head(20)

dfp[["params", "mean_test_score", "std_test_score"]].plot( kind="barh", legend=False, label="params", xerr="std_test_score")
plt.xlim([0.80, .93])
plt.title("Test scores")
plt.tight_layout()

dfp[["params", "mean_train_score", "std_train_score"]].plot( kind="barh", legend=False, label="params", xerr="std_train_score")
plt.xlim([0.80, .93])
plt.title("Training scores")
plt.tight_layout()

# Save final document
save_image(args.output)




