#include <stdio.h>
#define n 10
#define p printf
#define s scanf

struct Complejos
{
	float razon;
	float angulo;
};

void multi (struct Complejos com1,struct Complejos com2,struct Complejos comres);

int main()
{
	struct Complejos numco[n];
	struct Complejos resultado;
	int primCo,segunCo,i;

	for (i=0; i<n; i++)
	{
		p("Introduce la razon del complejo %d:	 ",i+1);
		s("%f",&numco[i].razon);
		p("Introduce el angulo del complejo %d:	 ",i+1);
		s("%f",&numco[i].angulo);
	}
	
	p("Introduce el primer complejo que multiplicaras: ");
	s("%d",&primCo);
	p("Introduce el segundo complejo que multiplicaras:: ");
	s("%d",&segunCo);
	
	multi (numco[primCo-1],numco[segunCo-1],resultado);
	return 0;
}

void multi (struct Complejos com1,struct Complejos com2,struct Complejos comres)
{
	(comres.razon)=(com1.razon)*(com2.razon);
	(comres.angulo)=(com1.angulo)+(com2.angulo);
	p("\n\n---------------------------------");
	p("\nEl resultado fue:	 %.3f cis %.3f\n",comres.razon,comres.angulo);
}
