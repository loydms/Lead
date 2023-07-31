#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Fri Jul 28 08:44:24 2023

@author: ixl
"""

import numpy as np
import matplotlib.pyplot as plt


class Data():
    def __init__(self,fn,lab = ''):
        self.lab = lab
        raw = np.genfromtxt(fn,dtype=str,delimiter=' ')
        g1_index = np.where(raw[:,0] == '1')[0][0]
        g2_index = np.where(raw[:,0] == '2')[0][0]
        self.n_num = g1_index
        self.g1_num = g2_index-g1_index
        self.g2_num = len(raw) - g2_index
        temp = raw[:g1_index,1].astype(float)
        self.n_beam = temp[temp!= 0]
        temp = raw[g1_index:g2_index,1].astype(float)
        self.g1_beam = temp[temp!= 0]
        temp = raw[g2_index:,1].astype(float)
        self.g2_beam = temp[temp!= 0]
        temp = raw[:g1_index,2].astype(float)
        self.n_mid = temp[temp!= 0]
        temp = raw[g1_index:g2_index,2].astype(float)
        self.g1_mid = temp[temp!= 0]
        temp = raw[g2_index:,2].astype(float)
        self.g2_mid = temp[temp!= 0]
        temp = raw[:g1_index,3].astype(float)
        self.n_face = temp[temp!= 0]
        temp = raw[g1_index:g2_index,3].astype(float)
        self.g1_face = temp[temp!= 0]
        temp = raw[g2_index:,3].astype(float)
        self.g2_face = temp[temp!= 0]
        self.n_scint = raw[:g1_index,1].astype(float) + raw[:g1_index,3].astype(float)
        self.g1_scint = raw[g1_index:g2_index,1].astype(float) + raw[g1_index:g2_index,3].astype(float)
        self.g2_scint = raw[g2_index:,1].astype(float) + raw[g2_index:,3].astype(float)
        
#%%

def plot(d):
    plt.figure()
    plt.hist(d.n_beam,bins=20,label='beam',histtype='step',range=(0.001,10))
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
    print('Neutron events: ',d.n_num)
    print('Gamma 1 events: ',d.g1_num)
    print('Gamma 2 events: ',d.g2_num)

def plot_all(d):
    figs = []
    axes = []
    for i in range(3):
        f, a = plt.subplots()
        figs.append(f)
        axes.append(a)
    for i in d:
        axes[0].hist(i.n_scint,bins=20,label=i.lab,histtype='step')
        axes[1].hist(i.g1_scint,bins=20,label=i.lab,histtype='step')
        axes[2].hist(i.g2_scint,bins=20,label=i.lab,histtype='step')
    for i in axes:
        i.legend()
    axes[0].set_title('Neutrons both scint')
    axes[1].set_title('Gamma 1 both scint')
    axes[2].set_title('Gamma 2 both scint')
        

#%%
fn = 'results/PWO_250_500_100keach.txt'
fn2 = 'results/Q_250_500_100keach.txt'
fn3 = 'results/None_250_500_100keach.txt'
fn4 = 'results/PbG_250_500_100keach.txt'
PWO = Data(fn,'PWO')
Q = Data(fn2,'Quartz')
N = Data(fn3,'No Spacer')
LG = Data(fn4,'Lead Glass')

with open(fn,) as f:
    i = 0
    for line in f:
        line = line.split(' ')
        if float(line[1]) + float(line[2]) > 5:
            print(line)
            print(i)
        i += 1

#%%

plot_all([PWO,Q,N,LG])