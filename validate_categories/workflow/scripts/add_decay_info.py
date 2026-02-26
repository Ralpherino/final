#!/usr/bin/env python
#
# Script to add decay information to the data
#
import argparse
import logging
import sys
import ROOT
import uproot
import joblib
import categories4
import numpy as np
import pandas as pd
from numba import jit
from particle import PDGID, Particle
from itertools import groupby
import collections
from pathlib import Path

thispath = Path(__file__).resolve().parent
sys.path.append(str(thispath))

logging.basicConfig(level=logging.INFO, format='%(asctime)s %(message)s') 
log = logging.getLogger("add_decay_info")

filter_columns = [
    "B_MM",
    "Y_MM",
    "q2_2",
    "tauY_2",
    "BDT_Iso",
    "B_Y_SEP",
    "BDT_Bs",
    "BDT_3pi",
    "BDT_Ds",
    "Xc_Selection",
]

bdt_columns = [
    "Y_0_40_nc_mult",
    "Y_0_20_cc_mult",
    "Y_0_20_cc_PZ",
    "Y_0_30_nc_PZ",
    "Y_0_40_nc_PZ",
    "min_m2pi",
    "max_m2pi",
    "missing_mass_2",
    "B_M",
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

bdt_columns +=  [
    "PBsn", "PBv", "B_P", "PBvn", "mDs2vn", "Y_PE", "category"]

def add_derived_columns_for_bdtdblcharm(df):
    df["log(abs(PBsn))"] = np.log(np.abs(df["PBsn"]))
    df["log(abs(PBv/B_P))"] = np.log(np.abs(df["PBv"] / df["B_P"]))
    df["log(abs(PBvn/B_P))"] = np.log(np.abs(df["PBvn"] / df["B_P"]))
    df["log(abs((PBsn-PBvn)/PBvn))"] = np.log(np.abs((df["PBsn"] - df["PBvn"]) / df["PBvn"]))
    df["log(sqrt(abs(mDs2vn)))"] = np.log(np.sqrt(np.abs(df["mDs2vn"])))
    df["log(Y_PE)"] = np.log(df["Y_PE"]) 
    df["diff_m2pi"] = df["max_m2pi"] - df["min_m2pi"]
    return df

def apply_bdtdblcharm(df):
    """ Apply the BDT trained on double charm events 
    to a pandas DataFrame """
    bdt_all = joblib.load("bdtdblcharm_150_3_0.04.pkl")
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
    pred = bdt_all.predict_proba(df[train_columns])
    df['bdt_all'] = pred[:,1]
    df['bdt_dc'] = pred[:,1]
    return df
 
def _get_common3(k1, k2, k3):
    tmpk = []
    minlen = min(len(k1), len(k2), len(k3))
    for j in range(-1, - minlen, -1):
        if k1[j] == k2[j] and k1[j] == k3[j]:
            tmpk.append(k1[j])
        else:
            break
    return tmpk

def _get_common2(k1, k2):
    tmpk = []
    for j in range(-1, -1 * min(len(k1), len(k2)), -1):
        if k1[j] == k2[j]:
            tmpk.append(k1[j])
        else:
            break
    return tmpk


def id2name(id):
    try:
        return Particle.from_pdgid(id).name
    except:
        return str(id)
    


class DecayData(collections.namedtuple('DecayData', [ 'keys', 'ids'])):
        __slots__ = ()
        def __str__(self):
            if len(self.ids) > 1:
                return "( " + " -> ".join([ id2name(p) for p in reversed(self.ids)]) + " )"
            elif len(self.ids) == 1:
                return id2name(self.ids[0])
            else:
                return ""
    

class Node(collections.namedtuple('Node',['parent','children'])):
        __slots__ = ()
        def __str__(self):
            ret = "[ " + str(self.parent) + " -> "
            ret += " ".join([str(c) for c in self.children])
            ret += " ]"
            return ret
           
def _subtract_parent(dd, common):
    return DecayData(dd.keys[:-len(common)], dd.ids[:-len(common)])


def _lists_to_graph3(dd1, dd2, dd3):
    
    common_k = _get_common3(dd1.keys, dd2.keys, dd3.keys)
    common_ids = dd1.ids[-len(common_k):]
    common = DecayData(common_k, common_ids)
    
    tmp1 = _subtract_parent(dd1, common_k)
    tmp2 = _subtract_parent(dd2, common_k)
    tmp3 = _subtract_parent(dd3, common_k)

    children = []
    
    decays = []
    if len(tmp1.keys) != 0:
        decays.append(tmp1)
    if len(tmp2.keys) != 0:
        decays.append(tmp2)
    if len(tmp3.keys) != 0:
        decays.append(tmp3)
        
    for key, group in groupby(decays, lambda x: x.keys[-1]):
        lg = list(group)
        if len(lg) == 1:
            children += lg
        elif len(lg) == 2:
            common_k = _get_common2(lg[0].keys, lg[1].keys)
            if len(common_k) > 0:
                children.append(_lists_to_graph2(*lg))
            else:
                children += lg

    return Node(common, children)


def _lists_to_graph2(dd1, dd2):
    
    common_k = _get_common2(dd1.keys, dd2.keys)
    if len(common_k) == 0:
        raise Exception("No common particles in the 2 decays")
    common_id = dd1.ids[-len(common_k):]
    common = DecayData(common_k, common_id)
  
    children = [ _subtract_parent(dd1, common_k), 
                 _subtract_parent(dd2, common_k) ]
    
    return Node(common, children)


def find_decay(keys1, keys2, keys3, ids1, ids2, ids3):
    decays = []
    for i in range(len(keys1)):
        tmpk = []
        tmpid = []
        k1 = [ t for t in keys1[i] if t != 0.0 ]
        k2 = [ t for t in keys2[i] if t != 0.0 ]
        k3 = [ t for t in keys3[i] if t != 0.0 ]
        id1 = [ t for t in ids1[i] if t != 0.0 ]
        id2 = [ t for t in ids2[i] if t != 0.0 ]
        id3 = [ t for t in ids3[i] if t != 0.0 ]
        
        #print(f"================= \n k1:{k1}\n k2:{k2}\n k3:{k3}")
        #print(f" id1:{id1}\n id2:{id2}\n id3:{k3}")    
        dec = _lists_to_graph3( DecayData(k1, id1), DecayData(k2, id2), DecayData(k3, id3))
        decays.append(str(dec))
        #print(dec)
    return decays
 
def main():
    # categories_of_interest = [
    #     "Xc_signal_Ypis_nomatch_doubleCharm",
    #     "Xc_signal_Ypis_diffVertex_doubleCharm_OneFromB",
    #     "Xc_signal_Ypis_diffVertex_doubleCharm_TwoFromB",]

    # {'Xc_signal_Ypis_nomatch_doubleCharm': 7,
    #  'Xc_signal_Ypis_diffVertex_doubleCharm_OneFromB': 14,
    #  'Xc_signal_Ypis_diffVertex_doubleCharm_TwoFromB': 15}

    key2name = { k:v for k,v in categories4.categories_map.items() }
    name2key = { v:k for k, v in key2name.items()}

    # Parsing the arguments
    parser = argparse.ArgumentParser()
    parser.add_argument("category", help="Background category to select", type=str)
    parser.add_argument("input", help="Input file", type=str)
    parser.add_argument("output", help="Output file to write", type=str)
    args = parser.parse_args()
    category = int(args.category)

    log.info("Loading BDT data")
    rdf = ROOT.RDataFrame("DecayTree", args.input)
    rdf2 = rdf.Filter(f"category == {category}")
    df_bdt = pd.DataFrame(rdf2.Cache(["eventNumber"] + bdt_columns + filter_columns).AsNumpy())
    df_bdt = add_derived_columns_for_bdtdblcharm(df_bdt)
    df_bdt = apply_bdtdblcharm(df_bdt)

    log.info("Opening input file %s", args.input)
    res = {}
    with  uproot.open(args.input + ":DecayTree", file_handler=uproot.MultithreadedFileSource) as dt:

        log.info("Loading PANC data")
        extra_cols = [ "category", "eventNumber" ]  
        arrs = dt.arrays(["p1_fromY_PANC_IDs", "p2_fromY_PANC_IDs", "p3_fromY_PANC_IDs",
                        "p1_fromY_PANC_Keys", "p2_fromY_PANC_Keys", "p3_fromY_PANC_Keys",  ]
                        + extra_cols, f"category == {category}")

        log.info("Pretty print of decay information")
        @jit(nopython=True) 
        def pprint(a):
            return ":".join([ str(int(p)) for p in a if p != 0])

        @jit(nopython=True) 
        def top_decay(a):
            return ":".join([ str(abs(int(p))) for p in a if p != 0 and abs(p) >= 500])

        for i in range(1,4):
            tmp = arrs[f"p{i}_fromY_PANC_IDs"]
            res[f"p{i}_fromY_DECAY"] = [ pprint(p) for p in tmp ]        
            res[f"p{i}_fromY_TOP"] = [ top_decay(p) for p in tmp ]

            tmp = arrs[f"p{i}_fromY_PANC_Keys"]
            res[f"p{i}_fromY_Keys"] = [ pprint(p) for p in tmp ]

        for c in extra_cols:
            res[c] = arrs[c]

        log.info("Deriving the decays")
        decays = find_decay(arrs[f"p1_fromY_PANC_Keys"],
                        arrs[f"p2_fromY_PANC_Keys"],
                        arrs[f"p3_fromY_PANC_Keys"],
                        arrs[f"p1_fromY_PANC_IDs"],
                        arrs[f"p2_fromY_PANC_IDs"],
                        arrs[f"p3_fromY_PANC_IDs"])

        res["decay"] = decays

    df = pd.DataFrame(res)
    df['bdt_dc'] = df_bdt['bdt_dc']
    df['bdt_eventNumber'] = df_bdt['eventNumber']

    for c in filter_columns:
        df[c] = df_bdt[c]

    log.info("Saving the dataFrame to %s", args.output)
    df.to_pickle(args.output)
    log.info("Done")

if __name__ == "__main__":
    main()