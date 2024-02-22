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


#include <stdlib.h>
#include <stdio.h>

#include <stdbool.h>
// para bool, true y false


#define TAM_LISTA 6
// numero de elementos en la lista

enum {ASCENDING = 0, DESCENDING = 1};
typedef int Item;

void print( Item* list, size_t tam )
{
	for( size_t i = 0; i < tam; ++i ){
		printf( "%d, ", list[ i ] );
	}
	printf( "\n" );
}

void swap( Item* val1, int* val2 )
{
    Item tmp=*val1;
    *val1=*val2;
    *val2=tmp;
}

size_t g_comparaciones = 0;
// contamos el número de comparaciones. Es global para poder quitarla con
// facilidad del código ya que no es parte del mismo.

void bubble_asc(Item list[], size_t num_elems )
{
    bool done=false;
    
    for(size_t i=0; i<num_elems-1 && done==false;++i)
    {
        done=true;
        
        for(size_t j=num_elems-1; j>i; --j)
        {
            ++g_comparaciones;
            
            if(list[j]<list[j-1])
            {
                swap(&list[j], &list[j-1]);
                done=false;
            }
        }
    }
}

void bubble_desc( Item list[], size_t num_elems )
{
    bool done=false;
    
    for(size_t i=0; i<num_elems-1 && done==false;++i)
    {
        done=true;
        
        for(size_t j=num_elems-1; j>i; --j)
        {
            ++g_comparaciones;
            
            if(list[j]>list[j-1])
            {
                swap(&list[j], &list[j-1]);
                done=false;
            }
        }
    }
}

BubbleSort(Item list[], size_t num_elems, Item direction)
{
    if(direction==ASCENDING)
    {
        bubble_asc(list,num_elems);
    }
    else if(direction==DESCENDING)
    {
        bubble_desc(list,num_elems);
    }
    else
    {
        printf("Error");
    }
}


int main(void)
{
	int lista[ TAM_LISTA ] = { 6, 7, 9, 1, 2, 8 };


	printf( "Lista antes: " );
	print( lista, TAM_LISTA );

	bubble_asc( lista, TAM_LISTA );

	printf( "Lista despues: " );
	print( lista, TAM_LISTA );

	printf( "Se realizaron %ld comparaciones\n", g_comparaciones );
	
	bubble_desc(lista, TAM_LISTA);
	printf("Lista descendente (Actividad1): ");
	print(lista,TAM_LISTA);
	printf("\n");
	
	BubbleSort(lista,TAM_LISTA,ASCENDING);
	printf("Lista ascendente (Actividad2): ");
	print(lista,TAM_LISTA);
	
	BubbleSort(lista,TAM_LISTA,DESCENDING);
	printf("Lista descendente (Actividad2): ");
	print(lista,TAM_LISTA);
	
}
