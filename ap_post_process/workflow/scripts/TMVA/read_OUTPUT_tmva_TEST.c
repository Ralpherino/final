#include<stdio.h>
#include<TFile.h>
#include<TTree.h>
#include<TChain.h>
#include<TBranch.h>
#include<TMath.h>
#include<TH1F.h>
#include<TH2F.h>
#include<TApplication.h>
#include<TCanvas.h>
#include<TStyle.h>
#include<math.h>
#include<string.h>
#include<fstream>
#include<string>
#include<iomanip>
#include <iostream>
#include <fstream>

#include <time.h>





using namespace std;

#define SIZE 2000





int read_OUTPUT_tmva_TEST(){
    
    time_t start,end;
    time (&start);

   
    
    
    
//        TFile *f=new TFile("TMVA_OUTPUT_data.root","read");
//        TDirectoryFile *dir = (TDirectoryFile*)f->Get("dataset");
//        TTree* hh = (TTree*)dir->Get("TestTree");
//
    TFile *f=new TFile("output_BDT_cut.root","read");
    //TDirectoryFile *dir = (TDirectoryFile*)f->Get("dataset");
    TTree* hh = (TTree*)f->Get("DecayTree");
    
    int nentries=hh->GetEntries();
    cout<<"total entries: " <<nentries<<endl;
    
    //TH1D *MVA_BDT_effS = (TH1D*)f->Get("MVA_BDT_effS");
    
  
    
   
        
        // Declaration of leaf types
        //Int_t           classID;
        //Char_t          className[11];
//        Float_t         p1_fromY_ETA;
//        Float_t         p2_fromY_ETA;
//        Float_t         p3_fromY_ETA;
//        Float_t         log_p1_fromY_PT_;
//        Float_t         log_p2_fromY_PT_;
//        Float_t         log_p3_fromY_PT_;
//        Float_t         Y_DOCA1;
//        Float_t         Y_DOCA2;
//        Float_t         Y_DOCA3;
//        Float_t         Y_ENDVERTEX_CHI2;
//        Float_t         log_Y_IPCHI2_OWNPV_;
//        Float_t         B_MM;
//        Float_t         Xc_MM;
        //Float_t         weight;
        Float_t         BDT;
    
    Double_t         p1_fromY_ETA;
    Double_t         p2_fromY_ETA;
    Double_t         p3_fromY_ETA;
    Double_t         p1_fromY_PT;
    Double_t         p2_fromY_PT;
    Double_t         p3_fromY_PT;
    Double_t         Y_DOCA1;
    Double_t         Y_DOCA2;
    Double_t         Y_DOCA3;
    Double_t         Y_ENDVERTEX_CHI2;
    Double_t         Y_IPCHI2_OWNPV;
    Double_t         B_MM;
    Double_t         Xc_MM;
        
        // List of branches
        //TBranch        *b_classID;   //!
        //TBranch        *b_className;   //!
        TBranch        *b_p1_fromY_ETA;   //!
        TBranch        *b_p2_fromY_ETA;   //!
        TBranch        *b_p3_fromY_ETA;   //!
        TBranch        *b_p1_fromY_PT;   //!
        TBranch        *b_p2_fromY_PT;   //!
        TBranch        *b_p3_fromY_PT;   //!
        TBranch        *b_Y_DOCA1;   //!
        TBranch        *b_Y_DOCA2;   //!
        TBranch        *b_Y_DOCA3;   //!
        TBranch        *b_Y_ENDVERTEX_CHI2;   //!
        TBranch        *b_Y_IPCHI2_OWNPV;   //!
        TBranch        *b_B_MM;   //!
        TBranch        *b_Xc_MM;   //!
        //TBranch        *b_weight;   //!
        TBranch        *b_BDT;   //!
        
   
 
    
   
    
    
        
        //hh->SetBranchAddress("classID", &classID, &b_classID);
        //hh->SetBranchAddress("className", className, &b_className);
        hh->SetBranchAddress("p1_fromY_ETA", &p1_fromY_ETA, &b_p1_fromY_ETA);
        hh->SetBranchAddress("p2_fromY_ETA", &p2_fromY_ETA, &b_p2_fromY_ETA);
        hh->SetBranchAddress("p3_fromY_ETA", &p3_fromY_ETA, &b_p3_fromY_ETA);
        hh->SetBranchAddress("p1_fromY_PT", &p1_fromY_PT, &b_p1_fromY_PT);
        hh->SetBranchAddress("p2_fromY_PT", &p2_fromY_PT, &b_p2_fromY_PT);
        hh->SetBranchAddress("p3_fromY_PT", &p3_fromY_PT, &b_p3_fromY_PT);
        hh->SetBranchAddress("Y_DOCA1", &Y_DOCA1, &b_Y_DOCA1);
        hh->SetBranchAddress("Y_DOCA2", &Y_DOCA2, &b_Y_DOCA2);
        hh->SetBranchAddress("Y_DOCA3", &Y_DOCA3, &b_Y_DOCA3);
        hh->SetBranchAddress("Y_ENDVERTEX_CHI2", &Y_ENDVERTEX_CHI2, &b_Y_ENDVERTEX_CHI2);
        hh->SetBranchAddress("Y_IPCHI2_OWNPV", &Y_IPCHI2_OWNPV, &b_Y_IPCHI2_OWNPV);
        hh->SetBranchAddress("B_MM", &B_MM, &b_B_MM);
        hh->SetBranchAddress("Xc_MM", &Xc_MM, &b_Xc_MM);
        //hh->SetBranchAddress("weight", &weight, &b_weight);
        hh->SetBranchAddress("BDT", &BDT, &b_BDT);
    
    
    TH1F *B_mass = new TH1F("B_mass","",100,2500,6000);
    TH1F *B_mass_afterBDTcut = new TH1F("B_mass_afterBDTcut","",100,2500,6000);
    
    TH1F *D_mass = new TH1F("D_mass","",100,1948,1988);
    TH1F *D_mass_afterBDTcut = new TH1F("D_mass_afterBDTcut","",100,1948,1988);

    int events_after_BDT_cut=0;
    
    for(int i=0; i<nentries; i++){
        hh->GetEntry(i);

        
        B_mass->Fill(B_MM);
        D_mass->Fill(Xc_MM);

        
        if(BDT > (-0.0558)){
            events_after_BDT_cut ++;
            B_mass_afterBDTcut->Fill(B_MM);
            D_mass_afterBDTcut->Fill(Xc_MM);

            
        }
        
        
        
        
    }
    
    cout << "total events: " <<nentries <<endl;
   
    cout << "BDT > -0.0558: " <<events_after_BDT_cut <<endl;
    
    ///////ETA/////////
    
    
    
    TCanvas *canvas2=new TCanvas("canvas2","",700,700);
    
    
    canvas2->cd(1);
    
    
    TLegend *legenda = new TLegend(0.2, 0.75, 0.4, 0.9);
    gStyle->SetLegendTextSize(0.03);
    gPad->SetLeftMargin(0.17);
    
    
//    Double_t *integral = B_mass->GetIntegral();
//    //Double_t ratio = pow(integral,-1);
//    B_mass->Scale(pow(integral,-1));
    
    Double_t norm1 = 1;
    Double_t scale1 = norm1/(B_mass->Integral());
    B_mass->Scale(scale1);
    
    B_mass->SetTitle("Bs mass(B_MM)");
    B_mass->GetXaxis()->SetTitle("mass [MeV/c^{2}]");
    //SIGNAL_signal_tau_eta->GetXaxis()->SetLabelSize(0.03);
    B_mass->GetYaxis()->SetTitle("events");
    //gPad->SetLogy();
    B_mass->Draw("hist");
    
    Double_t norm2 = 1;
    Double_t scale2 = norm2/(B_mass_afterBDTcut->Integral());
    B_mass_afterBDTcut->Scale(scale2);
    
    B_mass_afterBDTcut->SetLineColor(2);
    B_mass_afterBDTcut->Draw("samehist");
    
    
    
    
    
    legenda->AddEntry(B_mass,Form("total: %d ",nentries),"lp");
    legenda->AddEntry(B_mass_afterBDTcut,Form("after BDT CUT: %d ",events_after_BDT_cut),"lp");
    
    //legenda->Draw();
    
    
    
//    TCanvas *canvas3=new TCanvas("canvas3","",700,700);
//
//
//    canvas3->cd(1);
//
//
//    TLegend *legenda1 = new TLegend(0.18, 0.75, 0.5, 0.9);
//    gStyle->SetLegendTextSize(0.025);
//    gPad->SetLeftMargin(0.17);
//
//
//    //    Double_t *integral = B_mass->GetIntegral();
//    //    //Double_t ratio = pow(integral,-1);
//    //    B_mass->Scale(pow(integral,-1));
//
//    Double_t norm3 = 1;
//    Double_t scale3 = norm3/(D_mass->Integral());
//    D_mass->Scale(scale3);
//
//    D_mass_afterBDTcut->SetTitle("Ds mass(Xc_MM)");
//    D_mass_afterBDTcut->GetXaxis()->SetTitle("mass [MeV/c^{2}]");
//    //SIGNAL_signal_tau_eta->GetXaxis()->SetLabelSize(0.03);
//    D_mass_afterBDTcut->GetYaxis()->SetTitle("events");
//    //gPad->SetLogy();
//
//
//    Double_t norm4 = 1;
//    Double_t scale4 = norm4/(D_mass_afterBDTcut->Integral());
//    D_mass_afterBDTcut->Scale(scale4);
//
//    D_mass_afterBDTcut->SetLineColor(2);
//    D_mass_afterBDTcut->Draw("samehist");
//
//    D_mass->Draw("samehist");
//
//
//
//
//
//    legenda1->AddEntry(D_mass,Form("total: %d ",nentries),"lp");
//    legenda1->AddEntry(D_mass_afterBDTcut,Form("after BDT CUT: %d ",events_after_BDT_cut),"lp");
//
//    legenda1->Draw();






    
    
    
    time (&end);
    double dif = difftime (end,start);
    printf ("Elasped time is %.2lf seconds.", dif );
    
    
//            cc->Print("htime_corr3new.pdf(");
    

    //myapp->Run(true);
   return 0;
	
	
}
