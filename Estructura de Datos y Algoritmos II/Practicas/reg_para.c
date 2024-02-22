#include <stdio.h>
#include <stdlib.h>

#include <omp.h>
//Para las funciones de biblioteca de OpenMP

int main()
{
	//Aqui iria el codigo secuencial

	#pragma omp parallel num_threads( 4 )
	{	//Abre la region paralela
		printf( "La region paralela es ejecutada por el hilo %d\n", omp_get_thread_num() );

		if( omp_get_thread_num() == 2 )
		{
			printf( "El hilo %d hace las cosas diferentes\n", omp_get_thread_num() );
		}
	}	//Cierra la region paralela

	//Aqui iria mas codigo secuencial
}