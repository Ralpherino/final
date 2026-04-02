#define BsSignalCUT_cxx
#include <TMVA/Reader.h>
#define MC 
#ifdef MC
#define PIDcorr  
#endif
//#define BsNORM  // abilita la giusta richiesta delle BKGCAT per BsDs3pi

#define TRIGGER
#define BDTcut  // writes only events passing the BDT_3pi, BDT_Ds and BDT_Bs selection
//#define WS

#include "BsSignalCUT.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

void BsSignalCUT::Loop()
{
//   In a ROOT session, you can do:
//      root> .L BsSignalCUT.C
//      root> BsSignalCUT t
//      root> t.GetEntry(12); // Fill t data members with entry number 12
//      root> t.Show();       // Show values of entry 12
//      root> t.Show(16);     // Read and show values of entry 16
//      root> t.Loop();       // Loop on all entries
//

//     This is the loop skeleton where:
//    jentry is the global entry number in the chain
//    ientry is the entry number in the current Tree
//  Note that the argument to GetEntry must be:
//    jentry for TChain::GetEntry
//    ientry for TTree::GetEntry and TBranch::GetEntry
//
//       To read only selected branches, Insert statements like:
// METHOD1:
//    fChain->SetBranchStatus("*",0);  // disable all branches
//    fChain->SetBranchStatus("branchname",1);  // activate branchname
// METHOD2: replace line
//    fChain->GetEntry(jentry);       //read all branches
//by  b_branchname->GetEntry(ientry); //read only this branch
  Float_t factor=1;  
#ifdef MC
  factor = exp(0.6); // Factor applied to MC GhostProbability to match data distribution
#endif  
   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriesFast();

   TString weightFile_BDT_3pi   = "TMVA/TMVAClassification_3pi_BDT.weights.xml";
   TString weightFile_BDT_Ds   = "TMVA/TMVAClassification_Ds_BDT.weights.xml";
   TString weightFile_BDT_Bs = "TMVA/TMVAClassification_Bs_BDT.weights.xml";

   // IsoGeneric charged track
   TString weightFile_BDTIso = "TMVA/TMVAClassification_test_BDT_prova1bis_plusBDTBs_KEY.weights.xml";
   
   TMVA::Reader *reader_Iso = new TMVA::Reader("!Color:!Silent");   
   Float_t var_Iso[5];
   reader_Iso->AddVariable("minimum_IsoMinBDT",&var_Iso[0]);   
   reader_Iso->AddVariable("minimum_Nb_NIsoTr",&var_Iso[1]);   
   reader_Iso->AddVariable("minimum_ConeIso",&var_Iso[2]);   
   reader_Iso->AddVariable("minimum_PAIR_M",&var_Iso[3]);   
   reader_Iso->AddVariable("BDT_Bs",&var_Iso[4]);
   Float_t spec_Iso[2];
   reader_Iso->AddSpectator( "B_MM",&spec_Iso[0]);   
   reader_Iso->AddSpectator( "Xc_MM",&spec_Iso[1]);
   reader_Iso->BookMVA("BDT method",  weightFile_BDTIso   );
   


   //ConeSize 0.20 bis
   TString weightFile_Fisher_nc_020_mult0 = "TMVA/TMVAClassification_nc_020_mult0_Fisher.weights.xml";   
   TMVA::Reader *reader_nc_020_mult0 = new TMVA::Reader("!Color:!Silent");   
   Float_t var_nc_020_mult0[1];   
   reader_nc_020_mult0->AddVariable( "Xc_pT_Breco_Yreco",&var_nc_020_mult0[0]);
   Float_t spec_nc_020_mult0[3];
   reader_nc_020_mult0->AddSpectator( "B_MM",&spec_nc_020_mult0[0]);
   reader_nc_020_mult0->AddSpectator( "Xc_MM",&spec_nc_020_mult0[1]);
   reader_nc_020_mult0->AddSpectator( "Xc_0.20_nc_mult",&spec_nc_020_mult0[2]);
   reader_nc_020_mult0->BookMVA("Fisher method",  weightFile_Fisher_nc_020_mult0   );

   TString weightFile_BDT_nc_020 = "TMVA/TMVAClassification_test_BDT_020_deltaMs_noMult.weights.xml";   
   TMVA::Reader *reader_nc_020 = new TMVA::Reader("!Color:!Silent");
   
   Float_t var_nc_020[7]; 
   reader_nc_020->AddVariable( "Xc_0.20_nc_maxPt_PT",&var_nc_020[0]); 
   reader_nc_020->AddVariable( "Xc_0.20_nc_asy_P",&var_nc_020[1]); 
   reader_nc_020->AddVariable( "Xc_0.20_nc_deltaEta",&var_nc_020[2]); 
   reader_nc_020->AddVariable( "Xc_0.20_nc_deltaPhi",&var_nc_020[3]); 
   reader_nc_020->AddVariable( "Xc_0.20_nc_avCL",&var_nc_020[4]); 
   reader_nc_020->AddVariable( "Xc_pT_Breco_Yreco",&var_nc_020[5]); 
   reader_nc_020->AddVariable( "Delta_ms_020_maxPt",&var_nc_020[6]);
   Float_t spec_nc_020[3]; 
   reader_nc_020->AddSpectator( "B_MM",&spec_nc_020[0]); 
   reader_nc_020->AddSpectator( "Xc_MM",&spec_nc_020[1]); 
   reader_nc_020->AddSpectator( "Xc_0.20_nc_mult",&spec_nc_020[2]);

   reader_nc_020->BookMVA("BDT method",  weightFile_BDT_nc_020   );



   TMVA::Reader *reader_Ds = new TMVA::Reader("!Color:!Silent");
   Float_t var_Ds[14];

   reader_Ds->AddVariable( "log(Xc_ENDVERTEX_CHI2)",&var_Ds[0]);
   reader_Ds->AddVariable( "log(Xc_FD_OWNPV)",      &var_Ds[1]);
   reader_Ds->AddVariable( "log(Xc_FD_ORIVX)",      &var_Ds[2]);
   reader_Ds->AddVariable( "Xc_ETA",                &var_Ds[3]);
   reader_Ds->AddVariable( "log(Xc_PT)",                 &var_Ds[4]);
   reader_Ds->AddVariable( "log(p1_fromXc_IPCHI2_OWNPV)",  &var_Ds[5]);
   reader_Ds->AddVariable( "log(p2_fromXc_IPCHI2_OWNPV)",  &var_Ds[6]);
   reader_Ds->AddVariable( "log(p3_fromXc_IPCHI2_OWNPV)",  &var_Ds[7]);    
   reader_Ds->AddVariable( "log(p1_fromXc_PT)",  &var_Ds[8]);
   reader_Ds->AddVariable( "log(p2_fromXc_PT)",  &var_Ds[9]);
   reader_Ds->AddVariable( "log(p3_fromXc_PT)",  &var_Ds[10]);
   reader_Ds->AddVariable( "log(p1_fromXc_TRACK_GhostProb)",  &var_Ds[11]);
   reader_Ds->AddVariable( "log(p2_fromXc_TRACK_GhostProb)",  &var_Ds[12]);
   reader_Ds->AddVariable( "log(p3_fromXc_TRACK_GhostProb)",  &var_Ds[13]);
   
   Float_t spec_Ds[2];   
   reader_Ds->AddSpectator( "B_MM",  &spec_Ds[0]);
   reader_Ds->AddSpectator( "Xc_MM",  &spec_Ds[1]);
   
   reader_Ds->BookMVA("BDT method",  weightFile_BDT_Ds   );


   TMVA::Reader *reader_3pi = new TMVA::Reader("!Color:!Silent");
   Float_t var_3pi[13], var_Bs[4];
   reader_3pi->AddVariable( "p1_fromY_ETA",                &var_3pi[0]);
   reader_3pi->AddVariable( "p2_fromY_ETA",                &var_3pi[1]);
   reader_3pi->AddVariable( "p3_fromY_ETA",                &var_3pi[2]);
   
   reader_3pi->AddVariable( "log(p1_fromY_IPCHI2_OWNPV)",  &var_3pi[3]);
   reader_3pi->AddVariable( "log(p2_fromY_IPCHI2_OWNPV)",  &var_3pi[4]);
   reader_3pi->AddVariable( "log(p3_fromY_IPCHI2_OWNPV)",  &var_3pi[5]);    

   reader_3pi->AddVariable( "log(p1_fromY_TRACK_GhostProb)",  &var_3pi[6]);
   reader_3pi->AddVariable( "log(p2_fromY_TRACK_GhostProb)",  &var_3pi[7]);
   reader_3pi->AddVariable( "log(p3_fromY_TRACK_GhostProb)",  &var_3pi[8]);    
   
   reader_3pi->AddVariable( "Y_DOCA1",                &var_3pi[9]);
   reader_3pi->AddVariable( "Y_DOCA2",                &var_3pi[10]);
   reader_3pi->AddVariable( "Y_DOCA3",                &var_3pi[11]);
   
   reader_3pi->AddVariable( "Y_ENDVERTEX_CHI2",       &var_3pi[12]);
   
   Float_t spec_3pi[2];   
   reader_3pi->AddSpectator( "B_MM",  &spec_3pi[0]);
   reader_3pi->AddSpectator( "Xc_MM",  &spec_3pi[1]);
   
   reader_3pi->BookMVA("BDT method",  weightFile_BDT_3pi   );


   TMVA::Reader *reader_Bs = new TMVA::Reader("!Color:!Silent");
   reader_Bs->AddVariable( "B_ETA",     &var_Bs[0]);   // B_ETA_R);
   reader_Bs->AddVariable( "log(B_FD_OWNPV)",&var_Bs[1]);   //&B_FD_OWNPV_R);
   reader_Bs->AddVariable( "BDT_3pi",   &var_Bs[2]);   //&BDT_3pi_R);
   reader_Bs->AddVariable( "BDT_Ds",&var_Bs[3]);   //&Xc_PT_R);
   ////////reader_Bs->AddVariable( "log(Xc_PT)",&var_Bs[3]);   //&Xc_PT_R);
   
   Float_t spec_Bs[2];
   reader_Bs->AddSpectator("B_MM",  &spec_Bs[0]);
   reader_Bs->AddSpectator("Xc_MM", &spec_Bs[1]);
   
   reader_Bs->BookMVA("BDT method",weightFile_BDT_Bs);
   
  

   // ============================================== =====================================

   //TString filename;
   //filename ="/eos/lhcb/wg/semileptonic/RDsHad/tuple/2012/final/BsDsTauNu_MagDown_MC2012_PIDcorr_withMOREinfo_ISO.root";
   //filename ="/tmp/BsDsTauNu_MagDown_MC2012_PIDcorr_withMOREinfo_ISO.root";
  
   //filename.Form("/eos/lhcb/wg/semileptonic/RDsHad/tuple/2012/final/DATA_MagUp_ISO_BDTcut_%d.root",i0);
   TFile *newfile = TFile::Open(fOutputFilename,"recreate");   
   
   // ============================================== =====================================
   auto newtree = fChain->CloneTree(0);    

  //  Double_t clone_p1_fromXc_PIDK_pidgen_default(0), clone_p2_fromXc_PIDK_pidgen_default(0), clone_p3_fromXc_PIDK_pidgen_default(0);
  //  Double_t clone_p1_fromXc_PIDp_pidgen_default(0), clone_p2_fromXc_PIDp_pidgen_default(0), clone_p3_fromXc_PIDp_pidgen_default(0);
  //  Double_t clone_p1_fromY_PIDK_pidgen_default(0), clone_p2_fromY_PIDK_pidgen_default(0), clone_p3_fromY_PIDK_pidgen_default(0);
  //  Double_t clone_p1_fromY_PIDp_pidgen_default(0), clone_p2_fromY_PIDp_pidgen_default(0), clone_p3_fromY_PIDp_pidgen_default(0);
  //  Double_t clone_p1_fromY_K_PIDK_pidgen_default(0), clone_p2_fromY_K_PIDK_pidgen_default(0), clone_p3_fromY_K_PIDK_pidgen_default(0);
  //  Double_t clone_p1_fromY_pi_PIDK_pidgen_default(0), clone_p2_fromY_pi_PIDK_pidgen_default(0), clone_p3_fromY_pi_PIDK_pidgen_default(0);

  //  TBranch* p1_fromXc_PIDK_pidgen_default_b = newtree->Branch("p1_fromXc_PIDK_pidgen_default"   , &clone_p1_fromXc_PIDK_pidgen_default   , "p1_fromXc_PIDK_pidgen_default/D");
  //  TBranch* p2_fromXc_PIDK_pidgen_default_b = newtree->Branch("p2_fromXc_PIDK_pidgen_default"   , &clone_p2_fromXc_PIDK_pidgen_default   , "p2_fromXc_PIDK_pidgen_default/D");
  //  TBranch* p3_fromXc_PIDK_pidgen_default_b = newtree->Branch("p3_fromXc_PIDK_pidgen_default"   , &clone_p3_fromXc_PIDK_pidgen_default   , "p3_fromXc_PIDK_pidgen_default/D");
  //  TBranch* p1_fromXc_PIDp_pidgen_default_b = newtree->Branch("p1_fromXc_PIDp_pidgen_default"   , &clone_p1_fromXc_PIDp_pidgen_default   , "p1_fromXc_PIDp_pidgen_default/D");
  //  TBranch* p2_fromXc_PIDp_pidgen_default_b = newtree->Branch("p2_fromXc_PIDp_pidgen_default"   , &clone_p2_fromXc_PIDp_pidgen_default   , "p2_fromXc_PIDp_pidgen_default/D");
  //  TBranch* p3_fromXc_PIDp_pidgen_default_b = newtree->Branch("p3_fromXc_PIDp_pidgen_default"   , &clone_p3_fromXc_PIDp_pidgen_default   , "p3_fromXc_PIDp_pidgen_default/D");
   
  //  if (fInclMCmode) {
  //     TBranch* p1_fromY_K_PIDK_pidgen_default_b = newtree->Branch("p1_fromY_K_PIDK_pidgen_default"   , &clone_p1_fromY_K_PIDK_pidgen_default   , "p1_fromY_K_PIDK_pidgen_default/D"    );
  //     TBranch* p2_fromY_K_PIDK_pidgen_default_b = newtree->Branch("p2_fromY_K_PIDK_pidgen_default"   , &clone_p2_fromY_K_PIDK_pidgen_default   , "p2_fromY_K_PIDK_pidgen_default/D"    );
  //     TBranch* p3_fromY_K_PIDK_pidgen_default_b = newtree->Branch("p3_fromY_K_PIDK_pidgen_default"   , &clone_p3_fromY_K_PIDK_pidgen_default   , "p3_fromY_K_PIDK_pidgen_default/D"    );
  //     TBranch* p1_fromY_pi_PIDK_pidgen_default_b = newtree->Branch("p1_fromY_pi_PIDK_pidgen_default"   , &clone_p1_fromY_pi_PIDK_pidgen_default   , "p1_fromY_pi_PIDK_pidgen_default/D"    );
  //     TBranch* p2_fromY_pi_PIDK_pidgen_default_b = newtree->Branch("p2_fromY_pi_PIDK_pidgen_default"   , &clone_p2_fromY_pi_PIDK_pidgen_default   , "p2_fromY_pi_PIDK_pidgen_default/D"    );
  //     TBranch* p3_fromY_pi_PIDK_pidgen_default_b = newtree->Branch("p3_fromY_pi_PIDK_pidgen_default"   , &clone_p3_fromY_pi_PIDK_pidgen_default   , "p3_fromY_pi_PIDK_pidgen_default/D"    );
  //  } else {
  //     TBranch* p1_fromY_PIDK_pidgen_default_b = newtree->Branch("p1_fromY_PIDK_pidgen_default"   , &clone_p1_fromY_PIDK_pidgen_default   , "p1_fromY_PIDK_pidgen_default/D"    );
  //     TBranch* p2_fromY_PIDK_pidgen_default_b = newtree->Branch("p2_fromY_PIDK_pidgen_default"   , &clone_p2_fromY_PIDK_pidgen_default   , "p2_fromY_PIDK_pidgen_default/D"    );
  //     TBranch* p3_fromY_PIDK_pidgen_default_b = newtree->Branch("p3_fromY_PIDK_pidgen_default"   , &clone_p3_fromY_PIDK_pidgen_default   , "p3_fromY_PIDK_pidgen_default/D"    );
  //     TBranch* p1_fromY_PIDp_pidgen_default_b = newtree->Branch("p1_fromY_PIDp_pidgen_default"   , &clone_p1_fromY_PIDp_pidgen_default   , "p1_fromY_PIDp_pidgen_default/D"    );
  //     TBranch* p2_fromY_PIDp_pidgen_default_b = newtree->Branch("p2_fromY_PIDp_pidgen_default"   , &clone_p2_fromY_PIDp_pidgen_default   , "p2_fromY_PIDp_pidgen_default/D"    );
  //     TBranch* p3_fromY_PIDp_pidgen_default_b = newtree->Branch("p3_fromY_PIDp_pidgen_default"   , &clone_p3_fromY_PIDp_pidgen_default   , "p3_fromY_PIDp_pidgen_default/D"    );
  //  }

   Double_t BDT_3pi(0.),BDT_Bs(0.), BDT_Ds(0.);
   TBranch* BDT_3pi_b = newtree->Branch("BDT_3pi"   , &BDT_3pi   , "BDT_3pi/D"          );
   TBranch* BDT_Ds_b  = newtree->Branch("BDT_Ds"    , &BDT_Ds    , "BDT_Ds/D"          );
   TBranch* BDT_Bs_b  = newtree->Branch("BDT_Bs"    , &BDT_Bs    , "BDT_Bs/D"          );

   Int_t count(0.),count_StrippingSig(0.);
#ifdef MC
   Int_t Xc_Selection(0.);
   TBranch* Xc_Selection_b   = newtree->Branch("Xc_Selection" , &Xc_Selection , "Xc_Selection/I"          ); 
#endif   

   Double_t B_Y_SEP(0.);
   TBranch* B_Y_SEP_b   = newtree->Branch("B_Y_SEP" , &B_Y_SEP , "B_Y_SEP/D"          );

   Int_t index(0.);
   TBranch* index_b   = newtree->Branch("eventIndex" , &index, "eventIndex/I");

   Int_t sign(0);
   TBranch* sign_b    = newtree->Branch("sign"      , &sign                , "sign/I"          );

   Double_t  theta_p1p3_cmsp1p2(0.), theta_p3p1_cmsp2p3(0.), theta_n3pi_pYrec_cms3pi(0.), theta_n3pi_pXc_cms3pi(0.);
   TBranch* theta_p1p3_cmsp1p2_b = newtree->Branch("theta_p1p3_cmsp1p2", &theta_p1p3_cmsp1p2 , "theta_p1p3_cmsp1p2/D");
   TBranch* theta_p3p1_cmsp2p3_b = newtree->Branch("theta_p3p1_cmsp2p3", &theta_p3p1_cmsp2p3 , "theta_p3p1_cmsp2p3/D");
   TBranch* theta_n3pi_pYrec_cms3pi_b  = newtree->Branch("theta_n3pi_pYrec_cms3pi", &theta_n3pi_pYrec_cms3pi , "theta_n3pi_pYrec_cms3pi/D");
   TBranch* theta_n3pi_pXc_cms3pi_b    = newtree->Branch("theta_n3pi_pXc_cms3pi", &theta_n3pi_pXc_cms3pi , "theta_n3pi_pXc_cms3pi/D" );

   Double_t  theta_Bdir_pB_withpY_rec(0.), theta_pB_pY_cmsW (0.), theta_pB_pY_cmsW_2(0.);
   TBranch* theta_Bdir_pB_withpY_rec_b = newtree->Branch("theta_Bdir_pB_withpY_rec", &theta_Bdir_pB_withpY_rec , "theta_Bdir_pB_withpY_rec/D" );
   TBranch* theta_pB_pY_cmsW_b = newtree->Branch("theta_pB_pY_cmsW", &theta_pB_pY_cmsW , "theta_pB_pY_cmsW/D" );
   TBranch* theta_pB_pY_cmsW_2_b = newtree->Branch("theta_pB_pY_cmsW_2", &theta_pB_pY_cmsW_2,"theta_pB_pY_cmsW_2/D" );

   Double_t B_Prec(0.), Y_Prec(0.);
   TBranch* B_Prec_b = newtree->Branch("B_Prec", &B_Prec, "B_Prec/D");
   TBranch* Y_Prec_b = newtree->Branch("Y_Prec", &Y_Prec, "Y_Prec/D");

   Double_t  theta_Ydir_pY(0.), theta_Ymax(0.), theta_Bmax(0.);
   TBranch* theta_Ydir_pY_b  = newtree->Branch("theta_Ydir_pY", &theta_Ydir_pY, "theta_Ydir_pY/D" );
   TBranch* theta_Ymax_b     = newtree->Branch("theta_Ymax", &theta_Ymax , "theta_Ymax/D" );
   TBranch* theta_Bmax_b     = newtree->Branch("theta_Bmax", &theta_Bmax , "theta_Bmax/D" );

   Double_t cos2pimin(0.), cos2pimax(0.);
   TBranch* cos2pimin_b    = newtree->Branch("cos2pimin"      , &cos2pimin                , "cos2pimin/D"          );
   TBranch* cos2pimax_b    = newtree->Branch("cos2pimax"      , &cos2pimax                , "cos2pimax/D"          );

   Double_t Y_correctedMass(0), B_correctedMass(0);
   TBranch* Y_correctedMass_b = newtree->Branch("Y_correctedMass", &Y_correctedMass, "Y_correctedMass/D");
   TBranch* B_correctedMass_b = newtree->Branch("B_correctedMass", &B_correctedMass, "B_correctedMass/D");

   Double_t  Y_pT_Ydir(0.), Y_pT_Bdir(0.), B_pT_Bdir(0.);
   TBranch* Y_pT_Ydir_b = newtree->Branch("Y_pT_Ydir", &Y_pT_Ydir, "Y_pT_Ydir/D");
   TBranch* Y_pT_Bdir_b = newtree->Branch("Y_pT_Bdir", &Y_pT_Bdir, "Y_pT_Bdir/D");
   TBranch* B_pT_Bdir_b = newtree->Branch("B_pT_Bdir", &B_pT_Bdir, "B_pT_Bdir/D");
   
   Double_t  mass_W(0.), mass_W_2(0.),missing_mass(0.), missing_mass_2(0.),mass_XcX(0.), mass_XcX_2(0.),missing_pY_mass(0.);
   TBranch* mass_W_b = newtree->Branch("mass_W", &mass_W , "mass_W/D" );
   TBranch* mass_W_2_b = newtree->Branch("mass_W_2", &mass_W_2, "mass_W_2/D" );
   TBranch* missing_mass_b = newtree->Branch("missing_mass", &missing_mass, "missing_mass/D" );
   TBranch* missing_mass_2_b = newtree->Branch("missing_mass_2", &missing_mass_2, "missing_mass_2/D" );
   TBranch* mass_XcX_b = newtree->Branch("mass_XcX", &mass_XcX, "mass_XcX/D" );
   TBranch* mass_XcX_2_b = newtree->Branch("mass_XcX_2", &mass_XcX_2, "mass_XcX_2/D" );
   TBranch* missing_pY_mass_b = newtree->Branch("missing_pY_mass", &missing_pY_mass, "missing_pY_mass/D" );

   Double_t  mass2pi_12(0.), mass2pi_23(0.), mass2pi_31(0.), min_m2pi(0.), max_m2pi(0.);
   TBranch* mass2pi_12_b  = newtree->Branch("mass2pi_12"             , &mass2pi_12              , "mass2pi_12/D"          );
   TBranch* mass2pi_23_b  = newtree->Branch("mass2pi_23"             , &mass2pi_23              , "mass2pi_23/D"          );
   TBranch* mass2pi_31_b  = newtree->Branch("mass2pi_31"             , &mass2pi_31              , "mass2pi_31/D"          );
   TBranch* min_m2pi_b    = newtree->Branch("min_m2pi"               , &min_m2pi                , "min_m2pi/D"          );
   TBranch* max_m2pi_b    = newtree->Branch("max_m2pi"               , &max_m2pi                , "max_m2pi/D"          );

   Double_t  massKK_12(0.), massKpi_23(0.), massKpi_13(0.), min_mKpi(0.), max_mKpi(0.);
   TBranch* massKK_12_b  = newtree->Branch("massKK_12"             , &massKK_12              , "massKK_12/D"          );
   TBranch* massKpi_23_b  = newtree->Branch("massKpi_23"             , &massKpi_23              , "massKpi_23/D"          );
   TBranch* massKpi_13_b  = newtree->Branch("massKpi_13"             , &massKpi_13              , "massKpi_13/D"          );
   TBranch* min_mKpi_b    = newtree->Branch("min_mKpi"               , &min_mKpi                , "min_mKpi/D"          );
   TBranch* max_mKpi_b    = newtree->Branch("max_mKpi"               , &max_mKpi                , "max_mKpi/D"          );


   Double_t q2,q2_2;
   TBranch* q2_b = newtree->Branch("q2", &q2, "q2/D" );
   TBranch* q2_2_b = newtree->Branch("q2_2", &q2_2, "q2_2/D" );

   Double_t tauY(0), tauY_2(0), CTAUY_2(0);
   TBranch* tauY_b = newtree->Branch("tauY", &tauY, "tauY/D" );
   TBranch* tauY_2_b = newtree->Branch("tauY_2", &tauY_2, "tauY_2/D" );
   TBranch* CTAUY_2_b = newtree->Branch("CTAUY_2", &CTAUY_2, "CTAUY_2/D" );

   Double_t tauB(0), tauB_2(0), CTAUB_2(0);
   TBranch* tauB_b = newtree->Branch("tauB", &tauB, "tauB/D" );
   TBranch* tauB_2_b = newtree->Branch("tauB_2", &tauB_2, "tauB_2/D" );
   TBranch* CTAUB_2_b = newtree->Branch("CTAUB_2", &CTAUB_2, "CTAUB_2/D" );

   Double_t _pY_miss(0.);
   TBranch* pY_miss_b = newtree->Branch("pY_miss", &_pY_miss, "pY_miss/D" );

   Double_t Xc_pT_Breco_Yreco(0.);   
   TBranch* Xc_pT_Breco_Yreco_b = newtree->Branch("Xc_pT_Breco_Yreco", &Xc_pT_Breco_Yreco, "Xc_pT_Breco_Yreco/D");

   Double_t _pBv, _pBs, _pDsv, _pDss, _pBvn, _pBsn, _pDsvn, _pDssn, _mDs2s, _mDs2v, _mDs2sn, _mDs2vn, _mN2s, _mN2v, _mN2n, _tpc;
   TBranch* PBs_b = newtree->Branch("PBs",&_pBs,"PBs/D");
   TBranch* PBv_b = newtree->Branch("PBv",&_pBv,"PBv/D");
   TBranch* PDsv_b = newtree->Branch("PDsv", &_pDsv, "PDsv/D");
   TBranch* PDss_b = newtree->Branch("PDss", &_pDss, "PDss/D");
   TBranch* PBvn_b = newtree->Branch("PBvn", &_pBvn, "PBvn/D");
   TBranch* PBsn_b = newtree->Branch("PBsn", &_pBsn, "PBsn/D");
   TBranch* PDsvn_b = newtree->Branch("PDsvn", &_pDsvn, "PDsvn/D");
   TBranch* PDssn_b = newtree->Branch("PDssn", &_pDssn, "PDssn/D");
   TBranch* mDs2s_b = newtree->Branch("mDs2s", &_mDs2s, "mDs2s/D");
   TBranch* mDs2v_b = newtree->Branch("mDs2v", &_mDs2v, "mDs2v/D");
   TBranch* mDs2sn_b = newtree->Branch("mDs2sn", &_mDs2sn, "mDs2sn/D");
   TBranch* mDs2vn_b = newtree->Branch("mDs2vn", &_mDs2vn, "mDs2vn/D");
   TBranch* mN2s_b = newtree->Branch("mN2s", &_mN2s, "mN2s/D");
   TBranch* mN2v_b = newtree->Branch("mN2v", &_mN2v, "mN2v/D");
   TBranch* mN2n_b = newtree->Branch("mN2n", &_mN2n, "mN2n/D");
   TBranch* tpc_b = newtree->Branch("tpc", &_tpc, "tpc/D");


   // Cone Isolation and Charge Isolation Variables
   Double_t Delta_ms_020_maxPt(0.),Xcst_maxPt_020_M(0.), MVA_nc_020(0.);
   TBranch* Delta_ms_020_maxPt_b = newtree->Branch("Delta_ms_020_maxPt", &Delta_ms_020_maxPt, "Delta_ms_020_maxPt/D");
   TBranch* MVA_nc_020_b = newtree->Branch("MVA_nc_020"    , &MVA_nc_020    , "MVA_nc_020/D"          );

   Double_t BDT_Iso(0.);   
   TBranch* BDT_Iso_b  = newtree->Branch("BDT_Iso"    , &BDT_Iso    , "BDT_Iso/D"          );   
   //==========================================

#ifdef MC
   Double_t
     theta_Bdir_pB_withpY_rec_MC(0.), theta_pB_pY_cmsW_MC (0.), theta_pB_pY_cmsW_MC_2(0.), 
     theta_Ydir_pY_MC(0.), theta_Ymax_MC(0.), theta_Bmax_MC(0.);
   
   TBranch* theta_Bdir_pB_withpY_rec_MC_b = newtree->Branch("theta_Bdir_pB_withpY_rec_MC", &theta_Bdir_pB_withpY_rec_MC , "theta_Bdir_pB_withpY_rec_MC/D" );
   TBranch* theta_pB_pY_cmsW_MC_b = newtree->Branch("theta_pB_pY_cmsW_MC", &theta_pB_pY_cmsW_MC , "theta_pB_pY_cmsW_MC/D" );   
   TBranch* theta_Ydir_pY_MC_b  = newtree->Branch("theta_Ydir_pY_MC", &theta_Ydir_pY_MC, "theta_Ydir_pY_MC/D" );
   TBranch* theta_Ymax_MC_b     = newtree->Branch("theta_Ymax_MC", &theta_Ymax_MC , "theta_Ymax_MC/D" );
   TBranch* theta_Bmax_MC_b     = newtree->Branch("theta_Bmax_MC", &theta_Bmax_MC , "theta_Bmax_MC/D" );

   Double_t 
     mass_W_MC(0.), mass_W_MC_2(0.), 
     missing_mass_MC(0.), missing_mass_MC_2(0.), 
     mass_XcX_MC(0.), mass_XcX_MC_2(0.), 
     missing_pB_mass_MC(0.), missing_pY_mass_MC(0.);


   TBranch* mass_W_b_MC       = newtree->Branch("mass_W_MC", &mass_W_MC , "mass_W_MC/D" );
   TBranch* mass_W_2_MC_b     = newtree->Branch("mass_W_MC_2", &mass_W_MC_2, "mass_W_MC_2/D" );
   TBranch* missing_mass_MC_b = newtree->Branch("missing_mass_MC", &missing_mass_MC, "missing_mass_MC/D" );
   TBranch* missing_mass_2_MC_b = newtree->Branch("missing_mass_MC_2", &missing_mass_MC_2, "missing_mass_MC_2/D" );
   TBranch* mass_XcX_MC_b     = newtree->Branch("mass_XcX_MC", &mass_XcX_MC, "mass_XcX_MC/D" );
   TBranch* mass_XcX_2_MC_b   = newtree->Branch("mass_XcX_MC_2", &mass_XcX_MC_2, "mass_XcX_MC_2/D" );
   TBranch* missing_pB_mass_MC_b = newtree->Branch("missing_pB_mass_MC", &missing_pB_mass_MC, "missing_pB_mass_MC/D" );
   TBranch* missing_pY_mass_MC_b = newtree->Branch("missing_pY_mass_MC", &missing_pY_mass_MC, "missing_pY_mass_MC/D" );


   Double_t q2_MC,q2_MC_2;
   TBranch* q2_MC_b    = newtree->Branch("q2_MC", &q2_MC, "q2_MC/D" );
   TBranch* q2_MC_2_b  = newtree->Branch("q2_MC_2", &q2_MC_2, "q2_MC_2/D" );
#endif

   
   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      if( 10000*int(jentry/10000)==jentry) cout << "Processed "<<jentry<<" "<<count<<endl;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
#ifdef MC
      Xc_Selection = Cut(ientry);
      // if (Cut(ientry) < 0) continue;
#else      
      if (Cut(ientry) < 0) continue;
#endif
      count++; 

      BDT_Ds = -10;      
      spec_Ds[0]=(Float_t) B_MM;
      spec_Ds[1]=(Float_t) Xc_MM;
      if(Xc_ENDVERTEX_CHI2> 0 && Xc_FD_OWNPV > 0 && Xc_FD_ORIVX> 0 && Xc_PT > 0 && 
         p1_fromXc_IPCHI2_OWNPV > 0 && p2_fromXc_IPCHI2_OWNPV > 0 && p3_fromXc_IPCHI2_OWNPV > 0 &&
         p1_fromXc_PT > 0 && p2_fromXc_PT > 0 && p3_fromXc_PT > 0 && 
         p1_fromXc_TRACK_GhostProb > 0&& p2_fromXc_TRACK_GhostProb > 0 && p3_fromXc_TRACK_GhostProb > 0) 
      {
        var_Ds[0] = log(Xc_ENDVERTEX_CHI2);
        var_Ds[1] = log(Xc_FD_OWNPV);
        var_Ds[2] = log(Xc_FD_ORIVX);
        var_Ds[3] = Xc_ETA;
        var_Ds[4] = log(Xc_PT);
        var_Ds[5] = log(p1_fromXc_IPCHI2_OWNPV);
        var_Ds[6] = log(p2_fromXc_IPCHI2_OWNPV);
        var_Ds[7] = log(p3_fromXc_IPCHI2_OWNPV);
        var_Ds[8] = log(p1_fromXc_PT);
        var_Ds[9] = log(p2_fromXc_PT);
        var_Ds[10]= log(p3_fromXc_PT);
        var_Ds[11]= log(p1_fromXc_TRACK_GhostProb*factor);
        var_Ds[12]= log(p2_fromXc_TRACK_GhostProb*factor);
        var_Ds[13]= log(p3_fromXc_TRACK_GhostProb*factor);

        BDT_Ds = reader_Ds->EvaluateMVA("BDT method");        
      }
      
      spec_3pi[0]=(Float_t) B_MM;
      spec_3pi[1]=(Float_t) Xc_MM;
      BDT_3pi = -10;
      if( p1_fromY_IPCHI2_OWNPV>0 && p2_fromY_IPCHI2_OWNPV>0 && p3_fromY_IPCHI2_OWNPV>0 &&
          p1_fromY_TRACK_GhostProb>0 && p2_fromY_TRACK_GhostProb>0 && p3_fromY_TRACK_GhostProb>0)      {  
        var_3pi[0]=(Float_t)p1_fromY_ETA;
        var_3pi[1]=(Float_t)p2_fromY_ETA;
        var_3pi[2]=(Float_t)p3_fromY_ETA;
        var_3pi[3]=(Float_t)log(p1_fromY_IPCHI2_OWNPV);
        var_3pi[4]=(Float_t)log(p2_fromY_IPCHI2_OWNPV);
        var_3pi[5]=(Float_t)log(p3_fromY_IPCHI2_OWNPV);
        var_3pi[6]=(Float_t)log(p1_fromY_TRACK_GhostProb*factor);
        var_3pi[7]=(Float_t)log(p2_fromY_TRACK_GhostProb*factor);
        var_3pi[8]=(Float_t)log(p3_fromY_TRACK_GhostProb*factor);
        var_3pi[9]=(Float_t)Y_DOCA1;
        var_3pi[10]=(Float_t)Y_DOCA2;
        var_3pi[11]=(Float_t)Y_DOCA3;
        var_3pi[12]=(Float_t)Y_ENDVERTEX_CHI2;

        BDT_3pi = reader_3pi->EvaluateMVA("BDT method");
      }      
      BDT_Bs = -10;
      if( B_FD_OWNPV>0 && BDT_3pi >-9 && BDT_Ds > -9){
        var_Bs[0] = (Float_t)B_ETA;
        var_Bs[1] = (Float_t)log(B_FD_OWNPV);
        var_Bs[2] = (Float_t)BDT_3pi;
        var_Bs[3] = (Float_t)BDT_Ds;

        spec_Bs[0] = (Float_t)B_MM;
        spec_Bs[1] = (Float_t)Xc_MM;

        BDT_Bs  = reader_Bs->EvaluateMVA("BDT method");
      }
#ifdef BDTcut
      if( !(BDT_Ds > -0.058858 && BDT_3pi>-0.039645 && BDT_Bs > -0.049076 ) ) continue;
#endif


      Double_t B_Y_SEPerr = sqrt((B_ENDVERTEX_ZERR*B_ENDVERTEX_ZERR) + (Y_ENDVERTEX_ZERR*Y_ENDVERTEX_ZERR));
      B_Y_SEP=-10000;
      if(B_Y_SEPerr>0) B_Y_SEP =  (B_ENDVERTEX_Z - Y_ENDVERTEX_Z) / B_Y_SEPerr;
      // Possible cut on B_Y_SEP, needed for inclusive MC to reduce data volume      
      // if (fB_Y_SEP_cut != NO_CUT) {
      //   if (B_Y_SEP > fB_Y_SEP_cut) {
      //     continue;
      //   }
      // }
      

      TLorentzVector pB;          pB.SetXYZM(B_PX,B_PY,B_PZ,B_M);
      TLorentzVector pXc;         pXc.SetXYZM(Xc_PX,Xc_PY,Xc_PZ,Xc_M);
      TLorentzVector pY;          pY.SetXYZM(Y_PX,Y_PY,Y_PZ,Y_M);
      
      missing_mass = (pB - pXc - pY).M();// <---------- missing mass con valori non corretti
      mass_XcX = (pB - pY).M();      // <-------------

      //1//======================= Variables to for BDT antiDs =================================================================      
      TVector3 Bdir(B_ENDVERTEX_X-B_OWNPV_X,B_ENDVERTEX_Y-B_OWNPV_Y,B_ENDVERTEX_Z-B_OWNPV_Z);             Bdir = Bdir.Unit();
      TVector3 Xcdir = pXc.Vect().Unit();
      TVector3 Ydir(Y_ENDVERTEX_X-B_ENDVERTEX_X,Y_ENDVERTEX_Y-B_ENDVERTEX_Y,Y_ENDVERTEX_Z-B_ENDVERTEX_Z); Ydir = Ydir.Unit();

      _pBv = (pXc.Vect().Cross(Ydir)).Mag()/(Bdir.Cross(Ydir)).Mag();// Eq.16a ANA note, modulo <<===========================
      _pBs = (pXc.Vect().Dot(Bdir)- pXc.Vect().Dot(Ydir)* Bdir.Dot(Ydir))/(1.-Bdir.Dot(Ydir)*Bdir.Dot(Ydir)); // Eq.16b <====================

      _pDsv = (pXc.Vect().Cross(Bdir)).Mag()/(Ydir.Cross(Bdir)).Mag();   // Eq.17 <<=====================
      _pDss = (pXc.Vect().Dot(Bdir) * Bdir.Dot(Ydir) - pXc.Vect().Dot(Ydir))/(1.-Bdir.Dot(Ydir)*Bdir.Dot(Ydir));  //Eq 17b <<================

      //========================================== Corrected variables =========================================
      Double_t Dz = TMath::Exp(xp0 + xp1*Y_M);   // Correzione Vertici
      Double_t Dx = Dz*Xcdir.x()/Xcdir.z();
      Double_t Dy = Dz*Xcdir.y()/Xcdir.z();
      
      TVector3 Bdirn(B_ENDVERTEX_X-B_OWNPV_X+Dx,B_ENDVERTEX_Y-B_OWNPV_Y+Dy,B_ENDVERTEX_Z-B_OWNPV_Z+Dz);   Bdirn =Bdirn.Unit(); // Vertici corretti
      TVector3 Ydirn(Y_ENDVERTEX_X-B_ENDVERTEX_X-Dx,Y_ENDVERTEX_Y-B_ENDVERTEX_Y-Dy,Y_ENDVERTEX_Z-B_ENDVERTEX_Z-Dz); Ydirn = Ydirn.Unit();      

      _pBvn = (pXc.Vect().Cross(Ydirn)).Mag()/(Bdirn.Cross(Ydirn)).Mag();// Eq.16a ANA note, modulo
      _pBsn = (pXc.Vect().Dot(Bdirn)- pXc.Vect().Dot(Ydirn)* Bdirn.Dot(Ydirn))/(1.-Bdirn.Dot(Ydirn)*Bdirn.Dot(Ydirn)); // Eq.16b

      _pDsvn = (pXc.Vect().Cross(Bdirn)).Mag()/(Ydirn.Cross(Bdirn)).Mag();   // Eq.17
      _pDssn = (pXc.Vect().Dot(Bdirn) * Bdirn.Dot(Ydirn) - pXc.Vect().Dot(Ydirn))/(1.-Bdirn.Dot(Ydirn)*Bdirn.Dot(Ydirn));  //Eq 17b

      Double_t _EBv,_EBs, _EBvn, _EBsn;            
      _EBv = sqrt(mB*mB+_pBv*_pBv);
      _mDs2v = mB*mB+mDs*mDs+2*(_pBv*(Bdir*pXc.Vect())-_EBv*pXc.E());

      //_mN2v = mB*mB+B_M*B_M+2*(_pBv*(Bdir*pY.Vect())-_EBv*pB.E()); // wrong 17/02/2023
      _mN2v = mB*mB+B_M*B_M+2*(_pBv*(Bdir*(pXc.Vect()+pY.Vect()))-_EBv*pB.E());// corrected (Resmi's code)

      _EBs = sqrt(mB*mB+_pBs*_pBs);
      _mDs2s = mB*mB+mDs*mDs+2*(_pBs*(Bdir*pXc.Vect())-_EBs*pXc.E());

      //_mN2s = mB*mB+B_M*B_M+2*(_pBs*(Bdir*pY.Vect())-_EBs*pB.E()); // wrong 17/02/2023
      _mN2s = mB*mB+B_M*B_M+2*(_pBs*(Bdir*(pXc.Vect()+pY.Vect()))-_EBs*pB.E()); // corrected (Resmi's code)

      _EBvn = sqrt(mB*mB+_pBvn*_pBvn);
      _mDs2vn = mB*mB+mDs*mDs+2*(_pBvn*(Bdirn*pXc.Vect())-_EBvn*pXc.E());

      //_mN2n = mB*mB+B_M*B_M+2*(_pBvn*(Bdirn*pY.Vect())-_EBvn*pB.E()); // wrong 17/02/2023
      _mN2n = mB*mB+B_M*B_M+2*(_pBvn*(Bdirn*(pXc.Vect()+pY.Vect()) )-_EBvn*pB.E());// corrected (Resmi's code)

      _EBsn = sqrt(mB*mB+_pBsn*_pBsn);
      _mDs2sn = mB*mB+mDs*mDs+2*(_pBsn*(Bdirn*pXc.Vect())-_EBsn*pXc.E());

      _tpc = Bdir.Cross(Ydir)*Xcdir;
      // End Federico's variables;
      //end1//======================= Variables to for BDT antiDs =================================================================



      Double_t PBv = (pXc.Vect().Cross(pY.Vect())).Mag()/(Bdir.Cross(pY.Vect())).Mag();
      TLorentzVector pBv;  pBv.SetXYZM(PBv*Bdir.Px(),PBv*Bdir.Py(),PBv*Bdir.Pz(),mB); // Eq.16a vettore con la direzione del momento

      TLorentzVector pW = pBv - pXc;
      mass_W = pW.M(); // legato al q2 <----      
      if (mass_W>0) q2 = 1.e-6*mass_W*mass_W;
      else          q2 = -1.e-6*mass_W*mass_W;     // <-------------  variabili non corrette



      TLorentzVector pB_cmsW  = pBv;  pB_cmsW.Boost(-pW.Px()/pW.E(),-pW.Py()/pW.E(),-pW.Pz()/pW.E());
      TLorentzVector pY_cmsW  = pY;   pY_cmsW.Boost(-pW.Px()/pW.E(),-pW.Py()/pW.E(),-pW.Pz()/pW.E());      
      theta_pB_pY_cmsW = pB_cmsW.Vect().Angle(pY_cmsW.Vect()); //<---- angolo tra B e Y nel s.d.r del W

      // ================ variabili del Tau ===========================      
      Double_t m3pi = pY.M();
      
      theta_Ydir_pY = Ydir.Angle(pY.Vect()); // Angolo tra p_tau e direzione di volo del tau <<--------

      Double_t theta_Ymax = asin((mtau*mtau-m3pi*m3pi)/2./mtau/pY.P());  // Valore dell'angolo che azzera il discriminante Eq11<<------


      Double_t _pY             = getP(mtau,    pY, Ydir);  // modulo dell'impulso del tau con Eq.10 calcolata con theta
      Double_t _pY_rec         = getPmax(mtau, pY, Ydir);  // modulo dell'impulso del tau con Eq.10 calcolata con thetaYmax
      Double_t _Delta          = getDelta(mtau, pY, Ydir); // parte di ±E sqrt(discriminante) dell'Eq.10
    
      Double_t _pY_rec_plus = -1.E8;
      Double_t _pY_rec_minus = -1.E8;
      if(_Delta>-1)   {
        _pY_rec_plus  = _pY + _Delta;   // 2 soluzioni dell'equazione di secondo grado Eq.10
        _pY_rec_minus = _pY - _Delta;
      }
      
      TLorentzVector pY_rec;        pY_rec.SetXYZM(Ydir.X()*_pY_rec,Ydir.Y()*_pY_rec,Ydir.Z()*_pY_rec,mtau);
      TLorentzVector pY_rec_plus;   pY_rec_plus.SetXYZM(Ydir.X()*_pY_rec_plus,Ydir.Y()*_pY_rec_plus,Ydir.Z()*_pY_rec_plus,mtau);
      TLorentzVector pY_rec_minus;  pY_rec_minus.SetXYZM(Ydir.X()*_pY_rec_minus,Ydir.Y()*_pY_rec_minus,Ydir.Z()*_pY_rec_minus,mtau);

      Y_Prec = pY_rec.P(); // <<----------------

      TVector3 pT_Yv = Ydir.Cross(pY.Vect());
      pT_Yv = Ydir.Cross(pT_Yv);
      Y_pT_Ydir = pT_Yv.Mag();// <<----------- pY component transverse to the Y direction
      Y_correctedMass = sqrt(Y_M*Y_M+Y_pT_Ydir*Y_pT_Ydir)+ Y_pT_Ydir; // <<---- corrected Y mass

      TVector3 pT_YBv = Bdir.Cross(pY.Vect());
      pT_YBv = Bdir.Cross(pT_YBv);
      Y_pT_Bdir = pT_YBv.Mag();// <<----------- pY component transverse to the B direction

      // =============== Correct the B information ======================
      TLorentzVector pB_withpY_rec       = pXc + pY_rec;          // impulso del B con p_tau corretto
      TLorentzVector pB_withpY_rec_plus  = pXc + pY_rec_plus;
      TLorentzVector pB_withpY_rec_minus = pXc + pY_rec_minus;      

      theta_Bdir_pB_withpY_rec = Bdir.Angle(pB_withpY_rec.Vect()); //<<----------

      theta_Bmax = -1.E8;
      if (fabs((mB*mB-pB_withpY_rec.M()*pB_withpY_rec.M())/(2.*mB*pB_withpY_rec.P()))<=1){
        theta_Bmax = asin((mB*mB-pB_withpY_rec.M()*pB_withpY_rec.M())/(2.*mB*pB_withpY_rec.P())); // Eq13  Angolo che azzera il discriminante
      }      
      
      TVector3 pT_Bv = Bdir.Cross(pB_withpY_rec.Vect());    pT_Bv = Bdir.Cross(pT_Bv); // calcolo della massa corretta
      B_pT_Bdir = pT_Bv.Mag();// <<----------- pB component transverse to the B direction
      B_correctedMass = sqrt(B_M*B_M + B_pT_Bdir*B_pT_Bdir) + B_pT_Bdir; // <<=========== massa corretta      
        
      
      Double_t _pB            = getP(mB, pB_withpY_rec, Bdir);     // modulo dell'impulso del tau con Eq.10 calcolata con theta
      Double_t _pB_rec_Yrec   = getPmax( mB, pB_withpY_rec, Bdir); // modulo dell'impulso del tau con Eq.10 calcolata con thetaYmax
      _Delta                = getDelta(mB, pB_withpY_rec, Bdir); // parte di ±E sqrt(discriminante) dell'Eq.10
      
      TLorentzVector pB_rec_Yrec;    pB_rec_Yrec.SetXYZM(_pB_rec_Yrec*Bdir.X(),_pB_rec_Yrec*Bdir.Y(),_pB_rec_Yrec*Bdir.Z(),mB);
      pW = pB_rec_Yrec - pXc;   // ridefinisco pW
      Xc_pT_Breco_Yreco = pXc.Perp(pB_rec_Yrec.Vect());   // Carmen 
       
      //----- Calcolo delle missing mass, mass_W, q2 etc
      q2_2 = -1.E8;
      mass_W_2 = -1.E8;    
      missing_mass_2 = -1.E8;    
      mass_XcX_2 = -1E8;
      
      if (_pB_rec_Yrec> -1 && _pY_rec> -1) {
        mass_W_2 = pW.M();            // <-------------
        if (mass_W_2>0) q2_2 = 1.e-6*mass_W_2*mass_W_2;
        else            q2_2 = -1.e-6*mass_W_2*mass_W_2;     // <-------------
        
        mass_XcX_2     = (pB_rec_Yrec - pY_rec).M();      // <-------------
        missing_mass_2 = (pB_rec_Yrec - pXc - pY_rec).M(); // <------------- missing mass con pB_rec_Yrec e pY corretto
      }

         
    // Cut in case the q2_2 is negative as this is not usable data
    // Commented out in this case to keep B_Y_SEP
    // if (q2_2 < 0) {
    //   continue;
    // } 
     
    TLorentzVector pBrec_cmsW = pB_rec_Yrec;      pBrec_cmsW.Boost(-pW.Px()/pW.E(),-pW.Py()/pW.E(),-pW.Pz()/pW.E());
    TLorentzVector pYrec_cmsW = pY_rec;           pYrec_cmsW.Boost(-pW.Px()/pW.E(),-pW.Py()/pW.E(),-pW.Pz()/pW.E());

    B_Prec = pB_rec_Yrec.P(); // <<----------------

    theta_pB_pY_cmsW_2 = pBrec_cmsW.Vect().Angle(pYrec_cmsW.Vect()); //<---- angolo tra il B e il Tau nel s.d.r. del W con le quantita corrette

    TVector3 Bdir2(B_ENDVERTEX_X-B_OWNPV_X,B_ENDVERTEX_Y-B_OWNPV_Y,B_ENDVERTEX_Z-B_OWNPV_Z);
    tauB = mB*Bdir2.Mag()/pB.P()/299.792458;       //<---- B lifetime
    tauB_2 = -1E8;
    if(_pB_rec_Yrec > -1)
    tauB_2 = mB*Bdir2.Mag()/pB_rec_Yrec.P()/299.792458; //<---- B lifetime with p_rec


    Double_t beta = pB_rec_Yrec.P()/pB_rec_Yrec.E();
    Double_t gamma = 1./sqrt(1.-beta*beta);
    Double_t CTAUB_2 = Bdir2.Mag()/beta/gamma/299.792458;
    if (cos(theta_Bdir_pB_withpY_rec)<0.) CTAUB_2 = -CTAUB_2;


    TVector3 Ydir2(Y_ENDVERTEX_X-B_ENDVERTEX_X,Y_ENDVERTEX_Y-B_ENDVERTEX_Y,Y_ENDVERTEX_Z-B_ENDVERTEX_Z); 
    tauY = mtau*Ydir2.Mag()/pY.P()/299.792458;       //<---- tau lifetime
    tauY_2 = mtau*Ydir2.Mag()/pY_rec.P()/299.792458; //<---- tau lifetime with pY_rec
    beta = pY_rec.P()/pY_rec.E();
    gamma = 1./sqrt(1.-beta*beta);
    Double_t CTAUY_2 = Ydir2.Mag()/beta/gamma/299.792458;
    if (cos(theta_Ydir_pY)<0.) CTAUY_2 = -CTAUY_2;    

    TLorentzVector pY_miss = pY_rec - pY; // missing momenta 
    _pY_miss = pY_miss.P();   // <------------- missing momenta (modulo) from tau decay
    missing_pY_mass = pY_miss.M(); // <-------------  missing mass from tau decay
    
    TLorentzVector p1_fromY;    p1_fromY.SetXYZM(p1_fromY_PX,p1_fromY_PY,p1_fromY_PZ,mpi);
    TLorentzVector p2_fromY;    p2_fromY.SetXYZM(p2_fromY_PX,p2_fromY_PY,p2_fromY_PZ,mpi);
    TLorentzVector p3_fromY;    p3_fromY.SetXYZM(p3_fromY_PX,p3_fromY_PY,p3_fromY_PZ,mpi);


    TLorentzVector p1p2_fromY = (p1_fromY+p2_fromY);

    TLorentzVector p1_fromY_cmsp1p2 = p1_fromY;
    p1_fromY_cmsp1p2.Boost(-p1p2_fromY.Px()/p1p2_fromY.E(),-p1p2_fromY.Py()/p1p2_fromY.E(),-p1p2_fromY.Pz()/p1p2_fromY.E());
    TLorentzVector p2_fromY_cmsp1p2 = p2_fromY;
    p2_fromY_cmsp1p2.Boost(-p1p2_fromY.Px()/p1p2_fromY.E(),-p1p2_fromY.Py()/p1p2_fromY.E(),-p1p2_fromY.Pz()/p1p2_fromY.E());
    TLorentzVector p3_fromY_cmsp1p2 = p3_fromY;
    p3_fromY_cmsp1p2.Boost(-p1p2_fromY.Px()/p1p2_fromY.E(),-p1p2_fromY.Py()/p1p2_fromY.E(),-p1p2_fromY.Pz()/p1p2_fromY.E());

    TLorentzVector p2p3_fromY = (p2_fromY+p3_fromY);
    TLorentzVector p1_fromY_cmsp2p3 = p1_fromY;
    p1_fromY_cmsp2p3.Boost(-p2p3_fromY.Px()/p2p3_fromY.E(),-p2p3_fromY.Py()/p2p3_fromY.E(),-p2p3_fromY.Pz()/p2p3_fromY.E());
    TLorentzVector p2_fromY_cmsp2p3 = p2_fromY;
    p2_fromY_cmsp2p3.Boost(-p2p3_fromY.Px()/p2p3_fromY.E(),-p2p3_fromY.Py()/p2p3_fromY.E(),-p2p3_fromY.Pz()/p2p3_fromY.E());
    TLorentzVector p3_fromY_cmsp2p3 = p3_fromY;
    p3_fromY_cmsp2p3.Boost(-p2p3_fromY.Px()/p2p3_fromY.E(),-p2p3_fromY.Py()/p2p3_fromY.E(),-p2p3_fromY.Pz()/p2p3_fromY.E());


    theta_p1p3_cmsp1p2 =  p1_fromY_cmsp1p2.Vect().Angle(p3_fromY_cmsp1p2.Vect());
    theta_p3p1_cmsp2p3 =  p3_fromY_cmsp2p3.Vect().Angle(p1_fromY_cmsp2p3.Vect());

    mass2pi_12 = (p1_fromY+p2_fromY).M(); //<----------
    mass2pi_23 = (p2_fromY+p3_fromY).M(); //<----------
    mass2pi_31 = (p1_fromY+p3_fromY).M(); //<----------

    min_m2pi = TMath::Min(mass2pi_12,mass2pi_23); //<----------
    max_m2pi = TMath::Max(mass2pi_12,mass2pi_23); //<----------
    
    if (mass2pi_12<mass2pi_23) {
      cos2pimin  = cos(theta_p1p3_cmsp1p2); //<----------
      cos2pimax  = cos(theta_p3p1_cmsp2p3); //<----------
    } else {
      cos2pimin  = cos(theta_p3p1_cmsp2p3);
      cos2pimax  = cos(theta_p1p3_cmsp1p2);
    }

    TLorentzVector p1_fromY_cms3pi = p1_fromY;      p1_fromY_cms3pi.Boost(-pY.Px()/pY.E(),-pY.Py()/pY.E(),-pY.Pz()/pY.E());
    TLorentzVector p2_fromY_cms3pi = p2_fromY;      p2_fromY_cms3pi.Boost(-pY.Px()/pY.E(),-pY.Py()/pY.E(),-pY.Pz()/pY.E());
    TLorentzVector p3_fromY_cms3pi = p3_fromY;      p3_fromY_cms3pi.Boost(-pY.Px()/pY.E(),-pY.Py()/pY.E(),-pY.Pz()/pY.E());
    TLorentzVector pY_rec_cms3pi = pY_rec;          pY_rec_cms3pi.Boost(-pY.Px()/pY.E(),-pY.Py()/pY.E(),-pY.Pz()/pY.E());
    TLorentzVector pXc_cms3pi    = pXc;             pXc_cms3pi.Boost(-pY.Px()/pY.E(),-pY.Py()/pY.E(),-pY.Pz()/pY.E());


    TVector3 n3pi_cms3pi = p1_fromY_cms3pi.Vect().Cross(p3_fromY_cms3pi.Vect()); // normale

    sign = 1;
    if (mass2pi_12>mass2pi_23)  sign = -1; //<------- da salvare

    Double_t theta_n3pi_pYrec_cms3pi = n3pi_cms3pi.Angle(pY_rec_cms3pi.Vect());  //<------ angolo tra n3pi e pY_rec nel sdr 3pi
    Double_t theta_n3pi_pXc_cms3pi = n3pi_cms3pi.Angle(pXc_cms3pi.Vect()); //<------ angolo tra n3pi e pXc nel sdr 3pi


    ////// fino qui ok

    TLorentzVector p1_fromXc; p1_fromXc.SetXYZM(p1_fromXc_PX,p1_fromXc_PY,p1_fromXc_PZ,p1_fromXc_M);
    TLorentzVector p2_fromXc; p2_fromXc.SetXYZM(p2_fromXc_PX,p2_fromXc_PY,p2_fromXc_PZ,p2_fromXc_M);
    TLorentzVector p3_fromXc; p3_fromXc.SetXYZM(p3_fromXc_PX,p3_fromXc_PY,p3_fromXc_PZ,p3_fromXc_M);
    massKK_12 = (p1_fromXc+p2_fromXc).M();
    massKpi_23 = (p2_fromXc+p3_fromXc).M();
    massKpi_13 = (p1_fromXc+p3_fromXc).M();
    min_mKpi = TMath::Min(massKpi_23,massKpi_13); //<----------
    max_mKpi = TMath::Max(massKpi_23,massKpi_13); //<----------

#ifdef MC

    TLorentzVector pB_MC(B_TRUEP_X,B_TRUEP_Y,B_TRUEP_Z,B_TRUEP_E);
    TLorentzVector pXc_MC(Xc_TRUEP_X,Xc_TRUEP_Y,Xc_TRUEP_Z,Xc_TRUEP_E);
    TLorentzVector pY_MC(Y_TRUEP_X,Y_TRUEP_Y,Y_TRUEP_Z, Y_TRUEP_E);
    TLorentzVector p1_fromY_MC(p1_fromY_TRUEP_X,p1_fromY_TRUEP_Y,p1_fromY_TRUEP_Z,p1_fromY_TRUEP_E);
    TLorentzVector p2_fromY_MC(p2_fromY_TRUEP_X,p2_fromY_TRUEP_Y,p2_fromY_TRUEP_Z,p2_fromY_TRUEP_E);
    TLorentzVector p3_fromY_MC(p3_fromY_TRUEP_X,p3_fromY_TRUEP_Y,p3_fromY_TRUEP_Z,p3_fromY_TRUEP_E);
    TLorentzVector p3pi_MC = (p1_fromY_MC + p2_fromY_MC + p3_fromY_MC);
    //p1_fromY_MC.Print();
    TLorentzVector pW_MC = pB_MC-pXc_MC;
    missing_mass_MC = (pB_MC-pXc_MC-p3pi_MC).M();
    mass_W_MC = pW_MC.M();
    if (mass_W_MC>0) q2_MC = 1.e-6*mass_W_MC*mass_W_MC;
    else             q2_MC = -1.e-6*mass_W_MC*mass_W_MC;     // <-------------      

    mass_XcX_MC = (pB_MC-p3pi_MC).M();
    missing_pY_mass_MC = (pY_MC-p3pi_MC).M();    
    missing_pB_mass_MC = (pB_MC-pXc_MC-pY_MC).M();    

    TLorentzVector pB_cmsW_MC = pB_MC;
    TLorentzVector pY_cmsW_MC = pY_MC;
    pB_cmsW_MC.Boost(-pW_MC.Px()/pW_MC.E(),-pW_MC.Py()/pW_MC.E(),-pW_MC.Pz()/pW_MC.E());
    pY_cmsW_MC.Boost(-pW_MC.Px()/pW_MC.E(),-pW_MC.Py()/pW_MC.E(),-pW_MC.Pz()/pW_MC.E());

    theta_pB_pY_cmsW_MC = pB_cmsW_MC.Vect().Angle(pY_cmsW_MC.Vect()); // Definizione contraria rispetto ai dati (?)

    
    TLorentzVector p1_fromY_cms3pi_MC = p1_fromY_MC;
    TLorentzVector p2_fromY_cms3pi_MC = p2_fromY_MC;
    TLorentzVector p3_fromY_cms3pi_MC = p3_fromY_MC;
    TLorentzVector pY_cms3pi_MC = pY_MC;
    TLorentzVector pXc_cms3pi_MC = pXc_MC;
    
    p1_fromY_cms3pi_MC.Boost(-p3pi_MC.Px()/p3pi_MC.E(),-p3pi_MC.Py()/p3pi_MC.E(),-p3pi_MC.Pz()/p3pi_MC.E());
    p2_fromY_cms3pi_MC.Boost(-p3pi_MC.Px()/p3pi_MC.E(),-p3pi_MC.Py()/p3pi_MC.E(),-p3pi_MC.Pz()/p3pi_MC.E());
    p3_fromY_cms3pi_MC.Boost(-p3pi_MC.Px()/p3pi_MC.E(),-p3pi_MC.Py()/p3pi_MC.E(),-p3pi_MC.Pz()/p3pi_MC.E());
    pY_cms3pi_MC.Boost(-p3pi_MC.Px()/p3pi_MC.E(),-p3pi_MC.Py()/p3pi_MC.E(),-p3pi_MC.Pz()/p3pi_MC.E());
    pXc_cms3pi_MC.Boost(-p3pi_MC.Px()/p3pi_MC.E(),-p3pi_MC.Py()/p3pi_MC.E(),-p3pi_MC.Pz()/p3pi_MC.E());

    TVector3 n3pi_cms3pi_MC = p1_fromY_cms3pi_MC.Vect().Cross(p3_fromY_cms3pi_MC.Vect());    
    Double_t theta_n3pi_pY_cms3pi_MC  = n3pi_cms3pi_MC.Angle(pY_cms3pi_MC.Vect());//<------ angolo tra n3pi e pY  nel sdr 3pi
    Double_t theta_n3pi_pXc_cms3pi_MC = n3pi_cms3pi_MC.Angle(pXc_cms3pi_MC.Vect());//<------ angolo tra n3pi e pXc nel sdr 3pi


    TVector3 Ydir_MC(Y_TRUEENDVERTEX_X-B_TRUEENDVERTEX_X,Y_TRUEENDVERTEX_Y-B_TRUEENDVERTEX_Y,Y_TRUEENDVERTEX_Z-B_TRUEENDVERTEX_Z);
    Ydir_MC = Ydir_MC.Unit();    
    theta_Ydir_pY_MC = Ydir_MC.Angle(pY_MC.Vect()); // Angolo tra p_tau e direzione di volo del tau <<--------    
    Double_t theta_Ymax_MC = asin((mtau*mtau-m3pi*m3pi)/2./mtau/pY_MC.P()); // Valore dell'angolo che azzera il discriminante Eq11<< 
    
    TVector3 Bdir_MC(B_TRUEENDVERTEX_X-B_TRUEORIGINVERTEX_X,
                     B_TRUEENDVERTEX_Y-B_TRUEORIGINVERTEX_Y,
                     B_TRUEENDVERTEX_Z-B_TRUEORIGINVERTEX_Z);      
    Bdir_MC = Bdir_MC.Unit();
    
    Double_t _pY_rec_MC = getPmax(mtau, p3pi_MC, Ydir_MC);  // modulo dell'impulso del tau con Eq.10 calcolata con thetaYmax
    TLorentzVector pY_rec_MC;  pY_rec_MC.SetXYZM(Ydir_MC.X()*_pY_rec_MC,Ydir_MC.Y()*_pY_rec_MC,Ydir_MC.Z()*_pY_rec_MC,mtau);
    
    TLorentzVector pB_withpY_rec_MC      = pXc_MC + pY_rec_MC;          // impulso del B con p_tau corretto
    theta_Bdir_pB_withpY_rec_MC = Bdir_MC.Angle(pB_withpY_rec_MC.Vect()); // Angolo tra p_tau e direzione di volo del tau <<---
    
    theta_Bmax_MC = -1.E8;
    if (fabs((mB*mB-pB_withpY_rec_MC.M()*pB_withpY_rec_MC.M())/(2.*mB*pB_withpY_rec_MC.P()))<=1){        
      theta_Bmax_MC = asin((mB*mB-pB_withpY_rec_MC.M()*pB_withpY_rec_MC.M())/(2.*mB*pB_withpY_rec_MC.P())); // Eq13  Angolo che azzera il discriminante
    }
    Double_t _pB_rec_Yrec_MC   = getPmax( mB, pB_withpY_rec_MC, Bdir_MC); // modulo dell'impulso del tau con Eq.10 calcolata con thetaYmax
    TLorentzVector pB_rec_Yrec_MC;    
    pB_rec_Yrec_MC.SetXYZM(_pB_rec_Yrec_MC*Bdir_MC.X(),_pB_rec_Yrec_MC*Bdir_MC.Y(),_pB_rec_Yrec_MC*Bdir_MC.Z(),mB);
    TLorentzVector pW_MC_2 = pB_rec_Yrec_MC - pXc_MC;

    //----- Calcolo delle missing mass, mass_W, q2 etc
    //std::cout << "Creating q2_MC_2 _pB_rec_Yrec_MC: " <<_pB_rec_Yrec_MC << " << _pY_rec_MC:" << _pY_rec_MC << '\n';
    q2_MC_2 = -1.E8;
    mass_W_MC_2 = -1.E8;    
    missing_mass_MC_2 = -1.E8;    
    mass_XcX_MC_2 = -1E8;
    
    if (_pB_rec_Yrec_MC> -1 && _pY_rec_MC> -1) {
      //std::cout << "Creating q2_MC_2" << '\n';
      mass_W_MC_2 = pW_MC_2.M();            // <-------------
      if (mass_W_MC_2>0) q2_MC_2 = 1.e-6*mass_W_MC_2*mass_W_MC_2;
      else            q2_MC_2 = -1.e-6*mass_W_MC_2*mass_W_MC_2;     // <-------------
      
      mass_XcX_MC_2     = (pB_rec_Yrec_MC - pY_rec_MC).M();      // <-------------
      missing_mass_MC_2 = (pB_rec_Yrec_MC - pXc_MC - pY_rec_MC).M(); // <------------- missing mass con pB_rec_Yrec e pY corretto
    } 
    
#endif

    //TLorentzVector pXc;                pXc.SetXYZM(Xc_PX,Xc_PY,Xc_PZ,Xc_M);   
    TLorentzVector pGamma_020_maxPt;   pGamma_020_maxPt.SetXYZM(Xc_0_20_nc_maxPt_PX,Xc_0_20_nc_maxPt_PY,Xc_0_20_nc_maxPt_PZ,0);    
    
    //ConeSize0.2    
    MVA_nc_020 = -200;

    if(Xc_0_20_nc_mult >0)    {      
      Xcst_maxPt_020_M = (pXc+pGamma_020_maxPt).M();      
      Delta_ms_020_maxPt =Xcst_maxPt_020_M-Xc_M;      
      spec_nc_020[0]=(Float_t) B_MM;      
      spec_nc_020[1]=(Float_t) Xc_MM;      
      spec_nc_020[2]=(Int_t) Xc_0_20_nc_mult;
      
      var_nc_020[0] =(Float_t) Xc_0_20_nc_maxPt_PT;      
      var_nc_020[1] =(Float_t) Xc_0_20_nc_asy_P;      
      var_nc_020[2] =(Float_t) Xc_0_20_nc_deltaEta;      
      var_nc_020[3] =(Float_t) Xc_0_20_nc_deltaPhi;      
      var_nc_020[4] =(Float_t) Xc_0_20_nc_avCL;      
      var_nc_020[5] =(Float_t) Xc_pT_Breco_Yreco;      
      var_nc_020[6]=  Delta_ms_020_maxPt;      
      MVA_nc_020 = reader_nc_020->EvaluateMVA("BDT method");

    }else if(Xc_0_20_nc_mult==0){      
      spec_nc_020_mult0[0]=(Float_t) B_MM;      
      spec_nc_020_mult0[1]=(Float_t) Xc_MM;      
      spec_nc_020_mult0[2]= (Int_t) Xc_0_20_nc_mult;      

      var_nc_020_mult0[0] = Xc_pT_Breco_Yreco;
      MVA_nc_020 = reader_nc_020_mult0->EvaluateMVA("Fisher method");      
    }

    Int_t  min_index, minimum_Nb_NIsoTr;   
    Double_t minimum_IsoMinBDT, minimum_ConeIso, minimum_PAIR_M;
    
    Double_t arr_iso_min[]={ p1_fromXc_IsoMinBDT, p2_fromXc_IsoMinBDT,p3_fromXc_IsoMinBDT, 
                             p1_fromY_IsoMinBDT,  p2_fromY_IsoMinBDT,  p3_fromY_IsoMinBDT};
    //    Float_t arr_iso_min[]={(Float_t) p1_fromXc_IsoMinBDT, (Float_t) p2_fromXc_IsoMinBDT, (Float_t) p3_fromXc_IsoMinBDT, 
    //                           (Float_t)  p1_fromY_IsoMinBDT, (Float_t) p2_fromY_IsoMinBDT, (Float_t) p3_fromY_IsoMinBDT};
    
    int n = sizeof(arr_iso_min) / sizeof(arr_iso_min[0]);    
    minimum_IsoMinBDT = *min_element(arr_iso_min, arr_iso_min +n);
    

    if(p1_fromY_IsoMinBDT == minimum_IsoMinBDT)    {      
      minimum_PAIR_M =p1_fromY_PAIR_M;      
      minimum_Nb_NIsoTr= p1_fromY_Nb_NIsoTr;      
      minimum_ConeIso= p1_fromY_ConeIso;      
      min_index = 4;
    } else if(p2_fromY_IsoMinBDT == minimum_IsoMinBDT)    {      
      minimum_PAIR_M =p2_fromY_PAIR_M;      
      minimum_Nb_NIsoTr= p2_fromY_Nb_NIsoTr;      
      minimum_ConeIso= p2_fromY_ConeIso;      
      min_index = 5;
    } else if(p3_fromY_IsoMinBDT == minimum_IsoMinBDT)    {      
      minimum_PAIR_M =p3_fromY_PAIR_M;      
      minimum_Nb_NIsoTr= p3_fromY_Nb_NIsoTr;      
      minimum_ConeIso= p3_fromY_ConeIso;      
      min_index = 6;
    } else if(p1_fromXc_IsoMinBDT == minimum_IsoMinBDT)    {      
      minimum_PAIR_M =p1_fromXc_PAIR_M;      
      minimum_Nb_NIsoTr= p1_fromXc_Nb_NIsoTr;      
      minimum_ConeIso= p1_fromXc_ConeIso;      
      min_index = 1;
    } else if(p2_fromXc_IsoMinBDT == minimum_IsoMinBDT)    {      
      minimum_PAIR_M =p2_fromXc_PAIR_M;      
      minimum_Nb_NIsoTr= p2_fromXc_Nb_NIsoTr;      
      minimum_ConeIso= p2_fromXc_ConeIso;      
      min_index = 2;
    } else if(p3_fromXc_IsoMinBDT == minimum_IsoMinBDT)    {      
      minimum_PAIR_M =p3_fromXc_PAIR_M;      
      minimum_Nb_NIsoTr= p3_fromXc_Nb_NIsoTr;      
      minimum_ConeIso= p3_fromXc_ConeIso;      
      min_index = 3;
    }
    //BDT part
    BDT_Iso = -30;
    
    spec_Iso[0] =(Float_t) B_MM;    
    spec_Iso[1] =(Float_t) Xc_MM;    

    var_Iso[0]=(Float_t) minimum_IsoMinBDT;    
    var_Iso[1]=(Int_t) minimum_Nb_NIsoTr;    
    var_Iso[2]=(Float_t) minimum_ConeIso;    
    var_Iso[3]=(Float_t) minimum_PAIR_M;    
    var_Iso[4]=(Float_t) BDT_Bs;
    
    BDT_Iso = reader_Iso->EvaluateMVA("BDT method");

    if (fBDT_Iso_cut != NO_CUT) {
      if (BDT_Iso < fBDT_Iso_cut) {
          continue;
      }
    }
    
    // extra column to easily split the dataset
    if (eventNumber % 2 == 0) {
      //std::cout << "=== Even\n";
      index = 0;//Even
    } else {
      //std::cout << "=== Odd\n";
      index = 1;//Odd
    }



    // Clone the pidgen info into the correct vars
    // clone_p1_fromXc_PIDK_pidgen_default = p1_fromXc_PIDK_pidgen_default;
    // clone_p1_fromXc_PIDp_pidgen_default = p1_fromXc_PIDp_pidgen_default;
    // clone_p2_fromXc_PIDK_pidgen_default = p2_fromXc_PIDK_pidgen_default;
    // clone_p2_fromXc_PIDp_pidgen_default = p2_fromXc_PIDp_pidgen_default;
    // clone_p3_fromXc_PIDK_pidgen_default = p3_fromXc_PIDK_pidgen_default;
    // clone_p3_fromXc_PIDp_pidgen_default = p3_fromXc_PIDp_pidgen_default;
    // clone_p1_fromY_PIDK_pidgen_default = p1_fromY_PIDK_pidgen_default;
    // clone_p1_fromY_PIDp_pidgen_default = p1_fromY_PIDp_pidgen_default;
    // clone_p2_fromY_PIDK_pidgen_default = p2_fromY_PIDK_pidgen_default;
    // clone_p2_fromY_PIDp_pidgen_default = p2_fromY_PIDp_pidgen_default;
    // clone_p3_fromY_PIDK_pidgen_default = p3_fromY_PIDK_pidgen_default;
    // clone_p3_fromY_PIDp_pidgen_default = p3_fromY_PIDp_pidgen_default;
   
    newtree->Fill();
   }
   //newtree->Print();
   newfile->Write("", TObject::kOverwrite);
   cout<<" count = "<<count<<" pass StrippingSig"<<count_StrippingSig<<endl;
   newfile->Close();
   
}

void RDsProcess_noBYsep(TString ntuple_filename, TString pidinfo_filename, TString output_filename, TString eventtype) {

    // TString ntuple_filename{"root://eoslhcb.cern.ch//eos/lhcb/grid/prod/lhcb/MC/2012/BSDS3PI.ROOT/00172470/0000/00172470_00000001_1.bsds3pi.root"};
    // TString pidinfo_filename{"root://eoslhcb.cern.ch//eos/lhcb/wg/semileptonic/RDsHad/AP/pidgen_merged/mergedpidgen_2012_13266069_magdown_None_e15b007c-71c7-11ed-9717-51398e80beef.root"};
    // TString output_filename{"/tmp/toto.root"};
    bool inclMCmode = false;
    Double_t BDT_Iso_cut = NO_CUT;
    Double_t B_Y_SEP_cut = NO_CUT;
    if ((eventtype ==  "23903000") || (eventtype ==  "23903003")) {
      inclMCmode = true;
      BDT_Iso_cut = 0.03458;
    }

    if (BDT_Iso_cut != NO_CUT) {
      cout << "Filtering for BDT_Iso > " << BDT_Iso_cut << '\n';
    }
    BsSignalCUT c{ntuple_filename, pidinfo_filename, output_filename, inclMCmode, 10000.0, BDT_Iso_cut};
    c.Loop();
}
