
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

void funcA( size_t num )
{
   for( size_t i = 0; i < num; ++i )
      printf( "Hola desde el hilo %d\n", omp_get_thread_num() );
}

void funcB( size_t num )
{
   size_t i = num;
   while( i > 0 ){
      printf( "Hello " );
      printf( "from thread " );
      printf( "%d\n", omp_get_thread_num() );

      --i;
   }
}

void funcC( size_t num )
{
    size_t i = num;
    do {
        printf( "El hilo %d esta siendo ejecutado\n", omp_get_thread_num() );
        i--;
    }while (i != 0);
}

int main()
{
    size_t i = 3;
    size_t j = 4;
    size_t k = 5;

    #pragma omp parallel shared( i, j, k )
    {
        #pragma omp sections
        {
            #pragma omp section
            funcA( i );

            #pragma omp section
            funcB( j );
            
            #pragma omp section
            funcC( k );
            
            #pragma omp section
            {
                int array[6];
                for( size_t i = 0; i < 6; ++i){
                    array[i] = i+2;
                    printf("El hilo %d esta imprimiendo el numero %d\n", omp_get_thread_num(), array[i]);
                }
            }
        }
    }
}
