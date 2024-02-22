import random
def ordenaciónPorSelección(A,n):
    for i in range(0,n):
        mi=i
        for j in range(i+1,n):
            if A[j]<A[mi]:
                mi=j
        Intercambia(A,i,mi)
def Intercambia(A,i,mi):
    a=A[i]
    A[i]=A[mi]
    A[mi]=a
def main():
    lista=[]
    n=int(input("Ingrese la cantidad de elementos que desea en la lista:  "))
    for k in range (1,n+1):
        lista.append(random.randint(1,10))
    print(lista)
    ordenaciónPorSelección(lista,n)
    print(lista)
main() 