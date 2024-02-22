#include<stdio.h>
#define p printf
#define n 10
#define m 11
#define x 10

main()
{
	int matriz[n*m],i,j,k,arreglo[x],cont=0;
	
	for(k=0;k<=x;k++)
	{
		arreglo[k]=k;
	}
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			matriz[n*i+j]=rand()%10; //En lugar de usar arreglo bidimensional, lo almacenamos en uno dimensional//
		}
	}
	
	p("La matriz es la siguiente:\n\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			p("%d	",matriz[n*i+j]);  //De igual forma usamos arreglo bidimensional pero lo imprimimos como matriz//
		}
		p("\n");
	}
	
	p("\n");
	p("Valor(indice)		Ocurrencia\n\n");
	for(k=0;k<x;k++)
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				if(matriz[n*i+j]==k)
				{
					cont=cont+1;
				}
			}
		}
		p("	%d			%d\n\n",arreglo[k],cont);
		cont=0;
	}
	
}
