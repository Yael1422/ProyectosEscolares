def ordenaciónPorSelecciónporvalor(valor,peso,Beneficio,n):
    for i in range(0,n):
        may=i
        cuenta=i+1
        for j in range(cuenta,n):
            if valor[j]>valor[may]:
                may=j
        Intercambia(valor,i,may)
        Intercambia(Beneficio,i,may)
        Intercambia(peso,i,may)

def ordenaciónPorSelecciónporpeso(valor,peso,Beneficio,n):
    for i in range(0,n):
        may=i
        cuenta=i+1
        for j in range(cuenta,n):
            if peso[j]<peso[may]:
                may=j
        Intercambia(valor,i,may)
        Intercambia(Beneficio,i,may)
        Intercambia(peso,i,may)

def ordenaciónPorSelecciónporbeneficio(valor,peso,Beneficio,n):
    for i in range(0,n):
        may=i
        cuenta=i+1
        for j in range(cuenta,n):
            if Beneficio[j]>Beneficio[may]:
                may=j
        Intercambia(valor,i,may)
        Intercambia(Beneficio,i,may)
        Intercambia(peso,i,may)

def Intercambia(A,i,may):
    a=A[i]
    A[i]=A[may]
    A[may]=a
    
def mochila(peso,capacidad,n):
    sol=[]
    for i in range(n):
        sol.append(0.0)
    resto=capacidad
    k=0
    while (k<n and peso[k]<=resto):
        sol[k]=1
        resto=resto-peso[k]
        k=k+1
    if (resto>0):
        sol[k]=sol[k]+resto/peso[k]
        resto=resto-(peso[k])*(sol[k])
    print("Sol: {}".format(sol))
    print("Peso: {}".format(peso))
    print("Resto: {}".format(resto))
    print("Capacidad: {}".format(capacidad))
    return sol
def main():
    valor=[]
    valortotal=0
    Beneficio=[]
    peso=[]
    capacidad=int(input("Indique la capacidad de la mochila: "))
    n=int(input("Ingrese la cantidad de objetos que desea: "))
    for k in range (1,n+1):
        valor.append(0)
        peso.append(0)
        Beneficio.append(0)
    for i in range (0,n):    
        valor[i]=int(input("Ingrese el precio del objeto {} de la lista: ".format(i+1)))
        peso[i]=int(input("Ingrese el peso del objeto {} de la lista: ".format(i+1)))
        Beneficio[i]=valor[i]/peso[i]
        
    print("Como fueron ingresados")
    print("Valores: {}".format(valor))
    print("Pesos: {}".format(peso))
    print("Beneficio: {}".format(Beneficio))
    
    print("Ordenación por mayor valor")
    ordenaciónPorSelecciónporvalor(valor,peso,Beneficio,n)
    print("Valores: {}".format(valor))
    print("Pesos: {}".format(peso))
    print("Beneficio: {}".format(Beneficio))
    sol=mochila(peso,capacidad,n)
    valortotal=0
    for i in range(0,n):
        valortotal=valortotal+(valor[i])*(sol[i])
    print("Valor total: {}".format(valortotal))
    print("Ordenación por menor peso")
    
    ordenaciónPorSelecciónporpeso(valor,peso,Beneficio,n)
    print("Pesos: {}".format(peso))
    print("Valores: {}".format(valor))
    print("Beneficio: {}".format(Beneficio))
    sol=mochila(peso,capacidad,n)
    valortotal=0
    for i in range(0,n):
        valortotal=valortotal+(valor[i])*(sol[i])
    print("Valor total: {}".format(valortotal))
    
    print("Ordenación por mayor beneficio")
    ordenaciónPorSelecciónporbeneficio(valor,peso,Beneficio,n)
    print("Beneficio: {}".format(Beneficio))
    print("Valores: {}".format(valor))
    print("Pesos: {}".format(peso))
    sol=mochila(peso,capacidad,n)
    valortotal=0
    for i in range(0,n):
        valortotal=valortotal+(valor[i])*(sol[i])
    print("Valor total: {}".format(valortotal))
main() 