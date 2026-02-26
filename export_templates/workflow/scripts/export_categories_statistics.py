#!/usr/bin/env python
#
# Script to load a dataset and print teh categorisation
#
import argparse
import logging
import os
import sys
from collections.abc import Iterable
from pathlib import Path

import yaml
from yaml.loader import SafeLoader

from data import simple_load_inclusiveMC_df
from bdt_all import apply_bdtdblcharm
from grouping import CUTS, get_grouping_info
from utils import mygroupby

logging.basicConfig(level=logging.INFO)
log = logging.getLogger("export_stats")


# Parsing the arguments
parser = argparse.ArgumentParser()
parser.add_argument("output", help="Output file to write", type=str)
args = parser.parse_args()


log.info("Loading the data")
df = simple_load_inclusiveMC_df()

# Applying the bdt now
df = apply_bdtdblcharm(df)

# Adding the cuts on bdt_all and categories
log.info(f"Candidates before bdt_all cut: {df.shape[0]}")

df = df.query(f"bdt_all > {cutval}")
log.info(f"Candidates after bdt_all cut: {df.shape[0]}")
all_categories = [str(c) for c in df["category"].unique()]
groups, categ_to_group = get_grouping_info(
    templates_config, args.grouping, all_categories
)
from pprint import pprint

pprint(groups)
pprint(categ_to_group)


def map_categ(row):
    return categ_to_group[str(int(row["category"]))]


df["template_category"] = df.apply(map_categ, axis=1)

# grouping and saving the output
c = mygroupby(df, "template_category")
log.info("Writing %s", args.output)
os.makedirs(Path(args.output).parent, exist_ok=True)
c[["template_category", "count", "Percentage"]].to_json(args.output)
