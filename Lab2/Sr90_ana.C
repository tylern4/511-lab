double poison(double *x, double *par) { return par[0] * TMath::Poisson(x[0], par[1]); }

void Sr90_ana() {
  gStyle->SetOptStat(111);
  gStyle->SetOptFit(111);

  // Input filename
  const char *fin = "5ms_1000s.root";
  TChain *chain = new TChain("Sr90");
  chain->Add(fin);
  // This creates a Poisson fitting function from the function created above
  TF1 *pois = new TF1("pois", poison, 0, 10, 2);

  // Get values from the file
  int _x1;
  chain->SetBranchAddress("x1", &_x1);

  int num_of_events = (int)chain->GetEntries();
  for (int current_event = 0; current_event < num_of_events; current_event++) {
    // Get current event and print out the event rate
    chain->GetEntry(current_event);
    std::cout << "Count rate for event\t" << current_event << ":\t" << _x1 << std::endl;
  }

  chain->Reset();
}
