import math
def ClosestPair(P,n):
    d=1000
    for i in range (0,n):
      for j in range (i+1,n):
          d=min(d,math.sqrt(((P[j][0]-P[i][0])**2)+((P[j][1]-P[i][1])**2)))
    return d
def CrearLista(n):
    P=[]
    for i in range(1,n+1):
         p=[0,0]
         P.append(p)
    return P

def LlenarLista(P,n):
    for i in range(0,n):
        for j in range (0,2):
             P[i][j]= int(input("Ingrese la coordenada {} del punto {}:".format(j+1,i+1)))
def main():
    n=1
    while(n<2):
        n= int(input("Ingrese la cantidad de puntos a ingresar que sea mayor o igual a 2: "))
        if (n<2):
            print("Dato erróneo")
    P=CrearLista(n)
    LlenarLista(P,n)
    print("Los puntos ingresados son: {}".format(P))
    d=ClosestPair(P,n)
    print("La distancia entre los puntos mas cercanos es: {}".format(d))
main()