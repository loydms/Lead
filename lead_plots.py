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
        if raw[0][0] == 'Particle':
            raw = raw[1:]
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
        
    def add(self,fn):
        raw = np.genfromtxt(fn,dtype=str,delimiter=' ')
        if raw[0][0] == 'Particle':
            raw = raw[1:]
        g1_index = np.where(raw[:,0] == '1')[0][0]
        g2_index = np.where(raw[:,0] == '2')[0][0]
        self.g3_num = g2_index-g1_index
        self.g4_num = len(raw) - g2_index
        temp = raw[g1_index:g2_index,1].astype(float)
        self.g3_beam = temp[temp!= 0]
        temp = raw[g2_index:,1].astype(float)
        self.g4_beam = temp[temp!= 0]
        temp = raw[:g1_index,2].astype(float)
        self.g3_mid = temp[temp!= 0]
        temp = raw[g2_index:,2].astype(float)
        self.g4_mid = temp[temp!= 0]
        temp = raw[:g1_index,3].astype(float)
        self.g3_face = temp[temp!= 0]
        temp = raw[g2_index:,3].astype(float)
        self.g4_face = temp[temp!= 0]
        self.g3_scint = raw[g1_index:g2_index,1].astype(float) + raw[g1_index:g2_index,3].astype(float)
        self.g4_scint = raw[g2_index:,1].astype(float) + raw[g2_index:,3].astype(float)
        
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
    for i in range(5):
        f, a = plt.subplots()
        figs.append(f)
        axes.append(a)
    for i in d:
        axes[0].hist(i.n_scint,bins=50,label=i.lab,histtype='step',log=True)
        axes[1].hist(i.g4_scint,bins=50,label=i.lab,histtype='step',log=True)
        axes[2].hist(i.g2_scint,bins=50,label=i.lab,histtype='step',log=True)
        axes[3].hist(i.g1_scint,bins=50,label=i.lab,histtype='step',log=True)
        axes[4].hist(i.g3_scint,bins=50,label=i.lab,histtype='step',log=True)        
        print(f'Neutron events for {i.lab}: ',i.n_num)
        print(f'250 keV events or {i.lab}: ',i.g4_num)
        print(f'500 keV events for {i.lab}: ',i.g2_num)
        print(f'1 MeV events or {i.lab}: ',i.g1_num)
        print(f'1.25 MeV events for {i.lab}: ',i.g3_num)
    for i in axes:
        i.legend()
    axes[0].set_title('Neutrons both scint')
    axes[1].set_title('250 keV both scint')
    axes[2].set_title('500 keV both scint')
    axes[3].set_title('1 MeV 1 both scint')
    axes[4].set_title('1.25 MeV 2 both scint')
        

#%%
fn = 'results/PWO_500_1_200keach.txt'
an = 'results/PWO_250_125_200keach.txt'
fn2 = 'results/Q_500_1_200keach.txt'
an2 = 'results/Q_250_125_200keach.txt'
fn3 = 'results/None_500_1_200keach.txt'
an3 = 'results/None_250_125_200keach.txt'
fn4 = 'results/PbG_500_1_200keach.txt'
an4 = 'results/PbG_250_125_200keach.txt'

PWO = Data(fn,'PWO')
Q = Data(fn2,'Quartz')
N = Data(fn3,'No Spacer')
LG = Data(fn4,'Lead Glass')
PWO.add(an)
Q.add(an2)
N.add(an3)
LG.add(an4)



#%%

plot_all([PWO,Q,N,LG])