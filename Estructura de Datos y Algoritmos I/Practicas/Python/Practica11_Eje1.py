def cambio(denMonedas,numMon,importe):
    solCambio=[]
    for i in range (0,len(denMonedas)):
        solCambio.append(0)   
    while (importe>0 and numMon[i]>0):
        if (denMonedas[i]<=importe and numMon[i]>0):
            numMon[i]=numMon[i]-1
            solCambio[i]=solCambio[i]+1
            importe=importe-denMonedas[i]
        else:
            i=i-1
    if importe>0:
        print("No se puede dar el cambio correcto")
    else:
        return solCambio
    
def main():
    numMon=[]
    denMonedas=[]
    n=int(input("Indique la cantidad de tipos de monedas que hay: "))
    for i in range (0,n):
        numMon.append(0)
        denMonedas.append(0)
    for i in range (0,n):    
        denMonedas[i]=int(input("Indique el valor de la moneda {} : ".format(i+1)))
        numMon[i]=int(input("Indique la cantidad de monedas de {} pesos en la maquina: ".format(denMonedas[i])))
    importe=int(input("Indique el cambio: "))
    solucion=cambio(denMonedas,numMon,importe)
    print("Monedas: {}".format(denMonedas))
    print("Cambio:  {}".format(solucion))
main()

