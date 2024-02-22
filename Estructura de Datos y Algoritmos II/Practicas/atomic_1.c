
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main()
{
    int cont = 0, b = 1, i, n = 50;
    
    #pragma omp parallel for num_threads( 4 ) shared ( n, cont, b ) private( i )
    for( i = 0; i < n; ++i){
        
        #pragma omp atomic
        cont += b++;
    } // --- Implicit barrier
    
    printf( "cont = %d, b = %d\n", cont, b );
}
