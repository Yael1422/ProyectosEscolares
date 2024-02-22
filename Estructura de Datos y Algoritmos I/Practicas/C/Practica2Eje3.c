#include<stdio.h>
#define n 5
#define p printf
#define s scanf

/*agregar aquí los prototipos de las funciones*/
void llena(int *v);
void suma(int *v1, int *v2, int *v3);
void imprime(int *v);

int main()
{
	int A[n] ,B[n] ,C[n],*a,*b,*c;
	a=&A[0];
	llena(a);
 	b=&B[0]; // asignar valor correspondiente a b
 	llena(b);
	c=&C[0]; // asignar valor correspondiente a b
	suma(a,b,c); 
	p("\nPrimer vector\n");
 	imprime(a);
 	p("Segundo vector\n");
 	imprime(b);
 	p("Vector resultante\n");
 	imprime(c);
}

/* Agregar definición de las funciones/*
OJO: aquí solo deben definirse 3 funciones llena() , imprime() y suma()*/
void llena(int *v)
{
	int i;
	for(i=0;i<n;i++)
	{
		p("Introduce el %d dato\n",i+1);
		s("%d",(v+i));
	}
}

void suma(int *v1, int *v2, int *v3)
{
	int i;
	for(i=0;i<n;i++)
	{
		*(v3+i)=*(v1+i)+*(v2+i);
	}
}

void imprime(int *v)
{
	int i=0;
	for(i=0;i<n;i++)
	{
		p("%d	",*(v+i));
	}
	p("\n");
}
