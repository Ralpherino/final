#
# Tool to apply the BDT to the dataframe
#
import json
import joblib
import os
import logging
from pathlib import Path

logging.basicConfig(level=logging.INFO)
log = logging.getLogger("applybdt")

def get_output_dir():
    """ Locate the outdir dir of this rule to find the parent """
    configdir = Path(__file__).parent.parent //"config"
    with open(configdir / "config.json") as f:
        config = json.load(f)
    return config['OUTPUT_DIR']


def get_bdt_locally():
    # root_prefix = "root:/"
    # #remote_file = "root://eoslhcb.cern.ch//eos/lhcb/wg/semileptonic/RDsHad/AP/pidgen_merged/xgboost/bdt_all_200.pkl"
    # remote_file = "root://eoslhcb.cern.ch//eos/lhcb/wg/semileptonic/RDsHad/AP/final/train_bdt/output/bdt_all_200.pkl"
    # local_file = remote_file.replace(root_prefix, ".").replace("//", "/") + ".cp"
    # print(local_file)

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
    OUTPUT_DIR = get_output_dir()
    print(f"Loading BDT from {OUTPUT_DIR}")
    #bdt_all = joblib.load("./eoslhcb.cern.ch/eos/lhcb/wg/semileptonic/RDsHad/AP/final/train_bdt/output/bdt_all_200.pkl")
    bdt_all = joblib.load(OUTPUT_DIR / "bdt_all_200.pkl")
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