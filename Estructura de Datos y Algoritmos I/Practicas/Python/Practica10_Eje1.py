import random
def busquedaLineal(A,n,x):
    encontrado=-1
    for k in range(0,n):
        if x==A[k]:
            encontrado=k
    return encontrado

def main():
    lista=[]
    cantidad=int(input("Ingrese la cantidad de elementos que desea en la lista:  "))
    for k in range (1,cantidad+1):
        lista.append(random.randint(1,10))
    print(lista)
    encontrar=int(input("Ingrese el elemento que desea encontar en la lista:  "))
    encontrado=busquedaLineal(lista,cantidad,encontrar)
    print("El elemento {} se encuentra en la posición {}".format(encontrar,encontrado+1))
main() 