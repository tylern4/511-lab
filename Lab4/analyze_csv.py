#!/usr/bin/env python
from ROOT import TH2D, TH1D, TVector3, TLorentzVector, TFile
import numpy as np
import pandas as pd

# A basic analysis program looking at
# a electron beam on a proton target

# Follow the TODO portions to get the analysis working properly

# TODO: Create a 4 vector for the Electron beam.
#       Setup beam 4 vector
# e_mu = TLorentzVector(???)
#      Create a 4 vector for the Proton target.
# p_mu = TLorentzVector(???)

# TODO: Write a function to calculate Missing Mass


def analyze():
    BEAM = 4.81726  # Beam energy in GeV
    MASS_P = 0.93827203  # Mass in GeV
    MASS_E = 0.000511  # Mass in GeV
    MASS_PIP = 0.13957018  # Mass in GeV
    fin = "511_lab_E_PIP_data.csv.gz"
    fout = "MissingMass.root"

    # TODO: Create the histograms you want to fill

    # Load chain from branch lab
    OutputFile = TFile(fout, "RECREATE")

    #Create 4 vectors for the scattered electron
    e_mu_prime_3 = TVector3()
    e_mu_prime = TLorentzVector()

    # TODO: Create 4 vectors for the scattered pion

    data = pd.read_csv(fin, sep=',')

    data['e_px'] = data['e_p'] * data['e_cx']
    data['e_py'] = data['e_p'] * data['e_cy']
    data['e_pz'] = data['e_p'] * data['e_cz']

    for event in data.itertuples():
        e_mu_prime_3.SetXYZ(event.e_px, event.e_py, event.e_pz)
        e_mu_prime.SetVectM(e_mu_prime_3, MASS_E)
        # print(e_mu_prime.E())

        #TODO: Calculate missing mass using the functions you created above
        # and fill the histogram.

    #end stuff
    OutputFile.cd()
    # TODO:
    # Fit the missing mass peak.
    # Hint: Get everything else working first.
    # Then try some of the fits we used in previous labs.
    #TODO: Write the histograms into the file
    #hist.Write()
    OutputFile.Close()


if __name__ == "__main__":
    analyze()
