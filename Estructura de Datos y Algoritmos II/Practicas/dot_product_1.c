/*
 * dot_product_1.c
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

void print_a( double x[], size_t n, const char* msg )
{
   printf( "%s", msg );

   //#pragma omp parallel default( none ) shared( x, n )
   {
      for( size_t i = 0; i < n; ++i ){
         if( i%5 == 0 ) printf( "\n" );

         //#pragma omp single
         printf( "%0.2lf\t", x[ i ] );
      }
   }
   printf( "\n" );
   
}

#define TAM 3

int main()
{
   double v[ TAM ];
   double w[ TAM ];

   srand( time( NULL ) );

   for( size_t i = 0; i < TAM; ++i ){
      v[ i ] = rand() / (double)RAND_MAX * 100.0;
      w[ i ] = rand() / (double)RAND_MAX * 50.0 + 50.0;
   }

   print_a( v, TAM, "v: " );
   print_a( w, TAM, "w: " );

   double z = 0;
   size_t i;

   #pragma omp parallel for shared( v, w ) private( i ) num_threads(4)
   for( i = 0; i < TAM; ++i ){
     z += v[ i ] * w[ i ];
   }
   printf( "z = %lf\n", z );
}
