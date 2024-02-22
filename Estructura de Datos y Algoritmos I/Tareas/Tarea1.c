#include<stdio.h>
#include<stdlib.h>
#define p printf
#define s scanf

float **formaMat(int nr, int ncol);
void llena(float **ap, int nr, int nc);
void suma(float **a,float **b, float **c, int nr, int nc);
void imprime(float **c, int nr, int nc);
void libera(float **m, int nr);

main()
{
	float **a,**b,**c;
	int n=2,m=2;
	
	a=formaMat(n,m);
	b=formaMat(n,m);
	c=formaMat(n,m);
	
	p("\nPrimera matriz\n");
	llenaM(a,n,m);
	p("Segunda matriz\n");
	llenaM(b,n,m);
	
	suma(a,b,c,n,m);
	p("\n");
	p("Matriz resultante\n");
	imprime(c,n,m);
	p("\n");
	
	libera(a,n);
	libera(b,n);
	libera(c,n);
	return 0;
}

float **formaMat(int nr, int nc)
{
	float **ap;
	int i;
	
	ap=(float **)malloc(nr*sizeof(float *));
	for(i=0;i<nr;i++)
	{
		ap[i]=(float*)malloc(nc*sizeof(float));
		return ap;
	}
}

void llenaM(float **ap, int nr, int nc)
{
	int i,j;
	
	for(i=0;i<nr;i++)
	{
		for(j=0;j<nc;j++)
		{
			p("Introduce elemento [%d][%d]:	",i,j);
			s("%f",&ap[i][j]);
		}
	}
}

void suma(float **a,float **b, float **c, int nr, int nc)
{
	int i,j;
	for(i=0;i<nr;i++)
	{
		for(j=0;j<nc;j++)
		{
			*(*(c+i)+j)=*(*(a+i)+j)+*(*(b+i)+j);
		}
	}
}

void imprime(float **c, int nr, int nc)
{
	int i,j;
	for(i=0;i<nr;i++)
	{
		for(j=0;j<nc;j++)
		{
			p("%f	",c[i][j]);
		}
		p("\n");
	}
}

void libera(float **m, int nr)
{
	int i;
	for(i=0;i<nr;i++)
	{
		free(m[i]);
	}
	free(m);
}
