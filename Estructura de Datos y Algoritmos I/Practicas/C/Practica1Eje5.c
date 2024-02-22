#include<stdio.h>
#define p printf
#define s scanf
#define m 3
#define n 3

main()
{
	int matriz[4][m][n],i,j,k;
	int resultado[n][m];
	
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			matriz[1][i][j]=rand()%20;
			matriz[2][i][j]=rand()%8;
		}
	}
	
	p("La matriz 1 es:\n");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			p("%d	",matriz[1][i][j]);
		}
		p("\n");
	}
	
	p("\nLa matriz 2 es:\n");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			p("%d	",matriz[2][i][j]);
		}
		p("\n");
	}
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			matriz[3][i][j]=0;
		}
	}
	
	p("\nEl resultado de la multiplicacion de ambas matrices es:\n");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			for(k=0;k<m;k++)
			{
				matriz[3][i][j]=matriz[3][i][j]+matriz[1][i][k]*matriz[2][k][j];
			}
			p("%d	",matriz[3][i][j]);
		}
		p("\n");
	}
	
	
}
