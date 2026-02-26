#!/usr/bin/env python
#
# Script to train a BDT to separate the RDs hadronic signal against a specific background
#
from pathlib import Path
import argparse
import os
import sys

import pandas as pd
import ROOT
import matplotlib.pyplot as plt
from matplotlib.backends.backend_pdf import PdfPages
import numpy as np
import seaborn as sns
import xgboost as xgb

from sklearn.pipeline import make_pipeline
from sklearn.preprocessing import StandardScaler
from sklearn.metrics import RocCurveDisplay, accuracy_score
from sklearn.metrics import roc_curve, auc
from sklearn.utils import shuffle
from sklearn.model_selection import train_test_split
from sklearn.metrics import confusion_matrix, ConfusionMatrixDisplay
from sklearn.model_selection import KFold

# Our methods to load the data
from data import load_signal_all
from data import load_background_category

plt.rcParams["figure.figsize"] = [25, 8]

train_columns = [
    "Y_0_40_nc_mult",
    "Y_0_20_cc_mult",
    "Y_0_20_cc_PZ",
    "Y_0_30_nc_PZ",
    "Y_0_40_nc_PZ",
    "min_m2pi",
    "max_m2pi",
    "missing_mass_2",
    "B_BPVVDR",
    "B_M",
    "B_correctedMass",
    "log(abs(PBsn))",
    "log(abs(PBv/B_P))",
    "log(abs(PBvn/B_P))",
    "log(abs((PBsn-PBvn)/PBvn))",
    "log(sqrt(abs(mDs2vn)))",
    "mN2v",
    "log(Y_PE)",
    "BDT_Iso",
    "B_pT_Bdir",
    "Y_BPVVDR",
    "missing_pY_mass",
    "Y_correctedMass",
]


def load_dataframe(category):
    df_signal = load_signal_all()
    df_background = load_background_category(category)
    df = pd.concat([df_signal, df_background], axis=0)
    df = shuffle(df)
    return df


def split_dataframe(df, test_size=0.2):
    train, test = train_test_split(df, test_size=test_size)
    Xtrain = train[train_columns]
    ytrain = train["signal"]
    Xtest = test[train_columns]
    ytest = test["signal"]
    return Xtrain, ytrain, Xtest, ytest


def scale_data(Xtrain, Xtest):
    scaler = StandardScaler().fit(Xtrain)
    Xtrain_scaled = scaler.transform(Xtrain)
    Xtest_scaled = scaler.transform(Xtest)
    return scaler, Xtrain_scaled, Xtest_scaled


def train_classifier(Xtrain_scaled, ytrain, Xtest_scaled, ytest, nb_iterations):
    # Create classifier
    ratio = len(ytrain[ytrain == 0]) / len(ytrain[ytrain == 1])
    print(f"Ratio bkg=/sign is {ratio}")
    model = xgb.XGBClassifier(
        tree_method='gpu_hist',
        eval_metric="logloss",
        n_estimators=nb_iterations,
        eta=0.03,
        scale_pos_weight=ratio,
    )

    # doing the training itself
    evalset = [(Xtrain_scaled, ytrain), (Xtest_scaled, ytest)]
    res = model.fit(Xtrain_scaled, ytrain, eval_set=evalset)
    return model, res


def check_classifier(model, Xtest, ytest):
    # Plot the learning curves using the results stored in the model itself
    figtraining = plt.figure()
    results = model.evals_result()
    plt.plot(results["validation_0"]["logloss"], label="train")
    plt.plot(results["validation_1"]["logloss"], label="test")
    plt.legend()
    plt.ylabel("logloss")
    plt.xlabel("training iteration")
    plt.title("Learning curve")

    # Use the model to predict the outcome onthe test sample
    yscore = model.predict_proba(Xtest)
    ypred = model.predict(Xtest)

    # Acuracy measure, not that useful...
    accuracy = accuracy_score(ytest, ypred)
    print("Accuracy: %.3f" % accuracy)

    fig, (ax1, ax2) = plt.subplots(1, 2)
    # ROC curve display
    # RocCurveDisplay.from_estimator(classifier, Xtest, ytest).plot(ax=ax2)
    fpr, tpr, _ = roc_curve(ytest, yscore[:, 1])
    roc_auc = auc(fpr, tpr)
    ax2.plot(1 - fpr, tpr)
    ax2.set_title(f" True Pos rate  vs (1 - false pros rate) (AUC:{roc_auc})")
    print(f"ROC AUC: {roc_auc}")

    # Classifier output
    ax1.set_title(f"XGBoost Classifier output")
    t = "step"
    n, bins, p = ax1.hist(
        yscore[ytest == 1, 1], bins=60, histtype=t, label="signal", density=True
    )
    ax1.hist(
        yscore[ytest == 0, 1],
        bins=len(bins) - 1,
        histtype=t,
        label="background",
        density=True,
    )
    ax1.legend()

    # Confusion matrix
    confusion_matrix(ytest, ypred)
    class_names = ["background", "signal"]
    fig, (ax1, ax2) = plt.subplots(1, 2, figsize=(25, 8))
    ConfusionMatrixDisplay.from_estimator(
        model,
        Xtest_scaled,
        ytest,
        display_labels=class_names,
        cmap=plt.cm.Blues,
        normalize="all",
        ax=ax1,
    )
    ConfusionMatrixDisplay.from_estimator(
        model,
        Xtest_scaled,
        ytest,
        display_labels=class_names,
        cmap=plt.cm.Blues,
        normalize=None,
        ax=ax2,
    )

    # And now the importance of each feature
    plt.figure()
    plt.barh(Xtrain.columns, model.feature_importances_)
    plt.title("Feature importance")


def save_image(filename):
    dirname = os.path.dirname(filename)
    if dirname:
        os.makedirs(dirname, exist_ok=True)

    p = PdfPages(filename)
    fig_nums = plt.get_fignums()
    figs = [plt.figure(n) for n in fig_nums]
    for fig in figs:
        fig.savefig(p, format="pdf")
    p.close()


def plot_roc_curve_list(model_list, Xtest_list, ytest_list, ax):
    data = zip(model_list, Xtest_list, ytest_list)
    roc_aucs = []
    for i, (model, Xtest, ytest) in enumerate(data):
        yscore = model.predict_proba(Xtest)
        fpr, tpr, _ = roc_curve(ytest, yscore[:, 1])
        roc_auc = auc(fpr, tpr)
        print(f"ROC AUC: {roc_auc}")
        roc_aucs.append(roc_auc)
        ax.plot(1 - fpr, tpr, label=f"Fold {i}")
    ax.set_title(
        f" True Pos rate  vs (1 - false pros rate) (AUC:{np.mean(roc_aucs):.4f} stddev:{np.std(roc_aucs):.4f})"
    )
    ax.legend()
    return roc_aucs


def train_on_kfold(df, nbfold, nbiter):
    fig, (ax1, ax2) = plt.subplots(1, 2)
    model_list = []
    Xtest_list = []
    ytest_list = []

    kf = KFold(n_splits=nbfold, shuffle=True)
    for train_index, test_index in kf.split(df):
        train_index, test_index = list(kf.split(df))[0]

        # Create the data set
        train = df.iloc[train_index]
        test = df.iloc[test_index]
        print(f"Length of training sample: {len(train)}")
        print(f"Length of test     sample: {len(test)}")

        Xtrain = train[train_columns]
        ytrain = train["signal"]
        Xtest = test[train_columns]
        ytest = test["signal"]

        scaler, Xtrain_scaled, Xtest_scaled = scale_data(Xtrain, Xtest)

        # Ratio background to noise, used to set the weight on the signal samples in the training
        ratio = len(train[train["signal"] == 0]) / len(train[train["signal"] == 1])
        print(f"Ratio bkg=/sign is {ratio}")

        model, res = train_classifier(
            Xtrain_scaled, ytrain, Xtest_scaled, ytest, nb_iterations=nbiter
        )
        model_list.append(model)
        Xtest_list.append(Xtest_scaled)
        ytest_list.append(ytest)

    roc_aucs = plot_roc_curve_list(model_list, Xtest_list, ytest_list, ax1)
    ax2.hist(roc_aucs, bins=15)
    ax2.axvline(np.mean(roc_aucs), color="k", linestyle="dashed", linewidth=1)
    ax2.set_title("ROC AUC spread between folds")


def print_stats(category, Xtrain, ytrain, Xtest, ytest):
    fig = plt.figure()
    plt.tick_params(axis="x", which="both", bottom=False, top=False, labelbottom=False)
    plt.tick_params(axis="y", which="both", right=False, left=False, labelleft=False)
    for pos in ["right", "top", "bottom", "left"]:
        plt.gca().spines[pos].set_visible(False)

    txt = f"Training BDT to sperate signal from background category {category}"
    plt.text(0.5, 0.9, txt, wrap=True, ha="center", va="center", size=20)

    sig_count = ytrain.value_counts()[1]
    bkg_count = ytrain.value_counts()[0]
    ratio = bkg_count / sig_count
    txt = f"Training sample size: {len(Xtrain)}\n"
    txt += f"Test     sample size: {len(Xtest)}\n"
    txt += f"\nTraining signal     candidates: {sig_count}\n"
    txt += f"Training background candidates: {bkg_count}\n"
    txt += f"Ratio background/signal in training sample is {ratio:.2f}"
    plt.text(0.05, 0.6, txt, size=16, wrap=True)


# Parsing the arguments
parser = argparse.ArgumentParser()
parser.add_argument("category", help="Background category to train against", type=int)
parser.add_argument("output", help="Output file to write", type=str)
parser.add_argument(
    "--nbiterations", help="Number of iterations to train for", type=int, default=200
)

args = parser.parse_args()

# Load the data and scale features
df = load_dataframe(args.category)
Xtrain, ytrain, Xtest, ytest = split_dataframe(df, test_size=0.2)
scaler, Xtrain_scaled, Xtest_scaled = scale_data(Xtrain, Xtest)
print_stats(args.category, Xtrain, ytrain, Xtest, ytest)

# train a classifier on the scaled data
model, res = train_classifier(
    Xtrain_scaled, ytrain, Xtest_scaled, ytest, nb_iterations=args.nbiterations
)
check_classifier(model, Xtest_scaled, ytest)

# Now we optimize the parameters of the model
from sklearn.model_selection import GridSearchCV

parameters = {
    "learning_rate": [0.005, 0.01, 0.1],
    "max_depth": [3, 6, 10, 20],
    "n_estimators": [
        100,
        200,
        500,
    ],
    'colsample_bytree': [0.3, 0.7],
}

grid_search = GridSearchCV(
    estimator=model,
    param_grid=parameters,
    scoring="roc_auc",
    n_jobs=2,
    cv=5,
    verbose=10,
)

grid_search.fit(Xtrain_scaled, ytrain)
results = pd.DataFrame(grid_search.cv_results_)

plt.figure()
basecols = ["mean_test_score", "std_test_score", "rank_test_score"]
cols = [c for c in results.columns if c.startswith("param_") or c in basecols]
fig = plt.figure()
plt.tick_params(axis="x", which="both", bottom=False, top=False, labelbottom=False)
plt.tick_params(axis="y", which="both", right=False, left=False, labelleft=False)
for pos in ["right", "top", "bottom", "left"]:
    plt.gca().spines[pos].set_visible(False)

pd.plotting.table(
    plt.gca(), results[cols].sort_values(["rank_test_score"]).head(15), loc="center"
)

# Save final document
save_image(args.output)

results.to_csv(args.output + ".csv")
