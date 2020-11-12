#include "TCanvas.h"
#include "TROOT.h"
#include "TGraphErrors.h"
#include "TF1.h"
#include "TLegend.h"
#include "TArrow.h"
#include "TLatex.h"

void genieread110520(){

Int_t npdg, mass    ;
   TFile *f = new TFile("gntp.5000.gtrac.root");
//f->ls();
   TTree *t2 = (TTree*)f->Get("gRooTracker");
Int_t nevent = t2->GetEntries();
TLeaf *PDG = (TLeaf*) t2->GetLeaf("StdHepPdg");
TLeaf *Mass = (TLeaf*) t2->GetLeaf("StdHepP4");
/*
for ( int event =0; event <nevent ; ++event){
    t2->GetEntry(event);
     npdg = PDG->GetValue();
     mass = Mass->GetValue(3);
    std::cout<<"PDG number   = " << npdg << "......with mass = "<<mass <<std::endl;
}
*/
//std::cout<<"number of events   = " << nevent <<std::endl;
//t2->ls();
TCanvas *c1 = new TCanvas("c1","c1",800,800);
 //  c1->SetFillColor(42);
 //  c1->Divide(1,2);
 //  t2->Draw("StdHepP4[3]:EvtVtx");
 // t2->Draw("EvtVtx");
//t2->Draw("StdHepP4[3]:StdHepPdg", "", "colz");
//t2->Draw("EvtVtx:StdHepPdg", "", "colz");
//t2->Draw("StdHepP4[3]:EvtVtx[2]");
//t2->Draw("StdHepPdg","StdHepP4[3]<0.1");
//t2->Draw("StdHepPdg:EvtVtx[0]","StdHepP4[3]<0.1", "colz");
//  t2->Draw("StdHepP4[3]","StdHepPdg<100000");
//  t2->SetLineColor(kRed);
//  t2->Draw("StdHepP4[3]","StdHepPdg>100000","same");
  t2->Draw("StdHepP4[3]","StdHepPdg<20000000");
  t2->SetLineColor(kRed);
  t2->Draw("StdHepP4[3]","StdHepPdg>20000000","same");
//t2->Draw("StdHepPdg");
/*
TCanvas *c1 = new TCanvas("c1","c1",600,800);
   c1->SetFillColor(42);
   c1->Divide(1,2);

c1->cd(1);
t2->SetMarkerColor(kRed);
   t2->Draw("vect[0]:vect[1]:vect[2]");

t3->Draw("pz","pt>3");
TCut cut1 = "x<1"  ;
t3->Draw("x", cut1);
t3->Draw("Cost:Age", "","",1000,100);

*/


//https://root.cern.ch/root/htmldoc/guides/users-guide/Trees.html#examples-for-writing-and-reading-trees
}
