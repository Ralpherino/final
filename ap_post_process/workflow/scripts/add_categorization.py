#
# Produce plots with the test dntuples with extra variables
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
parser.add_argument(
    "metadata", help="File to write with the metadata info about the categories"
)
args = parser.parse_args()

# Loading the data (or a local cache)
# --------------------------------------------------------------------------------------
log.info("Loading the dataframe")
input_filename = args.input
output_filename = args.output
metadata_filename = args.metadata
rdf = ROOT.RDataFrame("DecayTree", input_filename)
rdf = f.add_categories_and_filter(rdf, apply_BDT_Iso_cut=False, apply_PIDK_cut=False)

# Writing out the filtered ntuple
# --------------------------------------------------------------------------------------
log.info("Starting snapshot")
snapshot_variables = [
    "B_MM",
    "category",
    "simplified",
    "q2_2",
    "tauB_2",
    "tauY_2",
    "BDT_Iso",
    "B_Y_SEP",
    "B_Y_SEP_v2",
    "BDT_Bs",
    "BDT_3pi",
    "BDT_Ds",
    "Xc_Selection",
    "Xc_TRUEID",
] + list(f.categories.keys())

extra_vars = [
    "B_P",
    "min_m2pi",
    "max_m2pi",
    "missing_mass",
    "missing_mass_2",
    "PBs",
    "PBv",
    "PDsv",
    "PDss",
    "PBvn",
    "PBsn",
    "PDsvn",
    "PDssn",
    "mDs2s",
    "mDs2v",
    "mDs2sn",
    "mDs2vn",
    "mN2s",
    "mN2v",
    "mN2n",
    "Y_correctedMass",
    "Y_pT_Ydir",
    "Y_pT_Bdir",
    "B_correctedMass",
    "B_pT_Bdir",
    "missing_pY_mass",
    "theta_n3pi_pYrec_cms3pi",
    "theta_n3pi_pXc_cms3pi",
    "Y_PE",
    "Y_TRUEP_E",
    "Y_BPVVDR",
    "B_BPVVDR",
    "Xc_BPVVDR",
    "eventIndex"
]
snapshot_variables += extra_vars

Y_nc_vars = [
    "Y_0_20_nc_mult",
    "Y_0_20_nc_sPT",
    "Y_0_20_nc_vPT",
    "Y_0_20_nc_PX",
    "Y_0_20_nc_PY",
    "Y_0_20_nc_PZ",
    "Y_0_20_nc_avCL",
    "Y_0_20_nc_maxCL",
    "Y_0_20_nc_asy_P",
    "Y_0_20_nc_asy_PT",
    "Y_0_20_nc_asy_PX",
    "Y_0_20_nc_asy_PY",
    "Y_0_20_nc_asy_PZ",
    "Y_0_20_nc_deltaEta",
    "Y_0_20_nc_deltaPhi",
    "Y_0_20_nc_IT",
    "Y_0_20_nc_maxPt_PT",
    "Y_0_20_nc_maxPt_PX",
    "Y_0_20_nc_maxPt_PY",
    "Y_0_20_nc_maxPt_PZ",
    "Y_0_20_nc_H1",
    "Y_0_20_nc_H2",
    "Y_0_20_nc_H3",
    "Y_0_20_nc_H4",
    "Y_0_30_nc_mult",
    "Y_0_30_nc_sPT",
    "Y_0_30_nc_vPT",
    "Y_0_30_nc_PX",
    "Y_0_30_nc_PY",
    "Y_0_30_nc_PZ",
    "Y_0_30_nc_avCL",
    "Y_0_30_nc_maxCL",
    "Y_0_30_nc_asy_P",
    "Y_0_30_nc_asy_PT",
    "Y_0_30_nc_asy_PX",
    "Y_0_30_nc_asy_PY",
    "Y_0_30_nc_asy_PZ",
    "Y_0_30_nc_deltaEta",
    "Y_0_30_nc_deltaPhi",
    "Y_0_30_nc_IT",
    "Y_0_30_nc_maxPt_PT",
    "Y_0_30_nc_maxPt_PX",
    "Y_0_30_nc_maxPt_PY",
    "Y_0_30_nc_maxPt_PZ",
    "Y_0_30_nc_H1",
    "Y_0_30_nc_H2",
    "Y_0_30_nc_H3",
    "Y_0_30_nc_H4",
    "Y_0_40_nc_mult",
    "Y_0_40_nc_sPT",
    "Y_0_40_nc_vPT",
    "Y_0_40_nc_PX",
    "Y_0_40_nc_PY",
    "Y_0_40_nc_PZ",
    "Y_0_40_nc_avCL",
    "Y_0_40_nc_maxCL",
    "Y_0_40_nc_asy_P",
    "Y_0_40_nc_asy_PT",
    "Y_0_40_nc_asy_PX",
    "Y_0_40_nc_asy_PY",
    "Y_0_40_nc_asy_PZ",
    "Y_0_40_nc_deltaEta",
    "Y_0_40_nc_deltaPhi",
    "Y_0_40_nc_IT",
    "Y_0_40_nc_maxPt_PT",
    "Y_0_40_nc_maxPt_PX",
    "Y_0_40_nc_maxPt_PY",
    "Y_0_40_nc_maxPt_PZ",
    "Y_0_40_nc_H1",
    "Y_0_40_nc_H2",
    "Y_0_40_nc_H3",
    "Y_0_40_nc_H4",
]
Y_cc_vars = [
    "Y_0_20_cc_mult",
    "Y_0_20_cc_sPT",
    "Y_0_20_cc_vPT",
    "Y_0_20_cc_PX",
    "Y_0_20_cc_PY",
    "Y_0_20_cc_PZ",
    "Y_0_20_cc_asy_P",
    "Y_0_20_cc_asy_PT",
    "Y_0_20_cc_asy_PX",
    "Y_0_20_cc_asy_PY",
    "Y_0_20_cc_asy_PZ",
    "Y_0_20_cc_deltaEta",
    "Y_0_20_cc_deltaPhi",
    "Y_0_20_cc_IT",
    "Y_0_20_cc_maxPt_Q",
    "Y_0_20_cc_maxPt_PT",
    "Y_0_20_cc_maxPt_PX",
    "Y_0_20_cc_maxPt_PY",
    "Y_0_20_cc_maxPt_PZ",
    "Y_0_20_cc_maxPt_PE",
    "Y_0_30_cc_mult",
    "Y_0_30_cc_sPT",
    "Y_0_30_cc_vPT",
    "Y_0_30_cc_PX",
    "Y_0_30_cc_PY",
    "Y_0_30_cc_PZ",
    "Y_0_30_cc_asy_P",
    "Y_0_30_cc_asy_PT",
    "Y_0_30_cc_asy_PX",
    "Y_0_30_cc_asy_PY",
    "Y_0_30_cc_asy_PZ",
    "Y_0_30_cc_deltaEta",
    "Y_0_30_cc_deltaPhi",
    "Y_0_30_cc_IT",
    "Y_0_30_cc_maxPt_Q",
    "Y_0_30_cc_maxPt_PT",
    "Y_0_30_cc_maxPt_PX",
    "Y_0_30_cc_maxPt_PY",
    "Y_0_30_cc_maxPt_PZ",
    "Y_0_30_cc_maxPt_PE",
    "Y_0_40_cc_mult",
    "Y_0_40_cc_sPT",
    "Y_0_40_cc_vPT",
    "Y_0_40_cc_PX",
    "Y_0_40_cc_PY",
    "Y_0_40_cc_PZ",
    "Y_0_40_cc_asy_P",
    "Y_0_40_cc_asy_PT",
    "Y_0_40_cc_asy_PX",
    "Y_0_40_cc_asy_PY",
    "Y_0_40_cc_asy_PZ",
    "Y_0_40_cc_deltaEta",
    "Y_0_40_cc_deltaPhi",
    "Y_0_40_cc_IT",
    "Y_0_40_cc_maxPt_Q",
    "Y_0_40_cc_maxPt_PT",
    "Y_0_40_cc_maxPt_PX",
    "Y_0_40_cc_maxPt_PY",
    "Y_0_40_cc_maxPt_PZ",
    "Y_0_40_cc_maxPt_PE",
]
snapshot_variables += Y_nc_vars
snapshot_variables += Y_cc_vars

extra_vars_2 = [
    "B_M",
    "BDT_Ds",
    "Xc_MM",
    "Xc_ENDVERTEX_CHI2",
    "Xc_FD_OWNPV",
    "Xc_FD_ORIVX",
    "Xc_ETA",
    "Xc_PT",
]
extra_vars_2 += [
    "p1_fromXc_IPCHI2_OWNPV",
    "p2_fromXc_IPCHI2_OWNPV",
    "p3_fromXc_IPCHI2_OWNPV",
]
extra_vars_2 += [
    "p1_fromXc_PT",
    "p2_fromXc_PT",
    "p3_fromXc_PT",
]
extra_vars_2 += [
    "p1_fromXc_TRACK_GhostProb",
    "p2_fromXc_TRACK_GhostProb",
    "p3_fromXc_TRACK_GhostProb",
]
extra_vars_2 += [
    "p1_fromY_decay_top",
    "p2_fromY_decay_top",
    "p3_fromY_decay_top",
]
extra_vars_2 += [
    "p1_fromY_PANC_IDs",
    "p2_fromY_PANC_IDs",
    "p3_fromY_PANC_IDs",
]
extra_vars_2 += ["eventNumber"]

snapshot_variables += extra_vars_2

# columns for the U p1 alternatives
snapshot_variables += [
    f"p{i}_fromY_P{x}" for i in range(1, 4) for x in ["", "X", "Y", "Z", "E"]
]
snapshot_variables += [f"Y_M_p{i}K" for i in range(1, 4)] + [
    "Y_M",
    "p1K2_M",
    "K1p2_M",
    "p2K3_M",
    "K2p3_M",
    "p1K3_M",
    "K1p3_M",
]
snapshot_variables += (
    [f"p{i}_fromY_PIDK" for i in range(1, 4)]
    + ["Y_all_true_pions"]
)

snapshot_variables +=  [ "Xc_BKGCAT", "Y_BKGCAT", "B_BKGCAT"] 
snapshot_variables +=  [ f"p{i}_fromXc_TRUEID" for i in range(1, 4) ]
snapshot_variables +=  [ f"p{i}_fromY_TRUEID" for i in range(1, 4) ]

# Check what columsn we have for the corrected fromY_PIDK 
# inclusive MC has p?_fromY_(K|pi)_PIDK_pidgen_default
# whereas other samples have the same as for p?_fromXc
if "p1_fromY_K_PIDK_pidgen_default" in rdf.GetColumnNames():
    snapshot_variables +=         [
            f"p{i}_fromY_{p}_PIDK_pidgen_default"
            for i in range(1, 4)
            for p in ["K", "pi"]
    ]
else:
    snapshot_variables +=         [
            f"p{i}_fromY_PID{p}_pidgen_default"
            for i in range(1, 4)
            for p in [ "K", "p"]
    ]

final_sv =  list(set(snapshot_variables))
rdf.Snapshot("DecayTree", output_filename, final_sv)
log.info("Done snapshot")

# Writing out the mapping betwen categories
# --------------------------------------------------------------------------------------
categories_info = {}
categories_info["detailed_categories"] = f.categories_map
categories_info["simple_categories"] = f.simplified_categories_map
categories_info["mapping"] = f.detailed_to_simplified_category_mapping
with open(metadata_filename, "w") as f:
    json.dump(categories_info, f, indent=4)

cutReport = rdf.Report()
cutReport.Print()
