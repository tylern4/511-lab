# Lab 2

In this lab we will use data collected from the Sr90 source used in the previous lab. The number of β− decay reactions, x, occurring from our Sr90 sample within a given time interval ∆t, was collected for different lengths of time T.

If we look at the Poisson distribution:

![Poisson](https://latex.codecogs.com/png.latex?\large&space;P(x;r\Delta&space;t)&space;=&space;\frac{(r\Delta&space;t)&space;^&space;x}{x!}&space;e^{-r\Delta&space;t}&space;=&space;\frac{\mu^&space;x}{x!}&space;e^{-\mu})

We can find the rate, r, if we fit a Poisson to the histograms to get a μ value and by knowing the value of ∆t.

## Task for today

-   [ ] Update your working copy of the repository

    git merge origin/master

-   [ ] [Download Sr90 root Data](http://boson.physics.sc.edu/~gothe/511-S16/rootlab/PHYS511L-S16/Sr90-data.html)
    -   The data is labeled by the ∆t and T of the data: ∆t-T.root
-   [ ] Plot all the data into histogram.
    -   Look at Sr90_ana.C for a starting point.
-   [ ] Fit Poisson function to the histograms.
-   [ ] Extract the value μ.
-   [ ] Plot μ versus ∆t from the different runs to determine whether the rate is constant.
    -   Look at plot_points.C for a starting point.
-   [ ] Calculate the detected event rate, r.

### Extra Questions

-   [ ] Determine whether or not you can calculate the activity a for this sample of Sr90 from r. Are they the same? How is a related to r?
-   [ ] Investigate for which ∆t and T a Gaussian would work well for fitting the data and extracting the mean m and hence r. Use the χ2 statistic to justify your claims.

## Helpful Documentation

[Fitting in ROOT](https://root.cern.ch/root/html534/guides/users-guide/FittingHistograms.html)
[TF1](https://root.cern.ch/doc/v612/classTF1.html)
[TGraph](https://root.cern.ch/doc/master/classTGraph.html)
