#include<stdio.h>
#define p printf
#define n 5
#define m 3
#define x 8

main()
{
	int matriz[n][m],i,j,cont=0,suma[n*m]={0};
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			matriz[i][j]=rand()%10;
		}
	}
	
	p("\nLa matriz generada es la siguiente:\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			p("%d	",matriz[i][j]);
		}
		p("\n");
	}
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(matriz[i][j]==x)
			{
				cont=cont+1;
			}
		}
	}
	p("\nEl numero %d aparece %d en la matriz\n\n",x,cont);
	
	for(j=0;j<m;j++)
	{
		for(i=0;i<n;i++)
		{
			
			suma[j]=matriz[i][j]+suma[j];
		}
	}
	
	for(j=0;j<m;j++)
	{
			
		p("La suma de la columna %d es: %d\n",j,suma[j]);
	}
}
