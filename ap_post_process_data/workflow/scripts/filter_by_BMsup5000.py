#!/usr/bin/env python
import ROOT
import sys
import logging

logging.basicConfig(level=logging.INFO)
log = logging.getLogger("BM_sup_5000")

input_file  = sys.argv[1]
output_file = sys.argv[2]

log.info("Writing filtering output to %s", output_file)
rdf = ROOT.RDataFrame("DecayTree", input_file)
log.info("Total number of candidates before filter: %s", rdf.Count().GetValue())
filtered = rdf.Filter("B_M > 5000", "BM_sup_5000")
log.info("Total number of candidates after filter: %s", filtered.Count().GetValue())
filtered.Snapshot("DecayTree", output_file)
