#!/usr/bin/env python
#
# Script to load a dataset and print teh categorisation
#
import argparse
import logging
import ROOT
import categories4
import sys


from pathlib import Path
thispath = Path(__file__).resolve().parent
sys.path.append(str(thispath))

logging.basicConfig(level=logging.INFO)
log = logging.getLogger("filter")


# Parsing the arguments
parser = argparse.ArgumentParser()
parser.add_argument("input", help="Input file", type=str)
parser.add_argument("output", help="Output file to write", type=str)
args = parser.parse_args()

log.info("Loading the data from %s, writing to %s", args.input, args.output)
rdf = ROOT.RDataFrame("DecayTree", args.input)
rdf2 = categories4.add_categories_and_filter(rdf, apply_BDT_Iso_cut=True, apply_PIDK_cut=True)

log.info("Writing snapshot to %s", args.output)
rdf2.Snapshot("DecayTree", args.output)
log.info("Snapshot done")
