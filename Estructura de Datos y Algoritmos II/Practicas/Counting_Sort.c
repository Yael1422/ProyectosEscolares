#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define NUM_ELEMS 7
#define NUM_ELEMS2 500

enum {ASCENDING = 0, DESCENDING = 1};
typedef int Item;
Item g_operaciones=0;

void print( int* list, size_t tam, char* msg )
{
	printf( "%s", msg );
	for( size_t i = 0; i < tam; ++i ){
		printf( "%d, ", list[ i ] );
	}
	printf( "\n" );
}



static void counting_asc (int list[], size_t num_elems, size_t low, size_t high)
{
	g_operaciones=0;
	size_t capacity = high - low + 1;

	int* aux = calloc (capacity, sizeof(int));
	
	for(size_t i=0; i<num_elems; i++)
	{
		size_t pos=list[i];
		aux[pos]++;
		++g_operaciones;
	}
	
	size_t j=0;
	for(size_t i=0; i<capacity; ++i)
	{
		//if(aux[i]>0)
		//{
			for(size_t k=aux[i]; k>0; --k)
			{
				list[j]=i;
				++j;
				++g_operaciones;
			}
		//}
		/*
		Si comentamos esas lineas es lo mismo, ya que en nuestro for la k actua
		como si fuera el if, por lo cual podria decir que la k actua como si fuera
		aux[i] por ello al momento de pedir en el for que k>0 realiza lo mismo que el if
		*/
	}
	free(aux);
}


static void counting_desc (int list[], size_t num_elems, size_t low, size_t high)
{
	g_operaciones=0;
	size_t capacity = high - low + 1;

	int* aux = calloc (capacity, sizeof(int));
	
	for(size_t i=0; i<num_elems; i++)
	{
		size_t pos=list[i];
		aux[pos]++;
		++g_operaciones;
	}
	
	size_t j=0;
	for(size_t i=capacity; i>0; --i)
	{
		//if(aux[i]>0)
		//{
			for(size_t k=aux[i]; k>0; --k)
			{
				list[j]=i;
				++j;
				++g_operaciones;
			}
		//}
	}
	free(aux);
}

void Counting_Sort(Item list[], size_t num_elems, int direction)
{
	g_operaciones=0;
	
	if (direction==ASCENDING)
	{
		counting_asc(list, NUM_ELEMS, 0, 10);
	}
	else if(direction==DESCENDING)
	{
		counting_desc(list, NUM_ELEMS, 0, 10);
	}
	else
	{
		printf("Comando no valido");
	}
}


int main()
{
	Item list[ NUM_ELEMS ] = { 1, 4, 4, 2, 7, 5, 2};

	print( list, NUM_ELEMS, "Antes: " );

	counting_desc( list, NUM_ELEMS, 0, 20 );

	print( list, NUM_ELEMS, "Despues: " );
	printf("Numero de operaciones realizadas %d", g_operaciones );
	//Si representa el orden de O(n+m) ya que al ser 7 elementos, termina por arrojarme 14 operaciones
	
	
	
	//Random (Numero 3)

	Item listarandom[NUM_ELEMS2];
	srand(time(NULL));
    Item res;
    
    for(size_t i=0; i<NUM_ELEMS2; ++i)
    {
        res = ( rand() % 6001 );
        res-=1000;
        listarandom[i]=res;
    }
	print( listarandom, NUM_ELEMS2-450, "\n\nLista numeros random antes (50 elementos): \n" );
	
	counting_asc( listarandom, NUM_ELEMS2, -1000, 5000 );
	
	print( listarandom, NUM_ELEMS2-450, "\n\nLista numeros random despues (50 elementos): \n" );
	printf("\nEl numero de comparaciones es: %d", g_operaciones);
	
	
	
	//Random activacion (Numero 4)
	
	Item listrandom[NUM_ELEMS];
	srand(time(NULL));
	
	for(size_t i=0; i<NUM_ELEMS; i++)
	{
		res=(rand()% 10);
		listrandom[i]=res;
	}
	
	print( listrandom, NUM_ELEMS, "\n\n\n\nLista numeros random antes: \n" );
	
	Counting_Sort( listrandom, NUM_ELEMS, DESCENDING);
	
	print( listrandom, NUM_ELEMS, "\n\nLista numeros random despues: \n" );
	printf("\nEl numero de comparaciones es: %d", g_operaciones);
}
