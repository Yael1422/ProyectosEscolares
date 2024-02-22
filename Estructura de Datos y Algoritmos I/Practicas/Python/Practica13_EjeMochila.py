# -*- coding: utf-8 -*-
"""
Created on Mon May 27 17:37:43 2019

@author: gandh
"""

def creaTabla(n,W):
    V=[]
    for i in range(n+1):
        V.append([0]*(W+1))
    return V

def llenaTabla(V,n,W,v,p):
    for i in range(1,n+1):
        for j in range(1,W+1):
            if (j-p[i-1]<0):
                V[i][j]=V[i-1][j]
            else:
                V[i][j]=max(V[i-1][j],v[i-1]+V[i-1][j-p[i-1]])

def obtenerSol(V,p,W,n,x):
    j=W
    for i in range (n,0,-1):
        if V[i][j]==V[i-1][j]:
            x[i-1]=0
        else:
            x[i-1]=1
            j=j-p[i-1]

def main():
    V=creaTabla(3,6)
    
    v=[1,2,5]
    p=[2,3,4]
    n=3
    W=6
    x=[0 for i in range (n)]
    print(x)
    llenaTabla(V,3,W,v,p)
    obtenerSol(V,p,W,n,x)
    print(V)
    print(x)
    
main()