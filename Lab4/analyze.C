// A basic analysis program looking at
// a electron beam on a proton target
//
// Follow the TODO portions to get the analysis working properly
//

#define Square(x) ((x) * (x))

static const double BEAM = 4.81726;         // Beam energy in GeV
static const double MASS_P = 0.93827203;    // Mass in GeV
static const double MASS_E = 0.000511;      // Mass in GeV
static const double MASS_PIP = 0.13957018;  // Mass in GeV

/****
TODO:
Create a function to calculate the missing mass.
****/

void analyze() {
  const char *fin = "511_lab_E_PIP_data.root";
  const char *fout = "MissingMass.root";

  /****
  TODO:
  Create the histograms you want to fill
  ****/

  // Load chain from branch lab
  TFile *OutputFile = new TFile(fout, "RECREATE");
  TChain chain("lab");
  chain.Add(fin);
  double e_p, e_cx, e_cy, e_cz;
  chain.SetBranchAddress("e_p", &e_p);
  chain.SetBranchAddress("e_cx", &e_cx);
  chain.SetBranchAddress("e_cy", &e_cy);
  chain.SetBranchAddress("e_cz", &e_cz);

  // Create 4 vectors for the scattered electron
  TVector3 e_mu_prime_3;
  TLorentzVector e_mu_prime;

  // TODO: Create 4 vectors for the scattered pion

  int num_of_events = (int)chain.GetEntries();
  for (int current_event = 0; current_event < num_of_events; current_event++) {
    chain.GetEntry(current_event);
    // We setup the scattered electron by first setting the momentum 3 vector
    e_mu_prime_3.SetXYZ(e_p * e_cx, e_p * e_cy, e_p * e_cz);
    e_mu_prime.SetVectM(e_mu_prime_3, MASS_E);
    /****
    TODO:
    Calculate missing mass using the functions you created above
    and fill the histogram.
    ****/
  }
  //
  // end stuff
  chain.Reset();
  OutputFile->cd();
  /****
  TODO:
  Fit the missing mass peak.
  Hint: Get everything else working first.
  Then try some of the fits we used in previous labs.
  ****/
  /****
  TODO:
  Write the histograms into the file
  hist->Write();
  ****/
  OutputFile->Close();
}
