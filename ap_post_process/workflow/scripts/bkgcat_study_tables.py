#!/usr/bin/env python3
from pathlib import Path
import sys
import ROOT
import bkgcat_study as cats

BASE = Path("/eos/lhcb/user/r/relhage/test/rds/Ben/ap_post_process/output/")

TREE_CANDIDATES = [
    "DecayTree",
    "SignalTuple/DecayTree",
]

def find_working_tree(files, candidates):
    for tree in candidates:
        try:
            rdf = ROOT.RDataFrame(tree, files[:1])
            _ = rdf.Count().GetValue()
            return tree
        except Exception:
            pass
    return None

if len(sys.argv) < 2:
    print("Usage:")
    print("  python3 study_bkg_tables.py <rootfile>")
    print("Example:")
    print("  python3 study_bkg_tables.py rds_final_2012_23903000_magup_rs.root")
    sys.exit(1)

input_name = sys.argv[1]
input_path = BASE / input_name

if not input_path.exists():
    raise FileNotFoundError(f"File not found: {input_path}")

files = [str(input_path)]

print("Using file:")
print(" ", files[0])

tree_name = find_working_tree(files, TREE_CANDIDATES)
if tree_name is None:
    raise RuntimeError(
        f"Could not find a working tree among: {TREE_CANDIDATES}"
    )

print(f"\nUsing tree: {tree_name}")

rdf = ROOT.RDataFrame(tree_name, files)

print("\n=== DETAILED TABLE ===")
cats.print_detailed_category_table(
    rdf,
    apply_BDT_Iso_cut=True,
    apply_PIDK_cut=True,
    apply_Xc_Selection_cut=False,
)

print("\n=== Simplified Categorization ===")
cats.print_pretty_category_table(
    rdf,
    apply_BDT_Iso_cut=True,
    apply_PIDK_cut=True,
    apply_Xc_Selection_cut=False,
)
