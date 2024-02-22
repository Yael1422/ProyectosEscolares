#include <stdio.h>

#include <stdlib.h>
// para la función rand()

#include <time.h>
// para inicializar la semilla de aleatoriedad

#include <omp.h>
// para las funciones de biblioteca de OpenMP

void suma_par( int arr1[], int arr2[], int res[], int tam )
{
   #pragma omp parallel for num_threads( 2 )
   for( int i = 0; i < tam; ++i ){
      res[ i ] = arr1[ i ] + arr2[ i ];
   }
}

double f( double x )
{
   return 1.0 / x;
}

double trapecio_sec( double a, double b, size_t n )
{
   double h = (b - a) / n;

   double approx = ( f( a ) + f( b ) ) / 2.0;

   for( size_t i = 1; i <= n-1; ++i ){
      approx += f( a + i * h );
      printf( "i: %ld, Approx( %lf ) \n", i, approx );
   }

   return h * approx;
}

double trapecio_par( double a, double b, size_t n )
{
   double h = (b - a) / n;

   double approx = ( f( a ) + f( b ) ) / 2.0;

#pragma omp parallel for shared( a, h ) reduction( +: approx ) num_threads( 4 )
   for( size_t i = 1; i <= n-1; ++i ){
      approx += f( a + i * h );
      printf( "i: %ld, Thread( %d ), Approx( %lf ) \n", i, omp_get_thread_num(), approx );
   }

   return h * approx;
}

int main()
{
   float y_sec = trapecio_sec( 1.0, 2.0, 100 );
   printf( "Secuencial: %lf\n", y_sec );

   float y_par = trapecio_par( 1.0, 2.0, 100 );
   printf( "Paralelo: %lf\n", y_par );
}
