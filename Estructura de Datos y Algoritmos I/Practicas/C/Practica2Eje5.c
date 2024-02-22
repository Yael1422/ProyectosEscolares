#include<stdio.h>
#define p printf
#define s scanf

int longit(char *c);

int main()
{
	char s[30];
	int l;
	p("Introduce tu cadena\n");
	gets(s);
	l=longit(s);
	p("Longitud=%d",l);
	return 0;
}

int longit(char *s)
{
	int i=0;
	while(*(s+i)!='\0')
	{
		i++;
	}
	return i;
}
