#!/usr/bin/env python
from ROOT import TH2D, TH1D, TVector3, TLorentzVector, TFile
import numpy as np

# A basic analysis program looking at
# a electron beam on a proton target

# Follow the TODO portions to get the analysis working properly

# TODO: Write functions to calculate W and Q^2
# Calcuating Q^2
# q^mu^2 = (e^mu - e^mu')^2 = -Q^2

# Calcualting W
# gamma = e^mu - e^mu'
# P is proton target at rest
# Gotten from s channel [(gamma - P)^2 == s == w^2]


def analyze():
    BEAM = 4.81726  # Beam energy in GeV
    MASS_P = 0.93827203
    MASS_E = 0.000511
    fin = "511_lab.root"
    fout = "output.root"
    # TODO: Create the histograms you want to fill

    # Load chain from branch lab
    OutputFile = TFile(fout, "RECREATE")

    #Setup beam 4 vector
    e_mu = TLorentzVector(0.0, 0.0, np.sqrt(BEAM * BEAM - MASS_E * MASS_E),
                          BEAM)

    #Create 4 vectors for the scattered electron
    e_mu_prime_3 = TVector3()
    e_mu_prime = TLorentzVector()

    f = TFile.Open(fin)
    for event in f.lab:
        # We setup the scattered electron by first setting the momentum 3 vector
        e_mu_prime_3.SetXYZ(event.p * event.cx, event.p * event.cy,
                            event.p * event.cz)

        #  And then adding a mass to the 3 vector
        #  ROOT will calculate the proper energy for
        #  the 4 vector for us this way.
        #  Check out (https://root.cern.ch/doc/master/classTLorentzVector.html)
        #  for reference

        e_mu_prime.SetVectM(e_mu_prime_3, MASS_E)
        # print(e_mu_prime.E())

        #TODO: Calculate W and Q^2 using the functions you created above and fill the histograms.

    #end stuff
    OutputFile.cd()
    #TODO: Write the histograms into the file
    OutputFile.Close()


if __name__ == "__main__":
    analyze()
