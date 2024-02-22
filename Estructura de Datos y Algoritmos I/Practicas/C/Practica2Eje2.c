#include<stdio.h>
#define p printf

void intercambio(int *a, int*b);

main()
{
	int a=5,b=7;
	p("a=%d	 y	 b=%d",a,b);
	intercambio(&a,&b);
	p("\na=%d	 y	 b=%d",a,b);
}

void intercambio(int *a, int*b)
{
	int c;
	c=*a;
	*a=*b;
	*b=c;
}
