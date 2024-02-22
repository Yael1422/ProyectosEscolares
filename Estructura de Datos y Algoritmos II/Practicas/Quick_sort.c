#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define NUM_ELEMS 10


enum {ASCENDING = 0, DESCENDING = 1};
typedef int Item;
Item g_intercambios=0;
Item g_comparaciones=0;


void print( int* list, size_t tam, char* msg )
{
	printf( "%s", msg );
	for( size_t i = 0; i < tam; ++i ){
		printf( "%d, ", list[ i ] );
	}
	printf( "\n" );
}

void swap( Item* val1, Item* val2 )
{
	Item tmp = *val1;
	*val1 = *val2;
	*val2 = tmp;
}


static void quick_sort_asc( Item list[], size_t first, size_t last )
{
    size_t mid = (first+last)/2;
    Item piv=list[mid];
    size_t x0=first;
    size_t x1=last;
    
    while(x0<=x1)
    {
        while(list[x0]<piv)
        {
            ++x0;
            //
            ++g_comparaciones;
        }
        while(list[x1]>piv)
        {
            --x1;
            //
            ++g_comparaciones;
        }
        if(x0<=x1)
        {
            swap(&list[x0], &list[x1]);
            ++g_intercambios;
            ++x0;
            --x1;
        }
    }
    
    if (first<x1)
    {
        quick_sort_asc(list,first,x1);
    }
    if (x0<last)
    {
        quick_sort_asc(list,x0,last);
    }
}



static void quick_sort_desc( Item list[], size_t first, size_t last )
{
    size_t mid = (first+last)/2;
    Item piv=list[mid];
    size_t x0=first;
    size_t x1=last;
    
    while(x0<=x1)
    {
        while(list[x0]>piv)
        {
            ++x0;
            //
            ++g_comparaciones;
        }
        while(list[x1]<piv)
        {
            --x1;
            //
            ++g_comparaciones;
        }
        if(x0<=x1)
        {
            swap(&list[x0], &list[x1]);
            ++g_intercambios;
            ++x0;
            --x1;
        }
    }
    
    if (first<x1)
    {
        quick_sort_desc(list,first,x1);
    }
    if (x0<last)
    {
        quick_sort_desc(list,x0,last);
    }
}


void Quick_Sort( Item list[], size_t num_elems, int direction)
{
	g_comparaciones=0;
	
	if (direction==ASCENDING)
	{
		quick_sort_asc(list, 0, NUM_ELEMS-1);
	}
	else if(direction==DESCENDING)
	{
		quick_sort_desc(list, 0, NUM_ELEMS-1);
	}
	else
	{
		printf("Comando no valido");
	}
}


#define NUM_ELEMS2 5000

int main()
{
	Item list[ NUM_ELEMS ] = { 1, 8, 4, 9, 6, 3, 5, 2, 7, 0 };

	print( list, NUM_ELEMS, "Antes: " );

	quick_sort_asc( list, 0, NUM_ELEMS - 1 );

	print( list, NUM_ELEMS, "Despues: " );
	
	printf("Numero de intercambios %d \n\n", g_intercambios);
	//Representa O(n log(n)) ya que al calcularlo obtenemos el numero de intercambios hechos.
	
	
	
	//Random (Numero 2)

	Item listarandom[NUM_ELEMS2];
	srand(time(NULL));
    Item res;
    
    for(size_t i=0; i<NUM_ELEMS2; ++i)
    {
        res = ( rand() % 601 );
        res-=100;
        listarandom[i]=res;
    }
	print( listarandom, NUM_ELEMS2-4950, "\nLista numeros random antes (50 elementos): \n" );
	
	quick_sort_asc( listarandom, 0, NUM_ELEMS2-1 );
	
	print( listarandom, NUM_ELEMS2-4950, "\nLista numeros random despues (50 elementos): \n" );
	printf("\nEl numero de comparaciones es: %d", g_comparaciones);
	
    
    
	//Comparacion arreglo 5000 con numero igual (Numero 3)
	printf("\n\n\n\n");
	
	for(size_t i=0; i<NUM_ELEMS2; ++i)
    {
        listarandom[i]=10;
    }
	
	print( listarandom, NUM_ELEMS2-4950, "Lista numeros iguales (50 elementos): " );
	
	quick_sort_asc( listarandom, 0, NUM_ELEMS2-1);
	
	printf("El numero de comparaciones es: %d\n", g_comparaciones);
    
    printf("\n\n\n\n");
    
    
    //Lista ejemplo activacion (Numero 4)
    
    Item listarandomactivacion[NUM_ELEMS];
	srand(time(NULL));
    
    for(size_t i=0; i<NUM_ELEMS; ++i)
    {
        res = ( rand() % 601 );
        res-=100;
        listarandomactivacion[i]=res;
    }
	print( listarandomactivacion, NUM_ELEMS, "\nLista numeros random antes: \n" );
	
	Quick_Sort( listarandomactivacion, 10, ASCENDING );
	print( listarandomactivacion, NUM_ELEMS, "\nLista numeros random despues (ascendente): \n" );
	printf("El numero de comparaciones es: %d\n", g_comparaciones);
	
	
	Quick_Sort( listarandomactivacion, 10, DESCENDING );
	print( listarandomactivacion, NUM_ELEMS, "\nLista numeros random despues (descendente): \n" );
	printf("El numero de comparaciones es: %d\n", g_comparaciones);
    
}

