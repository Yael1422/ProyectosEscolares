#!/usr/bin/env python
# coding: utf-8

# In[23]:


def busqueda(P,T,n,m):
    for i in range(n):
        j=0
        while j<m and P[j]==T[i+j]:
            j=j+1
        if j==m:
            return i
            print(i)
    return -1

def main():
    Texto="Hola a todos sobre"
    Patron="sobre"
    n=len(Texto)
    m=len(Patron)
    print("El tamaño de la primera cadena es: {}".format(n))
    print("El tamaño de la segunda cadena es: {}".format(m))
    resul=busqueda(Patron,Texto,n,m)
    print("El indice de la subcadena es: {}".format(resul))
    
    
main()


# In[ ]:




