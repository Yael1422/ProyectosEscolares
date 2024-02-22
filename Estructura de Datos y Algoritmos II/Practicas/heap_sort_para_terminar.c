/*Copyright (C) 
 * 2019 - eda1 dot fiunam at yahoo dot com dot mx
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 * 
 */


#include <stdio.h>
#include <stdlib.h>

#include <stdbool.h>
// bool, true, false

#include <iso646.h>
// and, or, not


enum {ASCENDING = 0, DESCENDING = 1};
typedef int Item;

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

/**
 * @brief 
 *
 * @param list[] Una lista
 * @param n El número total de elementos en la lista
 * @param k El nivel del nodo raíz (0 para el primer nivel, 1, para el segundo
 * nivel, y así sucesivamente.)
 */
void heapify_max( Item list[], size_t n, size_t k )
{
	int left = (2*k)+1;
	int right = (2*k)+2;
	int largest = 0;
	
	if (left < n and list[left] > list[k])
	{
		largest = left;
	}
	else
	{
		largest=k;
	}
	if (right<n and list[right]>list[largest])
	{
		largest=right;
	}
	if (largest!=k)
	{
		swap(list[k], list[largest]);
		heapify_max(list,n,largest);
	}
}

/**
 * @brief Convierte una lista de números en un montículo.
 *
 * @param list[] Una lista.
 * @param num_elems El número de elementos totales en la lista.
 *
 * @post El montículo se ve reflejado en la lista original.
 */
void build_max_heap( int list[], size_t num_elems )
{
}

/**
 * @brief Ordena una lista de números utilizando al algoritmo heap sort en forma
 * ascendente.
 *
 * @param list[] Una lista.
 * @param num_elems El número de elementos totales en la lista.
 */
void heap_sort_asc( int list[], size_t num_elems )
{
	int i;
	for(i=num_elems/2-1; i>=0; --i)
	{
		heapofy(list,num_elems,i);
	}
	for(i=num_elems-1; i>=0; --i)
	{
		swap(list[0], list[i]);
		heapify_max(list,i,0);
	}
}


void Heap_Sort( Item list[], size_t num_elems, int direction)
{
	if (direction==ASCENDING)
	{
		heap_sort_asc(list, NUM_ELEMS);
	}
	else if(direction==DESCENDING)
	{
		//heap_sort_desc(list, NUM_ELEMS);
	}
	else
	{
		printf("Comando no valido");
	}
}


#define NUM_ELEMS 9

int main()
{
	Item list[ NUM_ELEMS ] = { 3, 9, 1, 2, 8, 5, 0, 7, 4 }; 

	print( list, NUM_ELEMS, "  Antes: " );

	heap_sort_max( list, NUM_ELEMS );
	print( list, NUM_ELEMS, "Despues: " );
	
	
	
	
	Item list2[ NUM_ELEMS ] = { 20, 1, 3, 8, 6, 2, 4, 6, 1}; 
	
	print( list2, NUM_ELEMS, "  Antes: " );

	Heap_Sort( list2, NUM_ELEMS, ASCENDING );
	print( list2, NUM_ELEMS, "Despues: " );
}
