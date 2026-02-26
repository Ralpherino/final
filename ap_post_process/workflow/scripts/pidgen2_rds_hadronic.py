##############################################################################
# (c) Copyright 2021 CERN for the benefit of the LHCb Collaboration           #
#                                                                             #
# This software is distributed under the terms of the GNU General Public      #
# Licence version 3 (GPL Version 3), copied verbatim in the file "COPYING".   #
#                                                                             #
# In applying this licence, CERN does not waive the privileges and immunities #
# granted to it by virtue of its status as an Intergovernmental Organization  #
# or submit itself to any jurisdiction.                                       #
###############################################################################
import ROOT
import sys
import logging

## START OF CONFIG

# Read comments and check vars at least until the end of config section

# List of input ROOT files with MC ntuples. Format:
#   (inputfile, outputfile, dataset)
# outputfile should be without the ".root" extension
# (it will be appended by the variable names when writing friend trees)
logging.basicConfig(level=logging.INFO)
log = logging.getLogger("pidgen")

log.info("Arguments: %s", str(sys.argv))
prefix = sys.argv[1]
datatype = sys.argv[2]
eventtype = sys.argv[3]
polarity = sys.argv[4]
sign = sys.argv[5]
track = sys.argv[6]
var = sys.argv[7]
input_files = sys.argv[8:]

fixed_polarities = ["MagUp", "MagDown"]

def fix_polarity(p):
    for fp in fixed_polarities:
        if p.lower() == fp.lower():
            return fp
    return p

def get_guid(filename):
    rf = ROOT.TFile.Open(filename)
    return rf.GetUUID().AsString()

files = [
    (
        f,
        f"{prefix}/pidgen_{datatype}_{eventtype}_{polarity}_{sign}_{get_guid(f)}",
        f"{fix_polarity(polarity)}_{datatype}",
    )
    for f in input_files
]

log.info("Process parameters: %s", str(files))

#  The files list should look like this
# files = [
#   ("root://eoslhcb.cern.ch//eos/lhcb/grid/prod/lhcb/MC/2012/BSDS3PI.ROOT/00172450/0000/00172450_00000001_1.bsds3pi.root", "/eos/lhcb/user/l/lben/rds/pidgen/pidgen_evttype", "MagUp_2012"),
# ]

log.info("Processing :%s", str(files))
# Name of the input tree
# Could also include ROOT directory, e.g. "Dir/Tree"
input_tree = "SignalTuple/DecayTree"

# Postfixes of the Pt, Eta and Ntracks variables (ntuple variable name the particle name part)
# e.g. if the ntuple contains "pi_PT" for the particle "pi", it should be just "PT"
ptvar = "PT"
etavar = "ETA"
pvar = None
## Could also use P variable instead of eta
# etavar = None
# pvar   = "p"

ntrvar = "nTracks"  # Number of tracks variable, this should correspond to the number of "Best tracks", not "Long tracks"!

seed = 10000  # initial random seed for resampling
friend = True  # If True, write friend trees with resampled PID instead of copying the whole tree

scale = (1.0, 1.0, 1.2)  # List of scale factors for each dimension of input data

# List of (kernel, seeds) combinations for raw template smearing
kernels = [
    ("default", [0, 1, 2, 3]),  # Default kernel width, no template sampling
    # and three "bootstrapped" templates with seeds 1..3
    #  ('syst1',      [0]),            # Wider "syst1" kernel, no template sampling
    #  ((2, 2, 2, 2), [0])             # Narrower kernel with custom widths (2,2,2,2) bins in PID,Pt,Eta,Ntracks
    #                                  # (will appear as "kern2" in ntuple), no template sampling
]

# Configuration dictionary for resampling, in the form {particle_name}:{pidvars}
# For each {particle_name}, {pidvars} is a dictionary in the form {ntuple_variable}:({sample}, {PID_var}, {kernels}),
#   where
#     {ntuple_variable} is the name of the corresponding ntuple PID variable without the particle name part
#                       (e.g. for "pi_PIDK" branch of particle "pi" it should be just "PIDK");
#     {sample} is the name of the calibration sample
#     {PID_var} is the string describing the PID variable template.
#     {kernels} is the list of kernels for template smearing (see example above)
#
# Run pidgen2.list_variables to get the full list of PID variables
# Run pidgen2.list_samples to get the full list of calibration samples

config_Bs2DsTauNu = {
    "p1_fromXc": {
        "PIDK": ("K_Dstar2Dpi", "CombDLLK", kernels),
        "PIDp": ("K_Dstar2Dpi", "CombDLLp", kernels),
    },
    "p2_fromXc": {
        "PIDK": ("K_Dstar2Dpi", "CombDLLK", kernels),
        "PIDp": ("K_Dstar2Dpi", "CombDLLp", kernels),
    },
    "p3_fromXc": {
        "PIDK": ("pi_Dstar2Dpi", "CombDLLK", kernels),
        "PIDp": ("pi_Dstar2Dpi", "CombDLLp", kernels),
    },
    "p1_fromY": {
        "PIDK": ("pi_Dstar2Dpi", "CombDLLK", kernels),
        "PIDp": ("pi_Dstar2Dpi", "CombDLLp", kernels),
    },
    "p2_fromY": {
        "PIDK": ("pi_Dstar2Dpi", "CombDLLK", kernels),
        "PIDp": ("pi_Dstar2Dpi", "CombDLLp", kernels),
    },
    "p3_fromY": {
        "PIDK": ("pi_Dstar2Dpi", "CombDLLK", kernels),
        "PIDp": ("pi_Dstar2Dpi", "CombDLLp", kernels),
    },
}

config_Bd2DTauNu = {
    "p1_fromXc": {
        "PIDK": ("K_Dstar2Dpi", "CombDLLK", kernels),
        "PIDp": ("K_Dstar2Dpi", "CombDLLp", kernels),
    },
    "p2_fromXc": {
        "PIDK": ("pi_Dstar2Dpi", "CombDLLK", kernels),
        "PIDp": ("pi_Dstar2Dpi", "CombDLLp", kernels),
    },
    "p3_fromXc": {
        "PIDK": ("pi_Dstar2Dpi", "CombDLLK", kernels),
        "PIDp": ("pi_Dstar2Dpi", "CombDLLp", kernels),
    },
    "p1_fromY": {
        "PIDK": ("pi_Dstar2Dpi", "CombDLLK", kernels),
        "PIDp": ("pi_Dstar2Dpi", "CombDLLp", kernels),
    },
    "p2_fromY": {
        "PIDK": ("pi_Dstar2Dpi", "CombDLLK", kernels),
        "PIDp": ("pi_Dstar2Dpi", "CombDLLp", kernels),
    },
    "p3_fromY": {
        "PIDK": ("pi_Dstar2Dpi", "CombDLLK", kernels),
        "PIDp": ("pi_Dstar2Dpi", "CombDLLp", kernels),
    },
}

config_inclDsHc = {
    "p1_fromXc": {
        "PIDK": ("K_Dstar2Dpi", "CombDLLK", kernels),
        "PIDp": ("K_Dstar2Dpi", "CombDLLp", kernels),
    },
    "p2_fromXc": {
        "PIDK": ("K_Dstar2Dpi", "CombDLLK", kernels),
        "PIDp": ("K_Dstar2Dpi", "CombDLLp", kernels),
    },
    "p3_fromXc": {
        "PIDK": ("pi_Dstar2Dpi", "CombDLLK", kernels),
        "PIDp": ("pi_Dstar2Dpi", "CombDLLp", kernels),
    },
    "p1_fromY": {
        "pi_PIDK": ("pi_Dstar2Dpi", "CombDLLK", kernels),
        "K_PIDK": ("K_Dstar2Dpi", "CombDLLK", kernels),
    },
    "p2_fromY": {
        "pi_PIDK": ("pi_Dstar2Dpi", "CombDLLK", kernels),
        "K_PIDK": ("K_Dstar2Dpi", "CombDLLK", kernels),
    },
    "p3_fromY": {
        "pi_PIDK": ("pi_Dstar2Dpi", "CombDLLK", kernels),
        "K_PIDK": ("K_Dstar2Dpi", "CombDLLK", kernels),
    },
}

config_map = {}
config_map["11266009"] = config_Bd2DTauNu

config_map["13266069"] = config_Bs2DsTauNu
config_map["13563002"] = config_Bs2DsTauNu
config_map["13763200"] = config_Bs2DsTauNu
config_map["13863401"] = config_Bs2DsTauNu

config_map["23903000"] = config_inclDsHc
config_map["23903003"] = config_inclDsHc


# Chosing the config to apply based on event type
config = config_map[eventtype]

## END OF CONFIG

output_tree = input_tree.split("/")[-1]
treename = input_tree

from pidgen2.resample import resample

varseed = seed

for input_file, output_file, dataset in files:

    log.warning(
        "Processing %s and saving as %s_<varname>.root", str(input_file), output_file
    )

    if isinstance(input_file, str):
        input_location = f"{input_file}:{input_tree}"
    else:
        # If we have a list of files instead of a string we create a map
        # file -> tree
        input_location = {f: input_tree for f in input_file}

    subst = config[track]
    (sample, calibvar, kernel_list) = subst[var]

    # Create the list of input branches, depending on whether Eta or P variable is available
    if pvar is None:
        branches = f"{track}_{ptvar}:{track}_{etavar}:{ntrvar}"
        eta_from_p = False
    else:
        branches = f"{track}_{ptvar}:{track}_{pvar}:{ntrvar}"
        eta_from_p = True

    if friend:
        output_root_file = f"{output_file}_{track}_{var}.root"
    else:
        output_root_file = f"{output_file}.root"

    varseed += 1  # Increment random seed to make sure all resampled variables are independent

    # Run resampling of a single variable in a single file
    resample(
        input=input_location,  # Input tuple
        sample=sample,  # Calibration sample (e.g. "pi_Dstar2Dpi")
        dataset=dataset,  # Dataset (e.g. "MagUp_2016")
        variable=calibvar,  # Calibration variable (e.g. "MC15TuneV1_ProbNNK")
        branches=branches,  # List of resampling branches (typically, corresponding to Pt, Eta and Ntracks, e.g. "pt:eta:ntr")
        output=output_root_file,  # Output ROOT file name
        outtree=output_tree,  # Output tree name
        plot=True,  # If template needs to be created from scratch, produce control plots
        pidgen=f"{track}_{var}_pidgen",  # Name of the resampled PID branch
        stat=f"{track}_{var}_pidstat",  # Name of output branch with calibration statistics for each resampled event
        resampling_seed=varseed,  # Random seed for resampling
        kernels=kernel_list,  # List of kernels and template seeds
        verbose=False,  # Print debugging information
        eta_from_p=eta_from_p,  # If eta needs to be calculated from p and pt
        friend=friend,  # If True, write output to friend trees
        nan=-1000.0,  # Numerical value to substitute NaN, for regions w/o calibration data
        scale=scale,  # Scale factors for input data
        local_storage="./templates/",  # Directory for local template storage, used when the template is not available in
        # the global storage on EOS.
    )

    if not friend:
        # All subsequent calls use output file as input
        input_location = f"{output_root_file}:{output_tree}"



    # for track, subst in config.items():
    #     for var, (sample, calibvar, kernel_list) in subst.items():

    #         # Create the list of input branches, depending on whether Eta or P variable is available
    #         if pvar is None:
    #             branches = f"{track}_{ptvar}:{track}_{etavar}:{ntrvar}"
    #             eta_from_p = False
    #         else:
    #             branches = f"{track}_{ptvar}:{track}_{pvar}:{ntrvar}"
    #             eta_from_p = True

    #         if friend:
    #             output_root_file = f"{output_file}_{track}_{var}.root"
    #         else:
    #             output_root_file = f"{output_file}.root"

    #         varseed += 1  # Increment random seed to make sure all resampled variables are independent

    #         # Run resampling of a single variable in a single file
    #         resample(
    #             input=input_location,  # Input tuple
    #             sample=sample,  # Calibration sample (e.g. "pi_Dstar2Dpi")
    #             dataset=dataset,  # Dataset (e.g. "MagUp_2016")
    #             variable=calibvar,  # Calibration variable (e.g. "MC15TuneV1_ProbNNK")
    #             branches=branches,  # List of resampling branches (typically, corresponding to Pt, Eta and Ntracks, e.g. "pt:eta:ntr")
    #             output=output_root_file,  # Output ROOT file name
    #             outtree=output_tree,  # Output tree name
    #             plot=True,  # If template needs to be created from scratch, produce control plots
    #             pidgen=f"{track}_{var}_pidgen",  # Name of the resampled PID branch
    #             stat=f"{track}_{var}_pidstat",  # Name of output branch with calibration statistics for each resampled event
    #             resampling_seed=varseed,  # Random seed for resampling
    #             kernels=kernel_list,  # List of kernels and template seeds
    #             verbose=False,  # Print debugging information
    #             eta_from_p=eta_from_p,  # If eta needs to be calculated from p and pt
    #             friend=friend,  # If True, write output to friend trees
    #             nan=-1000.0,  # Numerical value to substitute NaN, for regions w/o calibration data
    #             scale=scale,  # Scale factors for input data
    #             local_storage="./templates/",  # Directory for local template storage, used when the template is not available in
    #             # the global storage on EOS.
    #         )

    #         if not friend:
    #             # All subsequent calls use output file as input
    #             input_location = f"{output_root_file}:{output_tree}"
