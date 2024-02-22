# -*- coding: utf-8 -*-
"""
Editor de Spyder

Este es un archivo temporal.
"""

#Ejercicio1
def Factorial(numero):
    
    if numero==0 or numero==1:
        return 1
    else:
        return numero*Factorial(numero-1)
    



#Ejercicio2
def Fibonacci(indice):
    
    if indice==0:
        return indice
    elif indice==1:
        return 1
    elif indice>1:
        return Fibonacci(indice-1)+Fibonacci(indice-2)
    
 
def Potencias(num,potencia):
    
    if potencia==0:
        return 1
    
    elif potencia>0 and potencia%2==0:
        tmp=Potencias(num,potencia/2)
        return tmp*tmp
    
    elif potencia>0 and potencia%2!=0:
        return num*Potencias(num,potencia-1) 

    
    
#Ejercicio3
def main():
    while True:
        
        print("¿Que quieres realizar?:\n1)Factorial\n2)Fibonacci\n3)Exponenciación Entera\n4)Salir")
        opcion=int(input())
    
        if opcion==1:
        
            print("Introduce el numero al que quieres obtener su factorial")
            numero=int(input())
            resultado=Factorial(numero)
            print("El resultado es: {}".format(resultado))
    
    
        elif opcion==2:
            print("Introduce el indice que quieres conocer de la serie de Fibonacci")
            indice=int(input())
            resultado=Fibonacci(indice)
            print("El resultado es: {}".format(resultado))
    
    
        elif opcion==3:
            print("Introduce el numero a calcular su potencia")
            num=int(input())
            print("Introduce la potencia del numero a calcular")
            potencia=int(input())
            resultado=Potencias(num,potencia)
            print("El resultado es: {}".format(resultado))
    
    
        elif opcion==4:
            break
main()