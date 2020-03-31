#include "TCanvas.h"
#include "TH1.h"
#include "TRandom3.h"
#include "TStyle.h"
#include <iostream>

void Gaussian() {
  // Varibles for the gaussian
  int num = 100000;
  double mean = 5.0;
  double sigma = 1.0;
  double thrw = 0;
  // Create a random generator
  TRandom3 gen(rand());

  // Create histogram to fill
  TH1F *hist = new TH1F("hist", "Gaussian", 100, 0.0, 10.0);
  // Define the gui to display the graph and set the display options
  TCanvas *c1 = new TCanvas("c1", "Root Example", 200, 10, 700, 500);
  gStyle->SetOptStat(111);
  gStyle->SetOptFit(111);

  for (int i = 0; i < num; i++) {
    // Throw a normal(gaussian) distrobution
    thrw = gen.Gaus(mean, sigma);
    // Fill in histogram
    hist->Fill(thrw);
  }
  // Enter the canvas to draw
  c1->cd();
  // Draw histogram in gui
  hist->Draw();
  // Fit gaussian to the histogram
  hist->Fit("gaus");
}
