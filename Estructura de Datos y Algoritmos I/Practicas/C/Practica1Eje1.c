#include<stdio.h>
#define p printf

main()
{
	float a[15];
	int b[2][3];
	char c[2][3][4];
	int i,j,k;
	
	for(i=0;i<5;i++)
	{
		p("La direccion de inicio a[%d] es %X\n",i,&a[i]);
	}
	
	for(i=0;i<2;i++)
	{
		for(j=0;j<3;j++)
		{
			p("La direccion de b[%d][%d] es %X\n",i,j,&b[i][j]);
		}
	}
	
	for(i=0;i<2;i++)
	{
		for(j=0;j<3;j++)
		{
			for(k=0;k<4;k++)
			{
				p("La direccion de c[%d][%d][%d] es %X\n",i,j,k,&c[i][j][k]);
			}
		}
	}
}

/* 
Un int ocupa 4 bytes y 15 localidades
Un float ocupa 4 bytes y 6 localidades
Un char ocupa 1 byte y 24 localidades
*/
