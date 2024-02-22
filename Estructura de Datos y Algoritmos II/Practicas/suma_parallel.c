#include <stdio.h>

#include <stdlib.h>
// para la funci�n rand()

#include <time.h>
// para inicializar la semilla de aleatoriedad

#include <omp.h>
// para las funciones de biblioteca de OpenMP

#define TAM 10


// No vamos a usar esta funci�n, pero est� aqu� para que se vea la 
// diferencia con su contraparte paralela.
void suma_sec( int arr1[], int arr2[], int res[], int tam )
{
   for( int i = 0; i < tam; ++i ){
      res[ i ] = arr1[ i ] + arr2[ i ];
   }
}

void suma_par( int arr1[], int arr2[], int res[], int tam )
{
	int mitad = tam/2;
	#pragma omp parallel num_threads( 2 )
	{ // Abre la regi�n paralela

   		int id = omp_get_thread_num();
   		// obtenemos el id de este hilo

   		int inicio = id * mitad;
   		
   		int fin = inicio + mitad;
   		
   		for( int i = inicio; i < fin; ++i )
   		{
   			printf( "El hilo %d est� calculando res[ %d ]\n", id, i );

   			res[ i ] = arr1[ i ] + arr2[ i ];
		}

	} // Cierra la regi�n paralela

}

void Imprime( int arr[], int tam)
{
	printf("\n");
	int mitad = tam/2;
	#pragma omp parallel num_threads( 2 )
	{	//Abre la regi�n paralela
				
		int id = omp_get_thread_num();
   		// obtenemos el id de este hilo

   		int inicio = id * mitad;
   		
   		int fin = inicio + mitad;
   		
		for( int i = inicio; i<fin; ++i)
		{
			printf( "El hilo %d est� imprimiendo arr[ %d ] = %d\n", id, i, arr[i] );
		}
		
	}	//Cierra la regi�n paralela
}

int main()
{
   int a[ TAM ];
   int b[ TAM ];
   int c[ TAM ];

   srand( time( NULL ) );

   for( int i = 0; i < TAM; ++i ){
      a[ i ] = rand() % 100;
      b[ i ] = rand() % 100;
   }

   suma_par( a, b, c, TAM );

   /*for( int i = 0; i < TAM; ++i ){
      printf( "%2d) %d + %d = %d\n", i, a[ i ], b[ i ], c[ i ] );
   }*/
   
   printf("\nPrimer arreglo de n�meros:");
   Imprime(a,TAM);
   printf("\nSegundo arreglo de n�meros:");
   Imprime(b,TAM);
   printf("\nResultado de la suma:");
   Imprime(c,TAM);
}
