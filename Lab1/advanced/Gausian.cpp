#include "TH1.h"
#include "TRandom3.h"
#include "TCanvas.h"
#include "TFile.h"
#include "TStyle.h"
#include <iostream>

int main(int argc, char const *argv[]) {
  // Create output file
  TFile *out = new TFile("out.root", "RECREATE");
  TCanvas *c1 = new TCanvas("c1", "Root Example", 200, 10, 700, 500);
  // Varibles for the gaussian
  int num = 100000;
  double mean = 5.0;
  double sigma = 1.0;
  double thrw = 0;

  if (argc > 1) {
    num = atoi(argv[1]);
  } else if (argc > 2) {
    num = atoi(argv[1]);
    mean = atof(argv[2]);
  } else if (argc > 3) {
    num = atoi(argv[1]);
    mean = atof(argv[2]);
    sigma = atof(argv[3]);
  }

  // Create random generator
  TRandom3 gen;

  // Create histogram to fill
  TH1F *hist = new TH1F("hist", "Gaussian", 100, 0.0, 10.0);

  for (int i = 0; i < num; i++) {
    // Throw a normal(gaussian) distrobution
    thrw = gen.Gaus(mean, sigma);
    // Fill in histogram
    hist->Fill(thrw);
  }

  // Fit gaussian to the histogram
  hist->Fit("gaus");
  // Save histogram to output file
  out->cd();
  out->Write();

  return 0;
}
