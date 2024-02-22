
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define TAM 25

int main()
{
    int acum = 0;
    //Reduction no inicializa la variable a reducir
    int a[TAM];
    int n = TAM;

    for( int i =0; i < n; ++i ) a[i] = i + 1;

    for( int i = 0; i < n; ++i){
        printf( "a[%d] = %d\n", i, a[i] );
    }

    #pragma omp parallel for shared ( a, n ) reduction( +: acum)
    for(size_t i = 0; i < n; ++i){
        acum += a[ i ];
    }
    
    printf( "La suma es: %d\n", acum);
}
