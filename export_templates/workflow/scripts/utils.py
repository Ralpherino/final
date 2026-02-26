#!/usr/bin/env python
#
# Script to train a BDT to separate the RDs hadronic signal against a specific background
#

import os
import pandas as pd
import matplotlib.pyplot as plt
from matplotlib.backends.backend_pdf import PdfPages
import numpy as np
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


def load_dataframe(category, eventIndex=None):
    df_signal = load_signal_all()
    df_background = load_background_category(category)
    df = pd.concat([df_signal, df_background], axis=0)
    df = shuffle(df)
    if eventIndex is not None:
        df = df.query(f"eventIndex == {eventIndex}")
    return shuffle(df.copy())


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


def train_classifier(Xtrain_scaled, ytrain, Xtest_scaled, ytest, nb_estimators):
    # Create classifier
    ratio = len(ytrain[ytrain == 0]) / len(ytrain[ytrain == 1])
    print(f"Ratio bkg=/sign is {ratio}")
    model = xgb.XGBClassifier(
        eval_metric="logloss",
        n_estimators=nb_estimators,
        eta=0.03,
        scale_pos_weight=ratio,
    )

    # doing the training itself
    evalset = [(Xtrain_scaled, ytrain), (Xtest_scaled, ytest)]
    res = model.fit(Xtrain_scaled, ytrain, eval_set=evalset)
    return model, res


def check_classifier(model, Xtest_scaled, ytest, train_columns):
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
    yscore = model.predict_proba(Xtest_scaled)
    ypred = model.predict(Xtest_scaled)

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
    plt.barh(train_columns, model.feature_importances_)
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


def train_on_kfold(df, nbfold, nb_estimators):
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
            Xtrain_scaled, ytrain, Xtest_scaled, ytest, nb_estimators=nb_estimators
        )
        model_list.append(model)
        Xtest_list.append(Xtest_scaled)
        ytest_list.append(ytest)

    roc_aucs = plot_roc_curve_list(model_list, Xtest_list, ytest_list, ax1)
    ax2.hist(roc_aucs, bins=15)
    ax2.axvline(np.mean(roc_aucs), color="k", linestyle="dashed", linewidth=1)
    ax2.set_title("ROC AUC spread between folds")


def mygroupby(d, groupbycols):
    """ Utility to group by a column and show relative statistics """
    g = d.groupby(groupbycols).size().reset_index(name='count').sort_values([ 'count'], ascending=False).reset_index(drop=True)
    g["Percentage"] = g.apply(lambda row: 100 * row["count"]/d.shape[0], axis=1)
    g["cumulative %"] = g["Percentage"].cumsum(axis = 0)
    return g
