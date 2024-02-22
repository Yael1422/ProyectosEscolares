#include<stdio.h>
#define p printf
#define s scanf

/*Programa que realiza la suma de 4 matrices de 5x4
utilizando un arreglo de 3 dimensiones*/

int main()
{
	float m[5][5][4];
	int i,j,k;
	for(i=0;i<4;i++)
	{
		for(j=0;j<5;j++)
		{
			for(k=0;k<4;k++)
			{
				p("Introduce elemento %d,%d de matriz %d\n",j,k,i);
				s("%f",&m[i][j][k]);
			}
		}
	}
	for(j=0;j<5;j++)
	{
		for(k=0;k<4;k++)
		{
			m[4][j][k]=m[0][j][k]+m[1][j][k]+m[2][j][k]+m[3][j][k];
		}
	}
	for(j=0;j<5;j++)
	{
		for(k=0;k<4;k++)
		{
			p("%f\t",m[4][j][k]);
		}
		p("\n");
	}
}
