def ordenaciónPorSelección(valor,PesoO,n):
    for i in range(0,n):
        may=i
        cuenta=i+1
        for j in range(cuenta,n+1):
            if valor[j]>valor[may]:
                may=j
        Intercambia(valor,i,may)
        #Intercambia(BeneficioO,i,may)
        Intercambia(PesoO,i,may)
def Intercambia(A,i,may):
    a=A[i]
    A[i]=A[may]
    A[may]=A[a]
    
def mochila(peso,capacidad):
    sol=[]
    for i in range(3):
        sol.append(0.0)
    resto=capacidad
    k=0
    while (k<n and peso[k]<=resto):
        sol[k]=1
        resto=resto-peso[k]
        k=k+1
        
def main():
    valor=[]
    BeneficioO=[]
    pesoO=[]
    n=int(input("Ingrese la cantidad de objetos que desea: "))
    for k in range (1,n+1):
        valor.append(0)
        pesoO.append(0)
        BeneficioO.append(0)
    for i in range (0,n):    
        valor[i]=int(input("Ingrese el precio del objeto {} de la lista: ".format(i+1)))
        pesoO[i]=int(input("Ingrese el peso del objeto {} de la lista: ".format(i+1)))
    print(valor)
    ordenaciónPorSelección(valor,pesoO,n)
    print(pesoO)
main() 