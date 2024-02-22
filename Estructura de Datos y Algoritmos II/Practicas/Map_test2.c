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


/*
 * Hashing simple: <key,value> = <id_employee :Int, salary :Real>
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <iso646.h>
#include <assert.h>

#include "Map.h"


// El tipo de key dependerá del tipo de clave (int, cadena, clase, etc); 
// el tipo de 'max' (size_t) es fijo, ya que es el tamaño del arreglo
// subyacente.
static size_t hash( size_t key, size_t max )
{
	return key % max;
}


static size_t coll_res( size_t index, size_t max )
{
	 size_t new_index = (index + 1) % max;
	 return new_index;
}

void imprime( size_t id, float sueldo )
{
	printf( "%ld => %0.2f\n", id, sueldo);
}

int main()
{
	MapPtr dictionary = Map_New( 7, 0L, hash, coll_res );

	printf( "Before:\n" );
	if( Map_Iterator( dictionary, imprime ) == 0 ){ printf( "Empty table.\n" ); }

	Map_Insert( dictionary, 425, 3500.50 );
	Map_Insert( dictionary, 101, 4500.50 );
	Map_Insert( dictionary, 225, 5500.50 );
	Map_Insert( dictionary, 300, 6500.50 );

	printf( "After:\n" );
	if( Map_Iterator( dictionary, imprime ) == 0 ){ printf( "Empty table.\n" ); }


	size_t id;
	float sueldo;

	printf( "Key to look for?\n> " );
	scanf( "%ld", &id );

	if( Map_Retrieve( dictionary, id, &sueldo ) == true ){
		printf( "(%ld => %0.2f)\n", id, sueldo );
	} else{
		printf( "Key %ld didn't found!\n", id );
	}

	Map_Delete( dictionary );
}



