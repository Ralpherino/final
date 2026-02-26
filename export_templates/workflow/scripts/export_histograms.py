#!/usr/bin/env python
#
# Script to train a BDT to separate the RDs hadronic signal against all other backgrounds
#
import argparse
import logging
import yaml
from yaml.loader import SafeLoader
import ROOT

from utils import mygroupby, split_dataframe, scale_data, save_image
from utils import train_classifier, train_on_kfold, check_classifier

from data import load_complete_df
from bdt_all import apply_bdtdblcharm
from grouping import CUTS, get_other_categories

logging.basicConfig(level=logging.INFO)
log = logging.getLogger("export_hist")

# Parsing the arguments
parser = argparse.ArgumentParser()
parser.add_argument("grouping", help="Category grouping definition", type=str)
parser.add_argument("cut", help="Cut to apply to the data", type=str)
parser.add_argument("categories", help="Comma separated list of categories to include", type=str)
parser.add_argument("output", help="Output file to write", type=str)
parser.add_argument(
    "--eventIndex", help="eventIndex to use (either 0 or 1)", default=None, type=int
)
args = parser.parse_args()
log.info(f"Filtering for categories: {args.categories} and cut: {args.cut}")
cutval = CUTS[args.cut]

# Loading the template configuration
# We need this to define the catgory "others"
with open('config/templates.yaml') as f:
    templates_config = yaml.load(f, Loader=SafeLoader)

# I would make some tests with the 3D fitter (q2_2, tauY_2, bdt_all)  for events that pass bdt_all cuts: >0.75 (cut1) and >0.5 (cut3) for the moment.
# In all cases you should generate templates for each “group of category” as a TH3F histogram (or equivalent) with 5 bins in each dimension and the following ranges:
# q2_2:    [0,11]
# 1000 * tauY_2: [0,2]
# bdt_all: [cut_value,1]


# - cut1: consider 11 templates:
# - signal (from signal MC) (category 24)
# - background (from inclusive b->Ds3piX and inclusive b->DsHcX)
#  10 different templates grouping the categories as follows:     [18],[29],[23],[15,0,others],[16,14],[25,7,19,13],[27,22],[20],[26],[21]

# Loading the data, limit to a specific eventIndex if requested
log.info("Loading the data")
df = load_complete_df()
if args.eventIndex is not None:
    df = df.query(f"eventIndex == {args.eventIndex}").copy()

# Applying the bdt now
df = apply_bdtdblcharm(df)

# Finding the categories in "others"
all_categs = [ str(c) for c in df['category'].unique()]
others = "_".join(get_other_categories(templates_config, args.grouping, all_categs))

# Final list of categories...
categs = [ c.strip() for c in args.categories.replace("others", others).split("_") ]
logging.info("Keeping Categories %s" % " ".join(categs))

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
h = rdf_category.Histo3D((f"TemplateCat{args.categories}",f"Template for category {args.categories}",5,0,11,5,0.,0.002,5,cutval,1),"q2_2","tauY_2",  "bdt_all")
zero = 0.
for i in range(5*5*5) : 
    #print(h.GetBinContent(i+1))
    if (h.GetBinContent(i+1) == 0) : 
        zero = zero+1.
        h.SetBinContent(i+1,0.00001)

print(zero," ",zero/(5.*5.*5.))        
h.Write()
hfile.Close()
