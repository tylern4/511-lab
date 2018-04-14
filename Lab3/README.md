# Lab 3

In the final two labs we will be looking at experimental data from the CLAS detector at JLAB. The experimental we will be looking at is an electron scattering experiment with a beam energy of 4.8GeV, on a liquid hydrogen (proton) target.

The root/csv file has electron events with 4 banks, the scattered electron total momentum is stored in "p" and the cosine of the angle from the beam line is gives in the x, y, and z are given by the "cx", "cy", and "cz" banks respectively. Therefore to get the momentum of the electron in the x direction, Px  = P \* Cx.

## Physics Calculations

-   [ ] Write down the electron beam 4 vector.
-   [ ] Write down the proton target 4 vector.
-   [ ] Write down the scattered electron 4 vector.
-   [ ] Determine how to get the invariant mass, W from your 4 vectors.
    -   Hint: s channel.
-   [ ] Determine the energy transfer, Q^2.
    -   Hint: virtual photon 4 vector.

## Programming

-   [ ] Look at the C macro or python programs.
-   [ ] Create a 4 vector for the Electron beam, e_mu.
-   [ ] Create a 4 vector for the Proton target, p_mu.
-   [ ] Write a function to calculate W.
-   [ ] Write a function to calculate Q^2.
-   [ ] For each event calculate W and Q^2 and plot them in their histograms.

## Graphs

-   [ ] TH1D for W
-   [ ] TH1D for Q^2
-   [ ] TH2D for W vs Q^2
