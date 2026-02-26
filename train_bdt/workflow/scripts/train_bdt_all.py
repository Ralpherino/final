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

from utils import mygroupby, split_dataframe, scale_data, save_image
from utils import train_classifier, train_on_kfold, check_classifier
from utils import save_images_separately

from data import load_complete_df

logging.basicConfig(level=logging.INFO)
log = logging.getLogger("train_bdt_all")

plt.rcParams["figure.figsize"] = [25, 8]

# Parsing the arguments
parser = argparse.ArgumentParser()
parser.add_argument("output", help="Output file to write", type=str)
parser.add_argument("model", help="Model name to save", type=str)
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

# train a classifier on the scaled data
log.info("Training the classifier")
model, res = train_classifier(
    Xtrain_scaled, ytrain, Xtest_scaled, ytest, nb_estimators=args.nb_estimators
)
log.info("Checking the classifier")
check_classifier(model, Xtest_scaled, ytest, Xtest.columns)

log.info("Persisting the pipeline to file")
xgbclass = make_pipeline(scaler, model)
dirname = os.path.dirname(args.model)
if dirname:
    os.makedirs(dirname, exist_ok=True)
joblib.dump(xgbclass, args.model)



# Train several times on kfold of the data to check the consistency of the training
if not args.no_kfold:
    train_on_kfold(df, 5, args.nb_estimators)

# Save final document
save_image(args.output)
dirname =  os.path.dirname(args.output)
filename =  os.path.basename(args.output)
save_images_separately(dirname, f"{filename.split('.')[0]}_img")
