#include<stdio.h>
#define p printf
#define s scanf
#define n 100

char longCad(char *cad1, char *cad2);
 
main()
{
	char cadena1[n]="Como estan todos";
	char cadena2[n];
	
	p("Cadena original:	%s\n",cadena1);
	longCad(cadena2,cadena1);
	p("Cadena copiada:		%s",cadena2);
}

char longCad(char *cad1, char *cad2)
{
	int i=0;
	while(cad2[i]!='\0')
	{
		cad1[i] = cad2[i];
    	cad1++;
    	cad2++;
    }
    cad1[i]='\0';
    
    return cad1;
}
