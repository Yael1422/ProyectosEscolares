
#include <stdio.h>
#include <stdlib.h>

#include <omp.h>
// para las funciones de biblioteca de OpenMP

void hello();

int main( int argc, char* argv[] )
{
   int i, j = 0;

   #pragma omp parallel num_threads( 4 ) private( i )
   { // abre la región paralela

      printf("Hola mundo\n");

      for( i = 0; i < 200; ++i )
      {
         printf( "%d)   Contador: %d\n", j, i );

         if( omp_get_thread_num() == 0 )
         {
            ++j;
         }
      }

   } // cierra la región paralela

} // cierra main()