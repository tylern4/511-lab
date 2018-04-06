# Lab 2

In this lab we will use data collected from the Sr90 source used in the previous lab. The number of β− decay reactions, x, occurring from our Sr90 sample within a given time interval ∆t, was collected for different lengths of time T.

If we look at the Poisson distribution:

![Poisson]\(&lt;<https://latex.codecogs.com/png.latex?\large&space;P(x;r\Delta&space;t)&space;=&space;\frac{(r\Delta&space;t)&space;^&space;x}{x!}&space;e^{-r\Delta&space;t}&space;=&space;\frac{\mu^&space;x}{x!}&space;e^{-\mu}>)

We can see that the rate can be found if we fit a Poison to out histogram and use the known value of ∆t to get the value of r from μ.

## Task for today

-   [ ] [Download Sr90 root Data](http://boson.physics.sc.edu/~gothe/511-S16/rootlab/PHYS511L-S16/Sr90-data.html)
    -   The data is labeled by the ∆t and T of the data: ∆t-T.root
-   [ ] Plot data in histogram.
-   [ ] Fit Poisson function to the data.
-   [ ] Extract the detected event rate r.
-   [ ] Plot r versus ∆t from the different runs to determine whether the rate is constant.
-   [ ] Determine whether or not you can calculate the activity a for this sample of Sr-90 from r. Are they the same? How is a related to r?
-   [ ] Investigate for which ∆t and T a Gaussian would work well for fitting the data and extracting the mean m and hence r. Use the χ2 statistic to justify your claims.
