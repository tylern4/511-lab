# Lab 4

We will again be looking at experimental data from the CLAS detector at JLAB. Last week we just looked at the scattered electrons, this week we will look at events with both a scattered electron and a scattered pi^+. The electron information is stored in the "e_p","e_cx","e_cy" and "e_cz" banks while the pi^+ information is stored in the "pip_p","pip_cx","pip_cy" and "pip_cz" banks.

We will attempt to calculate the missing mass from the reactions which have a scattered electron and a pi^+.

## Physics Calculations

-   [ ] Write down the electron beam 4 vector.
-   [ ] Write down the proton target 4 vector.
-   [ ] Write down the scattered electron 4 vector.
-   [ ] Write down the pi^+ 4 vector.
-   [ ] Determine how to get the invariant mass, W from your 4 vectors.
    -   Hint: s channel.
-   [ ] Determine the energy transfer, Q^2.
    -   Hint: t channel.
-   [ ] Calculate the missing mass.
    -   Hint: Remember conservation of energy

## Programming

-   [ ] Look at the C macro or python programs.
-   [ ] Create a 4 vector for the Electron beam, e_mu.
-   [ ] Create a 4 vector for the Proton target, p_mu.
-   [ ] Write a function to calculate W.
-   [ ] Write a function to calculate Q^2.
-   [ ] For each event calculate W and Q^2 and plot them in their histograms.

## Graphs

-   [ ] TH1D for W before missing mass
-   [ ] TH1D for Q^2 before missing mass
-   [ ] TH2D for W vs Q^2 before missing mass
-   [ ] TH1D for missing mass with a fit
-   [ ] TH1D for W after missing mass cut
-   [ ] TH1D for Q^2 after missing mass cut
-   [ ] TH2D for W vs Q^2 after missing mass cut
