double x[3] = {1.0, 2.0, 3.0};
double y[3] = {3.0, 2.0, 3.5};

void plot_points() {
  gStyle->SetOptStat(111);
  gStyle->SetOptFit(111);
  TGraph *gr = new TGraph(3, x, y);
  gr->Fit("pol2");
  gr->Draw("AC*");
}
