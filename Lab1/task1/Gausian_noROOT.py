#!/usr/bin/env python
import numpy as np
import matplotlib.pyplot as plt
from scipy import stats


# Varibles for the gaussian
num = 100000
mean = 5.0
sigma = 1.0

# Throw a normal(gaussian) distobution using numpy
thrown = np.random.normal(loc=mean, scale=sigma, size=num)
# Plot the randome data
plt.hist(thrown, bins=100, density=True)

# Fit a normal distribution to the data using scipy stats
mu, std = stats.norm.fit(thrown)

# Plot the fit
# Get the min and max from the histogram
xmin, xmax = plt.xlim()
# Make a set of xs to plot the distrobution
x = np.linspace(xmin, xmax, 100)
# Get the y values in the x raneg
y = stats.norm.pdf(x, mu, std)
# Plot the line and set the legend and show the plots
plt.plot(x, y, linewidth=2,
         label="Fit results:\n$\mu$ = %.2f\n$\sigma$ = %.2f" % (mu, std))
plt.legend()
plt.show()
