#!/usr/bin/env python
import categories4
import json
import pandas as pd
import numpy as np
import ROOT
import joblib

from pathlib import Path
thispath = Path(__file__).resolve().parent
configpath = thispath.parent / "config" / "config.json"

# Getting the location of the data from the config file used by Snakemake
# #######################################################################
with open(configpath) as f:
    config = json.load(f)
ap_post_process_dir = config["AP_POST_PROCESS_DIR"]

def get_filenames(data_prefix, datatype="2012", eventtype="23903000", sign="rs"):
    polarities = [ "magdown", "magup" ]
    filenames = [ f"{data_prefix}/rds_final_{d}_{e}_{p}_{s}.root" 
                    for d in [ datatype ]
                    for e in [ eventtype ]
                    for p in polarities
                    for s in [ sign ] ]
    return filenames

def load_and_categorize( filenames):
    rdf = ROOT.RDataFrame("DecayTree", filenames)
    rdf = categories4.add_categories_and_filter(rdf,  apply_BDT_Iso_cut=True, apply_PIDK_cut=True)
    base_columns = [ "eventIndex", "category", "simplified", "B_M", "B_Y_SEP", "Xc_signal_Ypis_displaced_fromBs_fromTau", "fromY_from_B_vertex", "BDT_Iso", "q2_2"]
    load_columns = [
        "Y_0_40_nc_mult",
        "Y_0_20_cc_mult",
        "Y_0_20_cc_PZ",
        "Y_0_30_nc_PZ",
        "Y_0_40_nc_PZ",
        "min_m2pi",
        "max_m2pi",
        "missing_mass_2",
        "B_BPVVDR",
        "B_M",
        "B_correctedMass",
    #     "log(abs(PBsn))",
    #     "log(abs(PBv/B_P))",
    #     "log(abs(PBvn/B_P))",
    #     "log(abs((PBsn-PBvn)/PBvn))",
    #     "log(sqrt(abs(mDs2vn)))",
        "mN2v",
    #    "log(Y_PE)",
        "BDT_Iso",
        "B_pT_Bdir",
        "Y_BPVVDR",
        "missing_pY_mass",
        "Y_correctedMass",
        'PBsn',
        'PBv', 'PBvn', 'B_P', 'mDs2vn', 'Y_PE', 'Y_M'
    ]
    train_columns = [
        "Y_0_40_nc_mult",
        "Y_0_20_cc_mult",
        "Y_0_20_cc_PZ",
        "Y_0_30_nc_PZ",
        "Y_0_40_nc_PZ",
        "min_m2pi",
        "max_m2pi",
        "missing_mass_2",
        "B_BPVVDR",
        "B_M",
        "B_correctedMass",
        "log(abs(PBsn))",
        "log(abs(PBv/B_P))",
        "log(abs(PBvn/B_P))",
        "log(abs((PBsn-PBvn)/PBvn))",
        "log(sqrt(abs(mDs2vn)))",
        "mN2v",
        "log(Y_PE)",
        "BDT_Iso",
        "B_pT_Bdir",
        "Y_BPVVDR",
        "missing_pY_mass",
        "Y_correctedMass",
    ]

    columns = base_columns +  load_columns
    df = pd.DataFrame(rdf.Cache(columns).AsNumpy())
    df['simplified_key'] = df.apply(lambda row: categories4.pretty_categories_map[row["simplified"]], axis=1)
    df['key'] = df.apply(lambda row: categories4.categories_map[row["category"]], axis=1)
    df['signal'] = (df['simplified_key'] == 'Signal')
    dfbm = df.query("B_M < 5000")

    # We expect the workflow to have dragged the BDT file in the directory above
    bdtdblcharm = joblib.load("bdtdblcharm_150_3_0.04.pkl")
    def add_cols_for_bdt(tmpdf):
        df = tmpdf.copy()
        df["log(abs(PBsn))"] = np.log(np.abs(df["PBsn"]))
        df["log(abs(PBv/B_P))"] = np.log(np.abs(df["PBv"] / df["B_P"]))
        df["log(abs(PBvn/B_P))"] = np.log(np.abs(df["PBvn"] / df["B_P"]))
        df["log(abs((PBsn-PBvn)/PBvn))"] = np.log(np.abs((df["PBsn"] - df["PBvn"]) / df["PBvn"]))
        df["log(sqrt(abs(mDs2vn)))"] = np.log(np.sqrt(np.abs(df["mDs2vn"])))
        df["log(Y_PE)"] = np.log(df["Y_PE"]) 
        df["diff_m2pi"] = df["max_m2pi"] - df["min_m2pi"]
        return df
    dfbm2 = add_cols_for_bdt(dfbm)
    dfbm2['bdt_dc'] = bdtdblcharm.predict_proba(dfbm2[train_columns])[:,1]
    return dfbm2

def pickle_filtered_data(filename, datatype, eventtype, sign):
    filenames = get_filenames(ap_post_process_dir, datatype, eventtype, sign)
    df = load_and_categorize( filenames)
    df.to_pickle(filename)