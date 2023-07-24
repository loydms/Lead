#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Thu Feb 10 15:31:37 2022

@author: ixl
"""

import numpy as np
import matplotlib.pyplot as plt

a = np.loadtxt('/Users/ixl/Desktop/Cones/Single/5mm_xy.txt',delimiter=' ')
x = a[:,0]
y = a[:,1]
pixels = a[:,2]
length = 15.7
x += length / 2
y += length / 2
area = 24
data = np.zeros([area, area])

for i in range(len(x)):
    bin_x = int(x[i] // (length / area))
    bin_y = int(y[i] // (length / area))
    data[bin_x,bin_y] += 1
bins = np.zeros([area,area])
for val in pixels:
    x_ind = int(val % area)
    y_ind = int(val // area)
    bins [x_ind,y_ind] += 1
x_ind += length
y_ind += length
#plt.imshow(data)
plt.plot(np.sum(data,axis=0),label='x sum from float coordinates binned')
#plt.plot(np.sum(data,axis=1),label='y sum')
plt.plot(np.sum(bins,axis=0),label='x sum from pixels')
plt.title('Diff width = 0.3 cm')
plt.legend()
plt.figure()
plt.plot(np.sum(data,axis=1),label='y sum from float coordinates binned')
plt.title('Diff width = 0.3 cm')
plt.plot(np.sum(bins,axis=1),label='y sum from pixels')
plt.legend()
plt.show()
