#!/usr/bin/env python
import numpy as np
import matplotlib.pyplot as plt


counts = []
with open("5ms_1000s.dat") as data:
    for line in data:
        counts.append(int(line, 16))


# TODO: Plot the
