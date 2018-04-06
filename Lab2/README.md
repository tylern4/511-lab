# Lab 2

In this lab we will use data collected from the Sr90 source used in the previous lab. The number of β− decay reactions, x, occurring from our Sr90 sample within a given time interval ∆t, was collected for different time intervals T. If we look at the Poisson distribution:

* * *

![Poisson](https://latex.codecogs.com/png.latex?\large&space;P(x;r\Delta&space;t)&space;=&space;\frac{(r\Delta&space;t)&space;^&space;x}{x!}&space;e^{-r\Delta&space;t})

* * *

r is the detected-reaction rate and the mean number of events measured within the time interval is given by r∆t = m.

## Task for today

-   [ ] [Download Sr90 root Data](http://boson.physics.sc.edu/~gothe/511-S16/rootlab/PHYS511L-S16/Sr90-data.html)
-   [ ] Plot data in histogram.
-   [ ] Fit Poisson function to the data.
-   [ ] Extract the detected event rate r.
-   [ ] Plot r versus ∆t and determine whether the rate seems constant.
-   [ ] Determine whether or not you can calculate the activity a for this sample of Sr-90 from r. Are they the same? How is a related to r?
-   [ ] Investigate for which ∆t and T a Gaussian would work well for fitting the data and extracting the mean m and hence r. Use the χ2 statistic to justify your claims.
