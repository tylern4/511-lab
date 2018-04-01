#!/usr/bin/env python
from ROOT import TH1D, TCanvas, TF1
from ROOT import gStyle
from numpy.random import normal

# Varibles for the gaussian
num = 100000
mean = 5.0
sigma = 1.0

# Define the histogram to fill
hist = TH1D("hist", "Gaussian", 100, 0.0, 10.0)
# Define the gui to display the graph and set the display options
c1 = TCanvas('c1', 'Python Example', 200, 10, 700, 500)
gStyle.SetOptStat(111)
gStyle.SetOptFit(111)

# Thrown a normal(gaussian) distobution using numpy
throw = normal(loc=mean, scale=sigma, size=num)
# Loop over the thrown event and fill in histogram
#for t in throw:
#    hist.Fill(t)
# Same as above but in one line
[hist.Fill(t) for t in throw]

# Enter the canvas to draw
c1.cd()
# Draw histogram in gui
hist.Draw()
# Fit gaussian to the histogram
hist.Fit("gaus")

#Do this so it leaves the graph on the screen
raw_input("Press Enter to continue...")
