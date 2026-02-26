//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Mon Apr 20 16:15:00 2020 by ROOT version 6.20/02
// from TTree DecayTree/DecayTree

//////////////////////////////////////////////////////////

#ifndef BsSignalCUT_h
#define BsSignalCUT_h



#include <TLorentzVector.h>
#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <cstdlib>
#include <vector>
#include <iostream>
#include <map>
#include <string>
#include <TString.h>
#include <TSystem.h>
#include <TROOT.h>
#include <TStopwatch.h>
#include <TMath.h>
using namespace std;

const Double_t xp0 = 1.03, xp1 = -0.00199; // correzioni R(D*Had) Run2
int i0=0;

const Double_t NO_CUT=-10000;

class BsSignalCUT {
public :
  TTree          *fChain;   //!pointer to the analyzed TTree or TChain
  Int_t           fCurrent; //!current Tree number in a TChain
  TString         fOutputFilename;
  bool fInclMCmode;
  Double_t fB_Y_SEP_cut;
  Double_t fBDT_Iso_cut;

  Double_t mpi = 139.570175172;
  Double_t mDs = 1968.34;
  
  Double_t mK = 493.677001953;
  Double_t mtau = 1776.86;
  Double_t mnu = 0.;
  Double_t mB = 5366.88;

#include "LEAF_definition.h"



   BsSignalCUT(TString ntuple_filename, TString pidinfo_filename, TString output_filename, 
                bool inclMCmode=false, Double_t B_Y_SEP_cut=NO_CUT, Double_t BDT_Iso_cut=NO_CUT, TTree *tree=0);
   virtual ~BsSignalCUT();


  virtual Double_t getP(double mass, TLorentzVector p3pi, TVector3 taudir);
  virtual Double_t getPmax(double mass, TLorentzVector p3pi, TVector3 taudir);
  virtual Double_t getDelta(double mass, TLorentzVector p3pi, TVector3 taudir);
  virtual Double_t det(TVector3 X, TVector3 Y, TVector3 Z);  
  virtual TVector3 VProduct(TVector3 Vect1, TVector3 Vect2);

  virtual Double_t  ComputeEnergy(Double_t px,Double_t py,Double_t pz,Double_t mass);
  virtual Int_t    Cut(Long64_t entry);
  virtual Int_t    GetEntry(Long64_t entry);
  virtual Long64_t LoadTree(Long64_t entry);
  virtual void     Init(TTree *tree);
  virtual void     Loop();
  virtual Bool_t   Notify();
  virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef BsSignalCUT_cxx
BsSignalCUT::BsSignalCUT(TString ntuple_filename, TString pidinfo_filename, TString output_filename, 
                          bool inclMCmode, Double_t B_Y_SEP_cut, 
                          Double_t BDT_Iso_cut, TTree *tree) : fChain(0), fOutputFilename(output_filename) {
  fInclMCmode = inclMCmode;
  fB_Y_SEP_cut = B_Y_SEP_cut;
  fBDT_Iso_cut = BDT_Iso_cut;
  TString dirTree("");
  dirTree="SignalTuple/";
#ifdef WS
  dirTree="SignalTupleWS/";
#endif
#ifdef PIDcorr
  dirTree="";
#endif  
  TString treeName("DecayTree");
  
  // if parameter tree is not specified (or zero), connect the file
  // used to generate this class and read the Tree.
  
  //XXXTChain *ch = new TChain(dirTree+treeName,treeName);
  TChain *ch = new TChain("SignalTuple/DecayTree");
  Int_t nTOTfile=1000;  
  if (tree == 0) {
     TString fileName("pippo");  
#ifdef MC // -------------- MC -----------------
    //  TString dir("/eos/lhcb/wg/semileptonic/RDsHad/tuple/2012/PIDcorr/");

    //  for(int i=10*i0; i<min(10*(1+i0),nTOTfile); i++)  {
    //     fileName.Form("bsdstaunu_MagDown_2012_PIDcorr%d.root",i);
    //     if (!gSystem->AccessPathName(dir+fileName)) {
    //       cout<<" Processing "<<fileName<<endl;          
    //       ch->Add(dir+fileName);
    //     }
        
    //  }

    //  XXX BC replace previous code by loading the data from JSON
    // ch->Add("root://eoslhcb.cern.ch//eos/lhcb/grid/prod/lhcb/MC/2012/BSDS3PI.ROOT/00172470/0000/00172470_00000001_1.bsds3pi.root");
    // ch->AddFriend("DecayTree", "root://eoslhcb.cern.ch//eos/lhcb/wg/semileptonic/RDsHad/AP/pidgen_merged/mergedpidgen_2012_13266069_magdown_None_e15b007c-71c7-11ed-9717-51398e80beef.root");
    ch->Add(ntuple_filename);
    ch->AddFriend("DecayTree", pidinfo_filename);

#else //--------- DATI ------------------
     Int_t RunNumber=169890;  //Bup   Right sign
     //Int_t RunNumber=169914; // Bdown Right sign
#ifdef WS
     //Int_t RunNumber=169888;  //Bup   Wrong sign combination     
     //Int_t RunNumber=169912; // Bdown Wrong sign combination
#endif     
     TString dir;
     dir.Form("/eos/lhcb/grid/prod/lhcb/LHCb/Collision12/DATA_BS.ROOT/%08d/0000/",RunNumber);
     for(int i=10*i0; i<min(10*(1+i0),nTOTfile); i++)  {
       fileName.Form("%08d_%08d_1.data_bs.root",RunNumber,i);
       if (!gSystem->AccessPathName(dir+fileName)) {
          cout<<" Processing "<<fileName<<endl;          
          ch->Add(dir+fileName);
       }
       
     }
#endif
     tree = ch;
     Init(ch);
   }
  //Init(tree);
}

BsSignalCUT::~BsSignalCUT()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t BsSignalCUT::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t BsSignalCUT::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void BsSignalCUT::Init(TTree *tree)
{
   TString extra("");

#if defined(MC)
   //XXXextra = "_corr";
   extra = "_pidgen_default";

#endif

   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);
#include "LEAF_BranchAddress.h" //NB!!!! contains the string extra

   Notify();
}

Bool_t BsSignalCUT::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void BsSignalCUT::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Double_t BsSignalCUT::ComputeEnergy(Double_t px,Double_t py,Double_t pz,Double_t mass){
    double p2, E2, E;
    p2 = px*px+ py*py+pz*pz;    
    E2 = p2+mass*mass;    
    E = sqrt(E2);    
    return E;
}

Int_t BsSignalCUT::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
#ifdef TRIGGER
  if(!((B_L0HadronDecision_TOS==1 || B_L0Global_TIS==1) && B_Hlt1TrackAllL0Decision_TOS==1 )) return -1;  
#endif

  if( fabs(Xc_MM-1968)> 20 ) return -1;  
  /*
//==================== TAGLI su TRUEID e BKGCAT si fanno dopo ======================================
#ifdef MC
#ifdef BsNORM
  if( !( Xc_BKGCAT == 0 && B_BKGCAT==10  &&   //NB old definition included .OR. Xc_BKGCAT==50
#else
  if( !( Xc_BKGCAT== 0 &&  Y_BKGCAT==50 &&   // old definition didn't include Y_BKGCAT==50 but included .OR. Xc_BKGCAT==50
#endif
#ifndef WS
	 B_BKGCAT==50 
#endif
	 
	 &&
	 abs(p1_fromXc_TRUEID)==321 && 
	 abs(p2_fromXc_TRUEID)==321 && 
	 abs(p3_fromXc_TRUEID)==211 && 
	 abs(p1_fromY_TRUEID)+abs(p2_fromY_TRUEID)+abs(p3_fromY_TRUEID)==3*211 
	 //abs(p1_fromY_TRUEID)+abs(p2_fromY_TRUEID)+abs(p3_fromY_TRUEID)==2*211+321
	 
	 )) return -1;  
#else
  if(B_MM<5200) return -1;
#endif
//==========================================================================================
*/
  
  //D0->KK veto  
  TLorentzVector K1(p1_fromXc_PX,p1_fromXc_PY,p1_fromXc_PZ,p1_fromXc_PE);
  TLorentzVector K2(p2_fromXc_PX,p2_fromXc_PY,p2_fromXc_PZ,p2_fromXc_PE);
  TLorentzVector pi3(p3_fromXc_PX,p3_fromXc_PY,p3_fromXc_PZ,p3_fromXc_PE);


  if((K1 + K2).M()>1840) return -1;

  double E = ComputeEnergy(p2_fromXc_PX,p2_fromXc_PY,p2_fromXc_PZ,139.57);  
  TLorentzVector pi2(p2_fromXc_PX,p2_fromXc_PY,p2_fromXc_PZ,E);
  if(fabs ((K1+pi2+pi3).M()-1869.65)<=30 && p2_fromXc_PIDK<10) return -1;

  E = ComputeEnergy(p2_fromXc_PX,p2_fromXc_PY,p2_fromXc_PZ,938.27);
  TLorentzVector p2(p2_fromXc_PX,p2_fromXc_PY,p2_fromXc_PZ,E);  
  if(fabs ((K1+p2+pi3).M()-2286.46)<30 && (p2_fromXc_PIDK - p2_fromXc_PIDp)<5) return -1;

  if(fabs((K1+K2).M()-1020)<=12 )  {

    // std::cout << "p1_fromXc_PIDK:" << p1_fromXc_PIDK << '\n';
    // std::cout << "p2_fromXc_PIDK:" << p2_fromXc_PIDK << '\n';
    // std::cout << "p3_fromXc_PIDK:" << p3_fromXc_PIDK << '\n';    
    // std::cout << "=======================================\n";

    if (!(p1_fromXc_PIDK>-2 && p2_fromXc_PIDK>-2)) return -1;
  } else if (fabs((K1+pi3).M()-892)<=50){   //k star mass                    
    if (!(p1_fromXc_PIDK>-2 && p2_fromXc_PIDK>5)) return -1;
  } else 
    if (!(p1_fromXc_PIDK>5 && p2_fromXc_PIDK>5 && p3_fromXc_PIDK<10)) return -1;
  
  return 1;
  


}

  Double_t BsSignalCUT::getP(double mass, TLorentzVector p3pi, TVector3 taudir) {

  Double_t thetatau = taudir.Angle(p3pi.Vect());
  Double_t ptau_0_calc = 
    (p3pi.M()*p3pi.M()+mass*mass)*p3pi.P()*cos(thetatau)/2./
    (p3pi.E()*p3pi.E()-p3pi.P()*p3pi.P()*cos(thetatau)*cos(thetatau));

  return ptau_0_calc;
  
  }
Double_t BsSignalCUT::getPmax(double mass, TLorentzVector p3pi, TVector3 taudir) {

  double argu = (mass*mass-p3pi.M()*p3pi.M())/2./mass/p3pi.P();
  double thetataumax = asin(argu);
  double ptau_max_calc = 
    (p3pi.M()*p3pi.M()+mass*mass)*p3pi.P()*cos(thetataumax)/2. /
    (p3pi.E()*p3pi.E()-p3pi.P()*p3pi.P()*cos(thetataumax)*cos(thetataumax));
  if (abs(argu)>1.) {
    return -1.E+8;
  }
  else return ptau_max_calc;
  
}
Double_t BsSignalCUT::getDelta(double mass, TLorentzVector p3pi, TVector3 taudir) {

  double thetatau = taudir.Angle(p3pi.Vect());
  double ptau_D_calc = 0.;

  double Delta2 = 
    (mass*mass-p3pi.M()*p3pi.M())*(mass*mass-p3pi.M()*p3pi.M())
    -4.*mass*mass*p3pi.P()*p3pi.P()*sin(thetatau)*sin(thetatau);

  ptau_D_calc = -1.E+8;
  if (Delta2>0) 
    ptau_D_calc = p3pi.E()*sqrt(Delta2)/2./(p3pi.E()*p3pi.E()-p3pi.P()*p3pi.P()*cos(thetatau)*cos(thetatau));
  
  return ptau_D_calc;  

}
 Double_t BsSignalCUT::det(TVector3 X, TVector3 Y, TVector3 Z) {
  return X.X()*(Y.Y()*Z.Z()-Y.Z()*Z.Y()) - X.Y()*(Y.X()*Z.Z()-Y.Z()*Z.X()) + X.Z()*(Y.X()*Z.Y()-Y.Y()*Z.X());
}

 TVector3 BsSignalCUT::VProduct(TVector3 Vect1, TVector3 Vect2) {

  TVector3 Product;
  Product[0] = Vect1.Y()*Vect2.Z() - Vect1.Z()*Vect2.Y();
  Product[1] = -Vect1.X()*Vect2.Z() + Vect1.Z()*Vect2.X();
  Product[2] = Vect1.X()*Vect2.Y() - Vect1.Y()*Vect2.X();

  return TVector3(Product[0],Product[1],Product[2]);
}
#endif 
// #ifdef BsSignalCUT_cxx
