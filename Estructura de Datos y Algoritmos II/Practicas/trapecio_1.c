#include <stdio.h>

double f( double x ) 
{
	return 1.0 / x; 
}

int main() 
{
	double a = 1.0; 
	double b = 2.0;
	
	int div = 10;
	// 10 divisiones significan 9 segmentos
	
	double h = (b-a) / (double)div; 
	
	double area = ( f(a) + f(b) ) / 2.0; 
	
	size_t i;

	for( i = 1; i < div; ++i ) { 
		area += f( a + h * i );
	}

	area *= h;

	printf( "El área es: %lf\n", area ); 
}