#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Fri Jul 28 08:44:24 2023

@author: ixl
"""

import numpy as np
import matplotlib.pyplot as plt


class Data():
    def __init__(self,fn):
        raw = np.genfromtxt(fn,dtype=str,delimiter=' ')
        g1_index = np.where(raw[:,0] == '1')[0][0]
        g2_index = np.where(raw[:,0] == '2')[0][0]
        self.n_num = g1_index
        self.g1_num = g2_index-g1_index
        self.g2_num = len(raw) - g2_index
        print(g1_index)
        print(g2_index)
        self.n_beam = raw[:g1_index,1].astype(float)
        self.g1_beam = raw[g1_index:g2_index,1].astype(float)
        self.g2_beam = raw[g2_index:,1].astype(float)
        self.n_mid = raw[:g1_index,2].astype(float)
        self.g1_mid = raw[g1_index:g2_index,2].astype(float)
        self.g2_mid = raw[g2_index:,2].astype(float)
        self.n_face = raw[:g1_index,3].astype(float)
        self.g1_face = raw[g1_index:g2_index,3].astype(float)
        self.g2_face = raw[g2_index:,3].astype(float)
#%%

fn = 'results/PWO_250_500_100keach.txt'

d = Data(fn)
#%%
n = []
g1 = []
g2 = []
plt.figure()
plt.hist(d.n_beam,bins=20,label='beam',histtype='step')
plt.hist(d.n_mid,bins=20,label='middle',histtype='step')
plt.hist(d.n_face,bins=20,label='face',histtype='step')
plt.legend()

plt.figure()
plt.hist(d.g1_beam,bins=20,label='beam',histtype='step')
plt.hist(d.g1_mid,bins=20,label='middle',histtype='step')
plt.hist(d.g1_face,bins=20,label='face',histtype='step')
plt.legend()


plt.figure()
plt.hist(d.g2_beam,bins=20,label='beam',histtype='step')
plt.hist(d.g2_mid,bins=20,label='middle',histtype='step')
plt.hist(d.g2_face,bins=20,label='face',histtype='step')
plt.legend()




