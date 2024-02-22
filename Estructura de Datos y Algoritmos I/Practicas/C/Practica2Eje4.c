#include<stdio.h>
#define p printf
#define s scanf
#define n 10

main()
{
	int i=0, arreglo[n];
	for(i=0;i<n;i++)
	{
		p("Introduce tu %d numero:",i+1);
		s("%d",(arreglo+i));
	}
	
	p("\nTu arreglo fue el siguiente\n");
	for(i=0;i<n;i++)
	{
		p("%d	",*(arreglo+i));
	}
}
