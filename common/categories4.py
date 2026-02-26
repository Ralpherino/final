#
# Definition of the categories used to separate inclusive_MC simulation data
#

import pathlib
from re import S
import numpy as np
import pandas as pd
import ROOT

# C++ macro compilation
########################################################################
def _setup():
    """ Invoke this method to compile the C++ filters that can then be called from python """
    thisdir = config_dir = pathlib.Path(__file__).parent.absolute()
    root_macro = thisdir.joinpath("root_filters.C")
    with open(root_macro) as f:
        decs = f.read()
        ROOT.gInterpreter.Declare(decs)
        
_setup()
from cppyy.gbl import define_LL_columns


# Particles with lifetime
########################################################################
from particle import Particle
particles_to_keep = set([ int(p.pdgid.abspid) for p in Particle.all() if p.lifetime and p.lifetime > 1e-5 ])
#print("Particles to keep:")
#print(sorted(particles_to_keep))

# Predicates to check that the pions have common ancestors
########################################################################
p_fromY_commonAncestor_ANC = (
     "have_common_parents3(p1_fromY_PANC_Keys, p2_fromY_PANC_Keys, p3_fromY_PANC_Keys)"
)
p_fromXc_commonAncestor_ANC = "have_common_parents3(p1_fromXc_PANC_Keys, p2_fromXc_PANC_Keys, p3_fromXc_PANC_Keys)"
commonAncestor_YXc_ANC = "have_common_parents6(p1_fromY_PANC_Keys, p2_fromY_PANC_Keys, p3_fromY_PANC_Keys, p1_fromXc_PANC_Keys, p2_fromXc_PANC_Keys, p3_fromXc_PANC_Keys)"


# Predicates to check the ancestor types
########################################################################
def XfromID(p, id):
    return (
        f"from_id3(p1_from{p}_PANC_IDs, p2_from{p}_PANC_IDs, p3_from{p}_PANC_IDs, {id})"
    )


Y_fromB0 = "from_B0(p1_fromY_PANC_IDs, p2_fromY_PANC_IDs, p3_fromY_PANC_IDs)"
Y_fromBp = "from_Bp(p1_fromY_PANC_IDs, p2_fromY_PANC_IDs, p3_fromY_PANC_IDs)"
Y_fromBs = "from_Bs(p1_fromY_PANC_IDs, p2_fromY_PANC_IDs, p3_fromY_PANC_IDs)"
# Y_fromBsst = "from_Bsst(p1_fromY_PANC_IDs, p2_fromY_PANC_IDs, p3_fromY_PANC_IDs)"
# Y_fromBc = "from_Bc(p1_fromY_PANC_IDs, p2_fromY_PANC_IDs, p3_fromY_PANC_IDs)"
Y_fromLambdab = "from_LambdaB(p1_fromY_PANC_IDs, p2_fromY_PANC_IDs, p3_fromY_PANC_IDs)"
# Y_fromXiB = "from_XiB(p1_fromY_PANC_IDs, p2_fromY_PANC_IDs, p3_fromY_PANC_IDs)"
# # Cases when we are from other B than Bs
Y_fromOtherB = (
    "("
    + XfromID("Y", 511)
    + ") || ("
    + XfromID("Y", 521)
    + ") || ("
    + XfromID("Y", 541)
    + ") || ("
    + XfromID("Y", 5122)
    + ") || ("
    + XfromID("Y", 5132)
    + ") || ("
    + XfromID("Y", 5232)
    + ") || ("
    + XfromID("Y", 20523)
    + ")"
)

Y_fromTau = XfromID("Y", 15)
Y_fromD0 = XfromID("Y", 421)
Y_fromDs = XfromID("Y", 431)
Y_fromDp = XfromID("Y", 411)
Y_fromDps1 = XfromID("Y", 20433)
Y_fromDsst0 = XfromID("Y", 10431)
Y_fromDsst = XfromID("Y", 433)
Y_fromDsst2 = XfromID("Y", 415)
Y_fromDst = XfromID("Y", 413)
Y_fromA1 = XfromID("Y", 20213)
Y_fromLambdac = XfromID("Y", 4122)
Y_fromXic = XfromID("Y", 4232)

Y_fromHc = f"({Y_fromD0}) || ({Y_fromDs}) || ({Y_fromDp}) || ({Y_fromDps1}) || ({Y_fromDsst0}) || ({Y_fromDsst}) || ({Y_fromDsst2}) || ({Y_fromDst}) || ({Y_fromLambdac})"
Y_fromD = Y_fromHc

_from_Y_Rdist = [f"sqrt ( pow(p{i}_fromY_TRUEORIGINVERTEX_X,2) + pow(p{i}_fromY_TRUEORIGINVERTEX_Y,2))" for i in range(1,4) ]
fromY_maxRdist = f"max(max({_from_Y_Rdist[0]}, {_from_Y_Rdist[1]}), {_from_Y_Rdist[2]})"
fromY_maxVtxZsep = "max(max(abs(p1_fromY_TRUEORIGINVERTEX_Z - p2_fromY_TRUEORIGINVERTEX_Z), abs(p1_fromY_TRUEORIGINVERTEX_Z - p3_fromY_TRUEORIGINVERTEX_Z)), abs(p2_fromY_TRUEORIGINVERTEX_Z - p3_fromY_TRUEORIGINVERTEX_Z) )"
fromY_sameVertex = "((p1_fromY_TRUEORIGINVERTEX_Z==p2_fromY_TRUEORIGINVERTEX_Z) && (p1_fromY_TRUEORIGINVERTEX_Z==p3_fromY_TRUEORIGINVERTEX_Z))"
fromXc_sameVertex = "((p1_fromXc_TRUEORIGINVERTEX_Z==p2_fromXc_TRUEORIGINVERTEX_Z) && (p1_fromXc_TRUEORIGINVERTEX_Z==p3_fromXc_TRUEORIGINVERTEX_Z))"

Y_fromBVertex = "(((B_TRUEENDVERTEX_Z - p1_fromY_TRUEORIGINVERTEX_Z) == 0.0) && ((B_TRUEENDVERTEX_Z - p2_fromY_TRUEORIGINVERTEX_Z) == 0.0) && ((B_TRUEENDVERTEX_Z - p3_fromY_TRUEORIGINVERTEX_Z) == 0.0))"

# To check if Xc is from Ds*
Xc_fromDs = XfromID("Xc", 431)
Xc_fromDps1 = XfromID("Xc", 20433)
Xc_fromDsst0 = XfromID("Xc", 10431)
Xc_fromDsst = XfromID("Xc", 433)


# Definitions of the categories themselves
########################################################################

# Notes:
#  - relies on extra info provided by benedetto's plugin
#  - For Xc, looking at the Xc_BKGCAT meaning, we concluded that we should consider Xc_BKGCAT==0 for signal Ds->KKpi
#    all the rest has either a flat Xc_MM distribution in the range or a shifted distribution to lower mass wrt the Ds mass.


# Strategy: 
#  1. Use background categories to identify well reconstrict Ds->KKpi
#  2. Check if the 3 Y pion match to a MC particle (not much we can do otherwise)
#  3. Check whether the Y and Xc come from the same ancestor
#  4. CHeck whether the 3 pions come from the same vertex

pred_from_B_vertex = "(Xc_BKGCAT ==0) && (Y_TRUEID != 0) && (commonAncestor_YXc == 1) && (fromY_sameVertex == 1) && (Y_fromBVertex == 1) "
pred_displaced = "(Xc_BKGCAT ==0) && (Y_TRUEID != 0) && (commonAncestor_YXc == 1) && (fromY_sameVertex == 1) && (Y_fromBVertex == 0)"
pred_diffVertex = "(Xc_BKGCAT ==0) && (Y_TRUEID != 0) &&  (commonAncestor_YXc == 1) && (fromY_sameVertex == 0)"
pred_no_match =  "(Xc_BKGCAT ==0) && (Y_TRUEID == 0)"

categories = {
    "Xc_background": "Xc_BKGCAT != 0",
    "Xc_signal_Ypis_diffAncestorYXc": "(Xc_BKGCAT ==0) & (Y_TRUEID != 0) &  (commonAncestor_YXc == 0)",
    "Xc_signal_Ypis_B_vertex_fromBs": pred_from_B_vertex
    + "& (Y_fromHc == 0) && (Y_fromBs == 1)",
    "Xc_signal_Ypis_B_vertex_fromOtherB": pred_from_B_vertex
    + "& (Y_fromHc == 0) && (Y_fromBs == 0) && (Y_fromOtherB == 1)",
    "Xc_signal_Ypis_B_vertex_fromHc": pred_from_B_vertex + "& (Y_fromHc == 1)",
    "Xc_signal_Ypis_B_vertex_fromNone": pred_from_B_vertex
    + "& (Y_fromHc == 0) && (Y_fromBs == 0)& (Y_fromOtherB == 0)",
}

# def categorize(row):
#     ret = row['decays']
#     if row['beauty_count'] > 0 and row['charm_count'] == 0 and row['strange_count'] == 0:
#         ret = 'nomatch_Prompt'
#     elif row['charm_count'] > 0:
#         ret =  'nomatch_doublecharm'
#     elif row['strange_count'] > 0:
#         ret =  'nomatch_charmstrange'
#     else:
#         ret = 'nomatch_other'
#     return ret

no_match_categories = {
    "Xc_signal_Ypis_nomatch_Prompt": pred_no_match + " && (LL_beautycount > 0) && (LL_charmcount == 0) && (LL_strangecount == 0)",
    "Xc_signal_Ypis_nomatch_doubleCharm": pred_no_match + " && (LL_beautycount >0 ) && (LL_charmcount > 0) && (LL_strangecount == 0)",
    "Xc_signal_Ypis_nomatch_charmStrange": pred_no_match + " && (LL_beautycount > 0 ) && (LL_charmcount >= 0) && (LL_strangecount > 0)",
    "Xc_signal_Ypis_nomatch_Other": pred_no_match + " && (LL_beautycount == 0)",
}

categories |= no_match_categories


# def categorize(row):
#     ret = "NA"
#     # First taking care of cases where all pions come from B
#     if row['LL_beautycount'] == 3:
#         # All pions are from a B
#         if row['LL_taucount'] == 3 and row['LL_charmcount'] == 0 and row['LL_strangecount'] == 0:
#             # Check if we have signal in the mix
#             # COuld be cases where the pions decayes in the detector
#             if row['LL_pi_decay_count']:
#                 ret = 'signal_PionDecay'
#             elif row['LL_pi_matinter_count']:
#                 ret =  'signal_PionMatInteraction'
#             elif row['LL_photon_conversion_count']:
#                 ret =  'signal_PhotonConversion'
#             else:
#                 ret = 'signal_WARNING' # SHould not happen as vertices should be the same but just to check
#         elif row['LL_taucount'] > 0 and row['LL_charmcount'] == 0 and row['LL_strangecount'] == 0: # 1 or 2
#             ret = "tauFromB"
#         elif row['LL_taucount'] == 0 and row['LL_charmcount'] == 0 and row['LL_strangecount'] == 0:
#             # No taus in here
#             # Check if we have normalization events with decays in flight
#             if row['LL_photon_conversion_count']:
#                 ret =  'normlike_PhotonConversion'
#             elif row['LL_pi_decay_count']:
#                 ret =  'normlike_PionDecay'
#             elif row['LL_pi_matinter_count']:
#                 ret =  'signal_PionMatInteraction'
#             elif row['LL_Bccount'] > 0:
#                 ret = 'normlike_fromBc'
#         elif row['LL_charmcount'] > 0:
#             # Dealing with double charm cases here
#             if row['LL_charmcount'] == 3:
#                 if row['LL_photon_conversion_count']:
#                     ret =  'doublecharm_photonConversion'
#                 elif row['LL_pi_decay_count']:
#                     ret =  'doublecharm_PionDecay'
#                 elif row['LL_strangecount'] > 0:
#                     ret = 'doublecharm_withStrange'
#                 else:
#                     ret = "doublecharm" # Should not occur, why would we be in diffVertex ? 
#             elif row['LL_charmcount'] == 2:
#                 ret =  'doublecharm_OnePionFromB'
#             elif row['LL_charmcount'] == 1:
#                 ret =  'doublecharm_TwoPionsFromB'
#         elif row['LL_charmcount'] == 0 and row['LL_strangecount'] > 0:
#             ret = 'b_to_charm_strange'
#     else:
#         ret =  'AtLeastOneoneFromPV'
#     return ret

diffVertex_categories = {
    "Xc_signal_Ypis_diffVertex_signal": pred_diffVertex + " && (LL_beautycount == 3) && (LL_taucount == 3) && (LL_charmcount == 0) && (LL_strangecount == 0)",
    "Xc_signal_Ypis_diffVertex_tauFromB": pred_diffVertex + " && (LL_beautycount == 3) && ((LL_taucount == 2) || (LL_taucount == 1)) && (LL_charmcount == 0) && (LL_strangecount == 0)",
    "Xc_signal_Ypis_diffVertex_normlike": pred_diffVertex + " && (LL_beautycount == 3) && (LL_taucount == 0) && (LL_charmcount == 0) && (LL_strangecount == 0)",
    "Xc_signal_Ypis_diffVertex_doubleCharm": pred_diffVertex + " && (LL_beautycount == 3) && (LL_taucount == 0) && (LL_charmcount == 3) && (LL_strangecount == 0)",
    "Xc_signal_Ypis_diffVertex_doubleCharm_OneFromB": pred_diffVertex + " && (LL_beautycount == 3) && (LL_taucount == 0) && (LL_charmcount == 2) && (LL_strangecount == 0)",
    "Xc_signal_Ypis_diffVertex_doubleCharm_TwoFromB": pred_diffVertex + " && (LL_beautycount == 3) && (LL_taucount == 0) && (LL_charmcount == 1) && (LL_strangecount == 0)",
    "Xc_signal_Ypis_diffVertex_CharmStrange": pred_diffVertex + " && (LL_beautycount == 3) && (LL_taucount == 0) && (LL_strangecount > 0)",
    "Xc_signal_Ypis_diffVertex_SomeFromPV": pred_diffVertex + " && (LL_beautycount < 3)"
}

categories |= diffVertex_categories

charm_categories_plus_tau = [  "fromDp", "fromD0", "fromDs", "fromLambdac", "fromXic", "fromTau"]
beauty_categories = [  "fromBs", "fromBp", "fromB0", "fromLambdab" ]

displaced_categories = {
"Xc_signal_Ypis_displaced_fromBs_fromDs": pred_displaced + " && (Y_fromBs == 1) && (Y_fromBp == 0) && (Y_fromB0 == 0) && (Y_fromLambdab == 0) && (Y_fromDp == 0) && (Y_fromD0 == 0) && (Y_fromDs == 1) && (Y_fromLambdac == 0) && (Y_fromXic == 0) && (Y_fromTau == 0)",
"Xc_signal_Ypis_displaced_fromB0_fromDp": pred_displaced + " && (Y_fromBs == 0) && (Y_fromBp == 0) && (Y_fromB0 == 1) && (Y_fromLambdab == 0) && (Y_fromDp == 1) && (Y_fromD0 == 0) && (Y_fromDs == 0) && (Y_fromLambdac == 0) && (Y_fromXic == 0) && (Y_fromTau == 0)",
"Xc_signal_Ypis_displaced_fromBp_fromD0": pred_displaced + " && (Y_fromBs == 0) && (Y_fromBp == 1) && (Y_fromB0 == 0) && (Y_fromLambdab == 0) && (Y_fromDp == 0) && (Y_fromD0 == 1) && (Y_fromDs == 0) && (Y_fromLambdac == 0) && (Y_fromXic == 0) && (Y_fromTau == 0)",
"Xc_signal_Ypis_displaced_fromLambdab_fromLambdac": pred_displaced + " && (Y_fromBs == 0) && (Y_fromBp == 0) && (Y_fromB0 == 0) && (Y_fromLambdab == 1) && (Y_fromDp == 0) && (Y_fromD0 == 0) && (Y_fromDs == 0) && (Y_fromLambdac == 1) && (Y_fromXic == 0) && (Y_fromTau == 0)",
"Xc_signal_Ypis_displaced_fromBs_fromDp": pred_displaced + " && (Y_fromBs == 1) && (Y_fromBp == 0) && (Y_fromB0 == 0) && (Y_fromLambdab == 0) && (Y_fromDp == 1) && (Y_fromD0 == 0) && (Y_fromDs == 0) && (Y_fromLambdac == 0) && (Y_fromXic == 0) && (Y_fromTau == 0)",
"Xc_signal_Ypis_displaced_fromBp_fromDp": pred_displaced + " && (Y_fromBs == 0) && (Y_fromBp == 1) && (Y_fromB0 == 0) && (Y_fromLambdab == 0) && (Y_fromDp == 1) && (Y_fromD0 == 0) && (Y_fromDs == 0) && (Y_fromLambdac == 0) && (Y_fromXic == 0) && (Y_fromTau == 0)",
"Xc_signal_Ypis_displaced_fromBs_fromTau": pred_displaced + " && (Y_fromBs == 1) && (Y_fromBp == 0) && (Y_fromB0 == 0) && (Y_fromLambdab == 0) && (Y_fromDp == 0) && (Y_fromD0 == 0) && (Y_fromDs == 0) && (Y_fromLambdac == 0) && (Y_fromXic == 0) && (Y_fromTau == 1)",
"Xc_signal_Ypis_displaced_fromB0_fromD0": pred_displaced + " && (Y_fromBs == 0) && (Y_fromBp == 0) && (Y_fromB0 == 1) && (Y_fromLambdab == 0) && (Y_fromDp == 0) && (Y_fromD0 == 1) && (Y_fromDs == 0) && (Y_fromLambdac == 0) && (Y_fromXic == 0) && (Y_fromTau == 0)",
"Xc_signal_Ypis_displaced_fromB0_fromDs": pred_displaced + " && (Y_fromBs == 0) && (Y_fromBp == 0) && (Y_fromB0 == 1) && (Y_fromLambdab == 0) && (Y_fromDp == 0) && (Y_fromD0 == 0) && (Y_fromDs == 1) && (Y_fromLambdac == 0) && (Y_fromXic == 0) && (Y_fromTau == 0)",
"Xc_signal_Ypis_displaced_fromBs_fromD0": pred_displaced + " && (Y_fromBs == 1) && (Y_fromBp == 0) && (Y_fromB0 == 0) && (Y_fromLambdab == 0) && (Y_fromDp == 0) && (Y_fromD0 == 1) && (Y_fromDs == 0) && (Y_fromLambdac == 0) && (Y_fromXic == 0) && (Y_fromTau == 0)",
"Xc_signal_Ypis_displaced_fromBp_fromDs": pred_displaced + " && (Y_fromBs == 0) && (Y_fromBp == 1) && (Y_fromB0 == 0) && (Y_fromLambdab == 0) && (Y_fromDp == 0) && (Y_fromD0 == 0) && (Y_fromDs == 1) && (Y_fromLambdac == 0) && (Y_fromXic == 0) && (Y_fromTau == 0)",
"Xc_signal_Ypis_displaced_fromBs_fromDs_fromTau": pred_displaced + " && (Y_fromBs == 1) && (Y_fromBp == 0) && (Y_fromB0 == 0) && (Y_fromLambdab == 0) && (Y_fromDp == 0) && (Y_fromD0 == 0) && (Y_fromDs == 1) && (Y_fromLambdac == 0) && (Y_fromXic == 0) && (Y_fromTau == 1)",
"Xc_signal_Ypis_displaced_fromLambdab_fromDs": pred_displaced + " && (Y_fromBs == 0) && (Y_fromBp == 0) && (Y_fromB0 == 0) && (Y_fromLambdab == 1) && (Y_fromDp == 0) && (Y_fromD0 == 0) && (Y_fromDs == 1) && (Y_fromLambdac == 0) && (Y_fromXic == 0) && (Y_fromTau == 0)",
"Xc_signal_Ypis_displaced_fromLambdab_fromDp": pred_displaced + " && (Y_fromBs == 0) && (Y_fromBp == 0) && (Y_fromB0 == 0) && (Y_fromLambdab == 1) && (Y_fromDp == 1) && (Y_fromD0 == 0) && (Y_fromDs == 0) && (Y_fromLambdac == 0) && (Y_fromXic == 0) && (Y_fromTau == 0)",
"Xc_signal_Ypis_displaced_fromXic": pred_displaced + " && (Y_fromBs == 0) && (Y_fromBp == 0) && (Y_fromB0 == 0) && (Y_fromLambdab == 0) && (Y_fromDp == 0) && (Y_fromD0 == 0) && (Y_fromDs == 0) && (Y_fromLambdac == 0) && (Y_fromXic == 1) && (Y_fromTau == 0)",
"Xc_signal_Ypis_displaced_fromBs": pred_displaced + " && (Y_fromBs == 1) && (Y_fromBp == 0) && (Y_fromB0 == 0) && (Y_fromLambdab == 0) && (Y_fromDp == 0) && (Y_fromD0 == 0) && (Y_fromDs == 0) && (Y_fromLambdac == 0) && (Y_fromXic == 0) && (Y_fromTau == 0)",
"Xc_signal_Ypis_displaced_fromB0_fromLambdac": pred_displaced + " && (Y_fromBs == 0) && (Y_fromBp == 0) && (Y_fromB0 == 1) && (Y_fromLambdab == 0) && (Y_fromDp == 0) && (Y_fromD0 == 0) && (Y_fromDs == 0) && (Y_fromLambdac == 1) && (Y_fromXic == 0) && (Y_fromTau == 0)",
"Xc_signal_Ypis_displaced_fromB0_fromDs_fromTau": pred_displaced + " && (Y_fromBs == 0) && (Y_fromBp == 0) && (Y_fromB0 == 1) && (Y_fromLambdab == 0) && (Y_fromDp == 0) && (Y_fromD0 == 0) && (Y_fromDs == 1) && (Y_fromLambdac == 0) && (Y_fromXic == 0) && (Y_fromTau == 1)",
"Xc_signal_Ypis_displaced_fromLambdab_fromD0": pred_displaced + " && (Y_fromBs == 0) && (Y_fromBp == 0) && (Y_fromB0 == 0) && (Y_fromLambdab == 1) && (Y_fromDp == 0) && (Y_fromD0 == 1) && (Y_fromDs == 0) && (Y_fromLambdac == 0) && (Y_fromXic == 0) && (Y_fromTau == 0)",
"Xc_signal_Ypis_displaced_fromB0_fromDp_fromTau": pred_displaced + " && (Y_fromBs == 0) && (Y_fromBp == 0) && (Y_fromB0 == 1) && (Y_fromLambdab == 0) && (Y_fromDp == 1) && (Y_fromD0 == 0) && (Y_fromDs == 0) && (Y_fromLambdac == 0) && (Y_fromXic == 0) && (Y_fromTau == 1)",
"Xc_signal_Ypis_displaced_NA": pred_displaced + " && (Y_fromBs == 0) && (Y_fromBp == 0) && (Y_fromB0 == 0) && (Y_fromLambdab == 0) && (Y_fromDp == 0) && (Y_fromD0 == 0) && (Y_fromDs == 0) && (Y_fromLambdac == 0) && (Y_fromXic == 0) && (Y_fromTau == 0)",
"Xc_signal_Ypis_displaced_fromBp_fromDs_fromTau": pred_displaced + " && (Y_fromBs == 0) && (Y_fromBp == 1) && (Y_fromB0 == 0) && (Y_fromLambdab == 0) && (Y_fromDp == 0) && (Y_fromD0 == 0) && (Y_fromDs == 1) && (Y_fromLambdac == 0) && (Y_fromXic == 0) && (Y_fromTau == 1)",
"Xc_signal_Ypis_displaced_fromBp": pred_displaced + " && (Y_fromBs == 0) && (Y_fromBp == 1) && (Y_fromB0 == 0) && (Y_fromLambdab == 0) && (Y_fromDp == 0) && (Y_fromD0 == 0) && (Y_fromDs == 0) && (Y_fromLambdac == 0) && (Y_fromXic == 0) && (Y_fromTau == 0)",
"Xc_signal_Ypis_displaced_fromLambdab_fromDs_fromTau": pred_displaced + " && (Y_fromBs == 0) && (Y_fromBp == 0) && (Y_fromB0 == 0) && (Y_fromLambdab == 1) && (Y_fromDp == 0) && (Y_fromD0 == 0) && (Y_fromDs == 1) && (Y_fromLambdac == 0) && (Y_fromXic == 0) && (Y_fromTau == 1)",
"Xc_signal_Ypis_displaced_fromBp_fromLambdac": pred_displaced + " && (Y_fromBs == 0) && (Y_fromBp == 1) && (Y_fromB0 == 0) && (Y_fromLambdab == 0) && (Y_fromDp == 0) && (Y_fromD0 == 0) && (Y_fromDs == 0) && (Y_fromLambdac == 1) && (Y_fromXic == 0) && (Y_fromTau == 0)",
"Xc_signal_Ypis_displaced_fromDs": pred_displaced + " && (Y_fromBs == 0) && (Y_fromBp == 0) && (Y_fromB0 == 0) && (Y_fromLambdab == 0) && (Y_fromDp == 0) && (Y_fromD0 == 0) && (Y_fromDs == 1) && (Y_fromLambdac == 0) && (Y_fromXic == 0) && (Y_fromTau == 0)",
"Xc_signal_Ypis_displaced_fromBs_fromDp_fromTau": pred_displaced + " && (Y_fromBs == 1) && (Y_fromBp == 0) && (Y_fromB0 == 0) && (Y_fromLambdab == 0) && (Y_fromDp == 1) && (Y_fromD0 == 0) && (Y_fromDs == 0) && (Y_fromLambdac == 0) && (Y_fromXic == 0) && (Y_fromTau == 1)",
"Xc_signal_Ypis_displaced_fromBp_fromDp_fromTau": pred_displaced + " && (Y_fromBs == 0) && (Y_fromBp == 1) && (Y_fromB0 == 0) && (Y_fromLambdab == 0) && (Y_fromDp == 1) && (Y_fromD0 == 0) && (Y_fromDs == 0) && (Y_fromLambdac == 0) && (Y_fromXic == 0) && (Y_fromTau == 1)",
"Xc_signal_Ypis_displaced_fromBs_fromLambdac": pred_displaced + " && (Y_fromBs == 1) && (Y_fromBp == 0) && (Y_fromB0 == 0) && (Y_fromLambdab == 0) && (Y_fromDp == 0) && (Y_fromD0 == 0) && (Y_fromDs == 0) && (Y_fromLambdac == 1) && (Y_fromXic == 0) && (Y_fromTau == 0)",
"Xc_signal_Ypis_displaced_fromLambdab": pred_displaced + " && (Y_fromBs == 0) && (Y_fromBp == 0) && (Y_fromB0 == 0) && (Y_fromLambdab == 1) && (Y_fromDp == 0) && (Y_fromD0 == 0) && (Y_fromDs == 0) && (Y_fromLambdac == 0) && (Y_fromXic == 0) && (Y_fromTau == 0)",
"Xc_signal_Ypis_displaced_fromB0": pred_displaced + " && (Y_fromBs == 0) && (Y_fromBp == 0) && (Y_fromB0 == 1) && (Y_fromLambdab == 0) && (Y_fromDp == 0) && (Y_fromD0 == 0) && (Y_fromDs == 0) && (Y_fromLambdac == 0) && (Y_fromXic == 0) && (Y_fromTau == 0)",
"Xc_signal_Ypis_displaced_fromLambdac": pred_displaced + " && (Y_fromBs == 0) && (Y_fromBp == 0) && (Y_fromB0 == 0) && (Y_fromLambdab == 0) && (Y_fromDp == 0) && (Y_fromD0 == 0) && (Y_fromDs == 0) && (Y_fromLambdac == 1) && (Y_fromXic == 0) && (Y_fromTau == 0)",
}

categories |= displaced_categories

# Establish the keys and the mapping to integer values used to stored in the ROOT ntuple
categories_keys = list(categories.keys())
categories_map = { i: c for i, c in enumerate(categories_keys)}
categories_map[-1] = "NA"
reversed_categories_map = { c: i for i, c in categories_map.items() }

#
# Methods to defined derived columns on the RDataFrame
#########################################################################################

def define_vertex_separation_var(df):

    df = df.Define(
        "B_Y_SEP_v2",
        "( B_ENDVERTEX_Z - Y_ENDVERTEX_Z) / sqrt(B_ENDVERTEX_ZERR*B_ENDVERTEX_ZERR + Y_ENDVERTEX_ZERR*Y_ENDVERTEX_ZERR)",
    )
    df = df.Define(
        "Xc_Y_SEP",
        "( Xc_ENDVERTEX_Z - Y_ENDVERTEX_Z) / sqrt(Xc_ENDVERTEX_ZERR*Xc_ENDVERTEX_ZERR + Y_ENDVERTEX_ZERR*Y_ENDVERTEX_ZERR)",
    )
    df = df.Define(
        "B_Xc_SEP",
        "( B_ENDVERTEX_Z - Xc_ENDVERTEX_Z) / sqrt(B_ENDVERTEX_ZERR*B_ENDVERTEX_ZERR + Xc_ENDVERTEX_ZERR*Xc_ENDVERTEX_ZERR)",
    )
    df = df.Define(
        "BPVVDR_Y",
        "sqrt( pow(Y_ENDVERTEX_X - B_ENDVERTEX_X, 2) + pow(Y_ENDVERTEX_X - B_ENDVERTEX_X,2) )",
    )
    return df

#
# Methods to check if the Xc or Y come from Ds*
#########################################################################################

def define_dstar_vars(df):
    """ Method to define the variables to check if the Xc or Y come from Ds*"""

    vars = [
        "Xc_fromDs",
        "Xc_fromDps1",
        "Xc_fromDsst0",
        "Xc_fromDsst",
        "Y_fromDps1",
        "Y_fromDsst0",
        "Y_fromDsst",
    ]

    for v in vars:
        df = df.Define(v, eval(v))

    return df

# Defining columns with Kaon mass 
########################################################################

def define_Ypis_alternative(df):
    mKaon = 493.677 # MeV/c2 according to PDG

    # Energy of the particles considering they are Kaons
    columns = {
        "p1_fromY_PE_asK": f"sqrt(pow(p1_fromY_P, 2) + {mKaon**2})",
        "p2_fromY_PE_asK": f"sqrt(pow(p2_fromY_P, 2) + {mKaon**2})",
        "p3_fromY_PE_asK": f"sqrt(pow(p3_fromY_P, 2) + {mKaon**2})",
        "Y_4M_PX": "p1_fromY_PX + p2_fromY_PX + p3_fromY_PX",
        "Y_4M_PY": "p1_fromY_PY + p2_fromY_PY + p3_fromY_PY",
        "Y_4M_PZ": "p1_fromY_PZ + p2_fromY_PZ + p3_fromY_PZ",
        "Y_M_test": "sqrt( pow( p1_fromY_PE + p2_fromY_PE + p3_fromY_PE ,2) - pow(Y_4M_PX, 2) - pow(Y_4M_PY, 2) - pow(Y_4M_PZ, 2))",
        "Y_M_p1K": "sqrt( pow( p1_fromY_PE_asK + p2_fromY_PE + p3_fromY_PE ,2) - pow(Y_4M_PX, 2) - pow(Y_4M_PY, 2) - pow(Y_4M_PZ, 2))",
        "Y_M_p2K": "sqrt( pow( p1_fromY_PE + p2_fromY_PE_asK + p3_fromY_PE ,2) - pow(Y_4M_PX, 2) - pow(Y_4M_PY, 2) - pow(Y_4M_PZ, 2))",
        "Y_M_p3K": "sqrt( pow( p1_fromY_PE + p2_fromY_PE + p3_fromY_PE_asK ,2) - pow(Y_4M_PX, 2) - pow(Y_4M_PY, 2) - pow(Y_4M_PZ, 2))",
        "p1K2_M": "sqrt( pow( p1_fromY_PE + p2_fromY_PE_asK,2) - pow(p1_fromY_PX + p2_fromY_PX, 2) - pow(p1_fromY_PY + p2_fromY_PY, 2) - pow(p1_fromY_PZ + p2_fromY_PZ, 2))",
        "K1p2_M": "sqrt( pow( p1_fromY_PE_asK + p2_fromY_PE,2) - pow(p1_fromY_PX + p2_fromY_PX, 2) - pow(p1_fromY_PY + p2_fromY_PY, 2) - pow(p1_fromY_PZ + p2_fromY_PZ, 2))",
        "p2K3_M": "sqrt( pow( p2_fromY_PE + p3_fromY_PE_asK,2) - pow(p3_fromY_PX + p2_fromY_PX, 2) - pow(p3_fromY_PY + p2_fromY_PY, 2) - pow(p3_fromY_PZ + p2_fromY_PZ, 2))",
        "K2p3_M": "sqrt( pow( p2_fromY_PE_asK + p3_fromY_PE,2) - pow(p3_fromY_PX + p2_fromY_PX, 2) - pow(p3_fromY_PY + p2_fromY_PY, 2) - pow(p3_fromY_PZ + p2_fromY_PZ, 2))",
        "p1K3_M": "sqrt( pow( p1_fromY_PE + p3_fromY_PE_asK,2) - pow(p3_fromY_PX + p1_fromY_PX, 2) - pow(p3_fromY_PY + p1_fromY_PY, 2) - pow(p3_fromY_PZ + p1_fromY_PZ, 2))",
        "K1p3_M": "sqrt( pow( p1_fromY_PE_asK + p3_fromY_PE,2) - pow(p3_fromY_PX + p1_fromY_PX, 2) - pow(p3_fromY_PY + p1_fromY_PY, 2) - pow(p3_fromY_PZ + p1_fromY_PZ, 2))",
    }

    for k,v in columns.items():
        df = df.Define(k, v)

    return df

def define_p2_fromY_pairNearD0(df):
    """ Method to define the cut that excludes the pairs of pions from D"""
    mD0 = 1864.83
    mD0_range = 40
    return df.Define("p2_fromY_pairNearD0", f"(abs(p1K2_M - {mD0}) < {mD0_range}) || (abs(K2p3_M - {mD0}) < {mD0_range})")


# Method to view decays
########################################################################
def view_Y_decay(rdf, startrow, endrow, verbose=True):
    """method to dump the decay of the Y pions"""
    cols = [
        f"p{i}_fromY_PANC_{suffix}" for i in range(1, 4) for suffix in ["Keys", "IDs"]
    ]
    cols += [f"p{i}_fromY_TRUEID" for i in range(1, 4)]
    cols += [f"p{i}_fromY_TRUEORIGINVERTEX_Z" for i in range(1, 4)]
    cols += [f"p{i}_fromY_decay_top" for i in range(1, 4)]
    cols += ["Y_TRUEID"]
    cols += ["LL_beautycount", "LL_taucount", "LL_charmcount", "LL_strangecount", "fromY_sameVertex", "Xc_BKGCAT", "Y_TRUEID", "commonAncestor_YXc",]
    cols += list(categories.keys())

    data = rdf.Range(startrow, endrow).AsNumpy(columns=cols)
    for row in range(startrow, endrow):
        if verbose:
            print("Y_TRUEID       :" + str(data["Y_TRUEID"][row]))
            print(
                "p_fromY TRUEIDs:"
                + str([ data[f"p{i}_fromY_TRUEID"][row] for i in range(1, 4)])
            )            
            print(
                "p_fromY_TRUEORIGINVERTEX Z:"
                + str([ data[f"p{i}_fromY_TRUEORIGINVERTEX_Z"][row] for i in range(1, 4)])
            )
            print([ data[f"p{i}_fromY_TRUEORIGINVERTEX_Z"][row] for i in range(1, 4)])
            for suffix in ["IDs", "Keys"]:
                aslists = [list(data[f"p{i}_fromY_PANC_{suffix}"][row]) for i in range(1, 4)]
                for i, l in enumerate(aslists):
                    print(f"{suffix} {i + 1}: {l}")
        
        declist_str = []
        declist = []
        ancestor_with_charm = 0
        for i in range(1, 4):
            initial_list =  [ data[f"p{i}_fromY_TRUEID"][row]]  +  list(data[f"p{i}_fromY_PANC_IDs"][row])
            not_null = [ int(abs(pid)) for pid in initial_list if abs(pid) > 0 ]
            filtered = [ pid for pid in not_null if abs(pid) in particles_to_keep ]
            has_charm = len([ p for p in filtered if (abs(p) >=400 and abs(p) < 500) or (abs(p) >=4000 and abs(p) < 50000) ])
            if (has_charm):
                ancestor_with_charm += 1

            ancstr = "->".join(map(str, filtered[::-1]))
            declist_str.append(ancstr)
            declist.append(filtered[::-1])

        decstr = ", ".join(sorted(declist_str))
        if verbose:
            print(f"DECAY: {decstr}")
            for c in ["Xc_BKGCAT", "Y_TRUEID", "commonAncestor_YXc", "fromY_sameVertex", "LL_beautycount", "LL_taucount", "LL_charmcount", "LL_strangecount"]:
                print(f"{c} : {data[c][row]}")
            for c in categories.keys():
                print(f"{c} : {data[c][row]}")
            print("==============================")


# Methods to enrich the dataframe with the columns for categorization
########################################################################
def group_categories(df, categ_map):
    """ Agregate all category columns in one """
    call, code = build_categories_func(categ_map)
    #print(code)
    if not is_function_defined("summarize_categs"):
        ROOT.gInterpreter.Declare(code)
    return df.Define("category", call)

def build_categories_func(categ_map):
    map_no_default = { i:v for i,v in categ_map.items() if i != -1 }
    typeandnames = [ "int " + c for c in map_no_default.values() ]
    code = f"int summarize_categs({', '.join(typeandnames)})" + "{\n"
    for i, c in map_no_default.items():
        if i != -1: # Default value, ignore from map
            code += f"if ({c}) return {i};\n"
    code+= "return -1;\n}\n"
    call = f"summarize_categs({', '.join(map_no_default.values())})"
    return call, code

def categorize_key(row):
    """Categorize and event based on the fact each category in the map has been defined a column in the dataset"""
    for k in categories.keys():
        if row[k]:
            return k
    return "NA"

def _define_categories_common(df):
    """Add the category columns to the RDataFrame"""
    # Adding the columns needed for diffVertex classification
    df = define_LL_columns(df)
    df = df.Define("fromY_sameVertex", fromY_sameVertex)
    df = df.Define("fromY_maxVtxZsep", fromY_maxVtxZsep)
    df = df.Define("fromY_maxRdist", fromY_maxRdist)
    df = df.Define("fromY_has_e_or_mu", "((abs(p1_fromY_TRUEID) == 13) || (abs(p2_fromY_TRUEID) == 13) || (abs(p3_fromY_TRUEID) == 13) || (abs(p1_fromY_TRUEID) == 11) || (abs(p2_fromY_TRUEID) == 11) || (abs(p3_fromY_TRUEID) == 11))")
    df = df.Define(
        "fromY_sameMother",
        "same_mother3(p1_fromY_PANC_Keys, p2_fromY_PANC_Keys, p3_fromY_PANC_Keys)",
    )
    df = df.Define("fromXc_sameVertex", fromXc_sameVertex)
    df = df.Define("p_fromY_commonAncestor", p_fromY_commonAncestor_ANC)
    df = df.Define("commonAncestor_YXc", commonAncestor_YXc_ANC)
    df = df.Define("Y_fromBVertex", Y_fromBVertex)
    df = df.Define("Y_fromTau", Y_fromTau)
    df = df.Define("Y_fromDp", Y_fromDp)
    df = df.Define("Y_fromD0", Y_fromD0)
    df = df.Define("Y_fromDs", Y_fromDs)
    df = df.Define("Y_fromLambdac", Y_fromLambdac)
    df = df.Define("Y_fromXic", Y_fromXic)
    df = df.Define("Y_fromHc", Y_fromHc)
    df = df.Define("Y_fromOtherB", Y_fromOtherB)
    df = df.Define("Y_fromBs", Y_fromBs)
    df = df.Define("Y_fromB0", Y_fromB0)
    df = df.Define("Y_fromBp", Y_fromBp)
    df = df.Define("Y_fromLambdab", Y_fromLambdab)
    df = df.Define("Y_all_true_pions", "all_pions(p1_fromY_TRUEID, p2_fromY_TRUEID, p3_fromY_TRUEID)")
    for i in range(1, 4):
        df = df.Define(f"p{i}_fromY_decay_top", f"decay_top(p{i}_fromY_PANC_IDs)")
    return df

def _define_categories(df):
    """Add the category columns to the RDataFrame"""
    df = _define_categories_common(df)
    for c, query in categories.items():
        df = df.Define(c, query)
    df = df.Define("fromY_displaced", pred_displaced)
    df = df.Define("fromY_from_B_vertex", pred_from_B_vertex)
    df = define_Ypis_alternative(df)
    df = define_p2_fromY_pairNearD0(df)
    df = define_vertex_separation_var(df)
    df = define_dstar_vars(df)
    return df

def cut_PIDK(df):
    cut2 = "(p2_fromY_pairNearD0 == false && p2_fromY_PIDK < 0) || (p2_fromY_pairNearD0 == true && p2_fromY_PIDK < -5)"
    df = df.Filter(cut2, "PIDK_cut")
    return df

def cut_BDT_Iso(rdf):
    rdf = rdf.Filter("BDT_Iso > 0.03458", "BDT_Iso")
    return rdf

def cut_Xc_selection(rdf):
    rdf = rdf.Filter("Xc_Selection > 0")
    return rdf

# Simplified categorization
#####################################################################
detailed_to_simplified_category_mapping = {
    "Xc_background": "Xc_background",
    "Xc_signal_Ypis_diffAncestorYXc": "Xc_signal_Ypis_diffAncestorYXc",
    "Xc_signal_Ypis_nomatch_Prompt":  "normlike",
    "Xc_signal_Ypis_nomatch_doubleCharm":  "doubleCharm",
    "Xc_signal_Ypis_nomatch_charmStrange": "doubleCharm",
    "Xc_signal_Ypis_nomatch_Other": "Xc_signal_Ypis_nomatch_Other",
    "Xc_signal_Ypis_B_vertex_fromBs": "normlike",
    "Xc_signal_Ypis_B_vertex_fromOtherB": "normlike",
    "Xc_signal_Ypis_B_vertex_fromHc": "normlike",
    "Xc_signal_Ypis_B_vertex_fromNone": "normlike",
    "Xc_signal_Ypis_diffVertex_signal": "signal",
    "Xc_signal_Ypis_diffVertex_tauFromB": "signal",
    "Xc_signal_Ypis_diffVertex_normlike": "normlike",
    "Xc_signal_Ypis_diffVertex_doubleCharm": "doubleCharm",
    "Xc_signal_Ypis_diffVertex_doubleCharm_OneFromB": "doubleCharm",
    "Xc_signal_Ypis_diffVertex_doubleCharm_TwoFromB": "doubleCharm",
    "Xc_signal_Ypis_diffVertex_CharmStrange": "doubleCharm",
    "Xc_signal_Ypis_diffVertex_SomeFromPV": "WithfromPV",
    "Xc_signal_Ypis_displaced_fromBs_fromDs": "doubleCharm",
    "Xc_signal_Ypis_displaced_fromB0_fromDp": "doubleCharm",
    "Xc_signal_Ypis_displaced_fromBp_fromD0": "doubleCharm",
    "Xc_signal_Ypis_displaced_fromLambdab_fromLambdac": "doubleCharm",
    "Xc_signal_Ypis_displaced_fromBs_fromDp": "doubleCharm",
    "Xc_signal_Ypis_displaced_fromBp_fromDp": "doubleCharm",
    "Xc_signal_Ypis_displaced_fromBs_fromTau": "signal",
    "Xc_signal_Ypis_displaced_fromB0_fromD0": "doubleCharm",
    "Xc_signal_Ypis_displaced_fromB0_fromDs": "doubleCharm",
    "Xc_signal_Ypis_displaced_fromBs_fromD0": "doubleCharm",
    "Xc_signal_Ypis_displaced_fromBp_fromDs": "doubleCharm",
    "Xc_signal_Ypis_displaced_fromBs_fromDs_fromTau": "tauFromCharm",
    "Xc_signal_Ypis_displaced_fromLambdab_fromDs": "doubleCharm",
    "Xc_signal_Ypis_displaced_fromLambdab_fromDp": "doubleCharm",
    "Xc_signal_Ypis_displaced_fromXic": "otherDisplaced",
    "Xc_signal_Ypis_displaced_fromBs": "otherDisplaced",
    "Xc_signal_Ypis_displaced_fromB0_fromLambdac": "doubleCharm",
    "Xc_signal_Ypis_displaced_fromB0_fromDs_fromTau": "tauFromCharm",
    "Xc_signal_Ypis_displaced_fromLambdab_fromD0": "doubleCharm",
    "Xc_signal_Ypis_displaced_fromB0_fromDp_fromTau": "tauFromCharm",
    "Xc_signal_Ypis_displaced_NA": "otherDisplaced",
    "Xc_signal_Ypis_displaced_fromBp_fromDs_fromTau": "tauFromCharm",
    "Xc_signal_Ypis_displaced_fromBp": "otherDisplaced",
    "Xc_signal_Ypis_displaced_fromLambdab_fromDs_fromTau": "tauFromCharm",
    "Xc_signal_Ypis_displaced_fromBp_fromLambdac": "doubleCharm",
    "Xc_signal_Ypis_displaced_fromDs": "otherDisplaced",
    "Xc_signal_Ypis_displaced_fromBs_fromDp_fromTau": "tauFromCharm",
    "Xc_signal_Ypis_displaced_fromBp_fromDp_fromTau": "tauFromCharm",
    "Xc_signal_Ypis_displaced_fromBs_fromLambdac": "doubleCharm",
    "Xc_signal_Ypis_displaced_fromLambdab": "otherDisplaced",
    "Xc_signal_Ypis_displaced_fromB0": "otherDisplaced",
    "Xc_signal_Ypis_displaced_fromLambdac": "otherDisplaced",
 }

# Data preparation
simplified_categories_keys = sorted(list(set(detailed_to_simplified_category_mapping.values())))
simplified_categories_map = { i + 1000: c for i, c in enumerate(simplified_categories_keys)}
simplified_categories_map[-1] = "NA"
reversed_simplified_categories_map = { c: i for i, c in simplified_categories_map.items()}
reversed_simplified_categories_map["NA"] = -1

# Bridge between the categories
numeric_detailed_to_simplified_category_mapping = {  reversed_categories_map[d]: reversed_simplified_categories_map[s] for d, s in detailed_to_simplified_category_mapping.items() }


def is_function_defined(function_name):
        ci = ROOT.gInterpreter.ClassInfo_Factory()
        ret = ROOT.gInterpreter.ClassInfo_HasMethod(ci, function_name);
        ROOT.gInterpreter.ClassInfo_Delete(ci)
        return ret

def group_categories(df, categ_map):
    """ Agregate all category columns in one """
    call, code = build_categories_func(categ_map)
    #print(code)
    if not is_function_defined("summarize_categs"):
        ROOT.gInterpreter.Declare(code)
    return df.Define("category", call)


def define_ROOT_mapping_to_simplified(df):
    code = "int detailed_to_simplified(int d) {\n"
    for d, s in numeric_detailed_to_simplified_category_mapping.items():
        code += f"if (d == {d}) return {s};\n"
    code+= "return -1;\n}\n"
    call = f"detailed_to_simplified(category)"
    #print(code)
    if not is_function_defined("detailed_to_simplified"):
        ROOT.gInterpreter.Declare(code)
    return df.Define("simplified", call)

def define_categories_simplified(df):
    """Add the category columns to the RDataFrame"""
    df = define_ROOT_mapping_to_simplified(df)
    return df

def add_categories_and_filter(rdf, apply_BDT_Iso_cut=True, apply_PIDK_cut=True, apply_Xc_Selection_cut=False):
    rdf = _define_categories(rdf)
    if apply_PIDK_cut:
        rdf = cut_PIDK(rdf)
    if apply_BDT_Iso_cut:
        rdf = cut_BDT_Iso(rdf)
    if apply_Xc_Selection_cut:
        rdf = cut_Xc_selection(rdf)
    rdf = group_categories(rdf, categories_map)
    rdf = define_categories_simplified(rdf)
    return rdf

# Pretty categorization
# Neater grouping of background categories for the thesis
###################################################################

pretty_bkg_name_map = {'WithfromPV': 'Combinatorial',
    'Xc_background': 'Bad Xc',
    'Xc_signal_Ypis_diffAncestorYXc': 'Combinatorial',
    'Xc_signal_Ypis_nomatch_Other': 'Combinatorial',
    'doubleCharm': 'Double Charm',
    'normlike': 'Normalization like',
    'otherDisplaced': 'Other displaced',
    'signal': 'Signal',
    'tauFromCharm': 'Tau from charm',
    'NA': 'Uncategorized'}

def pretty_bkg_categories():
    return set(pretty_bkg_name_map.values())

def map_name_simple_to_pretty(c):
    return pretty_bkg_name_map[c]

def detailed_to_pretty_category_mapping():
    return { d: pretty_bkg_name_map[s] for d,s in detailed_to_simplified_category_mapping.items() }

pretty_categories_map = { i:pretty_bkg_name_map[n]
    for i, n in simplified_categories_map.items()
}
