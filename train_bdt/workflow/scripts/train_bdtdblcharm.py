#!/usr/bin/env python
#
# Script to train a BDT to separate the RDs hadronic signal against all other backgrounds
#
import argparse
import logging
import os
import joblib
import matplotlib.pyplot as plt
from sklearn.pipeline import make_pipeline
import xgboost as xgb

from utils import mygroupby, split_dataframe, scale_data, save_image
from utils import train_classifier, train_on_kfold, check_classifier
from utils import save_images_separately, split_Xy, compare_train_test

from data import load_complete_df

logging.basicConfig(level=logging.INFO)
log = logging.getLogger("train_bdt_tuned")

plt.rcParams["figure.figsize"] = [25, 8]

# Parsing the arguments
parser = argparse.ArgumentParser()
parser.add_argument("output", help="Output file to write", type=str)
parser.add_argument("model", help="Model name to save", type=str)
parser.add_argument(
    "--nb-estimators", help="Number of iterations to train for", type=int, default=150
)
parser.add_argument(
    "--max-depth", help="Maximum tree depth", type=int, default=3
)
parser.add_argument(
    "--eta", help="Learning rate", type=float, default=0.04
)
parser.add_argument(
    "--gamma", help="Regularisation", type=float, default=0#0.11136310347001808
)
args = parser.parse_args()

# Loading the data, limit to a specifc eventIndex if requested
log.info("Loading the data")
df = load_complete_df()

print("Data statistics")
print(mygroupby(df, "signal").to_string(index=False))

Xtrain, ytrain =  split_Xy(df.query(f"eventIndex == 0"))
Xvalid, yvalid, Xtest, ytest = split_dataframe(df.query(f"eventIndex == 1"), 0.5)

scaler, Xtrain_scaled, Xtest_scaled, Xvalid_scaled = scale_data(Xtrain, Xtest, Xvalid)

log.info(f"{Xtrain_scaled.shape} {Xvalid_scaled.shape} {Xtest_scaled.shape}")

# train a classifier on the scaled data
log.info("Training the classifier")

# Create classifier
ratio = len(ytrain[ytrain == 0]) / len(ytrain[ytrain == 1])
print(f"Ratio bkg=/sign train is {ratio}")
print(f"Ratio bkg=/sign valid is {len(yvalid[yvalid == 0]) / len(yvalid[yvalid == 1])}")
print(f"Ratio bkg=/sign test  is {len(ytest[ytest == 0]) / len(ytest[ytest == 1])}")

model = xgb.XGBClassifier(
    eval_metric="logloss",
    tree_method="gpu_hist", 
    random_state=42,
    n_estimators=args.nb_estimators,
    eta=args.eta,
    max_depth=args.max_depth,
    gamma = args.gamma,
    scale_pos_weight=ratio,
)

# doing the training itself
evalset = [(Xtrain_scaled, ytrain), (Xtest_scaled, ytest)]
res = model.fit(Xtrain_scaled, ytrain, eval_set=evalset)

log.info("Checking the classifier")
check_classifier(model, Xtest_scaled, ytest, Xtest.columns)

compare_train_test(model, Xtrain_scaled, ytrain, Xtest_scaled, ytest)


log.info("Persisting the pipeline to file")
xgbclass = make_pipeline(scaler, model)
dirname = os.path.dirname(args.model)
if dirname:
    os.makedirs(dirname, exist_ok=True)
joblib.dump(xgbclass, args.model)


# Save final document
save_image(args.output)
dirname =  os.path.dirname(args.output)
filename =  os.path.basename(args.output)
save_images_separately(dirname, f"{filename.split('.')[0]}_img")
