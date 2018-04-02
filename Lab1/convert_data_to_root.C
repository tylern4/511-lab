void convert_data_to_root() {
  // Name the tree to fill
  TTree *tree = new TTree("data", "data");
  // Tell how many columns there are and what you want them to be named and the input file
  tree->ReadFile("example.csv", "x:y:z", ',');
  // Save to a root file
  tree->SaveAs("data.root");
}

void read_data() {
  // Load the file
  TChain chain("data");
  chain.Add("data.root");

  // Setup variables
  float x = 0.0;
  float y = 0.0;
  float z = 0.0;

  chain.SetBranchAddress("x", &x);
  chain.SetBranchAddress("y", &y);
  chain.SetBranchAddress("z", &z);

  int n = (int)chain.GetEntries();
  // Loop over the events in the file and print out the variables
  for (int i = 0; i < n; i++) {
    chain.GetEntry(i);
    std::cout << x << ",";
    std::cout << y << ",";
    std::cout << z << std::endl;
  }
}
