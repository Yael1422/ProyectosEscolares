
#include <stdio.h>
#include <stdlib.h>

#include <omp.h>
// para las funciones de biblioteca de OpenMP

void hello();

int main( int argc, char* argv[] )
{
   if( argc < 2 ){
      printf( "Usage:\n"
            "%s num_threads\n"
            "num_threads is the number of threads\n", argv[0] );
      return 0;
   } 

   int thread_count = strtol( argv[1], NULL, 10 );

#pragma omp parallel num_threads( thread_count )
{ // abre la región paralela

   hello();

} // cierra la región paralela

} // cierra main()

void hello()
{
   int my_rank = omp_get_thread_num();

   int thread_count = omp_get_num_threads();

   printf( "Hello from thread %d of %d\n", my_rank, thread_count );
}
