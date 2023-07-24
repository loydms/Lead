#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Feb 22 10:03:38 2022

@author: ixl
"""

import numpy as np
import matplotlib.pyplot as plt
import glob

single_list = glob.glob('/Users/ixl/Desktop/Cones/Single/*')
many_list = glob.glob('/Users/ixl/Desktop/Cones/Many/*')

singles = []
labels = []
many = []
for sin in single_list:
    if 'xy' in sin:
        singles.append(np.loadtxt(sin,delimiter=' ',usecols=(0,1)))
        labels.append(int(sin.split('/')[6].strip('mm_xy.txt')))
'''
for man in many_list:
    many.append(np.loadtxt(man,delimiter=' '))
'''
plt.figure()
for i in range(len(singles)):
    plt.hist(singles[i][:,0],label=labels[i],histtype='barstacked',bins=50)
plt.legend()
'''
plt.plot(singles[0][:,0])
plt.plot(many[0][:,1])
'''
plt.show()