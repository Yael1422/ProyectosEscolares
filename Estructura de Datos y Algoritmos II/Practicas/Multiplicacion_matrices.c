#include <stdio.h>

#include <stdlib.h>
// para system() y rand()

#include <time.h>
// para time()

#include <omp.h>

#define FIL1 3
#define COL1 2

#define FIL2 2
#define COL2 3

int main()
{
	int **a, **b, **c;
	srand( time( NULL ) );
	size_t i, j, k;
	
	//Guardar matriz A	
	#pragma omp parallel num_threads( 4 )
	{
		a = ( int** ) malloc( sizeof ( int* ) * FIL1);
	
		#pragma omp for private( i )
		for( i = 0; i < FIL1; ++i)
		{
			*( a + i ) = malloc( sizeof( int ) * COL1 );
		}

		#pragma omp single
		printf("Llenado primera matriz\n");
	
		#pragma omp for private( i, j )
		for( i = 0; i < FIL1; ++i )
		{
			for( j = 0; j < COL1; ++j )
			{
				*( a + i * COL1 + j ) = rand() % 20;
			}
		}
	
		#pragma omp for private ( i, j )
		for( i = 0; i < FIL1; ++i )
		{
			for( j = 0; j < COL1; ++j )
			{
				printf( "%d\t", *( a + i * COL1 + j ) );
			}
			printf("\n");
		}
	   
	   
		//Guardar Matriz B
	
		b = ( int** ) malloc( sizeof ( int* ) * FIL2);
	
		#pragma omp for private( i )
		for( size_t i = 0; i < FIL2; ++i)
		{
			*( b + i ) = malloc( sizeof( int ) * COL2 );
		}
		
		#pragma omp single
		printf("Llenado segunda matriz\n");
		
		#pragma omp for private( i, j )
		for( i = 0; i < FIL2; ++i )
		{
			for( j = 0; j < COL2; ++j )
			{
				*( b + i * COL2 + j ) = rand() % 30;
			}
		}
		
		#pragma omp for private( i, j )
		for( i = 0; i < FIL2; ++i )
		{
			for( j = 0; j < COL2; ++j )
			{
				printf( "%d\t", *( b + i * COL2 + j ) );
			}
			printf("\n");
		}
		
		
		//Guardar Multiplicacion Matriz C
		
		c = ( int** ) malloc( sizeof ( int* ) * FIL1);
		
		#pragma omp for private( i )
		for( i = 0; i < FIL1; ++i)
		{
			*( c + i ) = malloc( sizeof( int ) * COL2 );
		}
		
		#pragma omp single
		printf("\nLa multiplicacion es:\n");
		
		#pragma omp for private( i, j, k )
		for( i = 0; i < FIL1; ++i )
		{
			for(  j = 0; j < COL2; ++j )
			{
				for( k = 0; k < COL1 ; ++k )
				{
 					*( c + i * COL2 + j ) +=  *( a + i * COL1 + k ) * *( b + k * COL2 + j );
				}
			}
		}
		
		#pragma omp for private( i, j )
		for( i = 0; i < FIL1; ++i )
		{
			for( j = 0; j < COL2; ++j )
			{
				printf( "%d\t", *( c + i * COL2 + j ) );
			}
			printf("\n");
		}
	}		
}
