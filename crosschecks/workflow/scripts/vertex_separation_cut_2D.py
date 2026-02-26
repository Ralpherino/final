#
# Tune the cut on the separation between the B and Y vertices
#
import math
import os
import ROOT
import sys
import numpy as np
import matplotlib.pyplot as plt
import logging 
from multiprocessing import Pool
from multiprocessing import set_start_method
import categories4


# Setting the logging up
logging.basicConfig(format='%(asctime)s %(levelname)-8s %(message)s',
    level=logging.INFO,
    datefmt='%Y-%m-%d %H:%M:%S')
log = logging.getLogger("filters_eff")
log.setLevel(logging.INFO)

# Preparing the data
##########################################################################################

def load_data():
    import json
    import os
    from pathlib import Path
    with open(Path(os.getcwd()) / ".." / ".." / "config" / "config.json") as f:
        cfg = json.load(f)
    data_prefix = cfg["DATA_DIR"]
    print(f"Loading data from {data_prefix}")
    def get_filenames(datatype, eventtype, sign):
        polarities = [ "magdown", "magup" ]
        filenames = [ f"{data_prefix}/rds_finalnoBYsep_{datatype}_{eventtype}_{polarity}_{sign}.root" 
                        for polarity in polarities ]
        return filenames
    filenames = get_filenames("2012", "23903000", "rs")
    rdf = ROOT.RDataFrame("DecayTree", filenames)
    print("====================> adding categories")
    rdf = categories4.add_categories_and_filter(rdf)
    return rdf


#
# def get_fom(localsnapshot, dataframe_info, XC_Y_SEP_cut, B_Y_SEP_cut, i, j):
def get_fom(args):
    #print(">>>>>>>>>>>>>>>>>>>>>>>>>>", args)
    XC_Y_SEP_cut, B_Y_SEP_cut, i, j, idx, total = args
    log.info(f"Processing {idx}/{total}")
    rdf1 = load_data()
    #rdf1 = rdf1.Filter("B_M < 5000")
    cutstr = f"(Xc_Y_SEP < {XC_Y_SEP_cut}) && (B_Y_SEP < {B_Y_SEP_cut})"
    res = rdf1.Filter(cutstr, "sepcut").Filter("Xc_signal_Ypis_displaced_fromBs_fromTau == 1", "signal")
    r = res.Report().GetValue()
    log.info(f"cut: {cutstr}")
    r.Print()
    c = r['signal']
    signal_count = c.GetPass()

    resfromBvtx = rdf1.Filter(cutstr, "sepcut").Filter("fromY_from_B_vertex", "bvtx")
    r = resfromBvtx.Report().GetValue()
    r.Print()
    c = r['bvtx']
    background_count = c.GetPass()
    fom = signal_count/ math.sqrt(signal_count + background_count)
    log.info("FOM: %s", fom)
    return (fom, i, j)

#
# def get_fom(localsnapshot, dataframe_info, XC_Y_SEP_cut, B_Y_SEP_cut, i, j):
def get_fom_inv_cut(args):
    XC_Y_SEP_cut, B_Y_SEP_cut, i, j, idx, total = args
    log.info(f"Processing {idx}/{total}")
    rdf1 = load_data()
    #rdf1 = rdf1.Filter("B_M < 5000")
    cutstr = f"(Xc_Y_SEP > {XC_Y_SEP_cut}) && (B_Y_SEP < {B_Y_SEP_cut})"
    res = rdf1.Filter(cutstr, "sepcut").Filter("Xc_signal_Ypis_displaced_fromBs_fromTau == 1", "signal")
    r = res.Report().GetValue()
    log.info(f"cut: {cutstr}")
    r.Print()
    c = r['signal']
    signal_count = c.GetPass()

    resfromBvtx = rdf1.Filter(cutstr, "sepcut").Filter("fromY_from_B_vertex", "bvtx")
    r = resfromBvtx.Report().GetValue()
    r.Print()
    c = r['bvtx']
    background_count = c.GetPass()
    fom = signal_count/ math.sqrt(signal_count + background_count)
    log.info("FOM: %s", fom)
    return (fom, i, j)

# Now evaluating the cuts
##########################################################################################

# Now evaluating the cut
def plot_cut_background_fromB_vertex(B_Y_cuts, Xc_Y_cuts, name):
    log.info("Evaluating the cut")
    x, y = np.meshgrid(B_Y_cuts, Xc_Y_cuts)
    foms = np.zeros(x.shape)
    params = []
    total = foms.shape[0] * foms.shape[1]
    print(foms.shape)
    for i in range(foms.shape[0]):
        for j in range(foms.shape[1]):
            XC_Y_SEP_cut = y[i][j]
            B_Y_SEP_cut = x[i][j]
            idx = i*foms.shape[0] + j     
            params.append(( XC_Y_SEP_cut, B_Y_SEP_cut, i, j, idx, total))
    
    print(params[0])
    print(f"Total: {total}")
    with Pool(1) as p:
        res = p.map(get_fom, params, 1)

    for fom, i, j in res:
        foms[i][j] = fom

    #fom = get_fom(localsnapshot, dataframe_info, XC_Y_SEP_cut, B_Y_SEP_cut)
    #foms[i][j] = fom
    #print(f"Done {i*foms.shape[0]+j+1}/{foms.shape[0] * foms.shape[1]}")

       
    np.savez("foms.npy", x=x, y=y, foms=foms)
    plt.figure()
    plt.tight_layout()
    from mpl_toolkits import mplot3d
    ax = plt.axes()
    cs = ax.contourf (x, y, foms
            , 20    # the number of color levels in the heat-map
            , cmap = "RdGy"
            )
    plt.colorbar(cs)
    ax.set_xlabel('B_Y_SEP')
    ax.set_ylabel('Xc_Y_SEP')
    plt.title("FOM as as function of B_Y_SEP and Xc_Y_SEP")
    plt.savefig(name)
    plt.show()
    

if __name__ == "__main__":
    set_start_method("spawn")
    # B_Y_cuts = np.arange(-7, 5, 0.1)
    # Xc_Y_cuts = np.arange(-7, 10, 0.1)
    B_Y_cuts = np.arange(-7, 5, 1)
    Xc_Y_cuts = np.arange(-7, 10, 1)
    plot_cut_background_fromB_vertex(B_Y_cuts, Xc_Y_cuts, "2D_FOMBvtx_noBMcut.png")