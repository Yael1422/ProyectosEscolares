# -*- coding: utf-8 -*-
"""
Created on Thu May 16 22:42:10 2019

@author: gandh
"""

#%pylab inline
##########################
### bibliotecas######
import matplotlib.pyplot as plt
import random                    #AÑADE LIBRERIAS
from time import time


 ############### Algoritmo Merge Sort####
 
def creaSubA(A,indIzq,indDer):
    return A[indIzq:(indDer+1)]

def Merge(A,p,q,r):     #Se encarga de intercalar los elementos de las listas
    izq=creaSubA(A,p,q)
    der=creaSubA(A,q+1,r)
    i=0
    j=0
    for k in range(p,r+1):
        if(j >= len(der)) or (i < len(izq) and izq[i] < der[j]):
            A[k]=izq[i]
            i=i+1
        else:       #El if y else, se encarga de dividir los elementos para la izquierda y derecha
            A[k]=der[j]
            j=j+1
            
def MergeS(A,p,r):     #Se encarga de dividir la lista
    if(p < r):
        q = int((p+r)/2)   #Divide la lista en 2
        MergeS(A,p,q)      #Lo hace de manera recursiva
        MergeS(A,q+1,r)
        Merge(A,p,q,r)
        return A

###################Algoritmo Selection Sort###################################

def intercambia(A,i,min):  #Funcion que apoya al OrdenPorSeleccion
    tmp=A[i]
    A[i]=A[min]
    A[min]=tmp
    
    
def OrdenPorSeleccion(A):  #Se encarga de ordenar la lista
    for i in range(0,len(A)):
        min=i
        for j in range(i+1,len(A)):
            if (A[j]<A[min]):
                min=j
                intercambia(A,i,min)
                
                
#Función para graficar
                
def grafica():
    TiempoS=[]
    Tiempo=[]
    
    nDatos=[k*100 for k in range(1,31)]
    
    for k in nDatos:      #Añade los datos a las graficas
        datosOr=random.sample(range(0,10000000),k)
        datosSS=datosOr
        t0=time()
        MergeS(datosOr,0,len(datosOr)-1)
        Tiempo.append(round(time()-t0,6))
        #
        t0=time()
        OrdenPorSeleccion(datosSS)
        TiempoS.append(round(time()-t0,6))
        
        
    #GRAFICA MERGE
    fig,ax=plt.subplots()
    ax.plot(nDatos,Tiempo,label="MergeS",marker="*",color="r")
    ax.set_xlabel('Datos')     #Coloca el nombre del eje X
    ax.set_ylabel('Tiempo')    #Coloca el nombre del eje y
    ax.grid(True)
    plt.title('Merge: Datos vs Tiempo');    #Coloca el Titulo de la Grafica
    plt.show()         #Muestra la grafica
    
    
    #GRAFICA ORDENACION DE MAYOR A MENOR
    fig,ax=plt.subplots()
    ax.plot(nDatos,TiempoS,label="OrdenPorSeleccion",marker="*",color="b")
    ax.set_xlabel('Datos')
    ax.set_ylabel('Tiempo')
    ax.grid(True)
    plt.title('OrdenPorSeleccion: Datos vs Tiempo');
    plt.show()
    
    
    #GRAFICAS JUNTAS
    fig,ax=plt.subplots()
    ax.plot(nDatos,Tiempo,label="MergeS",marker="*",color="r")
    ax.plot(nDatos,TiempoS,label="OrdenPorSeleccion",marker="*",color="b")
    ax.set_xlabel('Datos')
    ax.set_ylabel('Tiempo')
    ax.grid(True)
    plt.title('MergeS(Rojo) vs Ordenacion(Azul)');
    
grafica()
