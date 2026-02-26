#!/usr/bin/env python
#
# Script to train a BDT to separate the RDs hadronic signal against a specific background
#
from pathlib import Path
import argparse
import os
import sys
import joblib
import pandas as pd
#import ROOT
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
from utils import load_dataframe, split_dataframe, mygroupby
from utils import scale_data, train_classifier, check_classifier
from utils import train_on_kfold, save_image

plt.rcParams["figure.figsize"] = [25, 8]

def print_stats(category, df, Xtrain, ytrain, Xtest, ytest):
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
    txt = "Data statistics\n"
    txt += mygroupby(df, "signal").to_string(index=False) + "\n"
    txt += f"Training sample size: {len(Xtrain)}\n"
    txt += f"Test     sample size: {len(Xtest)}\n"
    txt += f"\nTraining signal     candidates: {sig_count}\n"
    txt += f"Training background candidates: {bkg_count}\n"
    txt += f"Ratio background/signal in training sample is {ratio:.2f}"
    plt.text(0.05, 0.6, txt, size=16, wrap=True)

# Parsing the arguments
parser = argparse.ArgumentParser()
parser.add_argument("category", help="Background category to train against", type=int)
parser.add_argument("output", help="Output file to write", type=str)
parser.add_argument("model", help="Model name to save", type=str)
parser.add_argument(
    "--nb-estimators", help="Number of iterations to train for", type=int, default=200
)
parser.add_argument(
    "--no-kfold", help="Run the check of the classifier", action='store_true', default=False
)
parser.add_argument(
    "--eventIndex", help="eventIndex to use (either 0 or 1)", default=None, type=int
)
args = parser.parse_args()

# Load the data and scale features

df = load_dataframe(args.category, args.eventIndex)
print("Data statistics")
print(mygroupby(df, "signal").to_string(index=False))

Xtrain, ytrain, Xtest, ytest = split_dataframe(df, test_size=0.2)
scaler, Xtrain_scaled, Xtest_scaled = scale_data(Xtrain, Xtest)
print_stats(args.category, df, Xtrain, ytrain, Xtest, ytest)

# train a classifier on the scaled data
model, res = train_classifier(
    Xtrain_scaled, ytrain, Xtest_scaled, ytest, nb_estimators=args.nb_estimators, eta=0.04, max_depth=3
)
check_classifier(model, Xtest_scaled, ytest, Xtrain.columns)

# Persist the classifier

# dirname = os.path.dirname(args.model)
# if dirname:
#     os.makedirs(dirname, exist_ok=True)
# model.save_model(args.model)
xgbclass = make_pipeline(scaler, model)
dirname = os.path.dirname(args.model)
if dirname:
    os.makedirs(dirname, exist_ok=True)
joblib.dump(xgbclass, args.model)

# # Train several times on kfold of the data to check the consistency of the training
if not args.no_kfold:
    train_on_kfold(df, 5, args.nb_estimators)

# Save final document
save_image(args.output)
