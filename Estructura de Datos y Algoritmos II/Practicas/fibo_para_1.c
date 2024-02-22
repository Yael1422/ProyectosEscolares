#include <stdio.h> 
#include <omp.h>

unsigned long fibo( unsigned long n, int a[] ) 
{
	if( n < 2 ) return n; 
	
	unsigned long i, j;

	if( a[ n ] == 0 )
	{
		#pragma omp task shared( i ) firstprivate( n )
		{
			i = fibo( n - 1 , a );
		}
    
    	#pragma omp task shared( j ) firstprivate( n )
		{
			j = fibo( n - 2 , a );
		}

		#pragma omp taskwait
		a[ n ] = i + j;
	}

   	return a[ n ];
}

#define TAM 100

int main() 
{
	unsigned n = 10;
	int a[ TAM ] = {0} ;
	a[ 0 ] = 1;
	a[ 1 ] = 1;
	unsigned long res;
    
    #pragma omp parallel default( none ) shared( n, res, a )
	{
		#pragma omp single
		res = fibo( (unsigned long)n , a);
    }

    printf( "%ld\n", res );
}
