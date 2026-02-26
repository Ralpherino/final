#!/usr/bin/env python
#
# Script to train a BDT to separate the RDs hadronic signal against all other backgrounds
#
import argparse
import logging
from collections.abc import Iterable

import yaml
from yaml.loader import SafeLoader


from data import load_inclusive_df
from bdt_all import apply_bdtdblcharm

from utils import mygroupby

logging.basicConfig(level=logging.INFO)
log = logging.getLogger("export_hist")

# Loadingthe template configuration
with open('config/templates.yaml') as f:
    templates_config = yaml.load(f, Loader=SafeLoader)

# Parsing the arguments
parser = argparse.ArgumentParser()
parser.add_argument("cut", help="Cut to apply to the ", type=str)
parser.add_argument("output", help="Output file to write", type=str)
parser.add_argument(
    "--eventIndex", help="eventIndex to use (either 0 or 1)", default=None, type=int
)
args = parser.parse_args()

cuts = { 
    "cut1": 0.75,
    "cut2": 0.35,
    "cut3": 0.5
}
cutval = cuts[args.cut]

groups = templates_config['template_groups'][args.cut]
def group_name(group):
    if isinstance(group, Iterable):
        return "_".join([str(c) for c in group])
    else:
        return str(group)

categ_to_group = {}
# Iterate on the list of group defines
others_group_name = None
for group in groups:
    if isinstance(group, Iterable):
        for g in group:
            if g != "others":
                categ_to_group[g] = group_name(group)
            else:
                others_group_name = group_name(group)
    else:
        categ_to_group[group] = group_name(group)
# Map the unhandled categories to other
for c in templates_config['others_template']:
    categ_to_group[c] = others_group_name

from pprint import pprint
pprint(categ_to_group)

log.info("Loading the data")
df = load_inclusive_df()
if args.eventIndex is not None:
    df = df.query(f"eventIndex == {args.eventIndex}").copy()

# Applying the bdt now
df = apply_bdtdblcharm(df)

# Adding the cuts on bdt_all and categories
log.info(f"Candidates before bdt_all cut: {df.shape[0]}")
df = df.query(f"bdt_all > {cutval}")
log.info(f"Candidates after bdt_all cut: {df.shape[0]}")

def map_categ(row):
    #print(row)
    return categ_to_group[row['category']]

df['template_category'] = df.apply(map_categ, axis=1)

# grouping and saving the output
c = mygroupby(df, 'template_category')
log.info("Writing %s", args.output)
c[["template_category", "count", "Percentage"]].to_json(args.output)