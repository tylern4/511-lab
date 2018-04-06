double poison(double *x, double *par) { return par[0] * TMath::Poisson(x[0], par[1]); }

void Sr90_ana() {
  const char *fin = "5ms_1000s.root";
  TChain *chain = new TChain("Sr90");
  chain->Add(fin);
  TF1 *pois = new TF1("pois", poison, 0, 10, 2);

  gStyle->SetOptStat(111);
  gStyle->SetOptFit(111);

  int _x1;
  chain->SetBranchAddress("x1", &_x1);

  int num_of_events = (int)chain->GetEntries();
  for (int current_event = 0; current_event < num_of_events; current_event++) {
    chain->GetEntry(current_event);
    std::cout << "Count rate for event\t" << current_event << ":\t" << _x1 << std::endl;
  }

  chain->Reset();
}
