/*Programa que realiza la multiplicacion de dos matrices de nxm y 
mxh dando como resultado una matriz unidimensional de nxh.*/
#include<stdio.h>
#define p printf
#define s scanf

int main()
{
	int m1[2][3],m2[3][2],m3[4];
	int i,j;
	
	p("Dame los primeros 6 numeros de la matriz 1, separados por un enter o espacio\n");
	for(i=0;i<2;i++)
	{
		for(j=0;j<3;j++)
		{
			s("%d",&m1[i][j]);
		}
	}
	p("Dame los siguientes 6 numeros de la matriz 2, separados por un enter o espacio\n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<2;j++)
		{
			s("%d",&m2[i][j]);
		}
	}
	p("Matriz 1\n");
	for(i=0;i<2;i++)
	{
		for(j=0;j<3;j++)
		{
			p("%d\t",m1[i][j]);
		}
		p("\n");
	}
	p("Matriz 2\n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<2;j++)
		{
			p("%d\t",m2[i][j]);
		}
		p("\n");
	}
	
	for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
		{
			m3[3*i+j]=m3[2*i+j]+m1[i][j]+m2[i][j];
		}
	}
	
	p("El resultado de la suma es:\n");
	for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
		{
			p("%d\t",m3[3*i+j]);
		}
		p("\n");
	}
}
