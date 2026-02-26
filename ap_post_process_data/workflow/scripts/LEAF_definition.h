//++++++++++++++++= include file for leaf definition +++++++++++++++++++++++++++
// Fixed size dimensions of array or collections stored in the TTree if any.

   static constexpr Int_t kMaxB_ENDVERTEX_COV = 1;
   static constexpr Int_t kMaxB_OWNPV_COV = 1;
   static constexpr Int_t kMaxB_TOPPV_COV = 1;
   static constexpr Int_t kMaxXc_ENDVERTEX_COV = 1;
   static constexpr Int_t kMaxXc_OWNPV_COV = 1;
   static constexpr Int_t kMaxXc_TOPPV_COV = 1;
   static constexpr Int_t kMaxXc_ORIVX_COV = 1;
   static constexpr Int_t kMaxp1_fromXc_OWNPV_COV = 1;
   static constexpr Int_t kMaxp1_fromXc_TOPPV_COV = 1;
   static constexpr Int_t kMaxp1_fromXc_ORIVX_COV = 1;
   static constexpr Int_t kMaxp2_fromXc_OWNPV_COV = 1;
   static constexpr Int_t kMaxp2_fromXc_TOPPV_COV = 1;
   static constexpr Int_t kMaxp2_fromXc_ORIVX_COV = 1;
   static constexpr Int_t kMaxp3_fromXc_OWNPV_COV = 1;
   static constexpr Int_t kMaxp3_fromXc_TOPPV_COV = 1;
   static constexpr Int_t kMaxp3_fromXc_ORIVX_COV = 1;
   static constexpr Int_t kMaxY_ENDVERTEX_COV = 1;
   static constexpr Int_t kMaxY_OWNPV_COV = 1;
   static constexpr Int_t kMaxY_TOPPV_COV = 1;
   static constexpr Int_t kMaxY_ORIVX_COV = 1;
   static constexpr Int_t kMaxp1_fromY_OWNPV_COV = 1;
   static constexpr Int_t kMaxp1_fromY_TOPPV_COV = 1;
   static constexpr Int_t kMaxp1_fromY_ORIVX_COV = 1;
   static constexpr Int_t kMaxp2_fromY_OWNPV_COV = 1;
   static constexpr Int_t kMaxp2_fromY_TOPPV_COV = 1;
   static constexpr Int_t kMaxp2_fromY_ORIVX_COV = 1;
   static constexpr Int_t kMaxp3_fromY_OWNPV_COV = 1;
   static constexpr Int_t kMaxp3_fromY_TOPPV_COV = 1;
   static constexpr Int_t kMaxp3_fromY_ORIVX_COV = 1;

   // Declaration of leaf types
   Double_t        B_ETA;
   Double_t        B_MINIP;
   Double_t        B_MINIPCHI2;
   Double_t        B_MINIPNEXTBEST;
   Double_t        B_MINIPCHI2NEXTBEST;
   Int_t           nPV;
   Float_t         B_AllIP[100];   //[nPV]
   Float_t         B_AllIPchi2[100];   //[nPV]
   Float_t         B_AllDIRA[100];   //[nPV]
   Double_t        B_ENDVERTEX_X;
   Double_t        B_ENDVERTEX_Y;
   Double_t        B_ENDVERTEX_Z;
   Double_t        B_ENDVERTEX_XERR;
   Double_t        B_ENDVERTEX_YERR;
   Double_t        B_ENDVERTEX_ZERR;
   Double_t        B_ENDVERTEX_CHI2;
   Int_t           B_ENDVERTEX_NDOF;
   Float_t         B_ENDVERTEX_COV_[3][3];
   Double_t        B_OWNPV_X;
   Double_t        B_OWNPV_Y;
   Double_t        B_OWNPV_Z;
   Double_t        B_OWNPV_XERR;
   Double_t        B_OWNPV_YERR;
   Double_t        B_OWNPV_ZERR;
   Double_t        B_OWNPV_CHI2;
   Int_t           B_OWNPV_NDOF;
   Float_t         B_OWNPV_COV_[3][3];
   Double_t        B_IP_OWNPV;
   Double_t        B_IPCHI2_OWNPV;
   Double_t        B_FD_OWNPV;
   Double_t        B_FDCHI2_OWNPV;
   Double_t        B_DIRA_OWNPV;
   Double_t        B_TOPPV_X;
   Double_t        B_TOPPV_Y;
   Double_t        B_TOPPV_Z;
   Double_t        B_TOPPV_XERR;
   Double_t        B_TOPPV_YERR;
   Double_t        B_TOPPV_ZERR;
   Double_t        B_TOPPV_CHI2;
   Int_t           B_TOPPV_NDOF;
   Float_t         B_TOPPV_COV_[3][3];
   Double_t        B_IP_TOPPV;
   Double_t        B_IPCHI2_TOPPV;
   Double_t        B_FD_TOPPV;
   Double_t        B_FDCHI2_TOPPV;
   Double_t        B_DIRA_TOPPV;
   Double_t        B_P;
   Double_t        B_PT;
   Double_t        B_PE;
   Double_t        B_PX;
   Double_t        B_PY;
   Double_t        B_PZ;
   Double_t        B_MM;
   Double_t        B_MMERR;
   Double_t        B_M;
   Int_t           B_BKGCAT;
   Int_t           B_TRUEID;
   Int_t           B_MC_MOTHER_ID;
   Int_t           B_MC_MOTHER_KEY;
   Int_t           B_MC_GD_MOTHER_ID;
   Int_t           B_MC_GD_MOTHER_KEY;
   Int_t           B_MC_GD_GD_MOTHER_ID;
   Int_t           B_MC_GD_GD_MOTHER_KEY;
   Double_t        B_TRUEP_E;
   Double_t        B_TRUEP_X;
   Double_t        B_TRUEP_Y;
   Double_t        B_TRUEP_Z;
   Double_t        B_TRUEPT;
   Double_t        B_TRUEORIGINVERTEX_X;
   Double_t        B_TRUEORIGINVERTEX_Y;
   Double_t        B_TRUEORIGINVERTEX_Z;
   Double_t        B_TRUEENDVERTEX_X;
   Double_t        B_TRUEENDVERTEX_Y;
   Double_t        B_TRUEENDVERTEX_Z;
   Bool_t          B_TRUEISSTABLE;
   Double_t        B_TRUETAU;
   Int_t           B_ID;
   Double_t        B_NumVtxWithinChi2WindowOneTrack;
   Double_t        B_SmallestDeltaChi2OneTrack;
   Double_t        B_SmallestDeltaChi2MassOneTrack;
   Double_t        B_SmallestDeltaChi2TwoTracks;
   Double_t        B_SmallestDeltaChi2MassTwoTracks;
   Double_t        B_BPVVDR;
   Double_t        B_DOCA1;
   Double_t        B_TAU;
   Double_t        B_TAUERR;
   Int_t           B_DTF_nPV;
   Float_t         B_DTF_D_splus_Kplus_0_ID[100];   //[B_DTF_nPV]
   Float_t         B_DTF_D_splus_Kplus_0_PE[100];   //[B_DTF_nPV]
   Float_t         B_DTF_D_splus_Kplus_0_PX[100];   //[B_DTF_nPV]
   Float_t         B_DTF_D_splus_Kplus_0_PY[100];   //[B_DTF_nPV]
   Float_t         B_DTF_D_splus_Kplus_0_PZ[100];   //[B_DTF_nPV]
   Float_t         B_DTF_D_splus_Kplus_ID[100];   //[B_DTF_nPV]
   Float_t         B_DTF_D_splus_Kplus_PE[100];   //[B_DTF_nPV]
   Float_t         B_DTF_D_splus_Kplus_PX[100];   //[B_DTF_nPV]
   Float_t         B_DTF_D_splus_Kplus_PY[100];   //[B_DTF_nPV]
   Float_t         B_DTF_D_splus_Kplus_PZ[100];   //[B_DTF_nPV]
   Float_t         B_DTF_D_splus_M[100];   //[B_DTF_nPV]
   Float_t         B_DTF_D_splus_MERR[100];   //[B_DTF_nPV]
   Float_t         B_DTF_D_splus_P[100];   //[B_DTF_nPV]
   Float_t         B_DTF_D_splus_PERR[100];   //[B_DTF_nPV]
   Float_t         B_DTF_D_splus_ctau[100];   //[B_DTF_nPV]
   Float_t         B_DTF_D_splus_ctauErr[100];   //[B_DTF_nPV]
   Float_t         B_DTF_D_splus_decayLength[100];   //[B_DTF_nPV]
   Float_t         B_DTF_D_splus_decayLengthErr[100];   //[B_DTF_nPV]
   Float_t         B_DTF_D_splus_piplus_ID[100];   //[B_DTF_nPV]
   Float_t         B_DTF_D_splus_piplus_PE[100];   //[B_DTF_nPV]
   Float_t         B_DTF_D_splus_piplus_PX[100];   //[B_DTF_nPV]
   Float_t         B_DTF_D_splus_piplus_PY[100];   //[B_DTF_nPV]
   Float_t         B_DTF_D_splus_piplus_PZ[100];   //[B_DTF_nPV]
   Float_t         B_DTF_M[100];   //[B_DTF_nPV]
   Float_t         B_DTF_MERR[100];   //[B_DTF_nPV]
   Float_t         B_DTF_P[100];   //[B_DTF_nPV]
   Float_t         B_DTF_PERR[100];   //[B_DTF_nPV]
   Float_t         B_DTF_chi2[100];   //[B_DTF_nPV]
   Float_t         B_DTF_nDOF[100];   //[B_DTF_nPV]
   Float_t         B_DTF_nIter[100];   //[B_DTF_nPV]
   Float_t         B_DTF_status[100];   //[B_DTF_nPV]
   Float_t         B_DTF_tauminus_M[100];   //[B_DTF_nPV]
   Float_t         B_DTF_tauminus_MERR[100];   //[B_DTF_nPV]
   Float_t         B_DTF_tauminus_P[100];   //[B_DTF_nPV]
   Float_t         B_DTF_tauminus_PERR[100];   //[B_DTF_nPV]
   Float_t         B_DTF_tauminus_ctau[100];   //[B_DTF_nPV]
   Float_t         B_DTF_tauminus_ctauErr[100];   //[B_DTF_nPV]
   Float_t         B_DTF_tauminus_decayLength[100];   //[B_DTF_nPV]
   Float_t         B_DTF_tauminus_decayLengthErr[100];   //[B_DTF_nPV]
   Float_t         B_DTF_tauminus_piplus_0_ID[100];   //[B_DTF_nPV]
   Float_t         B_DTF_tauminus_piplus_0_PE[100];   //[B_DTF_nPV]
   Float_t         B_DTF_tauminus_piplus_0_PX[100];   //[B_DTF_nPV]
   Float_t         B_DTF_tauminus_piplus_0_PY[100];   //[B_DTF_nPV]
   Float_t         B_DTF_tauminus_piplus_0_PZ[100];   //[B_DTF_nPV]
   Float_t         B_DTF_tauminus_piplus_1_ID[100];   //[B_DTF_nPV]
   Float_t         B_DTF_tauminus_piplus_1_PE[100];   //[B_DTF_nPV]
   Float_t         B_DTF_tauminus_piplus_1_PX[100];   //[B_DTF_nPV]
   Float_t         B_DTF_tauminus_piplus_1_PY[100];   //[B_DTF_nPV]
   Float_t         B_DTF_tauminus_piplus_1_PZ[100];   //[B_DTF_nPV]
   Float_t         B_DTF_tauminus_piplus_ID[100];   //[B_DTF_nPV]
   Float_t         B_DTF_tauminus_piplus_PE[100];   //[B_DTF_nPV]
   Float_t         B_DTF_tauminus_piplus_PX[100];   //[B_DTF_nPV]
   Float_t         B_DTF_tauminus_piplus_PY[100];   //[B_DTF_nPV]
   Float_t         B_DTF_tauminus_piplus_PZ[100];   //[B_DTF_nPV]
   Int_t           B_DTFPVDs_nPV;
   Float_t         B_DTFPVDs_D_splus_Kplus_0_ID[100];   //[B_DTFPVDs_nPV]
   Float_t         B_DTFPVDs_D_splus_Kplus_0_PE[100];   //[B_DTFPVDs_nPV]
   Float_t         B_DTFPVDs_D_splus_Kplus_0_PX[100];   //[B_DTFPVDs_nPV]
   Float_t         B_DTFPVDs_D_splus_Kplus_0_PY[100];   //[B_DTFPVDs_nPV]
   Float_t         B_DTFPVDs_D_splus_Kplus_0_PZ[100];   //[B_DTFPVDs_nPV]
   Float_t         B_DTFPVDs_D_splus_Kplus_ID[100];   //[B_DTFPVDs_nPV]
   Float_t         B_DTFPVDs_D_splus_Kplus_PE[100];   //[B_DTFPVDs_nPV]
   Float_t         B_DTFPVDs_D_splus_Kplus_PX[100];   //[B_DTFPVDs_nPV]
   Float_t         B_DTFPVDs_D_splus_Kplus_PY[100];   //[B_DTFPVDs_nPV]
   Float_t         B_DTFPVDs_D_splus_Kplus_PZ[100];   //[B_DTFPVDs_nPV]
   Float_t         B_DTFPVDs_D_splus_M[100];   //[B_DTFPVDs_nPV]
   Float_t         B_DTFPVDs_D_splus_MERR[100];   //[B_DTFPVDs_nPV]
   Float_t         B_DTFPVDs_D_splus_P[100];   //[B_DTFPVDs_nPV]
   Float_t         B_DTFPVDs_D_splus_PERR[100];   //[B_DTFPVDs_nPV]
   Float_t         B_DTFPVDs_D_splus_ctau[100];   //[B_DTFPVDs_nPV]
   Float_t         B_DTFPVDs_D_splus_ctauErr[100];   //[B_DTFPVDs_nPV]
   Float_t         B_DTFPVDs_D_splus_decayLength[100];   //[B_DTFPVDs_nPV]
   Float_t         B_DTFPVDs_D_splus_decayLengthErr[100];   //[B_DTFPVDs_nPV]
   Float_t         B_DTFPVDs_D_splus_piplus_ID[100];   //[B_DTFPVDs_nPV]
   Float_t         B_DTFPVDs_D_splus_piplus_PE[100];   //[B_DTFPVDs_nPV]
   Float_t         B_DTFPVDs_D_splus_piplus_PX[100];   //[B_DTFPVDs_nPV]
   Float_t         B_DTFPVDs_D_splus_piplus_PY[100];   //[B_DTFPVDs_nPV]
   Float_t         B_DTFPVDs_D_splus_piplus_PZ[100];   //[B_DTFPVDs_nPV]
   Float_t         B_DTFPVDs_M[100];   //[B_DTFPVDs_nPV]
   Float_t         B_DTFPVDs_MERR[100];   //[B_DTFPVDs_nPV]
   Float_t         B_DTFPVDs_P[100];   //[B_DTFPVDs_nPV]
   Float_t         B_DTFPVDs_PERR[100];   //[B_DTFPVDs_nPV]
   Float_t         B_DTFPVDs_PV_X[100];   //[B_DTFPVDs_nPV]
   Float_t         B_DTFPVDs_PV_Y[100];   //[B_DTFPVDs_nPV]
   Float_t         B_DTFPVDs_PV_Z[100];   //[B_DTFPVDs_nPV]
   Float_t         B_DTFPVDs_PV_key[100];   //[B_DTFPVDs_nPV]
   Float_t         B_DTFPVDs_chi2[100];   //[B_DTFPVDs_nPV]
   Float_t         B_DTFPVDs_ctau[100];   //[B_DTFPVDs_nPV]
   Float_t         B_DTFPVDs_ctauErr[100];   //[B_DTFPVDs_nPV]
   Float_t         B_DTFPVDs_decayLength[100];   //[B_DTFPVDs_nPV]
   Float_t         B_DTFPVDs_decayLengthErr[100];   //[B_DTFPVDs_nPV]
   Float_t         B_DTFPVDs_nDOF[100];   //[B_DTFPVDs_nPV]
   Float_t         B_DTFPVDs_nIter[100];   //[B_DTFPVDs_nPV]
   Float_t         B_DTFPVDs_status[100];   //[B_DTFPVDs_nPV]
   Float_t         B_DTFPVDs_tauminus_M[100];   //[B_DTFPVDs_nPV]
   Float_t         B_DTFPVDs_tauminus_MERR[100];   //[B_DTFPVDs_nPV]
   Float_t         B_DTFPVDs_tauminus_P[100];   //[B_DTFPVDs_nPV]
   Float_t         B_DTFPVDs_tauminus_PERR[100];   //[B_DTFPVDs_nPV]
   Float_t         B_DTFPVDs_tauminus_ctau[100];   //[B_DTFPVDs_nPV]
   Float_t         B_DTFPVDs_tauminus_ctauErr[100];   //[B_DTFPVDs_nPV]
   Float_t         B_DTFPVDs_tauminus_decayLength[100];   //[B_DTFPVDs_nPV]
   Float_t         B_DTFPVDs_tauminus_decayLengthErr[100];   //[B_DTFPVDs_nPV]
   Float_t         B_DTFPVDs_tauminus_piplus_0_ID[100];   //[B_DTFPVDs_nPV]
   Float_t         B_DTFPVDs_tauminus_piplus_0_PE[100];   //[B_DTFPVDs_nPV]
   Float_t         B_DTFPVDs_tauminus_piplus_0_PX[100];   //[B_DTFPVDs_nPV]
   Float_t         B_DTFPVDs_tauminus_piplus_0_PY[100];   //[B_DTFPVDs_nPV]
   Float_t         B_DTFPVDs_tauminus_piplus_0_PZ[100];   //[B_DTFPVDs_nPV]
   Float_t         B_DTFPVDs_tauminus_piplus_1_ID[100];   //[B_DTFPVDs_nPV]
   Float_t         B_DTFPVDs_tauminus_piplus_1_PE[100];   //[B_DTFPVDs_nPV]
   Float_t         B_DTFPVDs_tauminus_piplus_1_PX[100];   //[B_DTFPVDs_nPV]
   Float_t         B_DTFPVDs_tauminus_piplus_1_PY[100];   //[B_DTFPVDs_nPV]
   Float_t         B_DTFPVDs_tauminus_piplus_1_PZ[100];   //[B_DTFPVDs_nPV]
   Float_t         B_DTFPVDs_tauminus_piplus_ID[100];   //[B_DTFPVDs_nPV]
   Float_t         B_DTFPVDs_tauminus_piplus_PE[100];   //[B_DTFPVDs_nPV]
   Float_t         B_DTFPVDs_tauminus_piplus_PX[100];   //[B_DTFPVDs_nPV]
   Float_t         B_DTFPVDs_tauminus_piplus_PY[100];   //[B_DTFPVDs_nPV]
   Float_t         B_DTFPVDs_tauminus_piplus_PZ[100];   //[B_DTFPVDs_nPV]
   Bool_t          B_L0Global_Dec;
   Bool_t          B_L0Global_TIS;
   Bool_t          B_L0Global_TOS;
   Bool_t          B_Hlt1Global_Dec;
   Bool_t          B_Hlt1Global_TIS;
   Bool_t          B_Hlt1Global_TOS;
   Bool_t          B_Hlt1Phys_Dec;
   Bool_t          B_Hlt1Phys_TIS;
   Bool_t          B_Hlt1Phys_TOS;
   Bool_t          B_Hlt2Global_Dec;
   Bool_t          B_Hlt2Global_TIS;
   Bool_t          B_Hlt2Global_TOS;
   Bool_t          B_Hlt2Phys_Dec;
   Bool_t          B_Hlt2Phys_TIS;
   Bool_t          B_Hlt2Phys_TOS;
   Bool_t          B_L0HadronDecision_Dec;
   Bool_t          B_L0HadronDecision_TIS;
   Bool_t          B_L0HadronDecision_TOS;
   Bool_t          B_L0GlobalDecision_Dec;
   Bool_t          B_L0GlobalDecision_TIS;
   Bool_t          B_L0GlobalDecision_TOS;
   Bool_t          B_Hlt1GlobalDecision_Dec;
   Bool_t          B_Hlt1GlobalDecision_TIS;
   Bool_t          B_Hlt1GlobalDecision_TOS;
   Bool_t          B_Hlt1TrackAllL0Decision_Dec;
   Bool_t          B_Hlt1TrackAllL0Decision_TIS;
   Bool_t          B_Hlt1TrackAllL0Decision_TOS;
   Bool_t          B_Hlt1TrackAllL0TightDecision_Dec;
   Bool_t          B_Hlt1TrackAllL0TightDecision_TIS;
   Bool_t          B_Hlt1TrackAllL0TightDecision_TOS;
   Bool_t          B_Hlt2GlobalDecision_Dec;
   Bool_t          B_Hlt2GlobalDecision_TIS;
   Bool_t          B_Hlt2GlobalDecision_TOS;
   Bool_t          B_Hlt2Topo2BodyBBDTDecision_Dec;
   Bool_t          B_Hlt2Topo2BodyBBDTDecision_TIS;
   Bool_t          B_Hlt2Topo2BodyBBDTDecision_TOS;
   Bool_t          B_Hlt2Topo3BodyBBDTDecision_Dec;
   Bool_t          B_Hlt2Topo3BodyBBDTDecision_TIS;
   Bool_t          B_Hlt2Topo3BodyBBDTDecision_TOS;
   Bool_t          B_Hlt2Topo4BodyBBDTDecision_Dec;
   Bool_t          B_Hlt2Topo4BodyBBDTDecision_TIS;
   Bool_t          B_Hlt2Topo4BodyBBDTDecision_TOS;
   Bool_t          B_Hlt2Topo2BodySimpleDecision_Dec;
   Bool_t          B_Hlt2Topo2BodySimpleDecision_TIS;
   Bool_t          B_Hlt2Topo2BodySimpleDecision_TOS;
   Bool_t          B_Hlt2Topo3BodySimpleDecision_Dec;
   Bool_t          B_Hlt2Topo3BodySimpleDecision_TIS;
   Bool_t          B_Hlt2Topo3BodySimpleDecision_TOS;
   Bool_t          B_Hlt2Topo4BodySimpleDecision_Dec;
   Bool_t          B_Hlt2Topo4BodySimpleDecision_TIS;
   Bool_t          B_Hlt2Topo4BodySimpleDecision_TOS;
   Bool_t          B_Hlt2IncPhiDecision_Dec;
   Bool_t          B_Hlt2IncPhiDecision_TIS;
   Bool_t          B_Hlt2IncPhiDecision_TOS;
   Bool_t          B_Hlt2IncPhiSidebandsDecision_Dec;
   Bool_t          B_Hlt2IncPhiSidebandsDecision_TIS;
   Bool_t          B_Hlt2IncPhiSidebandsDecision_TOS;
   Bool_t          B_Hlt2CharmHadD2HHHDecision_Dec;
   Bool_t          B_Hlt2CharmHadD2HHHDecision_TIS;
   Bool_t          B_Hlt2CharmHadD2HHHDecision_TOS;
   Bool_t          B_Hlt2CharmHadD2HHHWideMassDecision_Dec;
   Bool_t          B_Hlt2CharmHadD2HHHWideMassDecision_TIS;
   Bool_t          B_Hlt2CharmHadD2HHHWideMassDecision_TOS;
   Double_t        Xc_ETA;
   Double_t        Xc_MINIP;
   Double_t        Xc_MINIPCHI2;
   Double_t        Xc_MINIPNEXTBEST;
   Double_t        Xc_MINIPCHI2NEXTBEST;
   Float_t         Xc_AllIP[100];   //[nPV]
   Float_t         Xc_AllIPchi2[100];   //[nPV]
   Float_t         Xc_AllDIRA[100];   //[nPV]
   Double_t        Xc_ENDVERTEX_X;
   Double_t        Xc_ENDVERTEX_Y;
   Double_t        Xc_ENDVERTEX_Z;
   Double_t        Xc_ENDVERTEX_XERR;
   Double_t        Xc_ENDVERTEX_YERR;
   Double_t        Xc_ENDVERTEX_ZERR;
   Double_t        Xc_ENDVERTEX_CHI2;
   Int_t           Xc_ENDVERTEX_NDOF;
   Float_t         Xc_ENDVERTEX_COV_[3][3];
   Double_t        Xc_OWNPV_X;
   Double_t        Xc_OWNPV_Y;
   Double_t        Xc_OWNPV_Z;
   Double_t        Xc_OWNPV_XERR;
   Double_t        Xc_OWNPV_YERR;
   Double_t        Xc_OWNPV_ZERR;
   Double_t        Xc_OWNPV_CHI2;
   Int_t           Xc_OWNPV_NDOF;
   Float_t         Xc_OWNPV_COV_[3][3];
   Double_t        Xc_IP_OWNPV;
   Double_t        Xc_IPCHI2_OWNPV;
   Double_t        Xc_FD_OWNPV;
   Double_t        Xc_FDCHI2_OWNPV;
   Double_t        Xc_DIRA_OWNPV;
   Double_t        Xc_TOPPV_X;
   Double_t        Xc_TOPPV_Y;
   Double_t        Xc_TOPPV_Z;
   Double_t        Xc_TOPPV_XERR;
   Double_t        Xc_TOPPV_YERR;
   Double_t        Xc_TOPPV_ZERR;
   Double_t        Xc_TOPPV_CHI2;
   Int_t           Xc_TOPPV_NDOF;
   Float_t         Xc_TOPPV_COV_[3][3];
   Double_t        Xc_IP_TOPPV;
   Double_t        Xc_IPCHI2_TOPPV;
   Double_t        Xc_FD_TOPPV;
   Double_t        Xc_FDCHI2_TOPPV;
   Double_t        Xc_DIRA_TOPPV;
   Double_t        Xc_ORIVX_X;
   Double_t        Xc_ORIVX_Y;
   Double_t        Xc_ORIVX_Z;
   Double_t        Xc_ORIVX_XERR;
   Double_t        Xc_ORIVX_YERR;
   Double_t        Xc_ORIVX_ZERR;
   Double_t        Xc_ORIVX_CHI2;
   Int_t           Xc_ORIVX_NDOF;
   Float_t         Xc_ORIVX_COV_[3][3];
   Double_t        Xc_IP_ORIVX;
   Double_t        Xc_IPCHI2_ORIVX;
   Double_t        Xc_FD_ORIVX;
   Double_t        Xc_FDCHI2_ORIVX;
   Double_t        Xc_DIRA_ORIVX;
   Double_t        Xc_P;
   Double_t        Xc_PT;
   Double_t        Xc_PE;
   Double_t        Xc_PX;
   Double_t        Xc_PY;
   Double_t        Xc_PZ;
   Double_t        Xc_MM;
   Double_t        Xc_MMERR;
   Double_t        Xc_M;
   Int_t           Xc_BKGCAT;
   Int_t           Xc_TRUEID;
   Int_t           Xc_MC_MOTHER_ID;
   Int_t           Xc_MC_MOTHER_KEY;
   Int_t           Xc_MC_GD_MOTHER_ID;
   Int_t           Xc_MC_GD_MOTHER_KEY;
   Int_t           Xc_MC_GD_GD_MOTHER_ID;
   Int_t           Xc_MC_GD_GD_MOTHER_KEY;
   Double_t        Xc_TRUEP_E;
   Double_t        Xc_TRUEP_X;
   Double_t        Xc_TRUEP_Y;
   Double_t        Xc_TRUEP_Z;
   Double_t        Xc_TRUEPT;
   Double_t        Xc_TRUEORIGINVERTEX_X;
   Double_t        Xc_TRUEORIGINVERTEX_Y;
   Double_t        Xc_TRUEORIGINVERTEX_Z;
   Double_t        Xc_TRUEENDVERTEX_X;
   Double_t        Xc_TRUEENDVERTEX_Y;
   Double_t        Xc_TRUEENDVERTEX_Z;
   Bool_t          Xc_TRUEISSTABLE;
   Double_t        Xc_TRUETAU;
   Int_t           Xc_ID;
   Double_t        Xc_NumVtxWithinChi2WindowOneTrack;
   Double_t        Xc_SmallestDeltaChi2OneTrack;
   Double_t        Xc_SmallestDeltaChi2MassOneTrack;
   Double_t        Xc_SmallestDeltaChi2TwoTracks;
   Double_t        Xc_SmallestDeltaChi2MassTwoTracks;
   Double_t        Xc_BPVVDR;
   Double_t        Xc_DOCA1;
   Double_t        Xc_DOCA2;
   Double_t        Xc_DOCA3;
   Int_t           Xc_0_20_nc_mult;
   Double_t        Xc_0_20_nc_sPT;
   Double_t        Xc_0_20_nc_vPT;
   Double_t        Xc_0_20_nc_PX;
   Double_t        Xc_0_20_nc_PY;
   Double_t        Xc_0_20_nc_PZ;
   Double_t        Xc_0_20_nc_avCL;
   Double_t        Xc_0_20_nc_maxCL;
   Double_t        Xc_0_20_nc_asy_P;
   Double_t        Xc_0_20_nc_asy_PT;
   Double_t        Xc_0_20_nc_asy_PX;
   Double_t        Xc_0_20_nc_asy_PY;
   Double_t        Xc_0_20_nc_asy_PZ;
   Double_t        Xc_0_20_nc_deltaEta;
   Double_t        Xc_0_20_nc_deltaPhi;
   Double_t        Xc_0_20_nc_IT;
   Double_t        Xc_0_20_nc_maxPt_PT;
   Double_t        Xc_0_20_nc_maxPt_PX;
   Double_t        Xc_0_20_nc_maxPt_PY;
   Double_t        Xc_0_20_nc_maxPt_PZ;
   Double_t        Xc_0_20_nc_H1;
   Double_t        Xc_0_20_nc_H2;
   Double_t        Xc_0_20_nc_H3;
   Double_t        Xc_0_20_nc_H4;
   Bool_t          Xc_L0Global_Dec;
   Bool_t          Xc_L0Global_TIS;
   Bool_t          Xc_L0Global_TOS;
   Bool_t          Xc_Hlt1Global_Dec;
   Bool_t          Xc_Hlt1Global_TIS;
   Bool_t          Xc_Hlt1Global_TOS;
   Bool_t          Xc_Hlt1Phys_Dec;
   Bool_t          Xc_Hlt1Phys_TIS;
   Bool_t          Xc_Hlt1Phys_TOS;
   Bool_t          Xc_Hlt2Global_Dec;
   Bool_t          Xc_Hlt2Global_TIS;
   Bool_t          Xc_Hlt2Global_TOS;
   Bool_t          Xc_Hlt2Phys_Dec;
   Bool_t          Xc_Hlt2Phys_TIS;
   Bool_t          Xc_Hlt2Phys_TOS;
   Bool_t          Xc_L0HadronDecision_Dec;
   Bool_t          Xc_L0HadronDecision_TIS;
   Bool_t          Xc_L0HadronDecision_TOS;
   Bool_t          Xc_L0GlobalDecision_Dec;
   Bool_t          Xc_L0GlobalDecision_TIS;
   Bool_t          Xc_L0GlobalDecision_TOS;
   Bool_t          Xc_Hlt1GlobalDecision_Dec;
   Bool_t          Xc_Hlt1GlobalDecision_TIS;
   Bool_t          Xc_Hlt1GlobalDecision_TOS;
   Bool_t          Xc_Hlt1TrackAllL0Decision_Dec;
   Bool_t          Xc_Hlt1TrackAllL0Decision_TIS;
   Bool_t          Xc_Hlt1TrackAllL0Decision_TOS;
   Bool_t          Xc_Hlt1TrackAllL0TightDecision_Dec;
   Bool_t          Xc_Hlt1TrackAllL0TightDecision_TIS;
   Bool_t          Xc_Hlt1TrackAllL0TightDecision_TOS;
   Bool_t          Xc_Hlt2GlobalDecision_Dec;
   Bool_t          Xc_Hlt2GlobalDecision_TIS;
   Bool_t          Xc_Hlt2GlobalDecision_TOS;
   Bool_t          Xc_Hlt2Topo2BodyBBDTDecision_Dec;
   Bool_t          Xc_Hlt2Topo2BodyBBDTDecision_TIS;
   Bool_t          Xc_Hlt2Topo2BodyBBDTDecision_TOS;
   Bool_t          Xc_Hlt2Topo3BodyBBDTDecision_Dec;
   Bool_t          Xc_Hlt2Topo3BodyBBDTDecision_TIS;
   Bool_t          Xc_Hlt2Topo3BodyBBDTDecision_TOS;
   Bool_t          Xc_Hlt2Topo4BodyBBDTDecision_Dec;
   Bool_t          Xc_Hlt2Topo4BodyBBDTDecision_TIS;
   Bool_t          Xc_Hlt2Topo4BodyBBDTDecision_TOS;
   Bool_t          Xc_Hlt2Topo2BodySimpleDecision_Dec;
   Bool_t          Xc_Hlt2Topo2BodySimpleDecision_TIS;
   Bool_t          Xc_Hlt2Topo2BodySimpleDecision_TOS;
   Bool_t          Xc_Hlt2Topo3BodySimpleDecision_Dec;
   Bool_t          Xc_Hlt2Topo3BodySimpleDecision_TIS;
   Bool_t          Xc_Hlt2Topo3BodySimpleDecision_TOS;
   Bool_t          Xc_Hlt2Topo4BodySimpleDecision_Dec;
   Bool_t          Xc_Hlt2Topo4BodySimpleDecision_TIS;
   Bool_t          Xc_Hlt2Topo4BodySimpleDecision_TOS;
   Bool_t          Xc_Hlt2IncPhiDecision_Dec;
   Bool_t          Xc_Hlt2IncPhiDecision_TIS;
   Bool_t          Xc_Hlt2IncPhiDecision_TOS;
   Bool_t          Xc_Hlt2IncPhiSidebandsDecision_Dec;
   Bool_t          Xc_Hlt2IncPhiSidebandsDecision_TIS;
   Bool_t          Xc_Hlt2IncPhiSidebandsDecision_TOS;
   Bool_t          Xc_Hlt2CharmHadD2HHHDecision_Dec;
   Bool_t          Xc_Hlt2CharmHadD2HHHDecision_TIS;
   Bool_t          Xc_Hlt2CharmHadD2HHHDecision_TOS;
   Bool_t          Xc_Hlt2CharmHadD2HHHWideMassDecision_Dec;
   Bool_t          Xc_Hlt2CharmHadD2HHHWideMassDecision_TIS;
   Bool_t          Xc_Hlt2CharmHadD2HHHWideMassDecision_TOS;
   Double_t        p1_fromXc_ETA;
   Double_t        p1_fromXc_MC12TuneV2_ProbNNe;
   Double_t        p1_fromXc_MC12TuneV2_ProbNNmu;
   Double_t        p1_fromXc_MC12TuneV2_ProbNNpi;
   Double_t        p1_fromXc_MC12TuneV2_ProbNNk;
   Double_t        p1_fromXc_MC12TuneV2_ProbNNp;
   Double_t        p1_fromXc_MC12TuneV2_ProbNNghost;
   Double_t        p1_fromXc_MC12TuneV3_ProbNNe;
   Double_t        p1_fromXc_MC12TuneV3_ProbNNmu;
   Double_t        p1_fromXc_MC12TuneV3_ProbNNpi;
   Double_t        p1_fromXc_MC12TuneV3_ProbNNk;
   Double_t        p1_fromXc_MC12TuneV3_ProbNNp;
   Double_t        p1_fromXc_MC12TuneV3_ProbNNghost;
   Double_t        p1_fromXc_MC12TuneV4_ProbNNe;
   Double_t        p1_fromXc_MC12TuneV4_ProbNNmu;
   Double_t        p1_fromXc_MC12TuneV4_ProbNNpi;
   Double_t        p1_fromXc_MC12TuneV4_ProbNNk;
   Double_t        p1_fromXc_MC12TuneV4_ProbNNp;
   Double_t        p1_fromXc_MC12TuneV4_ProbNNghost;
   Double_t        p1_fromXc_MC15TuneV1_ProbNNe;
   Double_t        p1_fromXc_MC15TuneV1_ProbNNmu;
   Double_t        p1_fromXc_MC15TuneV1_ProbNNpi;
   Double_t        p1_fromXc_MC15TuneV1_ProbNNk;
   Double_t        p1_fromXc_MC15TuneV1_ProbNNp;
   Double_t        p1_fromXc_MC15TuneV1_ProbNNghost;
   Double_t        p1_fromXc_MINIP;
   Double_t        p1_fromXc_MINIPCHI2;
   Double_t        p1_fromXc_MINIPNEXTBEST;
   Double_t        p1_fromXc_MINIPCHI2NEXTBEST;
   Float_t         p1_fromXc_AllIP[100];   //[nPV]
   Float_t         p1_fromXc_AllIPchi2[100];   //[nPV]
   Float_t         p1_fromXc_AllDIRA[100];   //[nPV]
   Double_t        p1_fromXc_OWNPV_X;
   Double_t        p1_fromXc_OWNPV_Y;
   Double_t        p1_fromXc_OWNPV_Z;
   Double_t        p1_fromXc_OWNPV_XERR;
   Double_t        p1_fromXc_OWNPV_YERR;
   Double_t        p1_fromXc_OWNPV_ZERR;
   Double_t        p1_fromXc_OWNPV_CHI2;
   Int_t           p1_fromXc_OWNPV_NDOF;
   Float_t         p1_fromXc_OWNPV_COV_[3][3];
   Double_t        p1_fromXc_IP_OWNPV;
   Double_t        p1_fromXc_IPCHI2_OWNPV;
   Double_t        p1_fromXc_TOPPV_X;
   Double_t        p1_fromXc_TOPPV_Y;
   Double_t        p1_fromXc_TOPPV_Z;
   Double_t        p1_fromXc_TOPPV_XERR;
   Double_t        p1_fromXc_TOPPV_YERR;
   Double_t        p1_fromXc_TOPPV_ZERR;
   Double_t        p1_fromXc_TOPPV_CHI2;
   Int_t           p1_fromXc_TOPPV_NDOF;
   Float_t         p1_fromXc_TOPPV_COV_[3][3];
   Double_t        p1_fromXc_IP_TOPPV;
   Double_t        p1_fromXc_IPCHI2_TOPPV;
   Double_t        p1_fromXc_ORIVX_X;
   Double_t        p1_fromXc_ORIVX_Y;
   Double_t        p1_fromXc_ORIVX_Z;
   Double_t        p1_fromXc_ORIVX_XERR;
   Double_t        p1_fromXc_ORIVX_YERR;
   Double_t        p1_fromXc_ORIVX_ZERR;
   Double_t        p1_fromXc_ORIVX_CHI2;
   Int_t           p1_fromXc_ORIVX_NDOF;
   Float_t         p1_fromXc_ORIVX_COV_[3][3];
   Double_t        p1_fromXc_IP_ORIVX;
   Double_t        p1_fromXc_IPCHI2_ORIVX;
   Int_t           p1_fromXc_Nb_NIsoTr;
   Double_t        p1_fromXc_IsoMinBDT;
   Double_t        p1_fromXc_ConeIso;
   Double_t        p1_fromXc_PAIR_M;
   Double_t        p1_fromXc_NIso_PAIR_VtxChi2;
   Double_t        p1_fromXc_NIso_DCHI2;
   Double_t        p1_fromXc_NIso_DIS;
   Double_t        p1_fromXc_NIsoTr_VTXX;
   Double_t        p1_fromXc_NIsoTr_VTXY;
   Double_t        p1_fromXc_NIsoTr_VTXZ;
   Double_t        p1_fromXc_PAIR_IPchi2;
   Double_t        p1_fromXc_NIsoTr_PVDIS;
   Double_t        p1_fromXc_NIsoTr_SVDIS;
   Double_t        p1_fromXc_NIsoTr_DOCA;
   Double_t        p1_fromXc_NIsoTr_ANGLE;
   Double_t        p1_fromXc_NIsoTr_FC;
   Int_t           NTr;
   Float_t         p1_fromXc_Tr_MinIsoBDT[2000];   //[NTr]
   Float_t         p1_fromXc_Tr_PAIR_VTXX[2000];   //[NTr]
   Float_t         p1_fromXc_Tr_PAIR_VTXY[2000];   //[NTr]
   Float_t         p1_fromXc_Tr_PAIR_VTXZ[2000];   //[NTr]
   Float_t         p1_fromXc_Tr_PAIR_VTCHI2NDOF[2000];   //[NTr]
   Float_t         p1_fromXc_Tr_FirstHitX[2000];   //[NTr]
   Float_t         p1_fromXc_Tr_FirstHitY[2000];   //[NTr]
   Float_t         p1_fromXc_Tr_FirstHitZ[2000];   //[NTr]
   Float_t         p1_fromXc_Tr_DCHI2[2000];   //[NTr]
   Float_t         p1_fromXc_Tr_DIS[2000];   //[NTr]
   Float_t         p1_fromXc_Tr_MATCHCHI2[2000];   //[NTr]
   Float_t         p1_fromXc_Tr_PVDIS[2000];   //[NTr]
   Float_t         p1_fromXc_Tr_SVDIS[2000];   //[NTr]
   Float_t         p1_fromXc_Tr_DOCA[2000];   //[NTr]
   Float_t         p1_fromXc_Tr_ANGLE[2000];   //[NTr]
   Float_t         p1_fromXc_Tr_FC_MU[2000];   //[NTr]
   Double_t        p1_fromXc_NIsoTr_ETA;
   Double_t        p1_fromXc_NIsoTr_PHI;
   Double_t        p1_fromXc_NIsoTr_TRTYPE;
   Int_t           p1_fromXc_NIsoTr_TRUEID;
   Int_t           p1_fromXc_NIsoTr_MC_MOTHER_ID;
   Int_t           p1_fromXc_NIsoTr_MC_MOTHER_KEY;
   Int_t           p1_fromXc_NIsoTr_MC_GD_MOTHER_ID;
   Int_t           p1_fromXc_NIsoTr_MC_GD_MOTHER_KEY;
   Int_t           p1_fromXc_NIsoTr_MC_GD_GD_MOTHER_ID;
   Int_t           p1_fromXc_NIsoTr_MC_GD_GD_MOTHER_KEY;
   Double_t        p1_fromXc_P;
   Double_t        p1_fromXc_PT;
   Double_t        p1_fromXc_PE;
   Double_t        p1_fromXc_PX;
   Double_t        p1_fromXc_PY;
   Double_t        p1_fromXc_PZ;
   Double_t        p1_fromXc_M;
   Int_t           p1_fromXc_ID;
   Double_t        p1_fromXc_PIDe;
   Double_t        p1_fromXc_PIDmu;
   Double_t        p1_fromXc_PIDK;
   Double_t        p1_fromXc_PIDp;
   Double_t        p1_fromXc_PIDd;
   Double_t        p1_fromXc_ProbNNe;
   Double_t        p1_fromXc_ProbNNk;
   Double_t        p1_fromXc_ProbNNp;
   Double_t        p1_fromXc_ProbNNpi;
   Double_t        p1_fromXc_ProbNNmu;
   Double_t        p1_fromXc_ProbNNd;
   Double_t        p1_fromXc_ProbNNghost;
   Bool_t          p1_fromXc_hasMuon;
   Bool_t          p1_fromXc_isMuon;
   Bool_t          p1_fromXc_hasRich;
   Bool_t          p1_fromXc_UsedRichAerogel;
   Bool_t          p1_fromXc_UsedRich1Gas;
   Bool_t          p1_fromXc_UsedRich2Gas;
   Bool_t          p1_fromXc_RichAboveElThres;
   Bool_t          p1_fromXc_RichAboveMuThres;
   Bool_t          p1_fromXc_RichAbovePiThres;
   Bool_t          p1_fromXc_RichAboveKaThres;
   Bool_t          p1_fromXc_RichAbovePrThres;
   Bool_t          p1_fromXc_hasCalo;
   Int_t           p1_fromXc_TRACK_Type;
   Int_t           p1_fromXc_TRACK_Key;
   Double_t        p1_fromXc_TRACK_CHI2NDOF;
   Double_t        p1_fromXc_TRACK_PCHI2;
   Double_t        p1_fromXc_TRACK_MatchCHI2;
   Double_t        p1_fromXc_TRACK_GhostProb;
   Double_t        p1_fromXc_TRACK_CloneDist;
   Double_t        p1_fromXc_TRACK_Likelihood;
   Int_t           p1_fromXc_TRUEID;
   Bool_t          p1_fromXc_PANC_fromB;
   Bool_t          p1_fromXc_PANC_fromD;
   Float_t         p1_fromXc_PANC_IDs[15];
   Float_t         p1_fromXc_PANC_Keys[15];
   Int_t           p1_fromXc_N_ANC;
   Double_t        p2_fromXc_ETA;
   Double_t        p2_fromXc_MC12TuneV2_ProbNNe;
   Double_t        p2_fromXc_MC12TuneV2_ProbNNmu;
   Double_t        p2_fromXc_MC12TuneV2_ProbNNpi;
   Double_t        p2_fromXc_MC12TuneV2_ProbNNk;
   Double_t        p2_fromXc_MC12TuneV2_ProbNNp;
   Double_t        p2_fromXc_MC12TuneV2_ProbNNghost;
   Double_t        p2_fromXc_MC12TuneV3_ProbNNe;
   Double_t        p2_fromXc_MC12TuneV3_ProbNNmu;
   Double_t        p2_fromXc_MC12TuneV3_ProbNNpi;
   Double_t        p2_fromXc_MC12TuneV3_ProbNNk;
   Double_t        p2_fromXc_MC12TuneV3_ProbNNp;
   Double_t        p2_fromXc_MC12TuneV3_ProbNNghost;
   Double_t        p2_fromXc_MC12TuneV4_ProbNNe;
   Double_t        p2_fromXc_MC12TuneV4_ProbNNmu;
   Double_t        p2_fromXc_MC12TuneV4_ProbNNpi;
   Double_t        p2_fromXc_MC12TuneV4_ProbNNk;
   Double_t        p2_fromXc_MC12TuneV4_ProbNNp;
   Double_t        p2_fromXc_MC12TuneV4_ProbNNghost;
   Double_t        p2_fromXc_MC15TuneV1_ProbNNe;
   Double_t        p2_fromXc_MC15TuneV1_ProbNNmu;
   Double_t        p2_fromXc_MC15TuneV1_ProbNNpi;
   Double_t        p2_fromXc_MC15TuneV1_ProbNNk;
   Double_t        p2_fromXc_MC15TuneV1_ProbNNp;
   Double_t        p2_fromXc_MC15TuneV1_ProbNNghost;
   Double_t        p2_fromXc_MINIP;
   Double_t        p2_fromXc_MINIPCHI2;
   Double_t        p2_fromXc_MINIPNEXTBEST;
   Double_t        p2_fromXc_MINIPCHI2NEXTBEST;
   Float_t         p2_fromXc_AllIP[100];   //[nPV]
   Float_t         p2_fromXc_AllIPchi2[100];   //[nPV]
   Float_t         p2_fromXc_AllDIRA[100];   //[nPV]
   Double_t        p2_fromXc_OWNPV_X;
   Double_t        p2_fromXc_OWNPV_Y;
   Double_t        p2_fromXc_OWNPV_Z;
   Double_t        p2_fromXc_OWNPV_XERR;
   Double_t        p2_fromXc_OWNPV_YERR;
   Double_t        p2_fromXc_OWNPV_ZERR;
   Double_t        p2_fromXc_OWNPV_CHI2;
   Int_t           p2_fromXc_OWNPV_NDOF;
   Float_t         p2_fromXc_OWNPV_COV_[3][3];
   Double_t        p2_fromXc_IP_OWNPV;
   Double_t        p2_fromXc_IPCHI2_OWNPV;
   Double_t        p2_fromXc_TOPPV_X;
   Double_t        p2_fromXc_TOPPV_Y;
   Double_t        p2_fromXc_TOPPV_Z;
   Double_t        p2_fromXc_TOPPV_XERR;
   Double_t        p2_fromXc_TOPPV_YERR;
   Double_t        p2_fromXc_TOPPV_ZERR;
   Double_t        p2_fromXc_TOPPV_CHI2;
   Int_t           p2_fromXc_TOPPV_NDOF;
   Float_t         p2_fromXc_TOPPV_COV_[3][3];
   Double_t        p2_fromXc_IP_TOPPV;
   Double_t        p2_fromXc_IPCHI2_TOPPV;
   Double_t        p2_fromXc_ORIVX_X;
   Double_t        p2_fromXc_ORIVX_Y;
   Double_t        p2_fromXc_ORIVX_Z;
   Double_t        p2_fromXc_ORIVX_XERR;
   Double_t        p2_fromXc_ORIVX_YERR;
   Double_t        p2_fromXc_ORIVX_ZERR;
   Double_t        p2_fromXc_ORIVX_CHI2;
   Int_t           p2_fromXc_ORIVX_NDOF;
   Float_t         p2_fromXc_ORIVX_COV_[3][3];
   Double_t        p2_fromXc_IP_ORIVX;
   Double_t        p2_fromXc_IPCHI2_ORIVX;
   Int_t           p2_fromXc_Nb_NIsoTr;
   Double_t        p2_fromXc_IsoMinBDT;
   Double_t        p2_fromXc_ConeIso;
   Double_t        p2_fromXc_PAIR_M;
   Double_t        p2_fromXc_NIso_PAIR_VtxChi2;
   Double_t        p2_fromXc_NIso_DCHI2;
   Double_t        p2_fromXc_NIso_DIS;
   Double_t        p2_fromXc_NIsoTr_VTXX;
   Double_t        p2_fromXc_NIsoTr_VTXY;
   Double_t        p2_fromXc_NIsoTr_VTXZ;
   Double_t        p2_fromXc_PAIR_IPchi2;
   Double_t        p2_fromXc_NIsoTr_PVDIS;
   Double_t        p2_fromXc_NIsoTr_SVDIS;
   Double_t        p2_fromXc_NIsoTr_DOCA;
   Double_t        p2_fromXc_NIsoTr_ANGLE;
   Double_t        p2_fromXc_NIsoTr_FC;
   Float_t         p2_fromXc_Tr_MinIsoBDT[2000];   //[NTr]
   Float_t         p2_fromXc_Tr_PAIR_VTXX[2000];   //[NTr]
   Float_t         p2_fromXc_Tr_PAIR_VTXY[2000];   //[NTr]
   Float_t         p2_fromXc_Tr_PAIR_VTXZ[2000];   //[NTr]
   Float_t         p2_fromXc_Tr_PAIR_VTCHI2NDOF[2000];   //[NTr]
   Float_t         p2_fromXc_Tr_FirstHitX[2000];   //[NTr]
   Float_t         p2_fromXc_Tr_FirstHitY[2000];   //[NTr]
   Float_t         p2_fromXc_Tr_FirstHitZ[2000];   //[NTr]
   Float_t         p2_fromXc_Tr_DCHI2[2000];   //[NTr]
   Float_t         p2_fromXc_Tr_DIS[2000];   //[NTr]
   Float_t         p2_fromXc_Tr_MATCHCHI2[2000];   //[NTr]
   Float_t         p2_fromXc_Tr_PVDIS[2000];   //[NTr]
   Float_t         p2_fromXc_Tr_SVDIS[2000];   //[NTr]
   Float_t         p2_fromXc_Tr_DOCA[2000];   //[NTr]
   Float_t         p2_fromXc_Tr_ANGLE[2000];   //[NTr]
   Float_t         p2_fromXc_Tr_FC_MU[2000];   //[NTr]
   Double_t        p2_fromXc_NIsoTr_ETA;
   Double_t        p2_fromXc_NIsoTr_PHI;
   Double_t        p2_fromXc_NIsoTr_TRTYPE;
   Int_t           p2_fromXc_NIsoTr_TRUEID;
   Int_t           p2_fromXc_NIsoTr_MC_MOTHER_ID;
   Int_t           p2_fromXc_NIsoTr_MC_MOTHER_KEY;
   Int_t           p2_fromXc_NIsoTr_MC_GD_MOTHER_ID;
   Int_t           p2_fromXc_NIsoTr_MC_GD_MOTHER_KEY;
   Int_t           p2_fromXc_NIsoTr_MC_GD_GD_MOTHER_ID;
   Int_t           p2_fromXc_NIsoTr_MC_GD_GD_MOTHER_KEY;
   Double_t        p2_fromXc_P;
   Double_t        p2_fromXc_PT;
   Double_t        p2_fromXc_PE;
   Double_t        p2_fromXc_PX;
   Double_t        p2_fromXc_PY;
   Double_t        p2_fromXc_PZ;
   Double_t        p2_fromXc_M;
   Int_t           p2_fromXc_ID;
   Double_t        p2_fromXc_PIDe;
   Double_t        p2_fromXc_PIDmu;
   Double_t        p2_fromXc_PIDK;
   Double_t        p2_fromXc_PIDp;
   Double_t        p2_fromXc_PIDd;
   Double_t        p2_fromXc_ProbNNe;
   Double_t        p2_fromXc_ProbNNk;
   Double_t        p2_fromXc_ProbNNp;
   Double_t        p2_fromXc_ProbNNpi;
   Double_t        p2_fromXc_ProbNNmu;
   Double_t        p2_fromXc_ProbNNd;
   Double_t        p2_fromXc_ProbNNghost;
   Bool_t          p2_fromXc_hasMuon;
   Bool_t          p2_fromXc_isMuon;
   Bool_t          p2_fromXc_hasRich;
   Bool_t          p2_fromXc_UsedRichAerogel;
   Bool_t          p2_fromXc_UsedRich1Gas;
   Bool_t          p2_fromXc_UsedRich2Gas;
   Bool_t          p2_fromXc_RichAboveElThres;
   Bool_t          p2_fromXc_RichAboveMuThres;
   Bool_t          p2_fromXc_RichAbovePiThres;
   Bool_t          p2_fromXc_RichAboveKaThres;
   Bool_t          p2_fromXc_RichAbovePrThres;
   Bool_t          p2_fromXc_hasCalo;
   Int_t           p2_fromXc_TRACK_Type;
   Int_t           p2_fromXc_TRACK_Key;
   Double_t        p2_fromXc_TRACK_CHI2NDOF;
   Double_t        p2_fromXc_TRACK_PCHI2;
   Double_t        p2_fromXc_TRACK_MatchCHI2;
   Double_t        p2_fromXc_TRACK_GhostProb;
   Double_t        p2_fromXc_TRACK_CloneDist;
   Double_t        p2_fromXc_TRACK_Likelihood;
   Int_t           p2_fromXc_TRUEID;
   Bool_t          p2_fromXc_PANC_fromB;
   Bool_t          p2_fromXc_PANC_fromD;
   Float_t         p2_fromXc_PANC_IDs[15];
   Float_t         p2_fromXc_PANC_Keys[15];
   Int_t           p2_fromXc_N_ANC;
   Double_t        p3_fromXc_ETA;
   Double_t        p3_fromXc_MC12TuneV2_ProbNNe;
   Double_t        p3_fromXc_MC12TuneV2_ProbNNmu;
   Double_t        p3_fromXc_MC12TuneV2_ProbNNpi;
   Double_t        p3_fromXc_MC12TuneV2_ProbNNk;
   Double_t        p3_fromXc_MC12TuneV2_ProbNNp;
   Double_t        p3_fromXc_MC12TuneV2_ProbNNghost;
   Double_t        p3_fromXc_MC12TuneV3_ProbNNe;
   Double_t        p3_fromXc_MC12TuneV3_ProbNNmu;
   Double_t        p3_fromXc_MC12TuneV3_ProbNNpi;
   Double_t        p3_fromXc_MC12TuneV3_ProbNNk;
   Double_t        p3_fromXc_MC12TuneV3_ProbNNp;
   Double_t        p3_fromXc_MC12TuneV3_ProbNNghost;
   Double_t        p3_fromXc_MC12TuneV4_ProbNNe;
   Double_t        p3_fromXc_MC12TuneV4_ProbNNmu;
   Double_t        p3_fromXc_MC12TuneV4_ProbNNpi;
   Double_t        p3_fromXc_MC12TuneV4_ProbNNk;
   Double_t        p3_fromXc_MC12TuneV4_ProbNNp;
   Double_t        p3_fromXc_MC12TuneV4_ProbNNghost;
   Double_t        p3_fromXc_MC15TuneV1_ProbNNe;
   Double_t        p3_fromXc_MC15TuneV1_ProbNNmu;
   Double_t        p3_fromXc_MC15TuneV1_ProbNNpi;
   Double_t        p3_fromXc_MC15TuneV1_ProbNNk;
   Double_t        p3_fromXc_MC15TuneV1_ProbNNp;
   Double_t        p3_fromXc_MC15TuneV1_ProbNNghost;
   Double_t        p3_fromXc_MINIP;
   Double_t        p3_fromXc_MINIPCHI2;
   Double_t        p3_fromXc_MINIPNEXTBEST;
   Double_t        p3_fromXc_MINIPCHI2NEXTBEST;
   Float_t         p3_fromXc_AllIP[100];   //[nPV]
   Float_t         p3_fromXc_AllIPchi2[100];   //[nPV]
   Float_t         p3_fromXc_AllDIRA[100];   //[nPV]
   Double_t        p3_fromXc_OWNPV_X;
   Double_t        p3_fromXc_OWNPV_Y;
   Double_t        p3_fromXc_OWNPV_Z;
   Double_t        p3_fromXc_OWNPV_XERR;
   Double_t        p3_fromXc_OWNPV_YERR;
   Double_t        p3_fromXc_OWNPV_ZERR;
   Double_t        p3_fromXc_OWNPV_CHI2;
   Int_t           p3_fromXc_OWNPV_NDOF;
   Float_t         p3_fromXc_OWNPV_COV_[3][3];
   Double_t        p3_fromXc_IP_OWNPV;
   Double_t        p3_fromXc_IPCHI2_OWNPV;
   Double_t        p3_fromXc_TOPPV_X;
   Double_t        p3_fromXc_TOPPV_Y;
   Double_t        p3_fromXc_TOPPV_Z;
   Double_t        p3_fromXc_TOPPV_XERR;
   Double_t        p3_fromXc_TOPPV_YERR;
   Double_t        p3_fromXc_TOPPV_ZERR;
   Double_t        p3_fromXc_TOPPV_CHI2;
   Int_t           p3_fromXc_TOPPV_NDOF;
   Float_t         p3_fromXc_TOPPV_COV_[3][3];
   Double_t        p3_fromXc_IP_TOPPV;
   Double_t        p3_fromXc_IPCHI2_TOPPV;
   Double_t        p3_fromXc_ORIVX_X;
   Double_t        p3_fromXc_ORIVX_Y;
   Double_t        p3_fromXc_ORIVX_Z;
   Double_t        p3_fromXc_ORIVX_XERR;
   Double_t        p3_fromXc_ORIVX_YERR;
   Double_t        p3_fromXc_ORIVX_ZERR;
   Double_t        p3_fromXc_ORIVX_CHI2;
   Int_t           p3_fromXc_ORIVX_NDOF;
   Float_t         p3_fromXc_ORIVX_COV_[3][3];
   Double_t        p3_fromXc_IP_ORIVX;
   Double_t        p3_fromXc_IPCHI2_ORIVX;
   Int_t           p3_fromXc_Nb_NIsoTr;
   Double_t        p3_fromXc_IsoMinBDT;
   Double_t        p3_fromXc_ConeIso;
   Double_t        p3_fromXc_PAIR_M;
   Double_t        p3_fromXc_NIso_PAIR_VtxChi2;
   Double_t        p3_fromXc_NIso_DCHI2;
   Double_t        p3_fromXc_NIso_DIS;
   Double_t        p3_fromXc_NIsoTr_VTXX;
   Double_t        p3_fromXc_NIsoTr_VTXY;
   Double_t        p3_fromXc_NIsoTr_VTXZ;
   Double_t        p3_fromXc_PAIR_IPchi2;
   Double_t        p3_fromXc_NIsoTr_PVDIS;
   Double_t        p3_fromXc_NIsoTr_SVDIS;
   Double_t        p3_fromXc_NIsoTr_DOCA;
   Double_t        p3_fromXc_NIsoTr_ANGLE;
   Double_t        p3_fromXc_NIsoTr_FC;
   Float_t         p3_fromXc_Tr_MinIsoBDT[2000];   //[NTr]
   Float_t         p3_fromXc_Tr_PAIR_VTXX[2000];   //[NTr]
   Float_t         p3_fromXc_Tr_PAIR_VTXY[2000];   //[NTr]
   Float_t         p3_fromXc_Tr_PAIR_VTXZ[2000];   //[NTr]
   Float_t         p3_fromXc_Tr_PAIR_VTCHI2NDOF[2000];   //[NTr]
   Float_t         p3_fromXc_Tr_FirstHitX[2000];   //[NTr]
   Float_t         p3_fromXc_Tr_FirstHitY[2000];   //[NTr]
   Float_t         p3_fromXc_Tr_FirstHitZ[2000];   //[NTr]
   Float_t         p3_fromXc_Tr_DCHI2[2000];   //[NTr]
   Float_t         p3_fromXc_Tr_DIS[2000];   //[NTr]
   Float_t         p3_fromXc_Tr_MATCHCHI2[2000];   //[NTr]
   Float_t         p3_fromXc_Tr_PVDIS[2000];   //[NTr]
   Float_t         p3_fromXc_Tr_SVDIS[2000];   //[NTr]
   Float_t         p3_fromXc_Tr_DOCA[2000];   //[NTr]
   Float_t         p3_fromXc_Tr_ANGLE[2000];   //[NTr]
   Float_t         p3_fromXc_Tr_FC_MU[2000];   //[NTr]
   Double_t        p3_fromXc_NIsoTr_ETA;
   Double_t        p3_fromXc_NIsoTr_PHI;
   Double_t        p3_fromXc_NIsoTr_TRTYPE;
   Int_t           p3_fromXc_NIsoTr_TRUEID;
   Int_t           p3_fromXc_NIsoTr_MC_MOTHER_ID;
   Int_t           p3_fromXc_NIsoTr_MC_MOTHER_KEY;
   Int_t           p3_fromXc_NIsoTr_MC_GD_MOTHER_ID;
   Int_t           p3_fromXc_NIsoTr_MC_GD_MOTHER_KEY;
   Int_t           p3_fromXc_NIsoTr_MC_GD_GD_MOTHER_ID;
   Int_t           p3_fromXc_NIsoTr_MC_GD_GD_MOTHER_KEY;
   Double_t        p3_fromXc_P;
   Double_t        p3_fromXc_PT;
   Double_t        p3_fromXc_PE;
   Double_t        p3_fromXc_PX;
   Double_t        p3_fromXc_PY;
   Double_t        p3_fromXc_PZ;
   Double_t        p3_fromXc_M;
   Int_t           p3_fromXc_ID;
   Double_t        p3_fromXc_PIDe;
   Double_t        p3_fromXc_PIDmu;
   Double_t        p3_fromXc_PIDK;
   Double_t        p3_fromXc_PIDp;
   Double_t        p3_fromXc_PIDd;
   Double_t        p3_fromXc_ProbNNe;
   Double_t        p3_fromXc_ProbNNk;
   Double_t        p3_fromXc_ProbNNp;
   Double_t        p3_fromXc_ProbNNpi;
   Double_t        p3_fromXc_ProbNNmu;
   Double_t        p3_fromXc_ProbNNd;
   Double_t        p3_fromXc_ProbNNghost;
   Bool_t          p3_fromXc_hasMuon;
   Bool_t          p3_fromXc_isMuon;
   Bool_t          p3_fromXc_hasRich;
   Bool_t          p3_fromXc_UsedRichAerogel;
   Bool_t          p3_fromXc_UsedRich1Gas;
   Bool_t          p3_fromXc_UsedRich2Gas;
   Bool_t          p3_fromXc_RichAboveElThres;
   Bool_t          p3_fromXc_RichAboveMuThres;
   Bool_t          p3_fromXc_RichAbovePiThres;
   Bool_t          p3_fromXc_RichAboveKaThres;
   Bool_t          p3_fromXc_RichAbovePrThres;
   Bool_t          p3_fromXc_hasCalo;
   Int_t           p3_fromXc_TRACK_Type;
   Int_t           p3_fromXc_TRACK_Key;
   Double_t        p3_fromXc_TRACK_CHI2NDOF;
   Double_t        p3_fromXc_TRACK_PCHI2;
   Double_t        p3_fromXc_TRACK_MatchCHI2;
   Double_t        p3_fromXc_TRACK_GhostProb;
   Double_t        p3_fromXc_TRACK_CloneDist;
   Double_t        p3_fromXc_TRACK_Likelihood;
   Int_t           p3_fromXc_TRUEID;
   Bool_t          p3_fromXc_PANC_fromB;
   Bool_t          p3_fromXc_PANC_fromD;
   Float_t         p3_fromXc_PANC_IDs[15];
   Float_t         p3_fromXc_PANC_Keys[15];
   Int_t           p3_fromXc_N_ANC;
   Double_t        Y_ETA;
   Double_t        Y_MINIP;
   Double_t        Y_MINIPCHI2;
   Double_t        Y_MINIPNEXTBEST;
   Double_t        Y_MINIPCHI2NEXTBEST;
   Float_t         Y_AllIP[100];   //[nPV]
   Float_t         Y_AllIPchi2[100];   //[nPV]
   Float_t         Y_AllDIRA[100];   //[nPV]
   Double_t        Y_ENDVERTEX_X;
   Double_t        Y_ENDVERTEX_Y;
   Double_t        Y_ENDVERTEX_Z;
   Double_t        Y_ENDVERTEX_XERR;
   Double_t        Y_ENDVERTEX_YERR;
   Double_t        Y_ENDVERTEX_ZERR;
   Double_t        Y_ENDVERTEX_CHI2;
   Int_t           Y_ENDVERTEX_NDOF;
   Float_t         Y_ENDVERTEX_COV_[3][3];
   Double_t        Y_OWNPV_X;
   Double_t        Y_OWNPV_Y;
   Double_t        Y_OWNPV_Z;
   Double_t        Y_OWNPV_XERR;
   Double_t        Y_OWNPV_YERR;
   Double_t        Y_OWNPV_ZERR;
   Double_t        Y_OWNPV_CHI2;
   Int_t           Y_OWNPV_NDOF;
   Float_t         Y_OWNPV_COV_[3][3];
   Double_t        Y_IP_OWNPV;
   Double_t        Y_IPCHI2_OWNPV;
   Double_t        Y_FD_OWNPV;
   Double_t        Y_FDCHI2_OWNPV;
   Double_t        Y_DIRA_OWNPV;
   Double_t        Y_TOPPV_X;
   Double_t        Y_TOPPV_Y;
   Double_t        Y_TOPPV_Z;
   Double_t        Y_TOPPV_XERR;
   Double_t        Y_TOPPV_YERR;
   Double_t        Y_TOPPV_ZERR;
   Double_t        Y_TOPPV_CHI2;
   Int_t           Y_TOPPV_NDOF;
   Float_t         Y_TOPPV_COV_[3][3];
   Double_t        Y_IP_TOPPV;
   Double_t        Y_IPCHI2_TOPPV;
   Double_t        Y_FD_TOPPV;
   Double_t        Y_FDCHI2_TOPPV;
   Double_t        Y_DIRA_TOPPV;
   Double_t        Y_ORIVX_X;
   Double_t        Y_ORIVX_Y;
   Double_t        Y_ORIVX_Z;
   Double_t        Y_ORIVX_XERR;
   Double_t        Y_ORIVX_YERR;
   Double_t        Y_ORIVX_ZERR;
   Double_t        Y_ORIVX_CHI2;
   Int_t           Y_ORIVX_NDOF;
   Float_t         Y_ORIVX_COV_[3][3];
   Double_t        Y_IP_ORIVX;
   Double_t        Y_IPCHI2_ORIVX;
   Double_t        Y_FD_ORIVX;
   Double_t        Y_FDCHI2_ORIVX;
   Double_t        Y_DIRA_ORIVX;
   Double_t        Y_P;
   Double_t        Y_PT;
   Double_t        Y_PE;
   Double_t        Y_PX;
   Double_t        Y_PY;
   Double_t        Y_PZ;
   Double_t        Y_MM;
   Double_t        Y_MMERR;
   Double_t        Y_M;
   Int_t           Y_BKGCAT;
   Int_t           Y_TRUEID;
   Int_t           Y_MC_MOTHER_ID;
   Int_t           Y_MC_MOTHER_KEY;
   Int_t           Y_MC_GD_MOTHER_ID;
   Int_t           Y_MC_GD_MOTHER_KEY;
   Int_t           Y_MC_GD_GD_MOTHER_ID;
   Int_t           Y_MC_GD_GD_MOTHER_KEY;
   Double_t        Y_TRUEP_E;
   Double_t        Y_TRUEP_X;
   Double_t        Y_TRUEP_Y;
   Double_t        Y_TRUEP_Z;
   Double_t        Y_TRUEPT;
   Double_t        Y_TRUEORIGINVERTEX_X;
   Double_t        Y_TRUEORIGINVERTEX_Y;
   Double_t        Y_TRUEORIGINVERTEX_Z;
   Double_t        Y_TRUEENDVERTEX_X;
   Double_t        Y_TRUEENDVERTEX_Y;
   Double_t        Y_TRUEENDVERTEX_Z;
   Bool_t          Y_TRUEISSTABLE;
   Double_t        Y_TRUETAU;
   Int_t           Y_ID;
   Double_t        Y_NumVtxWithinChi2WindowOneTrack;
   Double_t        Y_SmallestDeltaChi2OneTrack;
   Double_t        Y_SmallestDeltaChi2MassOneTrack;
   Double_t        Y_SmallestDeltaChi2TwoTracks;
   Double_t        Y_SmallestDeltaChi2MassTwoTracks;
   Double_t        Y_BPVVDR;
   Double_t        Y_DOCA1;
   Double_t        Y_DOCA2;
   Double_t        Y_DOCA3;
   Int_t           Y_0_20_cc_mult;
   Double_t        Y_0_20_cc_sPT;
   Double_t        Y_0_20_cc_vPT;
   Double_t        Y_0_20_cc_PX;
   Double_t        Y_0_20_cc_PY;
   Double_t        Y_0_20_cc_PZ;
   Double_t        Y_0_20_cc_asy_P;
   Double_t        Y_0_20_cc_asy_PT;
   Double_t        Y_0_20_cc_asy_PX;
   Double_t        Y_0_20_cc_asy_PY;
   Double_t        Y_0_20_cc_asy_PZ;
   Double_t        Y_0_20_cc_deltaEta;
   Double_t        Y_0_20_cc_deltaPhi;
   Double_t        Y_0_20_cc_IT;
   Int_t           Y_0_20_cc_maxPt_Q;
   Double_t        Y_0_20_cc_maxPt_PT;
   Double_t        Y_0_20_cc_maxPt_PX;
   Double_t        Y_0_20_cc_maxPt_PY;
   Double_t        Y_0_20_cc_maxPt_PZ;
   Double_t        Y_0_20_cc_maxPt_PE;
   Int_t           Y_0_20_nc_mult;
   Double_t        Y_0_20_nc_sPT;
   Double_t        Y_0_20_nc_vPT;
   Double_t        Y_0_20_nc_PX;
   Double_t        Y_0_20_nc_PY;
   Double_t        Y_0_20_nc_PZ;
   Double_t        Y_0_20_nc_avCL;
   Double_t        Y_0_20_nc_maxCL;
   Double_t        Y_0_20_nc_asy_P;
   Double_t        Y_0_20_nc_asy_PT;
   Double_t        Y_0_20_nc_asy_PX;
   Double_t        Y_0_20_nc_asy_PY;
   Double_t        Y_0_20_nc_asy_PZ;
   Double_t        Y_0_20_nc_deltaEta;
   Double_t        Y_0_20_nc_deltaPhi;
   Double_t        Y_0_20_nc_IT;
   Double_t        Y_0_20_nc_maxPt_PT;
   Double_t        Y_0_20_nc_maxPt_PX;
   Double_t        Y_0_20_nc_maxPt_PY;
   Double_t        Y_0_20_nc_maxPt_PZ;
   Double_t        Y_0_20_nc_H1;
   Double_t        Y_0_20_nc_H2;
   Double_t        Y_0_20_nc_H3;
   Double_t        Y_0_20_nc_H4;
   Double_t        Y_0_20_IT;
   Int_t           Y_0_30_cc_mult;
   Double_t        Y_0_30_cc_sPT;
   Double_t        Y_0_30_cc_vPT;
   Double_t        Y_0_30_cc_PX;
   Double_t        Y_0_30_cc_PY;
   Double_t        Y_0_30_cc_PZ;
   Double_t        Y_0_30_cc_asy_P;
   Double_t        Y_0_30_cc_asy_PT;
   Double_t        Y_0_30_cc_asy_PX;
   Double_t        Y_0_30_cc_asy_PY;
   Double_t        Y_0_30_cc_asy_PZ;
   Double_t        Y_0_30_cc_deltaEta;
   Double_t        Y_0_30_cc_deltaPhi;
   Double_t        Y_0_30_cc_IT;
   Int_t           Y_0_30_cc_maxPt_Q;
   Double_t        Y_0_30_cc_maxPt_PT;
   Double_t        Y_0_30_cc_maxPt_PX;
   Double_t        Y_0_30_cc_maxPt_PY;
   Double_t        Y_0_30_cc_maxPt_PZ;
   Double_t        Y_0_30_cc_maxPt_PE;
   Int_t           Y_0_30_nc_mult;
   Double_t        Y_0_30_nc_sPT;
   Double_t        Y_0_30_nc_vPT;
   Double_t        Y_0_30_nc_PX;
   Double_t        Y_0_30_nc_PY;
   Double_t        Y_0_30_nc_PZ;
   Double_t        Y_0_30_nc_avCL;
   Double_t        Y_0_30_nc_maxCL;
   Double_t        Y_0_30_nc_asy_P;
   Double_t        Y_0_30_nc_asy_PT;
   Double_t        Y_0_30_nc_asy_PX;
   Double_t        Y_0_30_nc_asy_PY;
   Double_t        Y_0_30_nc_asy_PZ;
   Double_t        Y_0_30_nc_deltaEta;
   Double_t        Y_0_30_nc_deltaPhi;
   Double_t        Y_0_30_nc_IT;
   Double_t        Y_0_30_nc_maxPt_PT;
   Double_t        Y_0_30_nc_maxPt_PX;
   Double_t        Y_0_30_nc_maxPt_PY;
   Double_t        Y_0_30_nc_maxPt_PZ;
   Double_t        Y_0_30_nc_H1;
   Double_t        Y_0_30_nc_H2;
   Double_t        Y_0_30_nc_H3;
   Double_t        Y_0_30_nc_H4;
   Double_t        Y_0_30_IT;
   Int_t           Y_0_40_cc_mult;
   Double_t        Y_0_40_cc_sPT;
   Double_t        Y_0_40_cc_vPT;
   Double_t        Y_0_40_cc_PX;
   Double_t        Y_0_40_cc_PY;
   Double_t        Y_0_40_cc_PZ;
   Double_t        Y_0_40_cc_asy_P;
   Double_t        Y_0_40_cc_asy_PT;
   Double_t        Y_0_40_cc_asy_PX;
   Double_t        Y_0_40_cc_asy_PY;
   Double_t        Y_0_40_cc_asy_PZ;
   Double_t        Y_0_40_cc_deltaEta;
   Double_t        Y_0_40_cc_deltaPhi;
   Double_t        Y_0_40_cc_IT;
   Int_t           Y_0_40_cc_maxPt_Q;
   Double_t        Y_0_40_cc_maxPt_PT;
   Double_t        Y_0_40_cc_maxPt_PX;
   Double_t        Y_0_40_cc_maxPt_PY;
   Double_t        Y_0_40_cc_maxPt_PZ;
   Double_t        Y_0_40_cc_maxPt_PE;
   Int_t           Y_0_40_nc_mult;
   Double_t        Y_0_40_nc_sPT;
   Double_t        Y_0_40_nc_vPT;
   Double_t        Y_0_40_nc_PX;
   Double_t        Y_0_40_nc_PY;
   Double_t        Y_0_40_nc_PZ;
   Double_t        Y_0_40_nc_avCL;
   Double_t        Y_0_40_nc_maxCL;
   Double_t        Y_0_40_nc_asy_P;
   Double_t        Y_0_40_nc_asy_PT;
   Double_t        Y_0_40_nc_asy_PX;
   Double_t        Y_0_40_nc_asy_PY;
   Double_t        Y_0_40_nc_asy_PZ;
   Double_t        Y_0_40_nc_deltaEta;
   Double_t        Y_0_40_nc_deltaPhi;
   Double_t        Y_0_40_nc_IT;
   Double_t        Y_0_40_nc_maxPt_PT;
   Double_t        Y_0_40_nc_maxPt_PX;
   Double_t        Y_0_40_nc_maxPt_PY;
   Double_t        Y_0_40_nc_maxPt_PZ;
   Double_t        Y_0_40_nc_H1;
   Double_t        Y_0_40_nc_H2;
   Double_t        Y_0_40_nc_H3;
   Double_t        Y_0_40_nc_H4;
   Double_t        Y_0_40_IT;
   Int_t           Y_pi0_mult;
   Int_t           Y_Pi0_ArrayLength;
   Float_t         Y_MasshPi0[1000];   //[Y_Pi0_ArrayLength]
   Float_t         Y_Pi0_PX[1000];   //[Y_Pi0_ArrayLength]
   Float_t         Y_Pi0_PY[1000];   //[Y_Pi0_ArrayLength]
   Float_t         Y_Pi0_PZ[1000];   //[Y_Pi0_ArrayLength]
   Float_t         Y_Pi0_E[1000];   //[Y_Pi0_ArrayLength]
   Float_t         Y_Pi0_M[1000];   //[Y_Pi0_ArrayLength]
   Float_t         Y_Pi0_DeltaR[1000];   //[Y_Pi0_ArrayLength]
   Float_t         Y_Pi0Ph1_CL[1000];   //[Y_Pi0_ArrayLength]
   Float_t         Y_Pi0Ph2_CL[1000];   //[Y_Pi0_ArrayLength]
   Double_t        p1_fromY_ETA;
   Double_t        p1_fromY_MC12TuneV2_ProbNNe;
   Double_t        p1_fromY_MC12TuneV2_ProbNNmu;
   Double_t        p1_fromY_MC12TuneV2_ProbNNpi;
   Double_t        p1_fromY_MC12TuneV2_ProbNNk;
   Double_t        p1_fromY_MC12TuneV2_ProbNNp;
   Double_t        p1_fromY_MC12TuneV2_ProbNNghost;
   Double_t        p1_fromY_MC12TuneV3_ProbNNe;
   Double_t        p1_fromY_MC12TuneV3_ProbNNmu;
   Double_t        p1_fromY_MC12TuneV3_ProbNNpi;
   Double_t        p1_fromY_MC12TuneV3_ProbNNk;
   Double_t        p1_fromY_MC12TuneV3_ProbNNp;
   Double_t        p1_fromY_MC12TuneV3_ProbNNghost;
   Double_t        p1_fromY_MC12TuneV4_ProbNNe;
   Double_t        p1_fromY_MC12TuneV4_ProbNNmu;
   Double_t        p1_fromY_MC12TuneV4_ProbNNpi;
   Double_t        p1_fromY_MC12TuneV4_ProbNNk;
   Double_t        p1_fromY_MC12TuneV4_ProbNNp;
   Double_t        p1_fromY_MC12TuneV4_ProbNNghost;
   Double_t        p1_fromY_MC15TuneV1_ProbNNe;
   Double_t        p1_fromY_MC15TuneV1_ProbNNmu;
   Double_t        p1_fromY_MC15TuneV1_ProbNNpi;
   Double_t        p1_fromY_MC15TuneV1_ProbNNk;
   Double_t        p1_fromY_MC15TuneV1_ProbNNp;
   Double_t        p1_fromY_MC15TuneV1_ProbNNghost;
   Double_t        p1_fromY_MINIP;
   Double_t        p1_fromY_MINIPCHI2;
   Double_t        p1_fromY_MINIPNEXTBEST;
   Double_t        p1_fromY_MINIPCHI2NEXTBEST;
   Float_t         p1_fromY_AllIP[100];   //[nPV]
   Float_t         p1_fromY_AllIPchi2[100];   //[nPV]
   Float_t         p1_fromY_AllDIRA[100];   //[nPV]
   Double_t        p1_fromY_OWNPV_X;
   Double_t        p1_fromY_OWNPV_Y;
   Double_t        p1_fromY_OWNPV_Z;
   Double_t        p1_fromY_OWNPV_XERR;
   Double_t        p1_fromY_OWNPV_YERR;
   Double_t        p1_fromY_OWNPV_ZERR;
   Double_t        p1_fromY_OWNPV_CHI2;
   Int_t           p1_fromY_OWNPV_NDOF;
   Float_t         p1_fromY_OWNPV_COV_[3][3];
   Double_t        p1_fromY_IP_OWNPV;
   Double_t        p1_fromY_IPCHI2_OWNPV;
   Double_t        p1_fromY_TOPPV_X;
   Double_t        p1_fromY_TOPPV_Y;
   Double_t        p1_fromY_TOPPV_Z;
   Double_t        p1_fromY_TOPPV_XERR;
   Double_t        p1_fromY_TOPPV_YERR;
   Double_t        p1_fromY_TOPPV_ZERR;
   Double_t        p1_fromY_TOPPV_CHI2;
   Int_t           p1_fromY_TOPPV_NDOF;
   Float_t         p1_fromY_TOPPV_COV_[3][3];
   Double_t        p1_fromY_IP_TOPPV;
   Double_t        p1_fromY_IPCHI2_TOPPV;
   Double_t        p1_fromY_ORIVX_X;
   Double_t        p1_fromY_ORIVX_Y;
   Double_t        p1_fromY_ORIVX_Z;
   Double_t        p1_fromY_ORIVX_XERR;
   Double_t        p1_fromY_ORIVX_YERR;
   Double_t        p1_fromY_ORIVX_ZERR;
   Double_t        p1_fromY_ORIVX_CHI2;
   Int_t           p1_fromY_ORIVX_NDOF;
   Float_t         p1_fromY_ORIVX_COV_[3][3];
   Double_t        p1_fromY_IP_ORIVX;
   Double_t        p1_fromY_IPCHI2_ORIVX;
   Int_t           p1_fromY_Nb_NIsoTr;
   Double_t        p1_fromY_IsoMinBDT;
   Double_t        p1_fromY_ConeIso;
   Double_t        p1_fromY_PAIR_M;
   Double_t        p1_fromY_NIso_PAIR_VtxChi2;
   Double_t        p1_fromY_NIso_DCHI2;
   Double_t        p1_fromY_NIso_DIS;
   Double_t        p1_fromY_NIsoTr_VTXX;
   Double_t        p1_fromY_NIsoTr_VTXY;
   Double_t        p1_fromY_NIsoTr_VTXZ;
   Double_t        p1_fromY_PAIR_IPchi2;
   Double_t        p1_fromY_NIsoTr_PVDIS;
   Double_t        p1_fromY_NIsoTr_SVDIS;
   Double_t        p1_fromY_NIsoTr_DOCA;
   Double_t        p1_fromY_NIsoTr_ANGLE;
   Double_t        p1_fromY_NIsoTr_FC;
   Float_t         p1_fromY_Tr_MinIsoBDT[2000];   //[NTr]
   Float_t         p1_fromY_Tr_PAIR_VTXX[2000];   //[NTr]
   Float_t         p1_fromY_Tr_PAIR_VTXY[2000];   //[NTr]
   Float_t         p1_fromY_Tr_PAIR_VTXZ[2000];   //[NTr]
   Float_t         p1_fromY_Tr_PAIR_VTCHI2NDOF[2000];   //[NTr]
   Float_t         p1_fromY_Tr_FirstHitX[2000];   //[NTr]
   Float_t         p1_fromY_Tr_FirstHitY[2000];   //[NTr]
   Float_t         p1_fromY_Tr_FirstHitZ[2000];   //[NTr]
   Float_t         p1_fromY_Tr_DCHI2[2000];   //[NTr]
   Float_t         p1_fromY_Tr_DIS[2000];   //[NTr]
   Float_t         p1_fromY_Tr_MATCHCHI2[2000];   //[NTr]
   Float_t         p1_fromY_Tr_PVDIS[2000];   //[NTr]
   Float_t         p1_fromY_Tr_SVDIS[2000];   //[NTr]
   Float_t         p1_fromY_Tr_DOCA[2000];   //[NTr]
   Float_t         p1_fromY_Tr_ANGLE[2000];   //[NTr]
   Float_t         p1_fromY_Tr_FC_MU[2000];   //[NTr]
   Double_t        p1_fromY_NIsoTr_ETA;
   Double_t        p1_fromY_NIsoTr_PHI;
   Double_t        p1_fromY_NIsoTr_TRTYPE;
   Int_t           p1_fromY_NIsoTr_TRUEID;
   Int_t           p1_fromY_NIsoTr_MC_MOTHER_ID;
   Int_t           p1_fromY_NIsoTr_MC_MOTHER_KEY;
   Int_t           p1_fromY_NIsoTr_MC_GD_MOTHER_ID;
   Int_t           p1_fromY_NIsoTr_MC_GD_MOTHER_KEY;
   Int_t           p1_fromY_NIsoTr_MC_GD_GD_MOTHER_ID;
   Int_t           p1_fromY_NIsoTr_MC_GD_GD_MOTHER_KEY;
   Double_t        p1_fromY_P;
   Double_t        p1_fromY_PT;
   Double_t        p1_fromY_PE;
   Double_t        p1_fromY_PX;
   Double_t        p1_fromY_PY;
   Double_t        p1_fromY_PZ;
   Double_t        p1_fromY_M;
   Int_t           p1_fromY_ID;
   Double_t        p1_fromY_PIDe;
   Double_t        p1_fromY_PIDmu;
   Double_t        p1_fromY_PIDK;
   Double_t        p1_fromY_PIDp;
   Double_t        p1_fromY_PIDd;
   Double_t        p1_fromY_ProbNNe;
   Double_t        p1_fromY_ProbNNk;
   Double_t        p1_fromY_ProbNNp;
   Double_t        p1_fromY_ProbNNpi;
   Double_t        p1_fromY_ProbNNmu;
   Double_t        p1_fromY_ProbNNd;
   Double_t        p1_fromY_ProbNNghost;
   Bool_t          p1_fromY_hasMuon;
   Bool_t          p1_fromY_isMuon;
   Bool_t          p1_fromY_hasRich;
   Bool_t          p1_fromY_UsedRichAerogel;
   Bool_t          p1_fromY_UsedRich1Gas;
   Bool_t          p1_fromY_UsedRich2Gas;
   Bool_t          p1_fromY_RichAboveElThres;
   Bool_t          p1_fromY_RichAboveMuThres;
   Bool_t          p1_fromY_RichAbovePiThres;
   Bool_t          p1_fromY_RichAboveKaThres;
   Bool_t          p1_fromY_RichAbovePrThres;
   Bool_t          p1_fromY_hasCalo;
   Int_t           p1_fromY_TRACK_Type;
   Int_t           p1_fromY_TRACK_Key;
   Double_t        p1_fromY_TRACK_CHI2NDOF;
   Double_t        p1_fromY_TRACK_PCHI2;
   Double_t        p1_fromY_TRACK_MatchCHI2;
   Double_t        p1_fromY_TRACK_GhostProb;
   Double_t        p1_fromY_TRACK_CloneDist;
   Double_t        p1_fromY_TRACK_Likelihood;
   Int_t           p1_fromY_TRUEID;
   Bool_t          p1_fromY_PANC_fromB;
   Bool_t          p1_fromY_PANC_fromD;
   Float_t         p1_fromY_PANC_IDs[15];
   Float_t         p1_fromY_PANC_Keys[15];
   Int_t           p1_fromY_N_ANC;
   Double_t        p2_fromY_ETA;
   Double_t        p2_fromY_MC12TuneV2_ProbNNe;
   Double_t        p2_fromY_MC12TuneV2_ProbNNmu;
   Double_t        p2_fromY_MC12TuneV2_ProbNNpi;
   Double_t        p2_fromY_MC12TuneV2_ProbNNk;
   Double_t        p2_fromY_MC12TuneV2_ProbNNp;
   Double_t        p2_fromY_MC12TuneV2_ProbNNghost;
   Double_t        p2_fromY_MC12TuneV3_ProbNNe;
   Double_t        p2_fromY_MC12TuneV3_ProbNNmu;
   Double_t        p2_fromY_MC12TuneV3_ProbNNpi;
   Double_t        p2_fromY_MC12TuneV3_ProbNNk;
   Double_t        p2_fromY_MC12TuneV3_ProbNNp;
   Double_t        p2_fromY_MC12TuneV3_ProbNNghost;
   Double_t        p2_fromY_MC12TuneV4_ProbNNe;
   Double_t        p2_fromY_MC12TuneV4_ProbNNmu;
   Double_t        p2_fromY_MC12TuneV4_ProbNNpi;
   Double_t        p2_fromY_MC12TuneV4_ProbNNk;
   Double_t        p2_fromY_MC12TuneV4_ProbNNp;
   Double_t        p2_fromY_MC12TuneV4_ProbNNghost;
   Double_t        p2_fromY_MC15TuneV1_ProbNNe;
   Double_t        p2_fromY_MC15TuneV1_ProbNNmu;
   Double_t        p2_fromY_MC15TuneV1_ProbNNpi;
   Double_t        p2_fromY_MC15TuneV1_ProbNNk;
   Double_t        p2_fromY_MC15TuneV1_ProbNNp;
   Double_t        p2_fromY_MC15TuneV1_ProbNNghost;
   Double_t        p2_fromY_MINIP;
   Double_t        p2_fromY_MINIPCHI2;
   Double_t        p2_fromY_MINIPNEXTBEST;
   Double_t        p2_fromY_MINIPCHI2NEXTBEST;
   Float_t         p2_fromY_AllIP[100];   //[nPV]
   Float_t         p2_fromY_AllIPchi2[100];   //[nPV]
   Float_t         p2_fromY_AllDIRA[100];   //[nPV]
   Double_t        p2_fromY_OWNPV_X;
   Double_t        p2_fromY_OWNPV_Y;
   Double_t        p2_fromY_OWNPV_Z;
   Double_t        p2_fromY_OWNPV_XERR;
   Double_t        p2_fromY_OWNPV_YERR;
   Double_t        p2_fromY_OWNPV_ZERR;
   Double_t        p2_fromY_OWNPV_CHI2;
   Int_t           p2_fromY_OWNPV_NDOF;
   Float_t         p2_fromY_OWNPV_COV_[3][3];
   Double_t        p2_fromY_IP_OWNPV;
   Double_t        p2_fromY_IPCHI2_OWNPV;
   Double_t        p2_fromY_TOPPV_X;
   Double_t        p2_fromY_TOPPV_Y;
   Double_t        p2_fromY_TOPPV_Z;
   Double_t        p2_fromY_TOPPV_XERR;
   Double_t        p2_fromY_TOPPV_YERR;
   Double_t        p2_fromY_TOPPV_ZERR;
   Double_t        p2_fromY_TOPPV_CHI2;
   Int_t           p2_fromY_TOPPV_NDOF;
   Float_t         p2_fromY_TOPPV_COV_[3][3];
   Double_t        p2_fromY_IP_TOPPV;
   Double_t        p2_fromY_IPCHI2_TOPPV;
   Double_t        p2_fromY_ORIVX_X;
   Double_t        p2_fromY_ORIVX_Y;
   Double_t        p2_fromY_ORIVX_Z;
   Double_t        p2_fromY_ORIVX_XERR;
   Double_t        p2_fromY_ORIVX_YERR;
   Double_t        p2_fromY_ORIVX_ZERR;
   Double_t        p2_fromY_ORIVX_CHI2;
   Int_t           p2_fromY_ORIVX_NDOF;
   Float_t         p2_fromY_ORIVX_COV_[3][3];
   Double_t        p2_fromY_IP_ORIVX;
   Double_t        p2_fromY_IPCHI2_ORIVX;
   Int_t           p2_fromY_Nb_NIsoTr;
   Double_t        p2_fromY_IsoMinBDT;
   Double_t        p2_fromY_ConeIso;
   Double_t        p2_fromY_PAIR_M;
   Double_t        p2_fromY_NIso_PAIR_VtxChi2;
   Double_t        p2_fromY_NIso_DCHI2;
   Double_t        p2_fromY_NIso_DIS;
   Double_t        p2_fromY_NIsoTr_VTXX;
   Double_t        p2_fromY_NIsoTr_VTXY;
   Double_t        p2_fromY_NIsoTr_VTXZ;
   Double_t        p2_fromY_PAIR_IPchi2;
   Double_t        p2_fromY_NIsoTr_PVDIS;
   Double_t        p2_fromY_NIsoTr_SVDIS;
   Double_t        p2_fromY_NIsoTr_DOCA;
   Double_t        p2_fromY_NIsoTr_ANGLE;
   Double_t        p2_fromY_NIsoTr_FC;
   Float_t         p2_fromY_Tr_MinIsoBDT[2000];   //[NTr]
   Float_t         p2_fromY_Tr_PAIR_VTXX[2000];   //[NTr]
   Float_t         p2_fromY_Tr_PAIR_VTXY[2000];   //[NTr]
   Float_t         p2_fromY_Tr_PAIR_VTXZ[2000];   //[NTr]
   Float_t         p2_fromY_Tr_PAIR_VTCHI2NDOF[2000];   //[NTr]
   Float_t         p2_fromY_Tr_FirstHitX[2000];   //[NTr]
   Float_t         p2_fromY_Tr_FirstHitY[2000];   //[NTr]
   Float_t         p2_fromY_Tr_FirstHitZ[2000];   //[NTr]
   Float_t         p2_fromY_Tr_DCHI2[2000];   //[NTr]
   Float_t         p2_fromY_Tr_DIS[2000];   //[NTr]
   Float_t         p2_fromY_Tr_MATCHCHI2[2000];   //[NTr]
   Float_t         p2_fromY_Tr_PVDIS[2000];   //[NTr]
   Float_t         p2_fromY_Tr_SVDIS[2000];   //[NTr]
   Float_t         p2_fromY_Tr_DOCA[2000];   //[NTr]
   Float_t         p2_fromY_Tr_ANGLE[2000];   //[NTr]
   Float_t         p2_fromY_Tr_FC_MU[2000];   //[NTr]
   Double_t        p2_fromY_NIsoTr_ETA;
   Double_t        p2_fromY_NIsoTr_PHI;
   Double_t        p2_fromY_NIsoTr_TRTYPE;
   Int_t           p2_fromY_NIsoTr_TRUEID;
   Int_t           p2_fromY_NIsoTr_MC_MOTHER_ID;
   Int_t           p2_fromY_NIsoTr_MC_MOTHER_KEY;
   Int_t           p2_fromY_NIsoTr_MC_GD_MOTHER_ID;
   Int_t           p2_fromY_NIsoTr_MC_GD_MOTHER_KEY;
   Int_t           p2_fromY_NIsoTr_MC_GD_GD_MOTHER_ID;
   Int_t           p2_fromY_NIsoTr_MC_GD_GD_MOTHER_KEY;
   Double_t        p2_fromY_P;
   Double_t        p2_fromY_PT;
   Double_t        p2_fromY_PE;
   Double_t        p2_fromY_PX;
   Double_t        p2_fromY_PY;
   Double_t        p2_fromY_PZ;
   Double_t        p2_fromY_M;
   Int_t           p2_fromY_ID;
   Double_t        p2_fromY_PIDe;
   Double_t        p2_fromY_PIDmu;
   Double_t        p2_fromY_PIDK;
   Double_t        p2_fromY_PIDp;
   Double_t        p2_fromY_PIDd;
   Double_t        p2_fromY_ProbNNe;
   Double_t        p2_fromY_ProbNNk;
   Double_t        p2_fromY_ProbNNp;
   Double_t        p2_fromY_ProbNNpi;
   Double_t        p2_fromY_ProbNNmu;
   Double_t        p2_fromY_ProbNNd;
   Double_t        p2_fromY_ProbNNghost;
   Bool_t          p2_fromY_hasMuon;
   Bool_t          p2_fromY_isMuon;
   Bool_t          p2_fromY_hasRich;
   Bool_t          p2_fromY_UsedRichAerogel;
   Bool_t          p2_fromY_UsedRich1Gas;
   Bool_t          p2_fromY_UsedRich2Gas;
   Bool_t          p2_fromY_RichAboveElThres;
   Bool_t          p2_fromY_RichAboveMuThres;
   Bool_t          p2_fromY_RichAbovePiThres;
   Bool_t          p2_fromY_RichAboveKaThres;
   Bool_t          p2_fromY_RichAbovePrThres;
   Bool_t          p2_fromY_hasCalo;
   Int_t           p2_fromY_TRACK_Type;
   Int_t           p2_fromY_TRACK_Key;
   Double_t        p2_fromY_TRACK_CHI2NDOF;
   Double_t        p2_fromY_TRACK_PCHI2;
   Double_t        p2_fromY_TRACK_MatchCHI2;
   Double_t        p2_fromY_TRACK_GhostProb;
   Double_t        p2_fromY_TRACK_CloneDist;
   Double_t        p2_fromY_TRACK_Likelihood;
   Int_t           p2_fromY_TRUEID;
   Bool_t          p2_fromY_PANC_fromB;
   Bool_t          p2_fromY_PANC_fromD;
   Float_t         p2_fromY_PANC_IDs[15];
   Float_t         p2_fromY_PANC_Keys[15];
   Int_t           p2_fromY_N_ANC;
   Double_t        p3_fromY_ETA;
   Double_t        p3_fromY_MC12TuneV2_ProbNNe;
   Double_t        p3_fromY_MC12TuneV2_ProbNNmu;
   Double_t        p3_fromY_MC12TuneV2_ProbNNpi;
   Double_t        p3_fromY_MC12TuneV2_ProbNNk;
   Double_t        p3_fromY_MC12TuneV2_ProbNNp;
   Double_t        p3_fromY_MC12TuneV2_ProbNNghost;
   Double_t        p3_fromY_MC12TuneV3_ProbNNe;
   Double_t        p3_fromY_MC12TuneV3_ProbNNmu;
   Double_t        p3_fromY_MC12TuneV3_ProbNNpi;
   Double_t        p3_fromY_MC12TuneV3_ProbNNk;
   Double_t        p3_fromY_MC12TuneV3_ProbNNp;
   Double_t        p3_fromY_MC12TuneV3_ProbNNghost;
   Double_t        p3_fromY_MC12TuneV4_ProbNNe;
   Double_t        p3_fromY_MC12TuneV4_ProbNNmu;
   Double_t        p3_fromY_MC12TuneV4_ProbNNpi;
   Double_t        p3_fromY_MC12TuneV4_ProbNNk;
   Double_t        p3_fromY_MC12TuneV4_ProbNNp;
   Double_t        p3_fromY_MC12TuneV4_ProbNNghost;
   Double_t        p3_fromY_MC15TuneV1_ProbNNe;
   Double_t        p3_fromY_MC15TuneV1_ProbNNmu;
   Double_t        p3_fromY_MC15TuneV1_ProbNNpi;
   Double_t        p3_fromY_MC15TuneV1_ProbNNk;
   Double_t        p3_fromY_MC15TuneV1_ProbNNp;
   Double_t        p3_fromY_MC15TuneV1_ProbNNghost;
   Double_t        p3_fromY_MINIP;
   Double_t        p3_fromY_MINIPCHI2;
   Double_t        p3_fromY_MINIPNEXTBEST;
   Double_t        p3_fromY_MINIPCHI2NEXTBEST;
   Float_t         p3_fromY_AllIP[100];   //[nPV]
   Float_t         p3_fromY_AllIPchi2[100];   //[nPV]
   Float_t         p3_fromY_AllDIRA[100];   //[nPV]
   Double_t        p3_fromY_OWNPV_X;
   Double_t        p3_fromY_OWNPV_Y;
   Double_t        p3_fromY_OWNPV_Z;
   Double_t        p3_fromY_OWNPV_XERR;
   Double_t        p3_fromY_OWNPV_YERR;
   Double_t        p3_fromY_OWNPV_ZERR;
   Double_t        p3_fromY_OWNPV_CHI2;
   Int_t           p3_fromY_OWNPV_NDOF;
   Float_t         p3_fromY_OWNPV_COV_[3][3];
   Double_t        p3_fromY_IP_OWNPV;
   Double_t        p3_fromY_IPCHI2_OWNPV;
   Double_t        p3_fromY_TOPPV_X;
   Double_t        p3_fromY_TOPPV_Y;
   Double_t        p3_fromY_TOPPV_Z;
   Double_t        p3_fromY_TOPPV_XERR;
   Double_t        p3_fromY_TOPPV_YERR;
   Double_t        p3_fromY_TOPPV_ZERR;
   Double_t        p3_fromY_TOPPV_CHI2;
   Int_t           p3_fromY_TOPPV_NDOF;
   Float_t         p3_fromY_TOPPV_COV_[3][3];
   Double_t        p3_fromY_IP_TOPPV;
   Double_t        p3_fromY_IPCHI2_TOPPV;
   Double_t        p3_fromY_ORIVX_X;
   Double_t        p3_fromY_ORIVX_Y;
   Double_t        p3_fromY_ORIVX_Z;
   Double_t        p3_fromY_ORIVX_XERR;
   Double_t        p3_fromY_ORIVX_YERR;
   Double_t        p3_fromY_ORIVX_ZERR;
   Double_t        p3_fromY_ORIVX_CHI2;
   Int_t           p3_fromY_ORIVX_NDOF;
   Float_t         p3_fromY_ORIVX_COV_[3][3];
   Double_t        p3_fromY_IP_ORIVX;
   Double_t        p3_fromY_IPCHI2_ORIVX;
   Int_t           p3_fromY_Nb_NIsoTr;
   Double_t        p3_fromY_IsoMinBDT;
   Double_t        p3_fromY_ConeIso;
   Double_t        p3_fromY_PAIR_M;
   Double_t        p3_fromY_NIso_PAIR_VtxChi2;
   Double_t        p3_fromY_NIso_DCHI2;
   Double_t        p3_fromY_NIso_DIS;
   Double_t        p3_fromY_NIsoTr_VTXX;
   Double_t        p3_fromY_NIsoTr_VTXY;
   Double_t        p3_fromY_NIsoTr_VTXZ;
   Double_t        p3_fromY_PAIR_IPchi2;
   Double_t        p3_fromY_NIsoTr_PVDIS;
   Double_t        p3_fromY_NIsoTr_SVDIS;
   Double_t        p3_fromY_NIsoTr_DOCA;
   Double_t        p3_fromY_NIsoTr_ANGLE;
   Double_t        p3_fromY_NIsoTr_FC;
   Float_t         p3_fromY_Tr_MinIsoBDT[2000];   //[NTr]
   Float_t         p3_fromY_Tr_PAIR_VTXX[2000];   //[NTr]
   Float_t         p3_fromY_Tr_PAIR_VTXY[2000];   //[NTr]
   Float_t         p3_fromY_Tr_PAIR_VTXZ[2000];   //[NTr]
   Float_t         p3_fromY_Tr_PAIR_VTCHI2NDOF[2000];   //[NTr]
   Float_t         p3_fromY_Tr_FirstHitX[2000];   //[NTr]
   Float_t         p3_fromY_Tr_FirstHitY[2000];   //[NTr]
   Float_t         p3_fromY_Tr_FirstHitZ[2000];   //[NTr]
   Float_t         p3_fromY_Tr_DCHI2[2000];   //[NTr]
   Float_t         p3_fromY_Tr_DIS[2000];   //[NTr]
   Float_t         p3_fromY_Tr_MATCHCHI2[2000];   //[NTr]
   Float_t         p3_fromY_Tr_PVDIS[2000];   //[NTr]
   Float_t         p3_fromY_Tr_SVDIS[2000];   //[NTr]
   Float_t         p3_fromY_Tr_DOCA[2000];   //[NTr]
   Float_t         p3_fromY_Tr_ANGLE[2000];   //[NTr]
   Float_t         p3_fromY_Tr_FC_MU[2000];   //[NTr]
   Double_t        p3_fromY_NIsoTr_ETA;
   Double_t        p3_fromY_NIsoTr_PHI;
   Double_t        p3_fromY_NIsoTr_TRTYPE;
   Int_t           p3_fromY_NIsoTr_TRUEID;
   Int_t           p3_fromY_NIsoTr_MC_MOTHER_ID;
   Int_t           p3_fromY_NIsoTr_MC_MOTHER_KEY;
   Int_t           p3_fromY_NIsoTr_MC_GD_MOTHER_ID;
   Int_t           p3_fromY_NIsoTr_MC_GD_MOTHER_KEY;
   Int_t           p3_fromY_NIsoTr_MC_GD_GD_MOTHER_ID;
   Int_t           p3_fromY_NIsoTr_MC_GD_GD_MOTHER_KEY;
   Double_t        p3_fromY_P;
   Double_t        p3_fromY_PT;
   Double_t        p3_fromY_PE;
   Double_t        p3_fromY_PX;
   Double_t        p3_fromY_PY;
   Double_t        p3_fromY_PZ;
   Double_t        p3_fromY_M;
   Int_t           p3_fromY_ID;
   Double_t        p3_fromY_PIDe;
   Double_t        p3_fromY_PIDmu;
   Double_t        p3_fromY_PIDK;
   Double_t        p3_fromY_PIDp;
   Double_t        p3_fromY_PIDd;
   Double_t        p3_fromY_ProbNNe;
   Double_t        p3_fromY_ProbNNk;
   Double_t        p3_fromY_ProbNNp;
   Double_t        p3_fromY_ProbNNpi;
   Double_t        p3_fromY_ProbNNmu;
   Double_t        p3_fromY_ProbNNd;
   Double_t        p3_fromY_ProbNNghost;
   Bool_t          p3_fromY_hasMuon;
   Bool_t          p3_fromY_isMuon;
   Bool_t          p3_fromY_hasRich;
   Bool_t          p3_fromY_UsedRichAerogel;
   Bool_t          p3_fromY_UsedRich1Gas;
   Bool_t          p3_fromY_UsedRich2Gas;
   Bool_t          p3_fromY_RichAboveElThres;
   Bool_t          p3_fromY_RichAboveMuThres;
   Bool_t          p3_fromY_RichAbovePiThres;
   Bool_t          p3_fromY_RichAboveKaThres;
   Bool_t          p3_fromY_RichAbovePrThres;
   Bool_t          p3_fromY_hasCalo;
   Int_t           p3_fromY_TRACK_Type;
   Int_t           p3_fromY_TRACK_Key;
   Double_t        p3_fromY_TRACK_CHI2NDOF;
   Double_t        p3_fromY_TRACK_PCHI2;
   Double_t        p3_fromY_TRACK_MatchCHI2;
   Double_t        p3_fromY_TRACK_GhostProb;
   Double_t        p3_fromY_TRACK_CloneDist;
   Double_t        p3_fromY_TRACK_Likelihood;
   Int_t           p3_fromY_TRUEID;
   Bool_t          p3_fromY_PANC_fromB;
   Bool_t          p3_fromY_PANC_fromD;
   Float_t         p3_fromY_PANC_IDs[15];
   Float_t         p3_fromY_PANC_Keys[15];
   Int_t           p3_fromY_N_ANC;
   UInt_t          nCandidate;
   ULong64_t       totCandidates;
   ULong64_t       EventInSequence;
   UInt_t          runNumber;
   ULong64_t       eventNumber;
   UInt_t          BCID;
   Int_t           BCType;
   UInt_t          OdinTCK;
   UInt_t          L0DUTCK;
   UInt_t          HLT1TCK;
   UInt_t          HLT2TCK;
   ULong64_t       GpsTime;
   Short_t         Polarity;
   Float_t         PVX[100];   //[nPV]
   Float_t         PVY[100];   //[nPV]
   Float_t         PVZ[100];   //[nPV]
   Float_t         PVXERR[100];   //[nPV]
   Float_t         PVYERR[100];   //[nPV]
   Float_t         PVZERR[100];   //[nPV]
   Float_t         PVCHI2[100];   //[nPV]
   Float_t         PVNDOF[100];   //[nPV]
   Float_t         PVNTRACKS[100];   //[nPV]
   Int_t           nPVs;
   Int_t           nTracks;
   Int_t           nLongTracks;
   Int_t           nDownstreamTracks;
   Int_t           nUpstreamTracks;
   Int_t           nVeloTracks;
   Int_t           nTTracks;
   Int_t           nBackTracks;
   Int_t           nRich1Hits;
   Int_t           nRich2Hits;
   Int_t           nVeloClusters;
   Int_t           nITClusters;
   Int_t           nTTClusters;
   Int_t           nOTClusters;
   Int_t           nSPDHits;
   Int_t           nMuonCoordsS0;
   Int_t           nMuonCoordsS1;
   Int_t           nMuonCoordsS2;
   Int_t           nMuonCoordsS3;
   Int_t           nMuonCoordsS4;
   Int_t           nMuonTracks;
   Int_t           L0Global;
   UInt_t          Hlt1Global;
   UInt_t          Hlt2Global;
   Int_t           L0HadronDecision;
   Int_t           L0GlobalDecision;
   UInt_t          L0nSelections;
   Int_t           Hlt1GlobalDecision;
   Int_t           Hlt1TrackAllL0Decision;
   Int_t           Hlt1TrackAllL0TightDecision;
   UInt_t          Hlt1nSelections;
   Int_t           Hlt2GlobalDecision;
   Int_t           Hlt2Topo2BodyBBDTDecision;
   Int_t           Hlt2Topo3BodyBBDTDecision;
   Int_t           Hlt2Topo4BodyBBDTDecision;
   Int_t           Hlt2Topo2BodySimpleDecision;
   Int_t           Hlt2Topo3BodySimpleDecision;
   Int_t           Hlt2Topo4BodySimpleDecision;
   Int_t           Hlt2IncPhiDecision;
   Int_t           Hlt2IncPhiSidebandsDecision;
   Int_t           Hlt2CharmHadD2HHHDecision;
   Int_t           Hlt2CharmHadD2HHHWideMassDecision;
   UInt_t          Hlt2nSelections;
   Int_t           MaxRoutingBits;
   Float_t         RoutingBits[64];   //[MaxRoutingBits]
   Double_t        p1_fromXc_PIDK_corr;
   Double_t        p1_fromXc_PIDp_corr;
   Double_t        p2_fromXc_PIDK_corr;
   Double_t        p2_fromXc_PIDp_corr;
   Double_t        p3_fromXc_PIDK_corr;
   Double_t        p3_fromXc_PIDp_corr;
   Double_t        p1_fromY_PIDK_corr;
   Double_t        p1_fromY_PIDp_corr;
   Double_t        p2_fromY_PIDK_corr;
   Double_t        p2_fromY_PIDp_corr;
   Double_t        p3_fromY_PIDK_corr;
   Double_t        p3_fromY_PIDp_corr;
   // Double_t        p1_fromXc_PIDK_pidgen_default;
   // Double_t        p1_fromXc_PIDp_pidgen_default;
   // Double_t        p2_fromXc_PIDK_pidgen_default;
   // Double_t        p2_fromXc_PIDp_pidgen_default;
   // Double_t        p3_fromXc_PIDK_pidgen_default;
   // Double_t        p3_fromXc_PIDp_pidgen_default;
   
   // Double_t        p1_fromY_PIDK_pidgen_default;
   // Double_t        p1_fromY_PIDp_pidgen_default;
   // Double_t        p2_fromY_PIDK_pidgen_default;
   // Double_t        p2_fromY_PIDp_pidgen_default;
   // Double_t        p3_fromY_PIDK_pidgen_default;
   // Double_t        p3_fromY_PIDp_pidgen_default;
   
   Double_t        p1_fromY_K_PIDK_pidgen_default;
   Double_t        p1_fromY_pi_PIDK_pidgen_default;
   Double_t        p2_fromY_K_PIDK_pidgen_default;
   Double_t        p2_fromY_pi_PIDK_pidgen_default;
   Double_t        p3_fromY_K_PIDK_pidgen_default;
   Double_t        p3_fromY_pi_PIDK_pidgen_default;

   // List of branches
   TBranch        *b_B_ETA;   //!
   TBranch        *b_B_MINIP;   //!
   TBranch        *b_B_MINIPCHI2;   //!
   TBranch        *b_B_MINIPNEXTBEST;   //!
   TBranch        *b_B_MINIPCHI2NEXTBEST;   //!
   TBranch        *b_nPV;   //!
   TBranch        *b_B_AllIP;   //!
   TBranch        *b_B_AllIPchi2;   //!
   TBranch        *b_B_AllDIRA;   //!
   TBranch        *b_B_ENDVERTEX_X;   //!
   TBranch        *b_B_ENDVERTEX_Y;   //!
   TBranch        *b_B_ENDVERTEX_Z;   //!
   TBranch        *b_B_ENDVERTEX_XERR;   //!
   TBranch        *b_B_ENDVERTEX_YERR;   //!
   TBranch        *b_B_ENDVERTEX_ZERR;   //!
   TBranch        *b_B_ENDVERTEX_CHI2;   //!
   TBranch        *b_B_ENDVERTEX_NDOF;   //!
   TBranch        *b_B_ENDVERTEX_COV_;   //!
   TBranch        *b_B_OWNPV_X;   //!
   TBranch        *b_B_OWNPV_Y;   //!
   TBranch        *b_B_OWNPV_Z;   //!
   TBranch        *b_B_OWNPV_XERR;   //!
   TBranch        *b_B_OWNPV_YERR;   //!
   TBranch        *b_B_OWNPV_ZERR;   //!
   TBranch        *b_B_OWNPV_CHI2;   //!
   TBranch        *b_B_OWNPV_NDOF;   //!
   TBranch        *b_B_OWNPV_COV_;   //!
   TBranch        *b_B_IP_OWNPV;   //!
   TBranch        *b_B_IPCHI2_OWNPV;   //!
   TBranch        *b_B_FD_OWNPV;   //!
   TBranch        *b_B_FDCHI2_OWNPV;   //!
   TBranch        *b_B_DIRA_OWNPV;   //!
   TBranch        *b_B_TOPPV_X;   //!
   TBranch        *b_B_TOPPV_Y;   //!
   TBranch        *b_B_TOPPV_Z;   //!
   TBranch        *b_B_TOPPV_XERR;   //!
   TBranch        *b_B_TOPPV_YERR;   //!
   TBranch        *b_B_TOPPV_ZERR;   //!
   TBranch        *b_B_TOPPV_CHI2;   //!
   TBranch        *b_B_TOPPV_NDOF;   //!
   TBranch        *b_B_TOPPV_COV_;   //!
   TBranch        *b_B_IP_TOPPV;   //!
   TBranch        *b_B_IPCHI2_TOPPV;   //!
   TBranch        *b_B_FD_TOPPV;   //!
   TBranch        *b_B_FDCHI2_TOPPV;   //!
   TBranch        *b_B_DIRA_TOPPV;   //!
   TBranch        *b_B_P;   //!
   TBranch        *b_B_PT;   //!
   TBranch        *b_B_PE;   //!
   TBranch        *b_B_PX;   //!
   TBranch        *b_B_PY;   //!
   TBranch        *b_B_PZ;   //!
   TBranch        *b_B_MM;   //!
   TBranch        *b_B_MMERR;   //!
   TBranch        *b_B_M;   //!
   TBranch        *b_B_BKGCAT;   //!
   TBranch        *b_B_TRUEID;   //!
   TBranch        *b_B_MC_MOTHER_ID;   //!
   TBranch        *b_B_MC_MOTHER_KEY;   //!
   TBranch        *b_B_MC_GD_MOTHER_ID;   //!
   TBranch        *b_B_MC_GD_MOTHER_KEY;   //!
   TBranch        *b_B_MC_GD_GD_MOTHER_ID;   //!
   TBranch        *b_B_MC_GD_GD_MOTHER_KEY;   //!
   TBranch        *b_B_TRUEP_E;   //!
   TBranch        *b_B_TRUEP_X;   //!
   TBranch        *b_B_TRUEP_Y;   //!
   TBranch        *b_B_TRUEP_Z;   //!
   TBranch        *b_B_TRUEPT;   //!
   TBranch        *b_B_TRUEORIGINVERTEX_X;   //!
   TBranch        *b_B_TRUEORIGINVERTEX_Y;   //!
   TBranch        *b_B_TRUEORIGINVERTEX_Z;   //!
   TBranch        *b_B_TRUEENDVERTEX_X;   //!
   TBranch        *b_B_TRUEENDVERTEX_Y;   //!
   TBranch        *b_B_TRUEENDVERTEX_Z;   //!
   TBranch        *b_B_TRUEISSTABLE;   //!
   TBranch        *b_B_TRUETAU;   //!
   TBranch        *b_B_ID;   //!
   TBranch        *b_B_NumVtxWithinChi2WindowOneTrack;   //!
   TBranch        *b_B_SmallestDeltaChi2OneTrack;   //!
   TBranch        *b_B_SmallestDeltaChi2MassOneTrack;   //!
   TBranch        *b_B_SmallestDeltaChi2TwoTracks;   //!
   TBranch        *b_B_SmallestDeltaChi2MassTwoTracks;   //!
   TBranch        *b_B_BPVVDR;   //!
   TBranch        *b_B_DOCA1;   //!
   TBranch        *b_B_TAU;   //!
   TBranch        *b_B_TAUERR;   //!
   TBranch        *b_B_DTF_nPV;   //!
   TBranch        *b_B_DTF_D_splus_Kplus_0_ID;   //!
   TBranch        *b_B_DTF_D_splus_Kplus_0_PE;   //!
   TBranch        *b_B_DTF_D_splus_Kplus_0_PX;   //!
   TBranch        *b_B_DTF_D_splus_Kplus_0_PY;   //!
   TBranch        *b_B_DTF_D_splus_Kplus_0_PZ;   //!
   TBranch        *b_B_DTF_D_splus_Kplus_ID;   //!
   TBranch        *b_B_DTF_D_splus_Kplus_PE;   //!
   TBranch        *b_B_DTF_D_splus_Kplus_PX;   //!
   TBranch        *b_B_DTF_D_splus_Kplus_PY;   //!
   TBranch        *b_B_DTF_D_splus_Kplus_PZ;   //!
   TBranch        *b_B_DTF_D_splus_M;   //!
   TBranch        *b_B_DTF_D_splus_MERR;   //!
   TBranch        *b_B_DTF_D_splus_P;   //!
   TBranch        *b_B_DTF_D_splus_PERR;   //!
   TBranch        *b_B_DTF_D_splus_ctau;   //!
   TBranch        *b_B_DTF_D_splus_ctauErr;   //!
   TBranch        *b_B_DTF_D_splus_decayLength;   //!
   TBranch        *b_B_DTF_D_splus_decayLengthErr;   //!
   TBranch        *b_B_DTF_D_splus_piplus_ID;   //!
   TBranch        *b_B_DTF_D_splus_piplus_PE;   //!
   TBranch        *b_B_DTF_D_splus_piplus_PX;   //!
   TBranch        *b_B_DTF_D_splus_piplus_PY;   //!
   TBranch        *b_B_DTF_D_splus_piplus_PZ;   //!
   TBranch        *b_B_DTF_M;   //!
   TBranch        *b_B_DTF_MERR;   //!
   TBranch        *b_B_DTF_P;   //!
   TBranch        *b_B_DTF_PERR;   //!
   TBranch        *b_B_DTF_chi2;   //!
   TBranch        *b_B_DTF_nDOF;   //!
   TBranch        *b_B_DTF_nIter;   //!
   TBranch        *b_B_DTF_status;   //!
   TBranch        *b_B_DTF_tauminus_M;   //!
   TBranch        *b_B_DTF_tauminus_MERR;   //!
   TBranch        *b_B_DTF_tauminus_P;   //!
   TBranch        *b_B_DTF_tauminus_PERR;   //!
   TBranch        *b_B_DTF_tauminus_ctau;   //!
   TBranch        *b_B_DTF_tauminus_ctauErr;   //!
   TBranch        *b_B_DTF_tauminus_decayLength;   //!
   TBranch        *b_B_DTF_tauminus_decayLengthErr;   //!
   TBranch        *b_B_DTF_tauminus_piplus_0_ID;   //!
   TBranch        *b_B_DTF_tauminus_piplus_0_PE;   //!
   TBranch        *b_B_DTF_tauminus_piplus_0_PX;   //!
   TBranch        *b_B_DTF_tauminus_piplus_0_PY;   //!
   TBranch        *b_B_DTF_tauminus_piplus_0_PZ;   //!
   TBranch        *b_B_DTF_tauminus_piplus_1_ID;   //!
   TBranch        *b_B_DTF_tauminus_piplus_1_PE;   //!
   TBranch        *b_B_DTF_tauminus_piplus_1_PX;   //!
   TBranch        *b_B_DTF_tauminus_piplus_1_PY;   //!
   TBranch        *b_B_DTF_tauminus_piplus_1_PZ;   //!
   TBranch        *b_B_DTF_tauminus_piplus_ID;   //!
   TBranch        *b_B_DTF_tauminus_piplus_PE;   //!
   TBranch        *b_B_DTF_tauminus_piplus_PX;   //!
   TBranch        *b_B_DTF_tauminus_piplus_PY;   //!
   TBranch        *b_B_DTF_tauminus_piplus_PZ;   //!
   TBranch        *b_B_DTFPVDs_nPV;   //!
   TBranch        *b_B_DTFPVDs_D_splus_Kplus_0_ID;   //!
   TBranch        *b_B_DTFPVDs_D_splus_Kplus_0_PE;   //!
   TBranch        *b_B_DTFPVDs_D_splus_Kplus_0_PX;   //!
   TBranch        *b_B_DTFPVDs_D_splus_Kplus_0_PY;   //!
   TBranch        *b_B_DTFPVDs_D_splus_Kplus_0_PZ;   //!
   TBranch        *b_B_DTFPVDs_D_splus_Kplus_ID;   //!
   TBranch        *b_B_DTFPVDs_D_splus_Kplus_PE;   //!
   TBranch        *b_B_DTFPVDs_D_splus_Kplus_PX;   //!
   TBranch        *b_B_DTFPVDs_D_splus_Kplus_PY;   //!
   TBranch        *b_B_DTFPVDs_D_splus_Kplus_PZ;   //!
   TBranch        *b_B_DTFPVDs_D_splus_M;   //!
   TBranch        *b_B_DTFPVDs_D_splus_MERR;   //!
   TBranch        *b_B_DTFPVDs_D_splus_P;   //!
   TBranch        *b_B_DTFPVDs_D_splus_PERR;   //!
   TBranch        *b_B_DTFPVDs_D_splus_ctau;   //!
   TBranch        *b_B_DTFPVDs_D_splus_ctauErr;   //!
   TBranch        *b_B_DTFPVDs_D_splus_decayLength;   //!
   TBranch        *b_B_DTFPVDs_D_splus_decayLengthErr;   //!
   TBranch        *b_B_DTFPVDs_D_splus_piplus_ID;   //!
   TBranch        *b_B_DTFPVDs_D_splus_piplus_PE;   //!
   TBranch        *b_B_DTFPVDs_D_splus_piplus_PX;   //!
   TBranch        *b_B_DTFPVDs_D_splus_piplus_PY;   //!
   TBranch        *b_B_DTFPVDs_D_splus_piplus_PZ;   //!
   TBranch        *b_B_DTFPVDs_M;   //!
   TBranch        *b_B_DTFPVDs_MERR;   //!
   TBranch        *b_B_DTFPVDs_P;   //!
   TBranch        *b_B_DTFPVDs_PERR;   //!
   TBranch        *b_B_DTFPVDs_PV_X;   //!
   TBranch        *b_B_DTFPVDs_PV_Y;   //!
   TBranch        *b_B_DTFPVDs_PV_Z;   //!
   TBranch        *b_B_DTFPVDs_PV_key;   //!
   TBranch        *b_B_DTFPVDs_chi2;   //!
   TBranch        *b_B_DTFPVDs_ctau;   //!
   TBranch        *b_B_DTFPVDs_ctauErr;   //!
   TBranch        *b_B_DTFPVDs_decayLength;   //!
   TBranch        *b_B_DTFPVDs_decayLengthErr;   //!
   TBranch        *b_B_DTFPVDs_nDOF;   //!
   TBranch        *b_B_DTFPVDs_nIter;   //!
   TBranch        *b_B_DTFPVDs_status;   //!
   TBranch        *b_B_DTFPVDs_tauminus_M;   //!
   TBranch        *b_B_DTFPVDs_tauminus_MERR;   //!
   TBranch        *b_B_DTFPVDs_tauminus_P;   //!
   TBranch        *b_B_DTFPVDs_tauminus_PERR;   //!
   TBranch        *b_B_DTFPVDs_tauminus_ctau;   //!
   TBranch        *b_B_DTFPVDs_tauminus_ctauErr;   //!
   TBranch        *b_B_DTFPVDs_tauminus_decayLength;   //!
   TBranch        *b_B_DTFPVDs_tauminus_decayLengthErr;   //!
   TBranch        *b_B_DTFPVDs_tauminus_piplus_0_ID;   //!
   TBranch        *b_B_DTFPVDs_tauminus_piplus_0_PE;   //!
   TBranch        *b_B_DTFPVDs_tauminus_piplus_0_PX;   //!
   TBranch        *b_B_DTFPVDs_tauminus_piplus_0_PY;   //!
   TBranch        *b_B_DTFPVDs_tauminus_piplus_0_PZ;   //!
   TBranch        *b_B_DTFPVDs_tauminus_piplus_1_ID;   //!
   TBranch        *b_B_DTFPVDs_tauminus_piplus_1_PE;   //!
   TBranch        *b_B_DTFPVDs_tauminus_piplus_1_PX;   //!
   TBranch        *b_B_DTFPVDs_tauminus_piplus_1_PY;   //!
   TBranch        *b_B_DTFPVDs_tauminus_piplus_1_PZ;   //!
   TBranch        *b_B_DTFPVDs_tauminus_piplus_ID;   //!
   TBranch        *b_B_DTFPVDs_tauminus_piplus_PE;   //!
   TBranch        *b_B_DTFPVDs_tauminus_piplus_PX;   //!
   TBranch        *b_B_DTFPVDs_tauminus_piplus_PY;   //!
   TBranch        *b_B_DTFPVDs_tauminus_piplus_PZ;   //!
   TBranch        *b_B_L0Global_Dec;   //!
   TBranch        *b_B_L0Global_TIS;   //!
   TBranch        *b_B_L0Global_TOS;   //!
   TBranch        *b_B_Hlt1Global_Dec;   //!
   TBranch        *b_B_Hlt1Global_TIS;   //!
   TBranch        *b_B_Hlt1Global_TOS;   //!
   TBranch        *b_B_Hlt1Phys_Dec;   //!
   TBranch        *b_B_Hlt1Phys_TIS;   //!
   TBranch        *b_B_Hlt1Phys_TOS;   //!
   TBranch        *b_B_Hlt2Global_Dec;   //!
   TBranch        *b_B_Hlt2Global_TIS;   //!
   TBranch        *b_B_Hlt2Global_TOS;   //!
   TBranch        *b_B_Hlt2Phys_Dec;   //!
   TBranch        *b_B_Hlt2Phys_TIS;   //!
   TBranch        *b_B_Hlt2Phys_TOS;   //!
   TBranch        *b_B_L0HadronDecision_Dec;   //!
   TBranch        *b_B_L0HadronDecision_TIS;   //!
   TBranch        *b_B_L0HadronDecision_TOS;   //!
   TBranch        *b_B_L0GlobalDecision_Dec;   //!
   TBranch        *b_B_L0GlobalDecision_TIS;   //!
   TBranch        *b_B_L0GlobalDecision_TOS;   //!
   TBranch        *b_B_Hlt1GlobalDecision_Dec;   //!
   TBranch        *b_B_Hlt1GlobalDecision_TIS;   //!
   TBranch        *b_B_Hlt1GlobalDecision_TOS;   //!
   TBranch        *b_B_Hlt1TrackAllL0Decision_Dec;   //!
   TBranch        *b_B_Hlt1TrackAllL0Decision_TIS;   //!
   TBranch        *b_B_Hlt1TrackAllL0Decision_TOS;   //!
   TBranch        *b_B_Hlt1TrackAllL0TightDecision_Dec;   //!
   TBranch        *b_B_Hlt1TrackAllL0TightDecision_TIS;   //!
   TBranch        *b_B_Hlt1TrackAllL0TightDecision_TOS;   //!
   TBranch        *b_B_Hlt2GlobalDecision_Dec;   //!
   TBranch        *b_B_Hlt2GlobalDecision_TIS;   //!
   TBranch        *b_B_Hlt2GlobalDecision_TOS;   //!
   TBranch        *b_B_Hlt2Topo2BodyBBDTDecision_Dec;   //!
   TBranch        *b_B_Hlt2Topo2BodyBBDTDecision_TIS;   //!
   TBranch        *b_B_Hlt2Topo2BodyBBDTDecision_TOS;   //!
   TBranch        *b_B_Hlt2Topo3BodyBBDTDecision_Dec;   //!
   TBranch        *b_B_Hlt2Topo3BodyBBDTDecision_TIS;   //!
   TBranch        *b_B_Hlt2Topo3BodyBBDTDecision_TOS;   //!
   TBranch        *b_B_Hlt2Topo4BodyBBDTDecision_Dec;   //!
   TBranch        *b_B_Hlt2Topo4BodyBBDTDecision_TIS;   //!
   TBranch        *b_B_Hlt2Topo4BodyBBDTDecision_TOS;   //!
   TBranch        *b_B_Hlt2Topo2BodySimpleDecision_Dec;   //!
   TBranch        *b_B_Hlt2Topo2BodySimpleDecision_TIS;   //!
   TBranch        *b_B_Hlt2Topo2BodySimpleDecision_TOS;   //!
   TBranch        *b_B_Hlt2Topo3BodySimpleDecision_Dec;   //!
   TBranch        *b_B_Hlt2Topo3BodySimpleDecision_TIS;   //!
   TBranch        *b_B_Hlt2Topo3BodySimpleDecision_TOS;   //!
   TBranch        *b_B_Hlt2Topo4BodySimpleDecision_Dec;   //!
   TBranch        *b_B_Hlt2Topo4BodySimpleDecision_TIS;   //!
   TBranch        *b_B_Hlt2Topo4BodySimpleDecision_TOS;   //!
   TBranch        *b_B_Hlt2IncPhiDecision_Dec;   //!
   TBranch        *b_B_Hlt2IncPhiDecision_TIS;   //!
   TBranch        *b_B_Hlt2IncPhiDecision_TOS;   //!
   TBranch        *b_B_Hlt2IncPhiSidebandsDecision_Dec;   //!
   TBranch        *b_B_Hlt2IncPhiSidebandsDecision_TIS;   //!
   TBranch        *b_B_Hlt2IncPhiSidebandsDecision_TOS;   //!
   TBranch        *b_B_Hlt2CharmHadD2HHHDecision_Dec;   //!
   TBranch        *b_B_Hlt2CharmHadD2HHHDecision_TIS;   //!
   TBranch        *b_B_Hlt2CharmHadD2HHHDecision_TOS;   //!
   TBranch        *b_B_Hlt2CharmHadD2HHHWideMassDecision_Dec;   //!
   TBranch        *b_B_Hlt2CharmHadD2HHHWideMassDecision_TIS;   //!
   TBranch        *b_B_Hlt2CharmHadD2HHHWideMassDecision_TOS;   //!
   TBranch        *b_Xc_ETA;   //!
   TBranch        *b_Xc_MINIP;   //!
   TBranch        *b_Xc_MINIPCHI2;   //!
   TBranch        *b_Xc_MINIPNEXTBEST;   //!
   TBranch        *b_Xc_MINIPCHI2NEXTBEST;   //!
   TBranch        *b_Xc_AllIP;   //!
   TBranch        *b_Xc_AllIPchi2;   //!
   TBranch        *b_Xc_AllDIRA;   //!
   TBranch        *b_Xc_ENDVERTEX_X;   //!
   TBranch        *b_Xc_ENDVERTEX_Y;   //!
   TBranch        *b_Xc_ENDVERTEX_Z;   //!
   TBranch        *b_Xc_ENDVERTEX_XERR;   //!
   TBranch        *b_Xc_ENDVERTEX_YERR;   //!
   TBranch        *b_Xc_ENDVERTEX_ZERR;   //!
   TBranch        *b_Xc_ENDVERTEX_CHI2;   //!
   TBranch        *b_Xc_ENDVERTEX_NDOF;   //!
   TBranch        *b_Xc_ENDVERTEX_COV_;   //!
   TBranch        *b_Xc_OWNPV_X;   //!
   TBranch        *b_Xc_OWNPV_Y;   //!
   TBranch        *b_Xc_OWNPV_Z;   //!
   TBranch        *b_Xc_OWNPV_XERR;   //!
   TBranch        *b_Xc_OWNPV_YERR;   //!
   TBranch        *b_Xc_OWNPV_ZERR;   //!
   TBranch        *b_Xc_OWNPV_CHI2;   //!
   TBranch        *b_Xc_OWNPV_NDOF;   //!
   TBranch        *b_Xc_OWNPV_COV_;   //!
   TBranch        *b_Xc_IP_OWNPV;   //!
   TBranch        *b_Xc_IPCHI2_OWNPV;   //!
   TBranch        *b_Xc_FD_OWNPV;   //!
   TBranch        *b_Xc_FDCHI2_OWNPV;   //!
   TBranch        *b_Xc_DIRA_OWNPV;   //!
   TBranch        *b_Xc_TOPPV_X;   //!
   TBranch        *b_Xc_TOPPV_Y;   //!
   TBranch        *b_Xc_TOPPV_Z;   //!
   TBranch        *b_Xc_TOPPV_XERR;   //!
   TBranch        *b_Xc_TOPPV_YERR;   //!
   TBranch        *b_Xc_TOPPV_ZERR;   //!
   TBranch        *b_Xc_TOPPV_CHI2;   //!
   TBranch        *b_Xc_TOPPV_NDOF;   //!
   TBranch        *b_Xc_TOPPV_COV_;   //!
   TBranch        *b_Xc_IP_TOPPV;   //!
   TBranch        *b_Xc_IPCHI2_TOPPV;   //!
   TBranch        *b_Xc_FD_TOPPV;   //!
   TBranch        *b_Xc_FDCHI2_TOPPV;   //!
   TBranch        *b_Xc_DIRA_TOPPV;   //!
   TBranch        *b_Xc_ORIVX_X;   //!
   TBranch        *b_Xc_ORIVX_Y;   //!
   TBranch        *b_Xc_ORIVX_Z;   //!
   TBranch        *b_Xc_ORIVX_XERR;   //!
   TBranch        *b_Xc_ORIVX_YERR;   //!
   TBranch        *b_Xc_ORIVX_ZERR;   //!
   TBranch        *b_Xc_ORIVX_CHI2;   //!
   TBranch        *b_Xc_ORIVX_NDOF;   //!
   TBranch        *b_Xc_ORIVX_COV_;   //!
   TBranch        *b_Xc_IP_ORIVX;   //!
   TBranch        *b_Xc_IPCHI2_ORIVX;   //!
   TBranch        *b_Xc_FD_ORIVX;   //!
   TBranch        *b_Xc_FDCHI2_ORIVX;   //!
   TBranch        *b_Xc_DIRA_ORIVX;   //!
   TBranch        *b_Xc_P;   //!
   TBranch        *b_Xc_PT;   //!
   TBranch        *b_Xc_PE;   //!
   TBranch        *b_Xc_PX;   //!
   TBranch        *b_Xc_PY;   //!
   TBranch        *b_Xc_PZ;   //!
   TBranch        *b_Xc_MM;   //!
   TBranch        *b_Xc_MMERR;   //!
   TBranch        *b_Xc_M;   //!
   TBranch        *b_Xc_BKGCAT;   //!
   TBranch        *b_Xc_TRUEID;   //!
   TBranch        *b_Xc_MC_MOTHER_ID;   //!
   TBranch        *b_Xc_MC_MOTHER_KEY;   //!
   TBranch        *b_Xc_MC_GD_MOTHER_ID;   //!
   TBranch        *b_Xc_MC_GD_MOTHER_KEY;   //!
   TBranch        *b_Xc_MC_GD_GD_MOTHER_ID;   //!
   TBranch        *b_Xc_MC_GD_GD_MOTHER_KEY;   //!
   TBranch        *b_Xc_TRUEP_E;   //!
   TBranch        *b_Xc_TRUEP_X;   //!
   TBranch        *b_Xc_TRUEP_Y;   //!
   TBranch        *b_Xc_TRUEP_Z;   //!
   TBranch        *b_Xc_TRUEPT;   //!
   TBranch        *b_Xc_TRUEORIGINVERTEX_X;   //!
   TBranch        *b_Xc_TRUEORIGINVERTEX_Y;   //!
   TBranch        *b_Xc_TRUEORIGINVERTEX_Z;   //!
   TBranch        *b_Xc_TRUEENDVERTEX_X;   //!
   TBranch        *b_Xc_TRUEENDVERTEX_Y;   //!
   TBranch        *b_Xc_TRUEENDVERTEX_Z;   //!
   TBranch        *b_Xc_TRUEISSTABLE;   //!
   TBranch        *b_Xc_TRUETAU;   //!
   TBranch        *b_Xc_ID;   //!
   TBranch        *b_Xc_NumVtxWithinChi2WindowOneTrack;   //!
   TBranch        *b_Xc_SmallestDeltaChi2OneTrack;   //!
   TBranch        *b_Xc_SmallestDeltaChi2MassOneTrack;   //!
   TBranch        *b_Xc_SmallestDeltaChi2TwoTracks;   //!
   TBranch        *b_Xc_SmallestDeltaChi2MassTwoTracks;   //!
   TBranch        *b_Xc_BPVVDR;   //!
   TBranch        *b_Xc_DOCA1;   //!
   TBranch        *b_Xc_DOCA2;   //!
   TBranch        *b_Xc_DOCA3;   //!
   TBranch        *b_Xc_0_20_nc_mult;   //!
   TBranch        *b_Xc_0_20_nc_sPT;   //!
   TBranch        *b_Xc_0_20_nc_vPT;   //!
   TBranch        *b_Xc_0_20_nc_PX;   //!
   TBranch        *b_Xc_0_20_nc_PY;   //!
   TBranch        *b_Xc_0_20_nc_PZ;   //!
   TBranch        *b_Xc_0_20_nc_avCL;   //!
   TBranch        *b_Xc_0_20_nc_maxCL;   //!
   TBranch        *b_Xc_0_20_nc_asy_P;   //!
   TBranch        *b_Xc_0_20_nc_asy_PT;   //!
   TBranch        *b_Xc_0_20_nc_asy_PX;   //!
   TBranch        *b_Xc_0_20_nc_asy_PY;   //!
   TBranch        *b_Xc_0_20_nc_asy_PZ;   //!
   TBranch        *b_Xc_0_20_nc_deltaEta;   //!
   TBranch        *b_Xc_0_20_nc_deltaPhi;   //!
   TBranch        *b_Xc_0_20_nc_IT;   //!
   TBranch        *b_Xc_0_20_nc_maxPt_PT;   //!
   TBranch        *b_Xc_0_20_nc_maxPt_PX;   //!
   TBranch        *b_Xc_0_20_nc_maxPt_PY;   //!
   TBranch        *b_Xc_0_20_nc_maxPt_PZ;   //!
   TBranch        *b_Xc_0_20_nc_H1;   //!
   TBranch        *b_Xc_0_20_nc_H2;   //!
   TBranch        *b_Xc_0_20_nc_H3;   //!
   TBranch        *b_Xc_0_20_nc_H4;   //!
   TBranch        *b_Xc_L0Global_Dec;   //!
   TBranch        *b_Xc_L0Global_TIS;   //!
   TBranch        *b_Xc_L0Global_TOS;   //!
   TBranch        *b_Xc_Hlt1Global_Dec;   //!
   TBranch        *b_Xc_Hlt1Global_TIS;   //!
   TBranch        *b_Xc_Hlt1Global_TOS;   //!
   TBranch        *b_Xc_Hlt1Phys_Dec;   //!
   TBranch        *b_Xc_Hlt1Phys_TIS;   //!
   TBranch        *b_Xc_Hlt1Phys_TOS;   //!
   TBranch        *b_Xc_Hlt2Global_Dec;   //!
   TBranch        *b_Xc_Hlt2Global_TIS;   //!
   TBranch        *b_Xc_Hlt2Global_TOS;   //!
   TBranch        *b_Xc_Hlt2Phys_Dec;   //!
   TBranch        *b_Xc_Hlt2Phys_TIS;   //!
   TBranch        *b_Xc_Hlt2Phys_TOS;   //!
   TBranch        *b_Xc_L0HadronDecision_Dec;   //!
   TBranch        *b_Xc_L0HadronDecision_TIS;   //!
   TBranch        *b_Xc_L0HadronDecision_TOS;   //!
   TBranch        *b_Xc_L0GlobalDecision_Dec;   //!
   TBranch        *b_Xc_L0GlobalDecision_TIS;   //!
   TBranch        *b_Xc_L0GlobalDecision_TOS;   //!
   TBranch        *b_Xc_Hlt1GlobalDecision_Dec;   //!
   TBranch        *b_Xc_Hlt1GlobalDecision_TIS;   //!
   TBranch        *b_Xc_Hlt1GlobalDecision_TOS;   //!
   TBranch        *b_Xc_Hlt1TrackAllL0Decision_Dec;   //!
   TBranch        *b_Xc_Hlt1TrackAllL0Decision_TIS;   //!
   TBranch        *b_Xc_Hlt1TrackAllL0Decision_TOS;   //!
   TBranch        *b_Xc_Hlt1TrackAllL0TightDecision_Dec;   //!
   TBranch        *b_Xc_Hlt1TrackAllL0TightDecision_TIS;   //!
   TBranch        *b_Xc_Hlt1TrackAllL0TightDecision_TOS;   //!
   TBranch        *b_Xc_Hlt2GlobalDecision_Dec;   //!
   TBranch        *b_Xc_Hlt2GlobalDecision_TIS;   //!
   TBranch        *b_Xc_Hlt2GlobalDecision_TOS;   //!
   TBranch        *b_Xc_Hlt2Topo2BodyBBDTDecision_Dec;   //!
   TBranch        *b_Xc_Hlt2Topo2BodyBBDTDecision_TIS;   //!
   TBranch        *b_Xc_Hlt2Topo2BodyBBDTDecision_TOS;   //!
   TBranch        *b_Xc_Hlt2Topo3BodyBBDTDecision_Dec;   //!
   TBranch        *b_Xc_Hlt2Topo3BodyBBDTDecision_TIS;   //!
   TBranch        *b_Xc_Hlt2Topo3BodyBBDTDecision_TOS;   //!
   TBranch        *b_Xc_Hlt2Topo4BodyBBDTDecision_Dec;   //!
   TBranch        *b_Xc_Hlt2Topo4BodyBBDTDecision_TIS;   //!
   TBranch        *b_Xc_Hlt2Topo4BodyBBDTDecision_TOS;   //!
   TBranch        *b_Xc_Hlt2Topo2BodySimpleDecision_Dec;   //!
   TBranch        *b_Xc_Hlt2Topo2BodySimpleDecision_TIS;   //!
   TBranch        *b_Xc_Hlt2Topo2BodySimpleDecision_TOS;   //!
   TBranch        *b_Xc_Hlt2Topo3BodySimpleDecision_Dec;   //!
   TBranch        *b_Xc_Hlt2Topo3BodySimpleDecision_TIS;   //!
   TBranch        *b_Xc_Hlt2Topo3BodySimpleDecision_TOS;   //!
   TBranch        *b_Xc_Hlt2Topo4BodySimpleDecision_Dec;   //!
   TBranch        *b_Xc_Hlt2Topo4BodySimpleDecision_TIS;   //!
   TBranch        *b_Xc_Hlt2Topo4BodySimpleDecision_TOS;   //!
   TBranch        *b_Xc_Hlt2IncPhiDecision_Dec;   //!
   TBranch        *b_Xc_Hlt2IncPhiDecision_TIS;   //!
   TBranch        *b_Xc_Hlt2IncPhiDecision_TOS;   //!
   TBranch        *b_Xc_Hlt2IncPhiSidebandsDecision_Dec;   //!
   TBranch        *b_Xc_Hlt2IncPhiSidebandsDecision_TIS;   //!
   TBranch        *b_Xc_Hlt2IncPhiSidebandsDecision_TOS;   //!
   TBranch        *b_Xc_Hlt2CharmHadD2HHHDecision_Dec;   //!
   TBranch        *b_Xc_Hlt2CharmHadD2HHHDecision_TIS;   //!
   TBranch        *b_Xc_Hlt2CharmHadD2HHHDecision_TOS;   //!
   TBranch        *b_Xc_Hlt2CharmHadD2HHHWideMassDecision_Dec;   //!
   TBranch        *b_Xc_Hlt2CharmHadD2HHHWideMassDecision_TIS;   //!
   TBranch        *b_Xc_Hlt2CharmHadD2HHHWideMassDecision_TOS;   //!
   TBranch        *b_p1_fromXc_ETA;   //!
   TBranch        *b_p1_fromXc_MC12TuneV2_ProbNNe;   //!
   TBranch        *b_p1_fromXc_MC12TuneV2_ProbNNmu;   //!
   TBranch        *b_p1_fromXc_MC12TuneV2_ProbNNpi;   //!
   TBranch        *b_p1_fromXc_MC12TuneV2_ProbNNk;   //!
   TBranch        *b_p1_fromXc_MC12TuneV2_ProbNNp;   //!
   TBranch        *b_p1_fromXc_MC12TuneV2_ProbNNghost;   //!
   TBranch        *b_p1_fromXc_MC12TuneV3_ProbNNe;   //!
   TBranch        *b_p1_fromXc_MC12TuneV3_ProbNNmu;   //!
   TBranch        *b_p1_fromXc_MC12TuneV3_ProbNNpi;   //!
   TBranch        *b_p1_fromXc_MC12TuneV3_ProbNNk;   //!
   TBranch        *b_p1_fromXc_MC12TuneV3_ProbNNp;   //!
   TBranch        *b_p1_fromXc_MC12TuneV3_ProbNNghost;   //!
   TBranch        *b_p1_fromXc_MC12TuneV4_ProbNNe;   //!
   TBranch        *b_p1_fromXc_MC12TuneV4_ProbNNmu;   //!
   TBranch        *b_p1_fromXc_MC12TuneV4_ProbNNpi;   //!
   TBranch        *b_p1_fromXc_MC12TuneV4_ProbNNk;   //!
   TBranch        *b_p1_fromXc_MC12TuneV4_ProbNNp;   //!
   TBranch        *b_p1_fromXc_MC12TuneV4_ProbNNghost;   //!
   TBranch        *b_p1_fromXc_MC15TuneV1_ProbNNe;   //!
   TBranch        *b_p1_fromXc_MC15TuneV1_ProbNNmu;   //!
   TBranch        *b_p1_fromXc_MC15TuneV1_ProbNNpi;   //!
   TBranch        *b_p1_fromXc_MC15TuneV1_ProbNNk;   //!
   TBranch        *b_p1_fromXc_MC15TuneV1_ProbNNp;   //!
   TBranch        *b_p1_fromXc_MC15TuneV1_ProbNNghost;   //!
   TBranch        *b_p1_fromXc_MINIP;   //!
   TBranch        *b_p1_fromXc_MINIPCHI2;   //!
   TBranch        *b_p1_fromXc_MINIPNEXTBEST;   //!
   TBranch        *b_p1_fromXc_MINIPCHI2NEXTBEST;   //!
   TBranch        *b_p1_fromXc_AllIP;   //!
   TBranch        *b_p1_fromXc_AllIPchi2;   //!
   TBranch        *b_p1_fromXc_AllDIRA;   //!
   TBranch        *b_p1_fromXc_OWNPV_X;   //!
   TBranch        *b_p1_fromXc_OWNPV_Y;   //!
   TBranch        *b_p1_fromXc_OWNPV_Z;   //!
   TBranch        *b_p1_fromXc_OWNPV_XERR;   //!
   TBranch        *b_p1_fromXc_OWNPV_YERR;   //!
   TBranch        *b_p1_fromXc_OWNPV_ZERR;   //!
   TBranch        *b_p1_fromXc_OWNPV_CHI2;   //!
   TBranch        *b_p1_fromXc_OWNPV_NDOF;   //!
   TBranch        *b_p1_fromXc_OWNPV_COV_;   //!
   TBranch        *b_p1_fromXc_IP_OWNPV;   //!
   TBranch        *b_p1_fromXc_IPCHI2_OWNPV;   //!
   TBranch        *b_p1_fromXc_TOPPV_X;   //!
   TBranch        *b_p1_fromXc_TOPPV_Y;   //!
   TBranch        *b_p1_fromXc_TOPPV_Z;   //!
   TBranch        *b_p1_fromXc_TOPPV_XERR;   //!
   TBranch        *b_p1_fromXc_TOPPV_YERR;   //!
   TBranch        *b_p1_fromXc_TOPPV_ZERR;   //!
   TBranch        *b_p1_fromXc_TOPPV_CHI2;   //!
   TBranch        *b_p1_fromXc_TOPPV_NDOF;   //!
   TBranch        *b_p1_fromXc_TOPPV_COV_;   //!
   TBranch        *b_p1_fromXc_IP_TOPPV;   //!
   TBranch        *b_p1_fromXc_IPCHI2_TOPPV;   //!
   TBranch        *b_p1_fromXc_ORIVX_X;   //!
   TBranch        *b_p1_fromXc_ORIVX_Y;   //!
   TBranch        *b_p1_fromXc_ORIVX_Z;   //!
   TBranch        *b_p1_fromXc_ORIVX_XERR;   //!
   TBranch        *b_p1_fromXc_ORIVX_YERR;   //!
   TBranch        *b_p1_fromXc_ORIVX_ZERR;   //!
   TBranch        *b_p1_fromXc_ORIVX_CHI2;   //!
   TBranch        *b_p1_fromXc_ORIVX_NDOF;   //!
   TBranch        *b_p1_fromXc_ORIVX_COV_;   //!
   TBranch        *b_p1_fromXc_IP_ORIVX;   //!
   TBranch        *b_p1_fromXc_IPCHI2_ORIVX;   //!
   TBranch        *b_p1_fromXc_Nb_NIsoTr;   //!
   TBranch        *b_p1_fromXc_IsoMinBDT;   //!
   TBranch        *b_p1_fromXc_ConeIso;   //!
   TBranch        *b_p1_fromXc_PAIR_M;   //!
   TBranch        *b_p1_fromXc_NIso_PAIR_VtxChi2;   //!
   TBranch        *b_p1_fromXc_NIso_DCHI2;   //!
   TBranch        *b_p1_fromXc_NIso_DIS;   //!
   TBranch        *b_p1_fromXc_NIsoTr_VTXX;   //!
   TBranch        *b_p1_fromXc_NIsoTr_VTXY;   //!
   TBranch        *b_p1_fromXc_NIsoTr_VTXZ;   //!
   TBranch        *b_p1_fromXc_PAIR_IPchi2;   //!
   TBranch        *b_p1_fromXc_NIsoTr_PVDIS;   //!
   TBranch        *b_p1_fromXc_NIsoTr_SVDIS;   //!
   TBranch        *b_p1_fromXc_NIsoTr_DOCA;   //!
   TBranch        *b_p1_fromXc_NIsoTr_ANGLE;   //!
   TBranch        *b_p1_fromXc_NIsoTr_FC;   //!
   TBranch        *b_NTr;   //!
   TBranch        *b_p1_fromXc_Tr_MinIsoBDT;   //!
   TBranch        *b_p1_fromXc_Tr_PAIR_VTXX;   //!
   TBranch        *b_p1_fromXc_Tr_PAIR_VTXY;   //!
   TBranch        *b_p1_fromXc_Tr_PAIR_VTXZ;   //!
   TBranch        *b_p1_fromXc_Tr_PAIR_VTCHI2NDOF;   //!
   TBranch        *b_p1_fromXc_Tr_FirstHitX;   //!
   TBranch        *b_p1_fromXc_Tr_FirstHitY;   //!
   TBranch        *b_p1_fromXc_Tr_FirstHitZ;   //!
   TBranch        *b_p1_fromXc_Tr_DCHI2;   //!
   TBranch        *b_p1_fromXc_Tr_DIS;   //!
   TBranch        *b_p1_fromXc_Tr_MATCHCHI2;   //!
   TBranch        *b_p1_fromXc_Tr_PVDIS;   //!
   TBranch        *b_p1_fromXc_Tr_SVDIS;   //!
   TBranch        *b_p1_fromXc_Tr_DOCA;   //!
   TBranch        *b_p1_fromXc_Tr_ANGLE;   //!
   TBranch        *b_p1_fromXc_Tr_FC_MU;   //!
   TBranch        *b_p1_fromXc_NIsoTr_ETA;   //!
   TBranch        *b_p1_fromXc_NIsoTr_PHI;   //!
   TBranch        *b_p1_fromXc_NIsoTr_TRTYPE;   //!
   TBranch        *b_p1_fromXc_NIsoTr_TRUEID;   //!
   TBranch        *b_p1_fromXc_NIsoTr_MC_MOTHER_ID;   //!
   TBranch        *b_p1_fromXc_NIsoTr_MC_MOTHER_KEY;   //!
   TBranch        *b_p1_fromXc_NIsoTr_MC_GD_MOTHER_ID;   //!
   TBranch        *b_p1_fromXc_NIsoTr_MC_GD_MOTHER_KEY;   //!
   TBranch        *b_p1_fromXc_NIsoTr_MC_GD_GD_MOTHER_ID;   //!
   TBranch        *b_p1_fromXc_NIsoTr_MC_GD_GD_MOTHER_KEY;   //!
   TBranch        *b_p1_fromXc_P;   //!
   TBranch        *b_p1_fromXc_PT;   //!
   TBranch        *b_p1_fromXc_PE;   //!
   TBranch        *b_p1_fromXc_PX;   //!
   TBranch        *b_p1_fromXc_PY;   //!
   TBranch        *b_p1_fromXc_PZ;   //!
   TBranch        *b_p1_fromXc_M;   //!
   TBranch        *b_p1_fromXc_ID;   //!
   TBranch        *b_p1_fromXc_PIDe;   //!
   TBranch        *b_p1_fromXc_PIDmu;   //!
   TBranch        *b_p1_fromXc_PIDK;   //!
   TBranch        *b_p1_fromXc_PIDp;   //!
   TBranch        *b_p1_fromXc_PIDd;   //!
   TBranch        *b_p1_fromXc_ProbNNe;   //!
   TBranch        *b_p1_fromXc_ProbNNk;   //!
   TBranch        *b_p1_fromXc_ProbNNp;   //!
   TBranch        *b_p1_fromXc_ProbNNpi;   //!
   TBranch        *b_p1_fromXc_ProbNNmu;   //!
   TBranch        *b_p1_fromXc_ProbNNd;   //!
   TBranch        *b_p1_fromXc_ProbNNghost;   //!
   TBranch        *b_p1_fromXc_hasMuon;   //!
   TBranch        *b_p1_fromXc_isMuon;   //!
   TBranch        *b_p1_fromXc_hasRich;   //!
   TBranch        *b_p1_fromXc_UsedRichAerogel;   //!
   TBranch        *b_p1_fromXc_UsedRich1Gas;   //!
   TBranch        *b_p1_fromXc_UsedRich2Gas;   //!
   TBranch        *b_p1_fromXc_RichAboveElThres;   //!
   TBranch        *b_p1_fromXc_RichAboveMuThres;   //!
   TBranch        *b_p1_fromXc_RichAbovePiThres;   //!
   TBranch        *b_p1_fromXc_RichAboveKaThres;   //!
   TBranch        *b_p1_fromXc_RichAbovePrThres;   //!
   TBranch        *b_p1_fromXc_hasCalo;   //!
   TBranch        *b_p1_fromXc_TRACK_Type;   //!
   TBranch        *b_p1_fromXc_TRACK_Key;   //!
   TBranch        *b_p1_fromXc_TRACK_CHI2NDOF;   //!
   TBranch        *b_p1_fromXc_TRACK_PCHI2;   //!
   TBranch        *b_p1_fromXc_TRACK_MatchCHI2;   //!
   TBranch        *b_p1_fromXc_TRACK_GhostProb;   //!
   TBranch        *b_p1_fromXc_TRACK_CloneDist;   //!
   TBranch        *b_p1_fromXc_TRACK_Likelihood;   //!
   TBranch        *b_p1_fromXc_TRUEID;   //!
   TBranch        *b_p1_fromXc_PANC_fromB;   //!
   TBranch        *b_p1_fromXc_PANC_fromD;   //!
   TBranch        *b_p1_fromXc_PANC_IDs;   //!
   TBranch        *b_p1_fromXc_PANC_Keys;   //!
   TBranch        *b_p1_fromXc_N_ANC;   //!
   TBranch        *b_p2_fromXc_ETA;   //!
   TBranch        *b_p2_fromXc_MC12TuneV2_ProbNNe;   //!
   TBranch        *b_p2_fromXc_MC12TuneV2_ProbNNmu;   //!
   TBranch        *b_p2_fromXc_MC12TuneV2_ProbNNpi;   //!
   TBranch        *b_p2_fromXc_MC12TuneV2_ProbNNk;   //!
   TBranch        *b_p2_fromXc_MC12TuneV2_ProbNNp;   //!
   TBranch        *b_p2_fromXc_MC12TuneV2_ProbNNghost;   //!
   TBranch        *b_p2_fromXc_MC12TuneV3_ProbNNe;   //!
   TBranch        *b_p2_fromXc_MC12TuneV3_ProbNNmu;   //!
   TBranch        *b_p2_fromXc_MC12TuneV3_ProbNNpi;   //!
   TBranch        *b_p2_fromXc_MC12TuneV3_ProbNNk;   //!
   TBranch        *b_p2_fromXc_MC12TuneV3_ProbNNp;   //!
   TBranch        *b_p2_fromXc_MC12TuneV3_ProbNNghost;   //!
   TBranch        *b_p2_fromXc_MC12TuneV4_ProbNNe;   //!
   TBranch        *b_p2_fromXc_MC12TuneV4_ProbNNmu;   //!
   TBranch        *b_p2_fromXc_MC12TuneV4_ProbNNpi;   //!
   TBranch        *b_p2_fromXc_MC12TuneV4_ProbNNk;   //!
   TBranch        *b_p2_fromXc_MC12TuneV4_ProbNNp;   //!
   TBranch        *b_p2_fromXc_MC12TuneV4_ProbNNghost;   //!
   TBranch        *b_p2_fromXc_MC15TuneV1_ProbNNe;   //!
   TBranch        *b_p2_fromXc_MC15TuneV1_ProbNNmu;   //!
   TBranch        *b_p2_fromXc_MC15TuneV1_ProbNNpi;   //!
   TBranch        *b_p2_fromXc_MC15TuneV1_ProbNNk;   //!
   TBranch        *b_p2_fromXc_MC15TuneV1_ProbNNp;   //!
   TBranch        *b_p2_fromXc_MC15TuneV1_ProbNNghost;   //!
   TBranch        *b_p2_fromXc_MINIP;   //!
   TBranch        *b_p2_fromXc_MINIPCHI2;   //!
   TBranch        *b_p2_fromXc_MINIPNEXTBEST;   //!
   TBranch        *b_p2_fromXc_MINIPCHI2NEXTBEST;   //!
   TBranch        *b_p2_fromXc_AllIP;   //!
   TBranch        *b_p2_fromXc_AllIPchi2;   //!
   TBranch        *b_p2_fromXc_AllDIRA;   //!
   TBranch        *b_p2_fromXc_OWNPV_X;   //!
   TBranch        *b_p2_fromXc_OWNPV_Y;   //!
   TBranch        *b_p2_fromXc_OWNPV_Z;   //!
   TBranch        *b_p2_fromXc_OWNPV_XERR;   //!
   TBranch        *b_p2_fromXc_OWNPV_YERR;   //!
   TBranch        *b_p2_fromXc_OWNPV_ZERR;   //!
   TBranch        *b_p2_fromXc_OWNPV_CHI2;   //!
   TBranch        *b_p2_fromXc_OWNPV_NDOF;   //!
   TBranch        *b_p2_fromXc_OWNPV_COV_;   //!
   TBranch        *b_p2_fromXc_IP_OWNPV;   //!
   TBranch        *b_p2_fromXc_IPCHI2_OWNPV;   //!
   TBranch        *b_p2_fromXc_TOPPV_X;   //!
   TBranch        *b_p2_fromXc_TOPPV_Y;   //!
   TBranch        *b_p2_fromXc_TOPPV_Z;   //!
   TBranch        *b_p2_fromXc_TOPPV_XERR;   //!
   TBranch        *b_p2_fromXc_TOPPV_YERR;   //!
   TBranch        *b_p2_fromXc_TOPPV_ZERR;   //!
   TBranch        *b_p2_fromXc_TOPPV_CHI2;   //!
   TBranch        *b_p2_fromXc_TOPPV_NDOF;   //!
   TBranch        *b_p2_fromXc_TOPPV_COV_;   //!
   TBranch        *b_p2_fromXc_IP_TOPPV;   //!
   TBranch        *b_p2_fromXc_IPCHI2_TOPPV;   //!
   TBranch        *b_p2_fromXc_ORIVX_X;   //!
   TBranch        *b_p2_fromXc_ORIVX_Y;   //!
   TBranch        *b_p2_fromXc_ORIVX_Z;   //!
   TBranch        *b_p2_fromXc_ORIVX_XERR;   //!
   TBranch        *b_p2_fromXc_ORIVX_YERR;   //!
   TBranch        *b_p2_fromXc_ORIVX_ZERR;   //!
   TBranch        *b_p2_fromXc_ORIVX_CHI2;   //!
   TBranch        *b_p2_fromXc_ORIVX_NDOF;   //!
   TBranch        *b_p2_fromXc_ORIVX_COV_;   //!
   TBranch        *b_p2_fromXc_IP_ORIVX;   //!
   TBranch        *b_p2_fromXc_IPCHI2_ORIVX;   //!
   TBranch        *b_p2_fromXc_Nb_NIsoTr;   //!
   TBranch        *b_p2_fromXc_IsoMinBDT;   //!
   TBranch        *b_p2_fromXc_ConeIso;   //!
   TBranch        *b_p2_fromXc_PAIR_M;   //!
   TBranch        *b_p2_fromXc_NIso_PAIR_VtxChi2;   //!
   TBranch        *b_p2_fromXc_NIso_DCHI2;   //!
   TBranch        *b_p2_fromXc_NIso_DIS;   //!
   TBranch        *b_p2_fromXc_NIsoTr_VTXX;   //!
   TBranch        *b_p2_fromXc_NIsoTr_VTXY;   //!
   TBranch        *b_p2_fromXc_NIsoTr_VTXZ;   //!
   TBranch        *b_p2_fromXc_PAIR_IPchi2;   //!
   TBranch        *b_p2_fromXc_NIsoTr_PVDIS;   //!
   TBranch        *b_p2_fromXc_NIsoTr_SVDIS;   //!
   TBranch        *b_p2_fromXc_NIsoTr_DOCA;   //!
   TBranch        *b_p2_fromXc_NIsoTr_ANGLE;   //!
   TBranch        *b_p2_fromXc_NIsoTr_FC;   //!
   TBranch        *b_p2_fromXc_Tr_MinIsoBDT;   //!
   TBranch        *b_p2_fromXc_Tr_PAIR_VTXX;   //!
   TBranch        *b_p2_fromXc_Tr_PAIR_VTXY;   //!
   TBranch        *b_p2_fromXc_Tr_PAIR_VTXZ;   //!
   TBranch        *b_p2_fromXc_Tr_PAIR_VTCHI2NDOF;   //!
   TBranch        *b_p2_fromXc_Tr_FirstHitX;   //!
   TBranch        *b_p2_fromXc_Tr_FirstHitY;   //!
   TBranch        *b_p2_fromXc_Tr_FirstHitZ;   //!
   TBranch        *b_p2_fromXc_Tr_DCHI2;   //!
   TBranch        *b_p2_fromXc_Tr_DIS;   //!
   TBranch        *b_p2_fromXc_Tr_MATCHCHI2;   //!
   TBranch        *b_p2_fromXc_Tr_PVDIS;   //!
   TBranch        *b_p2_fromXc_Tr_SVDIS;   //!
   TBranch        *b_p2_fromXc_Tr_DOCA;   //!
   TBranch        *b_p2_fromXc_Tr_ANGLE;   //!
   TBranch        *b_p2_fromXc_Tr_FC_MU;   //!
   TBranch        *b_p2_fromXc_NIsoTr_ETA;   //!
   TBranch        *b_p2_fromXc_NIsoTr_PHI;   //!
   TBranch        *b_p2_fromXc_NIsoTr_TRTYPE;   //!
   TBranch        *b_p2_fromXc_NIsoTr_TRUEID;   //!
   TBranch        *b_p2_fromXc_NIsoTr_MC_MOTHER_ID;   //!
   TBranch        *b_p2_fromXc_NIsoTr_MC_MOTHER_KEY;   //!
   TBranch        *b_p2_fromXc_NIsoTr_MC_GD_MOTHER_ID;   //!
   TBranch        *b_p2_fromXc_NIsoTr_MC_GD_MOTHER_KEY;   //!
   TBranch        *b_p2_fromXc_NIsoTr_MC_GD_GD_MOTHER_ID;   //!
   TBranch        *b_p2_fromXc_NIsoTr_MC_GD_GD_MOTHER_KEY;   //!
   TBranch        *b_p2_fromXc_P;   //!
   TBranch        *b_p2_fromXc_PT;   //!
   TBranch        *b_p2_fromXc_PE;   //!
   TBranch        *b_p2_fromXc_PX;   //!
   TBranch        *b_p2_fromXc_PY;   //!
   TBranch        *b_p2_fromXc_PZ;   //!
   TBranch        *b_p2_fromXc_M;   //!
   TBranch        *b_p2_fromXc_ID;   //!
   TBranch        *b_p2_fromXc_PIDe;   //!
   TBranch        *b_p2_fromXc_PIDmu;   //!
   TBranch        *b_p2_fromXc_PIDK;   //!
   TBranch        *b_p2_fromXc_PIDp;   //!
   TBranch        *b_p2_fromXc_PIDd;   //!
   TBranch        *b_p2_fromXc_ProbNNe;   //!
   TBranch        *b_p2_fromXc_ProbNNk;   //!
   TBranch        *b_p2_fromXc_ProbNNp;   //!
   TBranch        *b_p2_fromXc_ProbNNpi;   //!
   TBranch        *b_p2_fromXc_ProbNNmu;   //!
   TBranch        *b_p2_fromXc_ProbNNd;   //!
   TBranch        *b_p2_fromXc_ProbNNghost;   //!
   TBranch        *b_p2_fromXc_hasMuon;   //!
   TBranch        *b_p2_fromXc_isMuon;   //!
   TBranch        *b_p2_fromXc_hasRich;   //!
   TBranch        *b_p2_fromXc_UsedRichAerogel;   //!
   TBranch        *b_p2_fromXc_UsedRich1Gas;   //!
   TBranch        *b_p2_fromXc_UsedRich2Gas;   //!
   TBranch        *b_p2_fromXc_RichAboveElThres;   //!
   TBranch        *b_p2_fromXc_RichAboveMuThres;   //!
   TBranch        *b_p2_fromXc_RichAbovePiThres;   //!
   TBranch        *b_p2_fromXc_RichAboveKaThres;   //!
   TBranch        *b_p2_fromXc_RichAbovePrThres;   //!
   TBranch        *b_p2_fromXc_hasCalo;   //!
   TBranch        *b_p2_fromXc_TRACK_Type;   //!
   TBranch        *b_p2_fromXc_TRACK_Key;   //!
   TBranch        *b_p2_fromXc_TRACK_CHI2NDOF;   //!
   TBranch        *b_p2_fromXc_TRACK_PCHI2;   //!
   TBranch        *b_p2_fromXc_TRACK_MatchCHI2;   //!
   TBranch        *b_p2_fromXc_TRACK_GhostProb;   //!
   TBranch        *b_p2_fromXc_TRACK_CloneDist;   //!
   TBranch        *b_p2_fromXc_TRACK_Likelihood;   //!
   TBranch        *b_p2_fromXc_TRUEID;   //!
   TBranch        *b_p2_fromXc_PANC_fromB;   //!
   TBranch        *b_p2_fromXc_PANC_fromD;   //!
   TBranch        *b_p2_fromXc_PANC_IDs;   //!
   TBranch        *b_p2_fromXc_PANC_Keys;   //!
   TBranch        *b_p2_fromXc_N_ANC;   //!
   TBranch        *b_p3_fromXc_ETA;   //!
   TBranch        *b_p3_fromXc_MC12TuneV2_ProbNNe;   //!
   TBranch        *b_p3_fromXc_MC12TuneV2_ProbNNmu;   //!
   TBranch        *b_p3_fromXc_MC12TuneV2_ProbNNpi;   //!
   TBranch        *b_p3_fromXc_MC12TuneV2_ProbNNk;   //!
   TBranch        *b_p3_fromXc_MC12TuneV2_ProbNNp;   //!
   TBranch        *b_p3_fromXc_MC12TuneV2_ProbNNghost;   //!
   TBranch        *b_p3_fromXc_MC12TuneV3_ProbNNe;   //!
   TBranch        *b_p3_fromXc_MC12TuneV3_ProbNNmu;   //!
   TBranch        *b_p3_fromXc_MC12TuneV3_ProbNNpi;   //!
   TBranch        *b_p3_fromXc_MC12TuneV3_ProbNNk;   //!
   TBranch        *b_p3_fromXc_MC12TuneV3_ProbNNp;   //!
   TBranch        *b_p3_fromXc_MC12TuneV3_ProbNNghost;   //!
   TBranch        *b_p3_fromXc_MC12TuneV4_ProbNNe;   //!
   TBranch        *b_p3_fromXc_MC12TuneV4_ProbNNmu;   //!
   TBranch        *b_p3_fromXc_MC12TuneV4_ProbNNpi;   //!
   TBranch        *b_p3_fromXc_MC12TuneV4_ProbNNk;   //!
   TBranch        *b_p3_fromXc_MC12TuneV4_ProbNNp;   //!
   TBranch        *b_p3_fromXc_MC12TuneV4_ProbNNghost;   //!
   TBranch        *b_p3_fromXc_MC15TuneV1_ProbNNe;   //!
   TBranch        *b_p3_fromXc_MC15TuneV1_ProbNNmu;   //!
   TBranch        *b_p3_fromXc_MC15TuneV1_ProbNNpi;   //!
   TBranch        *b_p3_fromXc_MC15TuneV1_ProbNNk;   //!
   TBranch        *b_p3_fromXc_MC15TuneV1_ProbNNp;   //!
   TBranch        *b_p3_fromXc_MC15TuneV1_ProbNNghost;   //!
   TBranch        *b_p3_fromXc_MINIP;   //!
   TBranch        *b_p3_fromXc_MINIPCHI2;   //!
   TBranch        *b_p3_fromXc_MINIPNEXTBEST;   //!
   TBranch        *b_p3_fromXc_MINIPCHI2NEXTBEST;   //!
   TBranch        *b_p3_fromXc_AllIP;   //!
   TBranch        *b_p3_fromXc_AllIPchi2;   //!
   TBranch        *b_p3_fromXc_AllDIRA;   //!
   TBranch        *b_p3_fromXc_OWNPV_X;   //!
   TBranch        *b_p3_fromXc_OWNPV_Y;   //!
   TBranch        *b_p3_fromXc_OWNPV_Z;   //!
   TBranch        *b_p3_fromXc_OWNPV_XERR;   //!
   TBranch        *b_p3_fromXc_OWNPV_YERR;   //!
   TBranch        *b_p3_fromXc_OWNPV_ZERR;   //!
   TBranch        *b_p3_fromXc_OWNPV_CHI2;   //!
   TBranch        *b_p3_fromXc_OWNPV_NDOF;   //!
   TBranch        *b_p3_fromXc_OWNPV_COV_;   //!
   TBranch        *b_p3_fromXc_IP_OWNPV;   //!
   TBranch        *b_p3_fromXc_IPCHI2_OWNPV;   //!
   TBranch        *b_p3_fromXc_TOPPV_X;   //!
   TBranch        *b_p3_fromXc_TOPPV_Y;   //!
   TBranch        *b_p3_fromXc_TOPPV_Z;   //!
   TBranch        *b_p3_fromXc_TOPPV_XERR;   //!
   TBranch        *b_p3_fromXc_TOPPV_YERR;   //!
   TBranch        *b_p3_fromXc_TOPPV_ZERR;   //!
   TBranch        *b_p3_fromXc_TOPPV_CHI2;   //!
   TBranch        *b_p3_fromXc_TOPPV_NDOF;   //!
   TBranch        *b_p3_fromXc_TOPPV_COV_;   //!
   TBranch        *b_p3_fromXc_IP_TOPPV;   //!
   TBranch        *b_p3_fromXc_IPCHI2_TOPPV;   //!
   TBranch        *b_p3_fromXc_ORIVX_X;   //!
   TBranch        *b_p3_fromXc_ORIVX_Y;   //!
   TBranch        *b_p3_fromXc_ORIVX_Z;   //!
   TBranch        *b_p3_fromXc_ORIVX_XERR;   //!
   TBranch        *b_p3_fromXc_ORIVX_YERR;   //!
   TBranch        *b_p3_fromXc_ORIVX_ZERR;   //!
   TBranch        *b_p3_fromXc_ORIVX_CHI2;   //!
   TBranch        *b_p3_fromXc_ORIVX_NDOF;   //!
   TBranch        *b_p3_fromXc_ORIVX_COV_;   //!
   TBranch        *b_p3_fromXc_IP_ORIVX;   //!
   TBranch        *b_p3_fromXc_IPCHI2_ORIVX;   //!
   TBranch        *b_p3_fromXc_Nb_NIsoTr;   //!
   TBranch        *b_p3_fromXc_IsoMinBDT;   //!
   TBranch        *b_p3_fromXc_ConeIso;   //!
   TBranch        *b_p3_fromXc_PAIR_M;   //!
   TBranch        *b_p3_fromXc_NIso_PAIR_VtxChi2;   //!
   TBranch        *b_p3_fromXc_NIso_DCHI2;   //!
   TBranch        *b_p3_fromXc_NIso_DIS;   //!
   TBranch        *b_p3_fromXc_NIsoTr_VTXX;   //!
   TBranch        *b_p3_fromXc_NIsoTr_VTXY;   //!
   TBranch        *b_p3_fromXc_NIsoTr_VTXZ;   //!
   TBranch        *b_p3_fromXc_PAIR_IPchi2;   //!
   TBranch        *b_p3_fromXc_NIsoTr_PVDIS;   //!
   TBranch        *b_p3_fromXc_NIsoTr_SVDIS;   //!
   TBranch        *b_p3_fromXc_NIsoTr_DOCA;   //!
   TBranch        *b_p3_fromXc_NIsoTr_ANGLE;   //!
   TBranch        *b_p3_fromXc_NIsoTr_FC;   //!
   TBranch        *b_p3_fromXc_Tr_MinIsoBDT;   //!
   TBranch        *b_p3_fromXc_Tr_PAIR_VTXX;   //!
   TBranch        *b_p3_fromXc_Tr_PAIR_VTXY;   //!
   TBranch        *b_p3_fromXc_Tr_PAIR_VTXZ;   //!
   TBranch        *b_p3_fromXc_Tr_PAIR_VTCHI2NDOF;   //!
   TBranch        *b_p3_fromXc_Tr_FirstHitX;   //!
   TBranch        *b_p3_fromXc_Tr_FirstHitY;   //!
   TBranch        *b_p3_fromXc_Tr_FirstHitZ;   //!
   TBranch        *b_p3_fromXc_Tr_DCHI2;   //!
   TBranch        *b_p3_fromXc_Tr_DIS;   //!
   TBranch        *b_p3_fromXc_Tr_MATCHCHI2;   //!
   TBranch        *b_p3_fromXc_Tr_PVDIS;   //!
   TBranch        *b_p3_fromXc_Tr_SVDIS;   //!
   TBranch        *b_p3_fromXc_Tr_DOCA;   //!
   TBranch        *b_p3_fromXc_Tr_ANGLE;   //!
   TBranch        *b_p3_fromXc_Tr_FC_MU;   //!
   TBranch        *b_p3_fromXc_NIsoTr_ETA;   //!
   TBranch        *b_p3_fromXc_NIsoTr_PHI;   //!
   TBranch        *b_p3_fromXc_NIsoTr_TRTYPE;   //!
   TBranch        *b_p3_fromXc_NIsoTr_TRUEID;   //!
   TBranch        *b_p3_fromXc_NIsoTr_MC_MOTHER_ID;   //!
   TBranch        *b_p3_fromXc_NIsoTr_MC_MOTHER_KEY;   //!
   TBranch        *b_p3_fromXc_NIsoTr_MC_GD_MOTHER_ID;   //!
   TBranch        *b_p3_fromXc_NIsoTr_MC_GD_MOTHER_KEY;   //!
   TBranch        *b_p3_fromXc_NIsoTr_MC_GD_GD_MOTHER_ID;   //!
   TBranch        *b_p3_fromXc_NIsoTr_MC_GD_GD_MOTHER_KEY;   //!
   TBranch        *b_p3_fromXc_P;   //!
   TBranch        *b_p3_fromXc_PT;   //!
   TBranch        *b_p3_fromXc_PE;   //!
   TBranch        *b_p3_fromXc_PX;   //!
   TBranch        *b_p3_fromXc_PY;   //!
   TBranch        *b_p3_fromXc_PZ;   //!
   TBranch        *b_p3_fromXc_M;   //!
   TBranch        *b_p3_fromXc_ID;   //!
   TBranch        *b_p3_fromXc_PIDe;   //!
   TBranch        *b_p3_fromXc_PIDmu;   //!
   TBranch        *b_p3_fromXc_PIDK;   //!
   TBranch        *b_p3_fromXc_PIDp;   //!
   TBranch        *b_p3_fromXc_PIDd;   //!
   TBranch        *b_p3_fromXc_ProbNNe;   //!
   TBranch        *b_p3_fromXc_ProbNNk;   //!
   TBranch        *b_p3_fromXc_ProbNNp;   //!
   TBranch        *b_p3_fromXc_ProbNNpi;   //!
   TBranch        *b_p3_fromXc_ProbNNmu;   //!
   TBranch        *b_p3_fromXc_ProbNNd;   //!
   TBranch        *b_p3_fromXc_ProbNNghost;   //!
   TBranch        *b_p3_fromXc_hasMuon;   //!
   TBranch        *b_p3_fromXc_isMuon;   //!
   TBranch        *b_p3_fromXc_hasRich;   //!
   TBranch        *b_p3_fromXc_UsedRichAerogel;   //!
   TBranch        *b_p3_fromXc_UsedRich1Gas;   //!
   TBranch        *b_p3_fromXc_UsedRich2Gas;   //!
   TBranch        *b_p3_fromXc_RichAboveElThres;   //!
   TBranch        *b_p3_fromXc_RichAboveMuThres;   //!
   TBranch        *b_p3_fromXc_RichAbovePiThres;   //!
   TBranch        *b_p3_fromXc_RichAboveKaThres;   //!
   TBranch        *b_p3_fromXc_RichAbovePrThres;   //!
   TBranch        *b_p3_fromXc_hasCalo;   //!
   TBranch        *b_p3_fromXc_TRACK_Type;   //!
   TBranch        *b_p3_fromXc_TRACK_Key;   //!
   TBranch        *b_p3_fromXc_TRACK_CHI2NDOF;   //!
   TBranch        *b_p3_fromXc_TRACK_PCHI2;   //!
   TBranch        *b_p3_fromXc_TRACK_MatchCHI2;   //!
   TBranch        *b_p3_fromXc_TRACK_GhostProb;   //!
   TBranch        *b_p3_fromXc_TRACK_CloneDist;   //!
   TBranch        *b_p3_fromXc_TRACK_Likelihood;   //!
   TBranch        *b_p3_fromXc_TRUEID;   //!
   TBranch        *b_p3_fromXc_PANC_fromB;   //!
   TBranch        *b_p3_fromXc_PANC_fromD;   //!
   TBranch        *b_p3_fromXc_PANC_IDs;   //!
   TBranch        *b_p3_fromXc_PANC_Keys;   //!
   TBranch        *b_p3_fromXc_N_ANC;   //!
   TBranch        *b_Y_ETA;   //!
   TBranch        *b_Y_MINIP;   //!
   TBranch        *b_Y_MINIPCHI2;   //!
   TBranch        *b_Y_MINIPNEXTBEST;   //!
   TBranch        *b_Y_MINIPCHI2NEXTBEST;   //!
   TBranch        *b_Y_AllIP;   //!
   TBranch        *b_Y_AllIPchi2;   //!
   TBranch        *b_Y_AllDIRA;   //!
   TBranch        *b_Y_ENDVERTEX_X;   //!
   TBranch        *b_Y_ENDVERTEX_Y;   //!
   TBranch        *b_Y_ENDVERTEX_Z;   //!
   TBranch        *b_Y_ENDVERTEX_XERR;   //!
   TBranch        *b_Y_ENDVERTEX_YERR;   //!
   TBranch        *b_Y_ENDVERTEX_ZERR;   //!
   TBranch        *b_Y_ENDVERTEX_CHI2;   //!
   TBranch        *b_Y_ENDVERTEX_NDOF;   //!
   TBranch        *b_Y_ENDVERTEX_COV_;   //!
   TBranch        *b_Y_OWNPV_X;   //!
   TBranch        *b_Y_OWNPV_Y;   //!
   TBranch        *b_Y_OWNPV_Z;   //!
   TBranch        *b_Y_OWNPV_XERR;   //!
   TBranch        *b_Y_OWNPV_YERR;   //!
   TBranch        *b_Y_OWNPV_ZERR;   //!
   TBranch        *b_Y_OWNPV_CHI2;   //!
   TBranch        *b_Y_OWNPV_NDOF;   //!
   TBranch        *b_Y_OWNPV_COV_;   //!
   TBranch        *b_Y_IP_OWNPV;   //!
   TBranch        *b_Y_IPCHI2_OWNPV;   //!
   TBranch        *b_Y_FD_OWNPV;   //!
   TBranch        *b_Y_FDCHI2_OWNPV;   //!
   TBranch        *b_Y_DIRA_OWNPV;   //!
   TBranch        *b_Y_TOPPV_X;   //!
   TBranch        *b_Y_TOPPV_Y;   //!
   TBranch        *b_Y_TOPPV_Z;   //!
   TBranch        *b_Y_TOPPV_XERR;   //!
   TBranch        *b_Y_TOPPV_YERR;   //!
   TBranch        *b_Y_TOPPV_ZERR;   //!
   TBranch        *b_Y_TOPPV_CHI2;   //!
   TBranch        *b_Y_TOPPV_NDOF;   //!
   TBranch        *b_Y_TOPPV_COV_;   //!
   TBranch        *b_Y_IP_TOPPV;   //!
   TBranch        *b_Y_IPCHI2_TOPPV;   //!
   TBranch        *b_Y_FD_TOPPV;   //!
   TBranch        *b_Y_FDCHI2_TOPPV;   //!
   TBranch        *b_Y_DIRA_TOPPV;   //!
   TBranch        *b_Y_ORIVX_X;   //!
   TBranch        *b_Y_ORIVX_Y;   //!
   TBranch        *b_Y_ORIVX_Z;   //!
   TBranch        *b_Y_ORIVX_XERR;   //!
   TBranch        *b_Y_ORIVX_YERR;   //!
   TBranch        *b_Y_ORIVX_ZERR;   //!
   TBranch        *b_Y_ORIVX_CHI2;   //!
   TBranch        *b_Y_ORIVX_NDOF;   //!
   TBranch        *b_Y_ORIVX_COV_;   //!
   TBranch        *b_Y_IP_ORIVX;   //!
   TBranch        *b_Y_IPCHI2_ORIVX;   //!
   TBranch        *b_Y_FD_ORIVX;   //!
   TBranch        *b_Y_FDCHI2_ORIVX;   //!
   TBranch        *b_Y_DIRA_ORIVX;   //!
   TBranch        *b_Y_P;   //!
   TBranch        *b_Y_PT;   //!
   TBranch        *b_Y_PE;   //!
   TBranch        *b_Y_PX;   //!
   TBranch        *b_Y_PY;   //!
   TBranch        *b_Y_PZ;   //!
   TBranch        *b_Y_MM;   //!
   TBranch        *b_Y_MMERR;   //!
   TBranch        *b_Y_M;   //!
   TBranch        *b_Y_BKGCAT;   //!
   TBranch        *b_Y_TRUEID;   //!
   TBranch        *b_Y_MC_MOTHER_ID;   //!
   TBranch        *b_Y_MC_MOTHER_KEY;   //!
   TBranch        *b_Y_MC_GD_MOTHER_ID;   //!
   TBranch        *b_Y_MC_GD_MOTHER_KEY;   //!
   TBranch        *b_Y_MC_GD_GD_MOTHER_ID;   //!
   TBranch        *b_Y_MC_GD_GD_MOTHER_KEY;   //!
   TBranch        *b_Y_TRUEP_E;   //!
   TBranch        *b_Y_TRUEP_X;   //!
   TBranch        *b_Y_TRUEP_Y;   //!
   TBranch        *b_Y_TRUEP_Z;   //!
   TBranch        *b_Y_TRUEPT;   //!
   TBranch        *b_Y_TRUEORIGINVERTEX_X;   //!
   TBranch        *b_Y_TRUEORIGINVERTEX_Y;   //!
   TBranch        *b_Y_TRUEORIGINVERTEX_Z;   //!
   TBranch        *b_Y_TRUEENDVERTEX_X;   //!
   TBranch        *b_Y_TRUEENDVERTEX_Y;   //!
   TBranch        *b_Y_TRUEENDVERTEX_Z;   //!
   TBranch        *b_Y_TRUEISSTABLE;   //!
   TBranch        *b_Y_TRUETAU;   //!
   TBranch        *b_Y_ID;   //!
   TBranch        *b_Y_NumVtxWithinChi2WindowOneTrack;   //!
   TBranch        *b_Y_SmallestDeltaChi2OneTrack;   //!
   TBranch        *b_Y_SmallestDeltaChi2MassOneTrack;   //!
   TBranch        *b_Y_SmallestDeltaChi2TwoTracks;   //!
   TBranch        *b_Y_SmallestDeltaChi2MassTwoTracks;   //!
   TBranch        *b_Y_BPVVDR;   //!
   TBranch        *b_Y_DOCA1;   //!
   TBranch        *b_Y_DOCA2;   //!
   TBranch        *b_Y_DOCA3;   //!
   TBranch        *b_Y_0_20_cc_mult;   //!
   TBranch        *b_Y_0_20_cc_sPT;   //!
   TBranch        *b_Y_0_20_cc_vPT;   //!
   TBranch        *b_Y_0_20_cc_PX;   //!
   TBranch        *b_Y_0_20_cc_PY;   //!
   TBranch        *b_Y_0_20_cc_PZ;   //!
   TBranch        *b_Y_0_20_cc_asy_P;   //!
   TBranch        *b_Y_0_20_cc_asy_PT;   //!
   TBranch        *b_Y_0_20_cc_asy_PX;   //!
   TBranch        *b_Y_0_20_cc_asy_PY;   //!
   TBranch        *b_Y_0_20_cc_asy_PZ;   //!
   TBranch        *b_Y_0_20_cc_deltaEta;   //!
   TBranch        *b_Y_0_20_cc_deltaPhi;   //!
   TBranch        *b_Y_0_20_cc_IT;   //!
   TBranch        *b_Y_0_20_cc_maxPt_Q;   //!
   TBranch        *b_Y_0_20_cc_maxPt_PT;   //!
   TBranch        *b_Y_0_20_cc_maxPt_PX;   //!
   TBranch        *b_Y_0_20_cc_maxPt_PY;   //!
   TBranch        *b_Y_0_20_cc_maxPt_PZ;   //!
   TBranch        *b_Y_0_20_cc_maxPt_PE;   //!
   TBranch        *b_Y_0_20_nc_mult;   //!
   TBranch        *b_Y_0_20_nc_sPT;   //!
   TBranch        *b_Y_0_20_nc_vPT;   //!
   TBranch        *b_Y_0_20_nc_PX;   //!
   TBranch        *b_Y_0_20_nc_PY;   //!
   TBranch        *b_Y_0_20_nc_PZ;   //!
   TBranch        *b_Y_0_20_nc_avCL;   //!
   TBranch        *b_Y_0_20_nc_maxCL;   //!
   TBranch        *b_Y_0_20_nc_asy_P;   //!
   TBranch        *b_Y_0_20_nc_asy_PT;   //!
   TBranch        *b_Y_0_20_nc_asy_PX;   //!
   TBranch        *b_Y_0_20_nc_asy_PY;   //!
   TBranch        *b_Y_0_20_nc_asy_PZ;   //!
   TBranch        *b_Y_0_20_nc_deltaEta;   //!
   TBranch        *b_Y_0_20_nc_deltaPhi;   //!
   TBranch        *b_Y_0_20_nc_IT;   //!
   TBranch        *b_Y_0_20_nc_maxPt_PT;   //!
   TBranch        *b_Y_0_20_nc_maxPt_PX;   //!
   TBranch        *b_Y_0_20_nc_maxPt_PY;   //!
   TBranch        *b_Y_0_20_nc_maxPt_PZ;   //!
   TBranch        *b_Y_0_20_nc_H1;   //!
   TBranch        *b_Y_0_20_nc_H2;   //!
   TBranch        *b_Y_0_20_nc_H3;   //!
   TBranch        *b_Y_0_20_nc_H4;   //!
   TBranch        *b_Y_0_20_IT;   //!
   TBranch        *b_Y_0_30_cc_mult;   //!
   TBranch        *b_Y_0_30_cc_sPT;   //!
   TBranch        *b_Y_0_30_cc_vPT;   //!
   TBranch        *b_Y_0_30_cc_PX;   //!
   TBranch        *b_Y_0_30_cc_PY;   //!
   TBranch        *b_Y_0_30_cc_PZ;   //!
   TBranch        *b_Y_0_30_cc_asy_P;   //!
   TBranch        *b_Y_0_30_cc_asy_PT;   //!
   TBranch        *b_Y_0_30_cc_asy_PX;   //!
   TBranch        *b_Y_0_30_cc_asy_PY;   //!
   TBranch        *b_Y_0_30_cc_asy_PZ;   //!
   TBranch        *b_Y_0_30_cc_deltaEta;   //!
   TBranch        *b_Y_0_30_cc_deltaPhi;   //!
   TBranch        *b_Y_0_30_cc_IT;   //!
   TBranch        *b_Y_0_30_cc_maxPt_Q;   //!
   TBranch        *b_Y_0_30_cc_maxPt_PT;   //!
   TBranch        *b_Y_0_30_cc_maxPt_PX;   //!
   TBranch        *b_Y_0_30_cc_maxPt_PY;   //!
   TBranch        *b_Y_0_30_cc_maxPt_PZ;   //!
   TBranch        *b_Y_0_30_cc_maxPt_PE;   //!
   TBranch        *b_Y_0_30_nc_mult;   //!
   TBranch        *b_Y_0_30_nc_sPT;   //!
   TBranch        *b_Y_0_30_nc_vPT;   //!
   TBranch        *b_Y_0_30_nc_PX;   //!
   TBranch        *b_Y_0_30_nc_PY;   //!
   TBranch        *b_Y_0_30_nc_PZ;   //!
   TBranch        *b_Y_0_30_nc_avCL;   //!
   TBranch        *b_Y_0_30_nc_maxCL;   //!
   TBranch        *b_Y_0_30_nc_asy_P;   //!
   TBranch        *b_Y_0_30_nc_asy_PT;   //!
   TBranch        *b_Y_0_30_nc_asy_PX;   //!
   TBranch        *b_Y_0_30_nc_asy_PY;   //!
   TBranch        *b_Y_0_30_nc_asy_PZ;   //!
   TBranch        *b_Y_0_30_nc_deltaEta;   //!
   TBranch        *b_Y_0_30_nc_deltaPhi;   //!
   TBranch        *b_Y_0_30_nc_IT;   //!
   TBranch        *b_Y_0_30_nc_maxPt_PT;   //!
   TBranch        *b_Y_0_30_nc_maxPt_PX;   //!
   TBranch        *b_Y_0_30_nc_maxPt_PY;   //!
   TBranch        *b_Y_0_30_nc_maxPt_PZ;   //!
   TBranch        *b_Y_0_30_nc_H1;   //!
   TBranch        *b_Y_0_30_nc_H2;   //!
   TBranch        *b_Y_0_30_nc_H3;   //!
   TBranch        *b_Y_0_30_nc_H4;   //!
   TBranch        *b_Y_0_30_IT;   //!
   TBranch        *b_Y_0_40_cc_mult;   //!
   TBranch        *b_Y_0_40_cc_sPT;   //!
   TBranch        *b_Y_0_40_cc_vPT;   //!
   TBranch        *b_Y_0_40_cc_PX;   //!
   TBranch        *b_Y_0_40_cc_PY;   //!
   TBranch        *b_Y_0_40_cc_PZ;   //!
   TBranch        *b_Y_0_40_cc_asy_P;   //!
   TBranch        *b_Y_0_40_cc_asy_PT;   //!
   TBranch        *b_Y_0_40_cc_asy_PX;   //!
   TBranch        *b_Y_0_40_cc_asy_PY;   //!
   TBranch        *b_Y_0_40_cc_asy_PZ;   //!
   TBranch        *b_Y_0_40_cc_deltaEta;   //!
   TBranch        *b_Y_0_40_cc_deltaPhi;   //!
   TBranch        *b_Y_0_40_cc_IT;   //!
   TBranch        *b_Y_0_40_cc_maxPt_Q;   //!
   TBranch        *b_Y_0_40_cc_maxPt_PT;   //!
   TBranch        *b_Y_0_40_cc_maxPt_PX;   //!
   TBranch        *b_Y_0_40_cc_maxPt_PY;   //!
   TBranch        *b_Y_0_40_cc_maxPt_PZ;   //!
   TBranch        *b_Y_0_40_cc_maxPt_PE;   //!
   TBranch        *b_Y_0_40_nc_mult;   //!
   TBranch        *b_Y_0_40_nc_sPT;   //!
   TBranch        *b_Y_0_40_nc_vPT;   //!
   TBranch        *b_Y_0_40_nc_PX;   //!
   TBranch        *b_Y_0_40_nc_PY;   //!
   TBranch        *b_Y_0_40_nc_PZ;   //!
   TBranch        *b_Y_0_40_nc_avCL;   //!
   TBranch        *b_Y_0_40_nc_maxCL;   //!
   TBranch        *b_Y_0_40_nc_asy_P;   //!
   TBranch        *b_Y_0_40_nc_asy_PT;   //!
   TBranch        *b_Y_0_40_nc_asy_PX;   //!
   TBranch        *b_Y_0_40_nc_asy_PY;   //!
   TBranch        *b_Y_0_40_nc_asy_PZ;   //!
   TBranch        *b_Y_0_40_nc_deltaEta;   //!
   TBranch        *b_Y_0_40_nc_deltaPhi;   //!
   TBranch        *b_Y_0_40_nc_IT;   //!
   TBranch        *b_Y_0_40_nc_maxPt_PT;   //!
   TBranch        *b_Y_0_40_nc_maxPt_PX;   //!
   TBranch        *b_Y_0_40_nc_maxPt_PY;   //!
   TBranch        *b_Y_0_40_nc_maxPt_PZ;   //!
   TBranch        *b_Y_0_40_nc_H1;   //!
   TBranch        *b_Y_0_40_nc_H2;   //!
   TBranch        *b_Y_0_40_nc_H3;   //!
   TBranch        *b_Y_0_40_nc_H4;   //!
   TBranch        *b_Y_0_40_IT;   //!
   TBranch        *b_Y_pi0_mult;   //!
   TBranch        *b_Y_Pi0_ArrayLength;   //!
   TBranch        *b_Y_MasshPi0;   //!
   TBranch        *b_Y_Pi0_PX;   //!
   TBranch        *b_Y_Pi0_PY;   //!
   TBranch        *b_Y_Pi0_PZ;   //!
   TBranch        *b_Y_Pi0_E;   //!
   TBranch        *b_Y_Pi0_M;   //!
   TBranch        *b_Y_Pi0_DeltaR;   //!
   TBranch        *b_Y_Pi0Ph1_CL;   //!
   TBranch        *b_Y_Pi0Ph2_CL;   //!
   TBranch        *b_p1_fromY_ETA;   //!
   TBranch        *b_p1_fromY_MC12TuneV2_ProbNNe;   //!
   TBranch        *b_p1_fromY_MC12TuneV2_ProbNNmu;   //!
   TBranch        *b_p1_fromY_MC12TuneV2_ProbNNpi;   //!
   TBranch        *b_p1_fromY_MC12TuneV2_ProbNNk;   //!
   TBranch        *b_p1_fromY_MC12TuneV2_ProbNNp;   //!
   TBranch        *b_p1_fromY_MC12TuneV2_ProbNNghost;   //!
   TBranch        *b_p1_fromY_MC12TuneV3_ProbNNe;   //!
   TBranch        *b_p1_fromY_MC12TuneV3_ProbNNmu;   //!
   TBranch        *b_p1_fromY_MC12TuneV3_ProbNNpi;   //!
   TBranch        *b_p1_fromY_MC12TuneV3_ProbNNk;   //!
   TBranch        *b_p1_fromY_MC12TuneV3_ProbNNp;   //!
   TBranch        *b_p1_fromY_MC12TuneV3_ProbNNghost;   //!
   TBranch        *b_p1_fromY_MC12TuneV4_ProbNNe;   //!
   TBranch        *b_p1_fromY_MC12TuneV4_ProbNNmu;   //!
   TBranch        *b_p1_fromY_MC12TuneV4_ProbNNpi;   //!
   TBranch        *b_p1_fromY_MC12TuneV4_ProbNNk;   //!
   TBranch        *b_p1_fromY_MC12TuneV4_ProbNNp;   //!
   TBranch        *b_p1_fromY_MC12TuneV4_ProbNNghost;   //!
   TBranch        *b_p1_fromY_MC15TuneV1_ProbNNe;   //!
   TBranch        *b_p1_fromY_MC15TuneV1_ProbNNmu;   //!
   TBranch        *b_p1_fromY_MC15TuneV1_ProbNNpi;   //!
   TBranch        *b_p1_fromY_MC15TuneV1_ProbNNk;   //!
   TBranch        *b_p1_fromY_MC15TuneV1_ProbNNp;   //!
   TBranch        *b_p1_fromY_MC15TuneV1_ProbNNghost;   //!
   TBranch        *b_p1_fromY_MINIP;   //!
   TBranch        *b_p1_fromY_MINIPCHI2;   //!
   TBranch        *b_p1_fromY_MINIPNEXTBEST;   //!
   TBranch        *b_p1_fromY_MINIPCHI2NEXTBEST;   //!
   TBranch        *b_p1_fromY_AllIP;   //!
   TBranch        *b_p1_fromY_AllIPchi2;   //!
   TBranch        *b_p1_fromY_AllDIRA;   //!
   TBranch        *b_p1_fromY_OWNPV_X;   //!
   TBranch        *b_p1_fromY_OWNPV_Y;   //!
   TBranch        *b_p1_fromY_OWNPV_Z;   //!
   TBranch        *b_p1_fromY_OWNPV_XERR;   //!
   TBranch        *b_p1_fromY_OWNPV_YERR;   //!
   TBranch        *b_p1_fromY_OWNPV_ZERR;   //!
   TBranch        *b_p1_fromY_OWNPV_CHI2;   //!
   TBranch        *b_p1_fromY_OWNPV_NDOF;   //!
   TBranch        *b_p1_fromY_OWNPV_COV_;   //!
   TBranch        *b_p1_fromY_IP_OWNPV;   //!
   TBranch        *b_p1_fromY_IPCHI2_OWNPV;   //!
   TBranch        *b_p1_fromY_TOPPV_X;   //!
   TBranch        *b_p1_fromY_TOPPV_Y;   //!
   TBranch        *b_p1_fromY_TOPPV_Z;   //!
   TBranch        *b_p1_fromY_TOPPV_XERR;   //!
   TBranch        *b_p1_fromY_TOPPV_YERR;   //!
   TBranch        *b_p1_fromY_TOPPV_ZERR;   //!
   TBranch        *b_p1_fromY_TOPPV_CHI2;   //!
   TBranch        *b_p1_fromY_TOPPV_NDOF;   //!
   TBranch        *b_p1_fromY_TOPPV_COV_;   //!
   TBranch        *b_p1_fromY_IP_TOPPV;   //!
   TBranch        *b_p1_fromY_IPCHI2_TOPPV;   //!
   TBranch        *b_p1_fromY_ORIVX_X;   //!
   TBranch        *b_p1_fromY_ORIVX_Y;   //!
   TBranch        *b_p1_fromY_ORIVX_Z;   //!
   TBranch        *b_p1_fromY_ORIVX_XERR;   //!
   TBranch        *b_p1_fromY_ORIVX_YERR;   //!
   TBranch        *b_p1_fromY_ORIVX_ZERR;   //!
   TBranch        *b_p1_fromY_ORIVX_CHI2;   //!
   TBranch        *b_p1_fromY_ORIVX_NDOF;   //!
   TBranch        *b_p1_fromY_ORIVX_COV_;   //!
   TBranch        *b_p1_fromY_IP_ORIVX;   //!
   TBranch        *b_p1_fromY_IPCHI2_ORIVX;   //!
   TBranch        *b_p1_fromY_Nb_NIsoTr;   //!
   TBranch        *b_p1_fromY_IsoMinBDT;   //!
   TBranch        *b_p1_fromY_ConeIso;   //!
   TBranch        *b_p1_fromY_PAIR_M;   //!
   TBranch        *b_p1_fromY_NIso_PAIR_VtxChi2;   //!
   TBranch        *b_p1_fromY_NIso_DCHI2;   //!
   TBranch        *b_p1_fromY_NIso_DIS;   //!
   TBranch        *b_p1_fromY_NIsoTr_VTXX;   //!
   TBranch        *b_p1_fromY_NIsoTr_VTXY;   //!
   TBranch        *b_p1_fromY_NIsoTr_VTXZ;   //!
   TBranch        *b_p1_fromY_PAIR_IPchi2;   //!
   TBranch        *b_p1_fromY_NIsoTr_PVDIS;   //!
   TBranch        *b_p1_fromY_NIsoTr_SVDIS;   //!
   TBranch        *b_p1_fromY_NIsoTr_DOCA;   //!
   TBranch        *b_p1_fromY_NIsoTr_ANGLE;   //!
   TBranch        *b_p1_fromY_NIsoTr_FC;   //!
   TBranch        *b_p1_fromY_Tr_MinIsoBDT;   //!
   TBranch        *b_p1_fromY_Tr_PAIR_VTXX;   //!
   TBranch        *b_p1_fromY_Tr_PAIR_VTXY;   //!
   TBranch        *b_p1_fromY_Tr_PAIR_VTXZ;   //!
   TBranch        *b_p1_fromY_Tr_PAIR_VTCHI2NDOF;   //!
   TBranch        *b_p1_fromY_Tr_FirstHitX;   //!
   TBranch        *b_p1_fromY_Tr_FirstHitY;   //!
   TBranch        *b_p1_fromY_Tr_FirstHitZ;   //!
   TBranch        *b_p1_fromY_Tr_DCHI2;   //!
   TBranch        *b_p1_fromY_Tr_DIS;   //!
   TBranch        *b_p1_fromY_Tr_MATCHCHI2;   //!
   TBranch        *b_p1_fromY_Tr_PVDIS;   //!
   TBranch        *b_p1_fromY_Tr_SVDIS;   //!
   TBranch        *b_p1_fromY_Tr_DOCA;   //!
   TBranch        *b_p1_fromY_Tr_ANGLE;   //!
   TBranch        *b_p1_fromY_Tr_FC_MU;   //!
   TBranch        *b_p1_fromY_NIsoTr_ETA;   //!
   TBranch        *b_p1_fromY_NIsoTr_PHI;   //!
   TBranch        *b_p1_fromY_NIsoTr_TRTYPE;   //!
   TBranch        *b_p1_fromY_NIsoTr_TRUEID;   //!
   TBranch        *b_p1_fromY_NIsoTr_MC_MOTHER_ID;   //!
   TBranch        *b_p1_fromY_NIsoTr_MC_MOTHER_KEY;   //!
   TBranch        *b_p1_fromY_NIsoTr_MC_GD_MOTHER_ID;   //!
   TBranch        *b_p1_fromY_NIsoTr_MC_GD_MOTHER_KEY;   //!
   TBranch        *b_p1_fromY_NIsoTr_MC_GD_GD_MOTHER_ID;   //!
   TBranch        *b_p1_fromY_NIsoTr_MC_GD_GD_MOTHER_KEY;   //!
   TBranch        *b_p1_fromY_P;   //!
   TBranch        *b_p1_fromY_PT;   //!
   TBranch        *b_p1_fromY_PE;   //!
   TBranch        *b_p1_fromY_PX;   //!
   TBranch        *b_p1_fromY_PY;   //!
   TBranch        *b_p1_fromY_PZ;   //!
   TBranch        *b_p1_fromY_M;   //!
   TBranch        *b_p1_fromY_ID;   //!
   TBranch        *b_p1_fromY_PIDe;   //!
   TBranch        *b_p1_fromY_PIDmu;   //!
   TBranch        *b_p1_fromY_PIDK;   //!
   TBranch        *b_p1_fromY_PIDp;   //!
   TBranch        *b_p1_fromY_PIDd;   //!
   TBranch        *b_p1_fromY_ProbNNe;   //!
   TBranch        *b_p1_fromY_ProbNNk;   //!
   TBranch        *b_p1_fromY_ProbNNp;   //!
   TBranch        *b_p1_fromY_ProbNNpi;   //!
   TBranch        *b_p1_fromY_ProbNNmu;   //!
   TBranch        *b_p1_fromY_ProbNNd;   //!
   TBranch        *b_p1_fromY_ProbNNghost;   //!
   TBranch        *b_p1_fromY_hasMuon;   //!
   TBranch        *b_p1_fromY_isMuon;   //!
   TBranch        *b_p1_fromY_hasRich;   //!
   TBranch        *b_p1_fromY_UsedRichAerogel;   //!
   TBranch        *b_p1_fromY_UsedRich1Gas;   //!
   TBranch        *b_p1_fromY_UsedRich2Gas;   //!
   TBranch        *b_p1_fromY_RichAboveElThres;   //!
   TBranch        *b_p1_fromY_RichAboveMuThres;   //!
   TBranch        *b_p1_fromY_RichAbovePiThres;   //!
   TBranch        *b_p1_fromY_RichAboveKaThres;   //!
   TBranch        *b_p1_fromY_RichAbovePrThres;   //!
   TBranch        *b_p1_fromY_hasCalo;   //!
   TBranch        *b_p1_fromY_TRACK_Type;   //!
   TBranch        *b_p1_fromY_TRACK_Key;   //!
   TBranch        *b_p1_fromY_TRACK_CHI2NDOF;   //!
   TBranch        *b_p1_fromY_TRACK_PCHI2;   //!
   TBranch        *b_p1_fromY_TRACK_MatchCHI2;   //!
   TBranch        *b_p1_fromY_TRACK_GhostProb;   //!
   TBranch        *b_p1_fromY_TRACK_CloneDist;   //!
   TBranch        *b_p1_fromY_TRACK_Likelihood;   //!
   TBranch        *b_p1_fromY_TRUEID;   //!
   TBranch        *b_p1_fromY_PANC_fromB;   //!
   TBranch        *b_p1_fromY_PANC_fromD;   //!
   TBranch        *b_p1_fromY_PANC_IDs;   //!
   TBranch        *b_p1_fromY_PANC_Keys;   //!
   TBranch        *b_p1_fromY_N_ANC;   //!
   TBranch        *b_p1_fromY_TRUEP_X;   //!
   TBranch        *b_p1_fromY_TRUEP_Y;   //!
   TBranch        *b_p1_fromY_TRUEP_Z;   //!
   TBranch        *b_p1_fromY_TRUEP_E;   //!
   
   TBranch        *b_p2_fromY_ETA;   //!
   TBranch        *b_p2_fromY_MC12TuneV2_ProbNNe;   //!
   TBranch        *b_p2_fromY_MC12TuneV2_ProbNNmu;   //!
   TBranch        *b_p2_fromY_MC12TuneV2_ProbNNpi;   //!
   TBranch        *b_p2_fromY_MC12TuneV2_ProbNNk;   //!
   TBranch        *b_p2_fromY_MC12TuneV2_ProbNNp;   //!
   TBranch        *b_p2_fromY_MC12TuneV2_ProbNNghost;   //!
   TBranch        *b_p2_fromY_MC12TuneV3_ProbNNe;   //!
   TBranch        *b_p2_fromY_MC12TuneV3_ProbNNmu;   //!
   TBranch        *b_p2_fromY_MC12TuneV3_ProbNNpi;   //!
   TBranch        *b_p2_fromY_MC12TuneV3_ProbNNk;   //!
   TBranch        *b_p2_fromY_MC12TuneV3_ProbNNp;   //!
   TBranch        *b_p2_fromY_MC12TuneV3_ProbNNghost;   //!
   TBranch        *b_p2_fromY_MC12TuneV4_ProbNNe;   //!
   TBranch        *b_p2_fromY_MC12TuneV4_ProbNNmu;   //!
   TBranch        *b_p2_fromY_MC12TuneV4_ProbNNpi;   //!
   TBranch        *b_p2_fromY_MC12TuneV4_ProbNNk;   //!
   TBranch        *b_p2_fromY_MC12TuneV4_ProbNNp;   //!
   TBranch        *b_p2_fromY_MC12TuneV4_ProbNNghost;   //!
   TBranch        *b_p2_fromY_MC15TuneV1_ProbNNe;   //!
   TBranch        *b_p2_fromY_MC15TuneV1_ProbNNmu;   //!
   TBranch        *b_p2_fromY_MC15TuneV1_ProbNNpi;   //!
   TBranch        *b_p2_fromY_MC15TuneV1_ProbNNk;   //!
   TBranch        *b_p2_fromY_MC15TuneV1_ProbNNp;   //!
   TBranch        *b_p2_fromY_MC15TuneV1_ProbNNghost;   //!
   TBranch        *b_p2_fromY_MINIP;   //!
   TBranch        *b_p2_fromY_MINIPCHI2;   //!
   TBranch        *b_p2_fromY_MINIPNEXTBEST;   //!
   TBranch        *b_p2_fromY_MINIPCHI2NEXTBEST;   //!
   TBranch        *b_p2_fromY_AllIP;   //!
   TBranch        *b_p2_fromY_AllIPchi2;   //!
   TBranch        *b_p2_fromY_AllDIRA;   //!
   TBranch        *b_p2_fromY_OWNPV_X;   //!
   TBranch        *b_p2_fromY_OWNPV_Y;   //!
   TBranch        *b_p2_fromY_OWNPV_Z;   //!
   TBranch        *b_p2_fromY_OWNPV_XERR;   //!
   TBranch        *b_p2_fromY_OWNPV_YERR;   //!
   TBranch        *b_p2_fromY_OWNPV_ZERR;   //!
   TBranch        *b_p2_fromY_OWNPV_CHI2;   //!
   TBranch        *b_p2_fromY_OWNPV_NDOF;   //!
   TBranch        *b_p2_fromY_OWNPV_COV_;   //!
   TBranch        *b_p2_fromY_IP_OWNPV;   //!
   TBranch        *b_p2_fromY_IPCHI2_OWNPV;   //!
   TBranch        *b_p2_fromY_TOPPV_X;   //!
   TBranch        *b_p2_fromY_TOPPV_Y;   //!
   TBranch        *b_p2_fromY_TOPPV_Z;   //!
   TBranch        *b_p2_fromY_TOPPV_XERR;   //!
   TBranch        *b_p2_fromY_TOPPV_YERR;   //!
   TBranch        *b_p2_fromY_TOPPV_ZERR;   //!
   TBranch        *b_p2_fromY_TOPPV_CHI2;   //!
   TBranch        *b_p2_fromY_TOPPV_NDOF;   //!
   TBranch        *b_p2_fromY_TOPPV_COV_;   //!
   TBranch        *b_p2_fromY_IP_TOPPV;   //!
   TBranch        *b_p2_fromY_IPCHI2_TOPPV;   //!
   TBranch        *b_p2_fromY_ORIVX_X;   //!
   TBranch        *b_p2_fromY_ORIVX_Y;   //!
   TBranch        *b_p2_fromY_ORIVX_Z;   //!
   TBranch        *b_p2_fromY_ORIVX_XERR;   //!
   TBranch        *b_p2_fromY_ORIVX_YERR;   //!
   TBranch        *b_p2_fromY_ORIVX_ZERR;   //!
   TBranch        *b_p2_fromY_ORIVX_CHI2;   //!
   TBranch        *b_p2_fromY_ORIVX_NDOF;   //!
   TBranch        *b_p2_fromY_ORIVX_COV_;   //!
   TBranch        *b_p2_fromY_IP_ORIVX;   //!
   TBranch        *b_p2_fromY_IPCHI2_ORIVX;   //!
   TBranch        *b_p2_fromY_Nb_NIsoTr;   //!
   TBranch        *b_p2_fromY_IsoMinBDT;   //!
   TBranch        *b_p2_fromY_ConeIso;   //!
   TBranch        *b_p2_fromY_PAIR_M;   //!
   TBranch        *b_p2_fromY_NIso_PAIR_VtxChi2;   //!
   TBranch        *b_p2_fromY_NIso_DCHI2;   //!
   TBranch        *b_p2_fromY_NIso_DIS;   //!
   TBranch        *b_p2_fromY_NIsoTr_VTXX;   //!
   TBranch        *b_p2_fromY_NIsoTr_VTXY;   //!
   TBranch        *b_p2_fromY_NIsoTr_VTXZ;   //!
   TBranch        *b_p2_fromY_PAIR_IPchi2;   //!
   TBranch        *b_p2_fromY_NIsoTr_PVDIS;   //!
   TBranch        *b_p2_fromY_NIsoTr_SVDIS;   //!
   TBranch        *b_p2_fromY_NIsoTr_DOCA;   //!
   TBranch        *b_p2_fromY_NIsoTr_ANGLE;   //!
   TBranch        *b_p2_fromY_NIsoTr_FC;   //!
   TBranch        *b_p2_fromY_Tr_MinIsoBDT;   //!
   TBranch        *b_p2_fromY_Tr_PAIR_VTXX;   //!
   TBranch        *b_p2_fromY_Tr_PAIR_VTXY;   //!
   TBranch        *b_p2_fromY_Tr_PAIR_VTXZ;   //!
   TBranch        *b_p2_fromY_Tr_PAIR_VTCHI2NDOF;   //!
   TBranch        *b_p2_fromY_Tr_FirstHitX;   //!
   TBranch        *b_p2_fromY_Tr_FirstHitY;   //!
   TBranch        *b_p2_fromY_Tr_FirstHitZ;   //!
   TBranch        *b_p2_fromY_Tr_DCHI2;   //!
   TBranch        *b_p2_fromY_Tr_DIS;   //!
   TBranch        *b_p2_fromY_Tr_MATCHCHI2;   //!
   TBranch        *b_p2_fromY_Tr_PVDIS;   //!
   TBranch        *b_p2_fromY_Tr_SVDIS;   //!
   TBranch        *b_p2_fromY_Tr_DOCA;   //!
   TBranch        *b_p2_fromY_Tr_ANGLE;   //!
   TBranch        *b_p2_fromY_Tr_FC_MU;   //!
   TBranch        *b_p2_fromY_NIsoTr_ETA;   //!
   TBranch        *b_p2_fromY_NIsoTr_PHI;   //!
   TBranch        *b_p2_fromY_NIsoTr_TRTYPE;   //!
   TBranch        *b_p2_fromY_NIsoTr_TRUEID;   //!
   TBranch        *b_p2_fromY_NIsoTr_MC_MOTHER_ID;   //!
   TBranch        *b_p2_fromY_NIsoTr_MC_MOTHER_KEY;   //!
   TBranch        *b_p2_fromY_NIsoTr_MC_GD_MOTHER_ID;   //!
   TBranch        *b_p2_fromY_NIsoTr_MC_GD_MOTHER_KEY;   //!
   TBranch        *b_p2_fromY_NIsoTr_MC_GD_GD_MOTHER_ID;   //!
   TBranch        *b_p2_fromY_NIsoTr_MC_GD_GD_MOTHER_KEY;   //!
   TBranch        *b_p2_fromY_P;   //!
   TBranch        *b_p2_fromY_PT;   //!
   TBranch        *b_p2_fromY_PE;   //!
   TBranch        *b_p2_fromY_PX;   //!
   TBranch        *b_p2_fromY_PY;   //!
   TBranch        *b_p2_fromY_PZ;   //!
   TBranch        *b_p2_fromY_M;   //!
   TBranch        *b_p2_fromY_ID;   //!
   TBranch        *b_p2_fromY_PIDe;   //!
   TBranch        *b_p2_fromY_PIDmu;   //!
   TBranch        *b_p2_fromY_PIDK;   //!
   TBranch        *b_p2_fromY_PIDp;   //!
   TBranch        *b_p2_fromY_PIDd;   //!
   TBranch        *b_p2_fromY_ProbNNe;   //!
   TBranch        *b_p2_fromY_ProbNNk;   //!
   TBranch        *b_p2_fromY_ProbNNp;   //!
   TBranch        *b_p2_fromY_ProbNNpi;   //!
   TBranch        *b_p2_fromY_ProbNNmu;   //!
   TBranch        *b_p2_fromY_ProbNNd;   //!
   TBranch        *b_p2_fromY_ProbNNghost;   //!
   TBranch        *b_p2_fromY_hasMuon;   //!
   TBranch        *b_p2_fromY_isMuon;   //!
   TBranch        *b_p2_fromY_hasRich;   //!
   TBranch        *b_p2_fromY_UsedRichAerogel;   //!
   TBranch        *b_p2_fromY_UsedRich1Gas;   //!
   TBranch        *b_p2_fromY_UsedRich2Gas;   //!
   TBranch        *b_p2_fromY_RichAboveElThres;   //!
   TBranch        *b_p2_fromY_RichAboveMuThres;   //!
   TBranch        *b_p2_fromY_RichAbovePiThres;   //!
   TBranch        *b_p2_fromY_RichAboveKaThres;   //!
   TBranch        *b_p2_fromY_RichAbovePrThres;   //!
   TBranch        *b_p2_fromY_hasCalo;   //!
   TBranch        *b_p2_fromY_TRACK_Type;   //!
   TBranch        *b_p2_fromY_TRACK_Key;   //!
   TBranch        *b_p2_fromY_TRACK_CHI2NDOF;   //!
   TBranch        *b_p2_fromY_TRACK_PCHI2;   //!
   TBranch        *b_p2_fromY_TRACK_MatchCHI2;   //!
   TBranch        *b_p2_fromY_TRACK_GhostProb;   //!
   TBranch        *b_p2_fromY_TRACK_CloneDist;   //!
   TBranch        *b_p2_fromY_TRACK_Likelihood;   //!
   TBranch        *b_p2_fromY_TRUEID;   //!
   TBranch        *b_p2_fromY_PANC_fromB;   //!
   TBranch        *b_p2_fromY_PANC_fromD;   //!
   TBranch        *b_p2_fromY_PANC_IDs;   //!
   TBranch        *b_p2_fromY_PANC_Keys;   //!
   TBranch        *b_p2_fromY_N_ANC;   //!
   TBranch        *b_p2_fromY_TRUEP_X;   //!
   TBranch        *b_p2_fromY_TRUEP_Y;   //!
   TBranch        *b_p2_fromY_TRUEP_Z;   //!
   TBranch        *b_p2_fromY_TRUEP_E;   //!

   TBranch        *b_p3_fromY_ETA;   //!
   TBranch        *b_p3_fromY_MC12TuneV2_ProbNNe;   //!
   TBranch        *b_p3_fromY_MC12TuneV2_ProbNNmu;   //!
   TBranch        *b_p3_fromY_MC12TuneV2_ProbNNpi;   //!
   TBranch        *b_p3_fromY_MC12TuneV2_ProbNNk;   //!
   TBranch        *b_p3_fromY_MC12TuneV2_ProbNNp;   //!
   TBranch        *b_p3_fromY_MC12TuneV2_ProbNNghost;   //!
   TBranch        *b_p3_fromY_MC12TuneV3_ProbNNe;   //!
   TBranch        *b_p3_fromY_MC12TuneV3_ProbNNmu;   //!
   TBranch        *b_p3_fromY_MC12TuneV3_ProbNNpi;   //!
   TBranch        *b_p3_fromY_MC12TuneV3_ProbNNk;   //!
   TBranch        *b_p3_fromY_MC12TuneV3_ProbNNp;   //!
   TBranch        *b_p3_fromY_MC12TuneV3_ProbNNghost;   //!
   TBranch        *b_p3_fromY_MC12TuneV4_ProbNNe;   //!
   TBranch        *b_p3_fromY_MC12TuneV4_ProbNNmu;   //!
   TBranch        *b_p3_fromY_MC12TuneV4_ProbNNpi;   //!
   TBranch        *b_p3_fromY_MC12TuneV4_ProbNNk;   //!
   TBranch        *b_p3_fromY_MC12TuneV4_ProbNNp;   //!
   TBranch        *b_p3_fromY_MC12TuneV4_ProbNNghost;   //!
   TBranch        *b_p3_fromY_MC15TuneV1_ProbNNe;   //!
   TBranch        *b_p3_fromY_MC15TuneV1_ProbNNmu;   //!
   TBranch        *b_p3_fromY_MC15TuneV1_ProbNNpi;   //!
   TBranch        *b_p3_fromY_MC15TuneV1_ProbNNk;   //!
   TBranch        *b_p3_fromY_MC15TuneV1_ProbNNp;   //!
   TBranch        *b_p3_fromY_MC15TuneV1_ProbNNghost;   //!
   TBranch        *b_p3_fromY_MINIP;   //!
   TBranch        *b_p3_fromY_MINIPCHI2;   //!
   TBranch        *b_p3_fromY_MINIPNEXTBEST;   //!
   TBranch        *b_p3_fromY_MINIPCHI2NEXTBEST;   //!
   TBranch        *b_p3_fromY_AllIP;   //!
   TBranch        *b_p3_fromY_AllIPchi2;   //!
   TBranch        *b_p3_fromY_AllDIRA;   //!
   TBranch        *b_p3_fromY_OWNPV_X;   //!
   TBranch        *b_p3_fromY_OWNPV_Y;   //!
   TBranch        *b_p3_fromY_OWNPV_Z;   //!
   TBranch        *b_p3_fromY_OWNPV_XERR;   //!
   TBranch        *b_p3_fromY_OWNPV_YERR;   //!
   TBranch        *b_p3_fromY_OWNPV_ZERR;   //!
   TBranch        *b_p3_fromY_OWNPV_CHI2;   //!
   TBranch        *b_p3_fromY_OWNPV_NDOF;   //!
   TBranch        *b_p3_fromY_OWNPV_COV_;   //!
   TBranch        *b_p3_fromY_IP_OWNPV;   //!
   TBranch        *b_p3_fromY_IPCHI2_OWNPV;   //!
   TBranch        *b_p3_fromY_TOPPV_X;   //!
   TBranch        *b_p3_fromY_TOPPV_Y;   //!
   TBranch        *b_p3_fromY_TOPPV_Z;   //!
   TBranch        *b_p3_fromY_TOPPV_XERR;   //!
   TBranch        *b_p3_fromY_TOPPV_YERR;   //!
   TBranch        *b_p3_fromY_TOPPV_ZERR;   //!
   TBranch        *b_p3_fromY_TOPPV_CHI2;   //!
   TBranch        *b_p3_fromY_TOPPV_NDOF;   //!
   TBranch        *b_p3_fromY_TOPPV_COV_;   //!
   TBranch        *b_p3_fromY_IP_TOPPV;   //!
   TBranch        *b_p3_fromY_IPCHI2_TOPPV;   //!
   TBranch        *b_p3_fromY_ORIVX_X;   //!
   TBranch        *b_p3_fromY_ORIVX_Y;   //!
   TBranch        *b_p3_fromY_ORIVX_Z;   //!
   TBranch        *b_p3_fromY_ORIVX_XERR;   //!
   TBranch        *b_p3_fromY_ORIVX_YERR;   //!
   TBranch        *b_p3_fromY_ORIVX_ZERR;   //!
   TBranch        *b_p3_fromY_ORIVX_CHI2;   //!
   TBranch        *b_p3_fromY_ORIVX_NDOF;   //!
   TBranch        *b_p3_fromY_ORIVX_COV_;   //!
   TBranch        *b_p3_fromY_IP_ORIVX;   //!
   TBranch        *b_p3_fromY_IPCHI2_ORIVX;   //!
   TBranch        *b_p3_fromY_Nb_NIsoTr;   //!
   TBranch        *b_p3_fromY_IsoMinBDT;   //!
   TBranch        *b_p3_fromY_ConeIso;   //!
   TBranch        *b_p3_fromY_PAIR_M;   //!
   TBranch        *b_p3_fromY_NIso_PAIR_VtxChi2;   //!
   TBranch        *b_p3_fromY_NIso_DCHI2;   //!
   TBranch        *b_p3_fromY_NIso_DIS;   //!
   TBranch        *b_p3_fromY_NIsoTr_VTXX;   //!
   TBranch        *b_p3_fromY_NIsoTr_VTXY;   //!
   TBranch        *b_p3_fromY_NIsoTr_VTXZ;   //!
   TBranch        *b_p3_fromY_PAIR_IPchi2;   //!
   TBranch        *b_p3_fromY_NIsoTr_PVDIS;   //!
   TBranch        *b_p3_fromY_NIsoTr_SVDIS;   //!
   TBranch        *b_p3_fromY_NIsoTr_DOCA;   //!
   TBranch        *b_p3_fromY_NIsoTr_ANGLE;   //!
   TBranch        *b_p3_fromY_NIsoTr_FC;   //!
   TBranch        *b_p3_fromY_Tr_MinIsoBDT;   //!
   TBranch        *b_p3_fromY_Tr_PAIR_VTXX;   //!
   TBranch        *b_p3_fromY_Tr_PAIR_VTXY;   //!
   TBranch        *b_p3_fromY_Tr_PAIR_VTXZ;   //!
   TBranch        *b_p3_fromY_Tr_PAIR_VTCHI2NDOF;   //!
   TBranch        *b_p3_fromY_Tr_FirstHitX;   //!
   TBranch        *b_p3_fromY_Tr_FirstHitY;   //!
   TBranch        *b_p3_fromY_Tr_FirstHitZ;   //!
   TBranch        *b_p3_fromY_Tr_DCHI2;   //!
   TBranch        *b_p3_fromY_Tr_DIS;   //!
   TBranch        *b_p3_fromY_Tr_MATCHCHI2;   //!
   TBranch        *b_p3_fromY_Tr_PVDIS;   //!
   TBranch        *b_p3_fromY_Tr_SVDIS;   //!
   TBranch        *b_p3_fromY_Tr_DOCA;   //!
   TBranch        *b_p3_fromY_Tr_ANGLE;   //!
   TBranch        *b_p3_fromY_Tr_FC_MU;   //!
   TBranch        *b_p3_fromY_NIsoTr_ETA;   //!
   TBranch        *b_p3_fromY_NIsoTr_PHI;   //!
   TBranch        *b_p3_fromY_NIsoTr_TRTYPE;   //!
   TBranch        *b_p3_fromY_NIsoTr_TRUEID;   //!
   TBranch        *b_p3_fromY_NIsoTr_MC_MOTHER_ID;   //!
   TBranch        *b_p3_fromY_NIsoTr_MC_MOTHER_KEY;   //!
   TBranch        *b_p3_fromY_NIsoTr_MC_GD_MOTHER_ID;   //!
   TBranch        *b_p3_fromY_NIsoTr_MC_GD_MOTHER_KEY;   //!
   TBranch        *b_p3_fromY_NIsoTr_MC_GD_GD_MOTHER_ID;   //!
   TBranch        *b_p3_fromY_NIsoTr_MC_GD_GD_MOTHER_KEY;   //!
   TBranch        *b_p3_fromY_P;   //!
   TBranch        *b_p3_fromY_PT;   //!
   TBranch        *b_p3_fromY_PE;   //!
   TBranch        *b_p3_fromY_PX;   //!
   TBranch        *b_p3_fromY_PY;   //!
   TBranch        *b_p3_fromY_PZ;   //!
   TBranch        *b_p3_fromY_M;   //!
   TBranch        *b_p3_fromY_ID;   //!
   TBranch        *b_p3_fromY_PIDe;   //!
   TBranch        *b_p3_fromY_PIDmu;   //!
   TBranch        *b_p3_fromY_PIDK;   //!
   TBranch        *b_p3_fromY_PIDp;   //!
   TBranch        *b_p3_fromY_PIDd;   //!
   TBranch        *b_p3_fromY_ProbNNe;   //!
   TBranch        *b_p3_fromY_ProbNNk;   //!
   TBranch        *b_p3_fromY_ProbNNp;   //!
   TBranch        *b_p3_fromY_ProbNNpi;   //!
   TBranch        *b_p3_fromY_ProbNNmu;   //!
   TBranch        *b_p3_fromY_ProbNNd;   //!
   TBranch        *b_p3_fromY_ProbNNghost;   //!
   TBranch        *b_p3_fromY_hasMuon;   //!
   TBranch        *b_p3_fromY_isMuon;   //!
   TBranch        *b_p3_fromY_hasRich;   //!
   TBranch        *b_p3_fromY_UsedRichAerogel;   //!
   TBranch        *b_p3_fromY_UsedRich1Gas;   //!
   TBranch        *b_p3_fromY_UsedRich2Gas;   //!
   TBranch        *b_p3_fromY_RichAboveElThres;   //!
   TBranch        *b_p3_fromY_RichAboveMuThres;   //!
   TBranch        *b_p3_fromY_RichAbovePiThres;   //!
   TBranch        *b_p3_fromY_RichAboveKaThres;   //!
   TBranch        *b_p3_fromY_RichAbovePrThres;   //!
   TBranch        *b_p3_fromY_hasCalo;   //!
   TBranch        *b_p3_fromY_TRACK_Type;   //!
   TBranch        *b_p3_fromY_TRACK_Key;   //!
   TBranch        *b_p3_fromY_TRACK_CHI2NDOF;   //!
   TBranch        *b_p3_fromY_TRACK_PCHI2;   //!
   TBranch        *b_p3_fromY_TRACK_MatchCHI2;   //!
   TBranch        *b_p3_fromY_TRACK_GhostProb;   //!
   TBranch        *b_p3_fromY_TRACK_CloneDist;   //!
   TBranch        *b_p3_fromY_TRACK_Likelihood;   //!
   TBranch        *b_p3_fromY_TRUEID;   //!
   TBranch        *b_p3_fromY_PANC_fromB;   //!
   TBranch        *b_p3_fromY_PANC_fromD;   //!
   TBranch        *b_p3_fromY_PANC_IDs;   //!
   TBranch        *b_p3_fromY_PANC_Keys;   //!
   TBranch        *b_p3_fromY_N_ANC;   //!
   TBranch        *b_p3_fromY_TRUEP_X;   //!
   TBranch        *b_p3_fromY_TRUEP_Y;   //!
   TBranch        *b_p3_fromY_TRUEP_Z;   //!
   TBranch        *b_p3_fromY_TRUEP_E;   //!

   TBranch        *b_nCandidate;   //!
   TBranch        *b_totCandidates;   //!
   TBranch        *b_EventInSequence;   //!
   TBranch        *b_runNumber;   //!
   TBranch        *b_eventNumber;   //!
   TBranch        *b_BCID;   //!
   TBranch        *b_BCType;   //!
   TBranch        *b_OdinTCK;   //!
   TBranch        *b_L0DUTCK;   //!
   TBranch        *b_HLT1TCK;   //!
   TBranch        *b_HLT2TCK;   //!
   TBranch        *b_GpsTime;   //!
   TBranch        *b_Polarity;   //!
   TBranch        *b_PVX;   //!
   TBranch        *b_PVY;   //!
   TBranch        *b_PVZ;   //!
   TBranch        *b_PVXERR;   //!
   TBranch        *b_PVYERR;   //!
   TBranch        *b_PVZERR;   //!
   TBranch        *b_PVCHI2;   //!
   TBranch        *b_PVNDOF;   //!
   TBranch        *b_PVNTRACKS;   //!
   TBranch        *b_nPVs;   //!
   TBranch        *b_nTracks;   //!
   TBranch        *b_nLongTracks;   //!
   TBranch        *b_nDownstreamTracks;   //!
   TBranch        *b_nUpstreamTracks;   //!
   TBranch        *b_nVeloTracks;   //!
   TBranch        *b_nTTracks;   //!
   TBranch        *b_nBackTracks;   //!
   TBranch        *b_nRich1Hits;   //!
   TBranch        *b_nRich2Hits;   //!
   TBranch        *b_nVeloClusters;   //!
   TBranch        *b_nITClusters;   //!
   TBranch        *b_nTTClusters;   //!
   TBranch        *b_nOTClusters;   //!
   TBranch        *b_nSPDHits;   //!
   TBranch        *b_nMuonCoordsS0;   //!
   TBranch        *b_nMuonCoordsS1;   //!
   TBranch        *b_nMuonCoordsS2;   //!
   TBranch        *b_nMuonCoordsS3;   //!
   TBranch        *b_nMuonCoordsS4;   //!
   TBranch        *b_nMuonTracks;   //!
   TBranch        *b_L0Global;   //!
   TBranch        *b_Hlt1Global;   //!
   TBranch        *b_Hlt2Global;   //!
   TBranch        *b_L0HadronDecision;   //!
   TBranch        *b_L0GlobalDecision;   //!
   TBranch        *b_L0nSelections;   //!
   TBranch        *b_Hlt1GlobalDecision;   //!
   TBranch        *b_Hlt1TrackAllL0Decision;   //!
   TBranch        *b_Hlt1TrackAllL0TightDecision;   //!
   TBranch        *b_Hlt1nSelections;   //!
   TBranch        *b_Hlt2GlobalDecision;   //!
   TBranch        *b_Hlt2Topo2BodyBBDTDecision;   //!
   TBranch        *b_Hlt2Topo3BodyBBDTDecision;   //!
   TBranch        *b_Hlt2Topo4BodyBBDTDecision;   //!
   TBranch        *b_Hlt2Topo2BodySimpleDecision;   //!
   TBranch        *b_Hlt2Topo3BodySimpleDecision;   //!
   TBranch        *b_Hlt2Topo4BodySimpleDecision;   //!
   TBranch        *b_Hlt2IncPhiDecision;   //!
   TBranch        *b_Hlt2IncPhiSidebandsDecision;   //!
   TBranch        *b_Hlt2CharmHadD2HHHDecision;   //!
   TBranch        *b_Hlt2CharmHadD2HHHWideMassDecision;   //!
   TBranch        *b_Hlt2nSelections;   //!
   TBranch        *b_MaxRoutingBits;   //!
   TBranch        *b_RoutingBits;   //!
   TBranch        *b_p1_fromXc_PIDK_corr;   //!
   TBranch        *b_p1_fromXc_PIDp_corr;   //!
   TBranch        *b_p2_fromXc_PIDK_corr;   //!
   TBranch        *b_p2_fromXc_PIDp_corr;   //!
   TBranch        *b_p3_fromXc_PIDK_corr;   //!
   TBranch        *b_p3_fromXc_PIDp_corr;   //!
   TBranch        *b_p1_fromY_PIDK_corr;   //!
   TBranch        *b_p1_fromY_PIDp_corr;   //!
   TBranch        *b_p2_fromY_PIDK_corr;   //!
   TBranch        *b_p2_fromY_PIDp_corr;   //!
   TBranch        *b_p3_fromY_PIDK_corr;   //!
   TBranch        *b_p3_fromY_PIDp_corr;   //!

   TBranch        *b_p1_fromY_K_PIDK_corr;   //!
   TBranch        *b_p1_fromY_pi_PIDK_corr;   //!
   TBranch        *b_p2_fromY_K_PIDK_corr;   //!
   TBranch        *b_p2_fromY_pi_PIDK_corr;   //!
   TBranch        *b_p3_fromY_K_PIDK_corr;   //!
   TBranch        *b_p3_fromY_pi_PIDK_corr;   //!

   TBranch        *b_p1_fromXc_PIDK_pidgen_default;   //!
   TBranch        *b_p1_fromXc_PIDp_pidgen_default;   //!
   TBranch        *b_p2_fromXc_PIDK_pidgen_default;   //!
   TBranch        *b_p2_fromXc_PIDp_pidgen_default;   //!
   TBranch        *b_p3_fromXc_PIDK_pidgen_default;   //!
   TBranch        *b_p3_fromXc_PIDp_pidgen_default;   //!

   TBranch        *b_p1_fromY_PIDK_pidgen_default;   //!
   TBranch        *b_p1_fromY_PIDp_pidgen_default;   //!
   TBranch        *b_p2_fromY_PIDK_pidgen_default;   //!
   TBranch        *b_p2_fromY_PIDp_pidgen_default;   //!
   TBranch        *b_p3_fromY_PIDK_pidgen_default;   //!
   TBranch        *b_p3_fromY_PIDp_pidgen_default;   //!

   TBranch        *b_p1_fromY_K_PIDK_pidgen_default;   //!
   TBranch        *b_p1_fromY_pi_PIDK_pidgen_default;   //!
   TBranch        *b_p2_fromY_K_PIDK_pidgen_default;   //!
   TBranch        *b_p2_fromY_pi_PIDK_pidgen_default;   //!
   TBranch        *b_p3_fromY_K_PIDK_pidgen_default;   //!
   TBranch        *b_p3_fromY_pi_PIDK_pidgen_default;   //!

   Int_t           p1_fromXc_MC_MOTHER_ID;
   Int_t           p1_fromXc_MC_MOTHER_KEY;
   Int_t           p1_fromXc_MC_GD_MOTHER_ID;
   Int_t           p1_fromXc_MC_GD_MOTHER_KEY;
   Int_t           p1_fromXc_MC_GD_GD_MOTHER_ID;
   Int_t           p1_fromXc_MC_GD_GD_MOTHER_KEY;
   Double_t        p1_fromXc_TRUEP_E;
   Double_t        p1_fromXc_TRUEP_X;
   Double_t        p1_fromXc_TRUEP_Y;
   Double_t        p1_fromXc_TRUEP_Z;
   Double_t        p1_fromXc_TRUEPT;
   Double_t        p1_fromXc_TRUEORIGINVERTEX_X;
   Double_t        p1_fromXc_TRUEORIGINVERTEX_Y;
   Double_t        p1_fromXc_TRUEORIGINVERTEX_Z;
   Double_t        p1_fromXc_TRUEENDVERTEX_X;
   Double_t        p1_fromXc_TRUEENDVERTEX_Y;
   Double_t        p1_fromXc_TRUEENDVERTEX_Z;
   Bool_t          p1_fromXc_TRUEISSTABLE;
   Double_t        p1_fromXc_TRUETAU;
//
   Int_t           p2_fromXc_MC_MOTHER_ID;
   Int_t           p2_fromXc_MC_MOTHER_KEY;
   Int_t           p2_fromXc_MC_GD_MOTHER_ID;
   Int_t           p2_fromXc_MC_GD_MOTHER_KEY;
   Int_t           p2_fromXc_MC_GD_GD_MOTHER_ID;
   Int_t           p2_fromXc_MC_GD_GD_MOTHER_KEY;
   Double_t        p2_fromXc_TRUEP_E;
   Double_t        p2_fromXc_TRUEP_X;
   Double_t        p2_fromXc_TRUEP_Y;
   Double_t        p2_fromXc_TRUEP_Z;
   Double_t        p2_fromXc_TRUEPT;
   Double_t        p2_fromXc_TRUEORIGINVERTEX_X;
   Double_t        p2_fromXc_TRUEORIGINVERTEX_Y;
   Double_t        p2_fromXc_TRUEORIGINVERTEX_Z;
   Double_t        p2_fromXc_TRUEENDVERTEX_X;
   Double_t        p2_fromXc_TRUEENDVERTEX_Y;
   Double_t        p2_fromXc_TRUEENDVERTEX_Z;
   Bool_t          p2_fromXc_TRUEISSTABLE;
   Double_t        p2_fromXc_TRUETAU;
//
   Int_t           p3_fromXc_MC_MOTHER_ID;
   Int_t           p3_fromXc_MC_MOTHER_KEY;
   Int_t           p3_fromXc_MC_GD_MOTHER_ID;
   Int_t           p3_fromXc_MC_GD_MOTHER_KEY;
   Int_t           p3_fromXc_MC_GD_GD_MOTHER_ID;
   Int_t           p3_fromXc_MC_GD_GD_MOTHER_KEY;
   Double_t        p3_fromXc_TRUEP_E;
   Double_t        p3_fromXc_TRUEP_X;
   Double_t        p3_fromXc_TRUEP_Y;
   Double_t        p3_fromXc_TRUEP_Z;
   Double_t        p3_fromXc_TRUEPT;
   Double_t        p3_fromXc_TRUEORIGINVERTEX_X;
   Double_t        p3_fromXc_TRUEORIGINVERTEX_Y;
   Double_t        p3_fromXc_TRUEORIGINVERTEX_Z;
   Double_t        p3_fromXc_TRUEENDVERTEX_X;
   Double_t        p3_fromXc_TRUEENDVERTEX_Y;
   Double_t        p3_fromXc_TRUEENDVERTEX_Z;
   Bool_t          p3_fromXc_TRUEISSTABLE;
   Double_t        p3_fromXc_TRUETAU;
//


   Int_t           p1_fromY_MC_MOTHER_ID;
   Int_t           p1_fromY_MC_MOTHER_KEY;
   Int_t           p1_fromY_MC_GD_MOTHER_ID;
   Int_t           p1_fromY_MC_GD_MOTHER_KEY;
   Int_t           p1_fromY_MC_GD_GD_MOTHER_ID;
   Int_t           p1_fromY_MC_GD_GD_MOTHER_KEY;
   Double_t        p1_fromY_TRUEP_E;
   Double_t        p1_fromY_TRUEP_X;
   Double_t        p1_fromY_TRUEP_Y;
   Double_t        p1_fromY_TRUEP_Z;
   Double_t        p1_fromY_TRUEPT;
   Double_t        p1_fromY_TRUEORIGINVERTEX_X;
   Double_t        p1_fromY_TRUEORIGINVERTEX_Y;
   Double_t        p1_fromY_TRUEORIGINVERTEX_Z;
   Double_t        p1_fromY_TRUEENDVERTEX_X;
   Double_t        p1_fromY_TRUEENDVERTEX_Y;
   Double_t        p1_fromY_TRUEENDVERTEX_Z;
   Bool_t          p1_fromY_TRUEISSTABLE;
   Double_t        p1_fromY_TRUETAU;
//
   Int_t           p2_fromY_MC_MOTHER_ID;
   Int_t           p2_fromY_MC_MOTHER_KEY;
   Int_t           p2_fromY_MC_GD_MOTHER_ID;
   Int_t           p2_fromY_MC_GD_MOTHER_KEY;
   Int_t           p2_fromY_MC_GD_GD_MOTHER_ID;
   Int_t           p2_fromY_MC_GD_GD_MOTHER_KEY;
   Double_t        p2_fromY_TRUEP_E;
   Double_t        p2_fromY_TRUEP_X;
   Double_t        p2_fromY_TRUEP_Y;
   Double_t        p2_fromY_TRUEP_Z;
   Double_t        p2_fromY_TRUEPT;
   Double_t        p2_fromY_TRUEORIGINVERTEX_X;
   Double_t        p2_fromY_TRUEORIGINVERTEX_Y;
   Double_t        p2_fromY_TRUEORIGINVERTEX_Z;
   Double_t        p2_fromY_TRUEENDVERTEX_X;
   Double_t        p2_fromY_TRUEENDVERTEX_Y;
   Double_t        p2_fromY_TRUEENDVERTEX_Z;
   Bool_t          p2_fromY_TRUEISSTABLE;
   Double_t        p2_fromY_TRUETAU;
//
   Int_t           p3_fromY_MC_MOTHER_ID;
   Int_t           p3_fromY_MC_MOTHER_KEY;
   Int_t           p3_fromY_MC_GD_MOTHER_ID;
   Int_t           p3_fromY_MC_GD_MOTHER_KEY;
   Int_t           p3_fromY_MC_GD_GD_MOTHER_ID;
   Int_t           p3_fromY_MC_GD_GD_MOTHER_KEY;
   Double_t        p3_fromY_TRUEP_E;
   Double_t        p3_fromY_TRUEP_X;
   Double_t        p3_fromY_TRUEP_Y;
   Double_t        p3_fromY_TRUEP_Z;
   Double_t        p3_fromY_TRUEPT;
   Double_t        p3_fromY_TRUEORIGINVERTEX_X;
   Double_t        p3_fromY_TRUEORIGINVERTEX_Y;
   Double_t        p3_fromY_TRUEORIGINVERTEX_Z;
   Double_t        p3_fromY_TRUEENDVERTEX_X;
   Double_t        p3_fromY_TRUEENDVERTEX_Y;
   Double_t        p3_fromY_TRUEENDVERTEX_Z;
   Bool_t          p3_fromY_TRUEISSTABLE;
   Double_t        p3_fromY_TRUETAU;
//


