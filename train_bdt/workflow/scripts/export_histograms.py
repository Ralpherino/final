#!/usr/bin/env python
#
# Script to train a BDT to separate the RDs hadronic signal against all other backgrounds
#
import argparse
import logging
import ROOT
import matplotlib.pyplot as plt
from sklearn.pipeline import make_pipeline

from utils import mygroupby, split_dataframe, scale_data, save_image
from utils import train_classifier, train_on_kfold, check_classifier

from data import load_complete_df
from bdt_all import apply_bdtdblcharm


logging.basicConfig(level=logging.INFO)
log = logging.getLogger("export_hist")

plt.rcParams["figure.figsize"] = [25, 8]

# Parsing the arguments
parser = argparse.ArgumentParser()
parser.add_argument("cut", help="Cut to apply to the ", type=str)
parser.add_argument("categories", help="Comma separated list of categories to include", type=str)
parser.add_argument("output", help="Output file to write", type=str)
parser.add_argument(
    "--eventIndex", help="eventIndex to use (either 0 or 1)", default=None, type=int
)
args = parser.parse_args()

log.info(f"Filtering for categories: {args.categories} and cut: {args.cut}")

# make sure we query all the "other" categories correctly
others = "1_2_3_4_6_8_9_10_11_12_17_24_28_30_31_32_33_34_35_36_37_38_39_40_41_43_44_45_46_47_48_-1"

categs = [ c.strip() for c in args.categories.replace("others", others).split("_") ]

cuts = { 
    "cut1": 0.75,
    "cut2": 0.35,
    "cut3": 0.5
}
cutval = cuts[args.cut]


# I would make some tests with the 3D fitter (q2_2, tauY_2, bdt_all)  for events that pass bdt_all cuts: >0.75 (cut1) and >0.5 (cut3) for the moment.
# In all cases you should generate templates for each “group of category” as a TH3F histogram (or equivalent) with 5 bins in each dimension and the following ranges:
# q2_2:    [0,11]
# 1000 * tauY_2: [0,2]
# bdt_all: [cut_value,1]


# - cut1: consider 11 templates:
# - signal (from signal MC) (category 24)
# - background (from inclusive b->Ds3piX and inclusive b->DsHcX)
#  10 different templates grouping the categories as follows:     [18],[29],[23],[15,0,others],[16,14],[25,7,19,13],[27,22],[20],[26],[21]

# Loading the data, limit to a specifc eventIndex if requested
log.info("Loading the data")
df = load_complete_df()
if args.eventIndex is not None:
    df = df.query(f"eventIndex == {args.eventIndex}").copy()

# Applying the bdt now
df = apply_bdtdblcharm(df)

# Adding the cuts on bdt_all and categories
log.info(f"Candidates before bdt_all cut: {df.shape[0]}")
df = df.query(f"bdt_all > {cutval}")
log.info(f"Candidates after bdt_all cut: {df.shape[0]}")
categ_query = " or ".join([ f"( category == {c})" for c in categs])
df = df.query(categ_query)
log.info(f"Candidates after category cut: {df.shape[0]}")

df_category = df
hfile = ROOT.TFile.Open(args.output,"RECREATE")
q2  = df_category["q2_2"].to_numpy()
tau = df_category["tauY_2"].to_numpy()
bdt = df_category["bdt_all"].to_numpy()

rdf_category = ROOT.RDF.FromNumpy({"q2_2":q2,"tauY_2":tau, "bdt_all":bdt})
h = rdf_category.Histo3D((f"TemplateCat{args.categories}",f"Template for category {args.categories}",5,0,11,5,0.,0.002,5,0.75,1),"q2_2","tauY_2",  "bdt_all")
zero = 0.
for i in range(5*5*5) : 
    #print(h.GetBinContent(i+1))
    if (h.GetBinContent(i+1) == 0) : 
        zero = zero+1.
        h.SetBinContent(i+1,0.00001)

print(zero," ",zero/(5.*5.*5.))        
h.Write()
hfile.Close()
