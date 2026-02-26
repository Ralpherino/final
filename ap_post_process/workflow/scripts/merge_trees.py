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

# We specify the columsn to be saved to make sure we have new pidgen columns in the final tree
basecolumns = [ str(c) for c in list(rdf.GetColumnNames()) if "DecayTree." not in str(c)]
pidcolumnsXc = [ f"p{i}_from{s}_PID{p}_pidgen_default" for i in range(1,4) for s in [ "Xc"] for p in ["K", "p"] ]
pidcolumnsY = [ f"p{i}_from{s}_PID{p}_pidgen_default" for i in range(1,4) for s in [ "Y"] for p in ["K", "p"] ]
if len([ str(c) for c in list(rdf.GetColumnNames()) if "p1_fromY_K_PIDK_pidgen_default" in str(c)]) > 0:
    pidcolumnsY = [ f"p{i}_fromY_{p}_PIDK_pidgen_default" for i in range(1,4)  for p in ["K", "pi"] ]

print("Total number of candidates: ", rdf.Count().GetValue())
rdf.Snapshot("DecayTree", output_file, basecolumns+pidcolumnsXc+pidcolumnsY)
