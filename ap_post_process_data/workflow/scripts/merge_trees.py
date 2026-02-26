#!/usr/bin/env python
import ROOT
import sys
import logging

logging.basicConfig(level=logging.INFO)
log = logging.getLogger("merge_trees")

output_file = sys.argv[1]
input_files = sys.argv[2:]
logging.info("Merging filtered output to %s", output_file)


ch = ROOT.TChain("DecayTree")
for f in input_files:
    ch.Add(f)

rdf = ROOT.RDataFrame(ch)

print("Total number of candidates: ", rdf.Count().GetValue())
rdf.Snapshot("DecayTree", output_file)
