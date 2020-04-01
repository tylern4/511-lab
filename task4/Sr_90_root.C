%jsroot on

// TODO:
// Download all the root files from (http://boson.physics.sc.edu/~nick/root_data.html)
// Make a histogram with all data from that file
// Fit with the poison function (https://root.cern.ch/root/htmldoc/guides/users-guide/FittingHistograms.html)
// Extract mu
// Plot mu versus Delta t from the different runs to calculate the detected event rate

#include "TChain.h"
#include "TF1.h"
#include "TMath.h"
#include "TROOT.h"
#include "TTree.h"
#include <string>

double poison(double *x, double *par) {
  return par[0] * TMath::Poisson(x[0], par[1]);
}

void Sr90_ana(std::string fin = "5ms_1000s.root") {
  gStyle->SetOptStat(111);
  gStyle->SetOptFit(111);

  // Input filename
  TChain *chain = new TChain("Sr90");
  chain->Add(fin.c_str());
  // This creates a Poisson fitting function from the function created above
  TF1 *pois = new TF1("pois", poison, 0, 10, 2);

  // Get values from the file
  int _x1;
  chain->SetBranchAddress("x1", &_x1);

  int num_of_events = (int)chain->GetEntries();
  for (int current_event = 0; current_event < num_of_events; current_event++) {
    // Get current event and print out the event rate
    chain->GetEntry(current_event);
    std::cout << _x1 << std::endl;
  }

  chain->Reset();
}

Sr90_ana("50ms_10000s.root")


