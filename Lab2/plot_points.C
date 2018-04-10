double x[3] = {1.0, 2.0, 3.0};
double y[3] = {3.0, 2.0, 3.5};

void plot_points() {
  gStyle->SetOptStat(1111);
  gStyle->SetOptFit(1111);
  // Creates a graph with 3 points from the arrays X and Y
  TGraph *gr = new TGraph(3, x, y);
  // Fit the graph with a polyinomial of order 2
  // I.E. y = p0 * x^2 + p1 * x + p2
  gr->Fit("pol2");
  // Draws all the points with a * marker
  gr->Draw("A*");
}
