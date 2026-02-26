#!/usr/bin/env python
import json
import pandas as pd
import numpy as np
import ROOT
import joblib
import logging
import categories4

# logging.basicConfig()
# log = logging.getLogger("data")

from pathlib import Path
thispath = Path(__file__).resolve().parent
configpath = thispath.parent / "config" / "config.json"

# Getting the location of the data from the config file used by Snakemake
# #######################################################################
with open(configpath) as f:
    config = json.load(f)
ap_post_process_data_dir = config["AP_POST_PROCESS_DATA_DIR"]
ap_post_process_dir = config["AP_POST_PROCESS_DIR"]

def get_filenames(datatype="2012", 
                  eventtype="90000000", sign="rs", name="final"):
    if eventtype == "90000000":
        data_prefix = ap_post_process_data_dir
    else:
        data_prefix = ap_post_process_dir
    print("Loading files from %s", data_prefix)

    polarities = [ "magdown", "magup" ]
    filenames = [ f"{data_prefix}/rds_{name}_{d}_{e}_{p}_{s}.root" 
                    for d in [ datatype ]
                    for e in [ eventtype ]
                    for p in polarities
                    for s in [ sign ] ]
    return filenames

# Columns to be passed to the BDT
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


def get_load_columns(isMC=False):
    base_columns = [ "eventIndex", "B_M", "B_Y_SEP", "BDT_Iso", "q2_2",
                     "BDT_3pi", "BDT_Ds", "BDT_Bs", "eventNumber",
                     "totCandidates", "nCandidate", "B_ENDVERTEX_ZERR", 
                     "Xc_ENDVERTEX_Z", "Y_ENDVERTEX_Z", "B_ENDVERTEX_Z", 
                     "Xc_ENDVERTEX_X", "Y_ENDVERTEX_X", "B_ENDVERTEX_X", 
                     "Xc_ENDVERTEX_Y", "Y_ENDVERTEX_Y", "B_ENDVERTEX_Y", 
                     "Y_ENDVERTEX_ZERR"]
    load_columns = [
        "B_MM",
        "Xc_M", "Xc_MM",
        "Y_0_40_nc_mult",
        "Y_0_20_cc_mult",
        "Y_0_20_cc_PZ",
        "Y_0_30_nc_PZ",
        "Y_0_40_nc_PZ",
        "min_m2pi",
        "max_m2pi",
        "missing_mass_2",
        "B_BPVVDR",
        "B_correctedMass",
        "mN2v",
        "BDT_Iso",
        "BDT_Ds",
        "BDT_Bs",
        "BDT_3pi",
        "B_pT_Bdir",
        "Y_BPVVDR",
        "missing_pY_mass",
        "Y_correctedMass",
        'PBsn',
        'PBv', 'PBvn', 'B_P', 'mDs2vn', 'Y_PE', 
        'Y_M', 'Y_MM', 'Xc_PT',
        'Xc_ENDVERTEX_CHI2',
        'Xc_FD_OWNPV',
        'Xc_FD_ORIVX',
        'Xc_ETA',
        'B_PT', 'B_ETA', 'nTracks', 'nSPDHits', 'tauY_2']
    if isMC:
        load_columns += [ "category", "simplified", "Xc_Selection", "Xc_BKGCAT",
                         "Xc_signal_Ypis_displaced_fromBs_fromTau", 
                         "fromY_from_B_vertex" ]
    
    return base_columns + load_columns


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

def add_bdt(df):
    dfbm2 = add_cols_for_bdt(df)
    # We expect the workflow to have dragged the BDT file in the directory
    bdtdblcharm = joblib.load("bdtdblcharm_150_3_0.04.pkl")
    dfbm2['bdt_dc'] = bdtdblcharm.predict_proba(dfbm2[train_columns])[:,1]
    return dfbm2


def load_fitcandidates( filenames):
    rdf = ROOT.RDataFrame("DecayTree", filenames)
    rdf = rdf.Filter("q2_2>0 && abs(mN2v)<250e6 && BDT_Iso > 0.03458 && B_M < 5000")
    columns = get_load_columns()
    df = pd.DataFrame(rdf.Cache(columns).AsNumpy())
    dfbm2 = add_bdt(df)
    return dfbm2

def pickle_fitcandidates(filename, datatype, eventtype, sign):
    filenames = get_filenames(datatype, eventtype, sign)
    if eventtype == "90000000":
        df = load_fitcandidates(filenames)
    else:
        df = load_and_categorize_MC(filenames)
    df.to_pickle(filename)



def load_and_categorize_MC( filenames):
    rdf = ROOT.RDataFrame("DecayTree", filenames)
    rdf = categories4.add_categories_and_filter(rdf,  apply_BDT_Iso_cut=False, apply_PIDK_cut=False)
    # This needs to be done AFTER the previous method
    rdf = rdf.Filter("q2_2>0 && abs(mN2v)<250e6 && BDT_Iso > 0.03458 && B_M < 5000")

    columns = get_load_columns(True)
    df = pd.DataFrame(rdf.Cache(columns).AsNumpy())
    df['simplified_key'] = df.apply(lambda row: categories4.pretty_categories_map[row["simplified"]], axis=1)
    df['key'] = df.apply(lambda row: categories4.categories_map[row["category"]], axis=1)
    df['signal'] = (df['simplified_key'] == 'Signal')
    df = add_bdt(df)
    return df


def load_norm( filenames, isMC = False):
    rdf = ROOT.RDataFrame("DecayTree", filenames)
    if isMC:
        rdf = categories4.add_categories_and_filter(rdf,  apply_BDT_Iso_cut=False, apply_PIDK_cut=False)
    rdf = rdf.Filter("B_M > 5000 && BDT_Iso > 0.03458")
    if isMC:
        rdf = rdf.Filter("Xc_Selection > 0")

    columns =get_load_columns(isMC)
    df = pd.DataFrame(rdf.Cache(columns).AsNumpy())
    df = add_bdt(df)
    if isMC:
        df['simplified_key'] = df.apply(lambda row: categories4.pretty_categories_map[row["simplified"]], axis=1)
        df['key'] = df.apply(lambda row: categories4.categories_map[row["category"]], axis=1)
        df['signal'] = (df['simplified_key'] == 'Signal')
    return df

def norm_filenames(datatype, eventtype, sign):

    if eventtype in [ "90000000", "23903000" ]:
        filenames = get_filenames(datatype, 
                                eventtype, sign, name="finalBMsup5000")
    else:
        filenames = get_filenames(datatype, 
                                eventtype, sign, name="finalnoBYsep")
    return filenames

def pickle_norm(filename, datatype, eventtype, sign):
    filenames = norm_filenames(datatype, eventtype, sign)
    df = load_norm(filenames, isMC = eventtype != "90000000")
    df.to_pickle(filename)

