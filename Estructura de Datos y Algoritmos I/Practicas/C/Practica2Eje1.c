#include <stdio.h>

main()
{
	float a,*ap;
	a=7.5;
	ap=&a;
	
	printf("Direccion asignada a la variable a %d \n", &a);
	printf("Direccion asignada a la variable ap %p \n", &ap);
	printf("Valor asignado a la variable a %.2f \n", a);
	printf("Valor asignado a la variable ap o direccion a la que apunta %d \n", ap);
	printf("Contenido de la variable a la que apunte %.2f \n", *ap);
	printf("Tamanio en bytes para la variable a %d \n", sizeof(a));
	printf("Tamanio en bytes para la variable ap %d \n", sizeof(*ap));
	
/*Escribir abajo la línea que modifique el valor de la variable -a- mediante el apuntador ap y se muestre el nuevo
valor en la salida estándar*/

	*ap=11;
	printf("\nEl nuevo valor de a es:%.2f",a);
	printf("\nEl nuevo valor de a es:%.2f",*ap);
} 
