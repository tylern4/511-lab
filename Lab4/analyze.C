// A basic analysis program looking at
// a electron beam on a proton target
//
// Follow the TODO portions to get the analysis working properly
//

#define Square(x) ((x) * (x))

static const double BEAM = 4.81726;       // Beam energy in GeV
static const double MASS_P = 0.93827203;  // Mass in GeV
static const double MASS_E = 0.000511;    // Mass in GeV

/****
TODO: Create a 4 vector for the Electron beam.
TLorentzVector e_mu(???);

TODO: Create a 4 vector for the Proton target.
TLorentzVector p_mu(???);
****/

/****
TODO: Write functions to calculate W and Q^2

// Calcuating Q^2
// q^mu^2 = (e^mu - e^mu')^2 = -Q^2


//	Calcualting W
//  gamma = e^mu - e^mu'
//  P is proton target at rest
//	Gotten from s channel [(gamma - P)^2 == s == w^2]

****/

void analyze() {
  const char *fin = "511_lab_E_data_small.root";
  const char *fout = "WvsQ2.root";
  /****
  TODO:
  Create the histograms you want to fill
  ****/

  // Load chain from branch lab
  TFile *OutputFile = new TFile(fout, "RECREATE");
  TChain chain("lab");
  chain.Add(fin);
  double e_p, e_cx, e_cy, e_cz;
  chain.SetBranchAddress("p", &e_p);
  chain.SetBranchAddress("cx", &e_cx);
  chain.SetBranchAddress("cy", &e_cy);
  chain.SetBranchAddress("cz", &e_cz);

  // Create 4 vectors for the scattered electron
  TVector3 e_mu_prime_3;
  TLorentzVector e_mu_prime;

  int num_of_events = (int)chain.GetEntries();
  for (int current_event = 0; current_event < num_of_events; current_event++) {
    chain.GetEntry(current_event);

    // We setup the scattered electron by first setting the momentum 3 vector
    e_mu_prime_3.SetXYZ(e_p * e_cx, e_p * e_cy, e_p * e_cz);
    /*
      And then adding a mass to the 3 vector
      ROOT will calculate the proper energy for
      the 4 vector for us this way.
      Check out (https://root.cern.ch/doc/master/classTLorentzVector.html)
      for reference
    */
    e_mu_prime.SetVectM(e_mu_prime_3, MASS_E);
    // std::cout << e_mu_prime.E() << std::endl;
    /****
    TODO:
    Calculate W and Q^2 using the functions you created above
    and fill the histograms.
    ****/
  }
  //
  // end stuff
  chain.Reset();
  OutputFile->cd();
  /****
  TODO:
  Write the histograms into the file
  hist->Write();
  ****/
  OutputFile->Close();
}
