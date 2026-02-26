#
# Split the ntuple with category by background category
#
import argparse
import json
import os
import sys
import logging
import categories4 as f
import ROOT

# Setting the logging up
logging.basicConfig(
    format="%(asctime)s %(levelname)-8s %(message)s",
    level=logging.INFO,
    datefmt="%Y-%m-%d %H:%M:%S",
)
log = logging.getLogger("filters_eff")
log.setLevel(logging.INFO)


# Parsing the script arguments
# --------------------------------------------------------------------------------------
parser = argparse.ArgumentParser(
    description="Filter a dataset and add the category variables."
)
parser.add_argument("input", help="File to load")
parser.add_argument("output", help="File to write")
parser.add_argument("category", help="Category to filter")
args = parser.parse_args()

# Loading the data (or a local cache)
# --------------------------------------------------------------------------------------
log.info("Loading the dataframe")
input_filename = args.input
output_filename = args.output
category = args.category
rdf = ROOT.RDataFrame("DecayTree", input_filename)
rdf2 = rdf.Filter(f"category == {category}")
rdf2.Snapshot("DecayTree", output_filename)
log.info("Done snapshot")

