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
#include <time.h>

#include <stdbool.h>
// bool, true, false

#include <iso646.h>
// and, or, not

#include <math.h>
//Para pow()

#include "Queue.h"

#define NUM_ELEMS 7
#define NUM_ELEMS2 100

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


static size_t subkey( Item val, size_t num_pos, size_t radix)
{
    return((val / (int)pow(radix, num_pos - 1)) %radix);
}


static void collect(Item list[], Queue* queues[], size_t radix)
{
    size_t index = 0;
    for(size_t i = 0; i<radix; ++i)
    {
        while(Queue_IsEmpty( queues[i] ) == false)
            {
                Item val;
                Queue_Dequeue(queues[i], &val);
                list[index] = val;
                ++index;
            }
    }
}


void radix_sort_10( int list[], size_t num_elems)
{
    size_t radix=10;

    Queue* queues[ radix ];

    for(size_t i=0; i<radix; i++)
    {
        queues[i] = Queue_New();
    }

    size_t num_pos = 3;

    for(size_t i = 1; i <= num_pos; ++i)
    {
        for(size_t j = 0; j < num_elems; ++j)
        {
            size_t whichQ = subkey(list[j], i, radix);
            Queue_Enqueue( queues[whichQ], list[j]);
        }

        collect(list, queues, radix);
        print(list, num_elems, "Collect: ");
    }

    for(size_t i=0; i<radix; i++)
    {
        Queue_Delete(queues[i]);
    }
}


void Radix_Sort(Item list[], size_t num_elems, int direction)
{
	if (direction==ASCENDING)
	{
		radix_sort_10(list, NUM_ELEMS2);
	}
	else
	{
		printf("Comando no valido");
	}
}


int main()
{
	Item list[ NUM_ELEMS ] = { 630, 421, 527, 911, 912, 266, 85 };

	print( list, NUM_ELEMS, "  Antes: " );

	radix_sort_10( list, NUM_ELEMS);
	print( list, NUM_ELEMS, "Despues: " );
	
	
	
	Item listarandom[NUM_ELEMS2];
	srand(time(NULL));
    Item res;
    
    for(size_t i=0; i<NUM_ELEMS2; ++i)
    {
        res = ( rand() % 50 );
        listarandom[i]=res;
    }
	print( listarandom, NUM_ELEMS2, "\nLista numeros random antes: \n" );
	radix_sort_10( listarandom, NUM_ELEMS2);
	print(listarandom, NUM_ELEMS2, "\nLista numeros random despues: \n");
	
	
	
	Item listarandom2[NUM_ELEMS2];
	srand(time(NULL));
    
    for(size_t i=0; i<NUM_ELEMS2; ++i)
    {
        res = ( rand() % 50 );
        listarandom2[i]=res;
    }
	print( listarandom2, NUM_ELEMS2, "\nLista numeros random antes: \n" );
	Radix_Sort( listarandom2, NUM_ELEMS2, ASCENDING);
	print(listarandom2, NUM_ELEMS2, "\nLista numeros random despues: \n");
	
	
}
