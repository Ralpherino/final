#
# Tool to apply the BDT to the dataframe
#

import joblib
import os
import logging
from pathlib import Path
from data import bdt_dir

logging.basicConfig(level=logging.INFO)
log = logging.getLogger("applybdt")

def get_bdt_locally():
    root_prefix = "root:/"
    remote_file = f"{bdt_dir}/bdt_all_200.pkl"
    local_file = remote_file.replace(root_prefix, ".").replace("//", "/") + ".cp"

    print(local_file)

    if not os.path.exists(local_file):
        from XRootD.client import CopyProcess
        cp = CopyProcess()
        cp.add_job(remote_file, local_file)
        cp.prepare()
        log.info("Copying %s to %s", remote_file, local_file)
        os.makedirs(Path(local_file).parent, exist_ok=True)
        res = cp.run()
        print(res)


def apply_bdt_all(df):
    bdt_all = joblib.load("bdt_all_200.pkl")
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
    return df

def apply_bdtdblcharm(df):
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