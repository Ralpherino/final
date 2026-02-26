#!/usr/bin/env python

import json
import pandas as pd
import numpy as np
import ROOT

from pathlib import Path
thispath = Path(__file__).resolve().parent
configpath = thispath.parent.parent / "config" / "config.json"
# Getting the location of the data from the config file used by Snakemake
# #######################################################################
with open(configpath) as f:
    config = json.load(f)
rdshad_dir = config["AP_POST_PROCESS_DIR"]

# Various utils to load the file 
# #######################################################################
def mc_category_file(eventtype, category, polarity, sign="rs"):
    return  f"{rdshad_dir}/rds_categfiltered_2012_{eventtype}_{polarity}_{sign}_{str(category)}.root"

def mc_category_files(eventtype, category, sign="rs"):
    return [ mc_category_file(eventtype, category, p, sign=sign) for p in [ "magdown", "magup" ] ]

def mc_file(eventtype, polarity, sign="rs"):
    return  f"{rdshad_dir}/rds_categ_2012_{eventtype}_{polarity}_{sign}.root"

def mc_files(eventtype, sign="rs"):
    return [ mc_file(eventtype, p, sign=sign) for p in [ "magdown", "magup" ] ]

def load_signal_rdf():
    rdf_signal = ROOT.RDataFrame("DecayTree",  mc_files("13563002"))
    # Extra cuts on signal, identical to the ones applied by Carmen
    rdf_signal = rdf_signal.Filter("(BDT_3pi>(-0.0727) && BDT_Ds>(-0.0876) && BDT_Bs>(-0.0655) && (Xc_Selection>0) && (Xc_BKGCAT== 0 ) &&  Y_BKGCAT==50 && B_BKGCAT==50 && a\
bs(p1_fromXc_TRUEID)==321 && abs(p2_fromXc_TRUEID)==321 && abs(p3_fromXc_TRUEID)==211 && abs(p1_fromY_TRUEID)+abs(p2_fromY_TRUEID)+abs(p3_from\
Y_TRUEID)==3*211 )")
    rdf_signal = rdf_signal.Filter("B_Y_SEP<-4.5 && BDT_Iso>0.03458 & q2_2>0 && abs(mN2v)<250e6")
    return rdf_signal

def load_category_rdf(category, inclmc_type):
    rdf = ROOT.RDataFrame("DecayTree", mc_category_files( inclmc_type, category))
    return rdf.Filter("abs(mN2v)<250e6")

def load_signal_from_inclMC_rdf():
    rdf = ROOT.RDataFrame("DecayTree",  mc_files("23903000"))
    rdf = rdf.Filter("category==24")
    rdf = rdf.Filter("(BDT_3pi>(-0.0727) && BDT_Ds>(-0.0876) && BDT_Bs>(-0.0655) && (Xc_Selection>0) && (Xc_BKGCAT== 0 ) &&  Y_BKGCAT==50 && B_BKGCAT==50 && abs(p1_fromXc_TRUEID)==321 && abs(p2_fromXc_TRUEID)==321 && abs(p3_fromXc_TRUEID)==211 && abs(p1_fromY_TRUEID)+abs(p2_fromY_TRUEID)+abs(p3_fromY_TRUEID)==3*211 )")
    rdf = rdf.Filter("B_Y_SEP<-4.5 && BDT_Iso>0.03458 & q2_2>0 && abs(mN2v)<250e6")
    return rdf

def load_incmc_from_inclMC_rdf(eventtype):
    """ Load the incmc, unfiltered. Exclude signal"""
    rdf1 = ROOT.RDataFrame("DecayTree",  mc_files(eventtype))
    return rdf1.Filter("abs(mN2v)<250e6 && q2_2>0  && category != 24")

def load_dataframes(inclmc_type):
    rdf_signal = load_signal_rdf()
    rdf_Xc_signal_Ypis_displaced_fromBs_fromDs = load_category_rdf(18, inclmc_type)
    rdf_Xc_signal_Ypis_displaced_fromB0_fromDp = load_category_rdf(19, inclmc_type)
    rdf_Xc_signal_Ypis_displaced_fromBp_fromD0 = load_category_rdf(20, inclmc_type)
    return (rdf_signal, rdf_Xc_signal_Ypis_displaced_fromBs_fromDs, rdf_Xc_signal_Ypis_displaced_fromB0_fromDp, rdf_Xc_signal_Ypis_displaced_fromBp_fromD0)

#Below are the variables used fir the clssification in TMVA
used_base_columns = [
    "Y_0_40_nc_mult",
    "Y_0_20_cc_mult",
    "Y_0_20_cc_PZ",
    "Y_0_30_nc_PZ",
    "Y_0_40_nc_PZ",
    "min_m2pi",
    "max_m2pi",
    "missing_mass_2",
    "B_M",
    # log(abs(PBsn))
    # log(abs(PBv/B_P))
    # log(abs(PBvn/B_P))
    # log(abs((PBsn-PBvn)/PBvn))
    # log(sqrt(abs(mDs2vn)))
    # log(Y_PE)
    "BDT_Iso",
    "B_pT_Bdir",
    "Y_BPVVDR",
    "missing_pY_mass",
    "Y_correctedMass", 
    "q2_2",
    "tauY_2",
    "B_BPVVDR", 
    "mN2v",
    "B_Y_SEP",
    "B_correctedMass",
    "eventIndex"
]

cache_columns = used_base_columns + [
    "PBsn", "PBv", "B_P", "PBvn", "mDs2vn", "Y_PE", "category"]

def load_df(rdf, signal = 0):
    df = pd.DataFrame(rdf.Cache(cache_columns).AsNumpy())
    df["log(abs(PBsn))"] = np.log(np.abs(df["PBsn"]))
    df["log(abs(PBv/B_P))"] = np.log(np.abs(df["PBv"] / df["B_P"]))
    df["log(abs(PBvn/B_P))"] = np.log(np.abs(df["PBvn"] / df["B_P"]))
    df["log(abs((PBsn-PBvn)/PBvn))"] = np.log(np.abs((df["PBsn"] - df["PBvn"]) / df["PBvn"]))
    df["log(sqrt(abs(mDs2vn)))"] = np.log(np.sqrt(np.abs(df["mDs2vn"])))
    df["log(Y_PE)"] = np.log(df["Y_PE"]) 
    df["signal"] = signal
    df["diff_m2pi"] = df["max_m2pi"] - df["min_m2pi"]
    return df

def load_data(inclmc_type="23903000"):
    
    # Creating the ROOT RDataFrames
    dataframes = load_dataframes(inclmc_type)
    (rdf_signal, rdf_disp_BsDs, rdf_disp_B0Dp, rdf_disp_BpD0) = dataframes
    # for rdf in dataframes:
    #      print(f"{rdf.Count().GetValue()}")
    root_datasets = {
        "rdf_signal": rdf_signal,
        "rdf_disp_BsDs": rdf_disp_BsDs,
        "rdf_disp_B0Dp": rdf_disp_B0Dp,
        "rdf_disp_BpD0": rdf_disp_BpD0,
    }

    # Creating Pandas dataframes based on the RDataFrames
    df_signal = load_df(rdf_signal, 1)
    df_disp_BsDs = load_df(rdf_disp_BsDs, 0)
    df_disp_B0Dp = load_df(rdf_disp_B0Dp, 0)
    df_disp_BpD0 = load_df(rdf_disp_BpD0, 0)
    pandas_datasets = {
        "df_signal": df_signal,
        "df_disp_BsDs": df_disp_BsDs,
        "df_disp_B0Dp": df_disp_B0Dp,
        "df_disp_BpD0": df_disp_BpD0,
    }


    for name, ds in pandas_datasets.items():
        print(f"Created {name}: {ds.shape}")
    
    return (root_datasets, pandas_datasets)

#
# Methods to prepare Pandas dataframes with the columns that we need#
#
def load_signal_from_inclMC():
    # Creating the ROOT RDataFrames
    rdf  = load_signal_from_inclMC_rdf()
    df_signal = load_df(rdf, 1) 
    print(f"Created df_signal_23903000: {df_signal.shape}")
    return df_signal

def load_signal_all():
    rdf_signal = load_signal_rdf()
    df_signal = load_df(rdf_signal, 1)
    rdf_signal_inclMC  = load_signal_from_inclMC_rdf()
    df_signal_incl_MC = load_df(rdf_signal_inclMC, 1) 
    return pd.concat([df_signal, df_signal_incl_MC], axis=0)

def load_background_category(category):
    bkg23903000 = load_df(load_category_rdf(category, "23903000"), 0)
    bkg23903003 = load_df(load_category_rdf(category, "23903003"), 0)
    return pd.concat([bkg23903000, bkg23903003], axis=0)


def load_complete_df():
    """ Load a dataset with all categories 
    """
    df1 = load_df(load_incmc_from_inclMC_rdf("23903000"), 0)
    df2 = load_df(load_incmc_from_inclMC_rdf("23903003"), 0)
    df = pd.concat([df1, df2], axis=0)
    dfsig = load_signal_all()
    dfall = pd.concat([df, dfsig], axis=0)
    return dfall


def load_inclusive_df():
    """ Load the dataset with inclusiveb->Ds3piX 
    """
    df1 = load_df(load_incmc_from_inclMC_rdf("23903000"), 0)
    dfsig = load_signal_from_inclMC()
    dfall = pd.concat([df1, dfsig], axis=0)
    return dfall