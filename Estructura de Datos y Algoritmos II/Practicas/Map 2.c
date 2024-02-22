/*Copyright (C) 
 * 2019 - eda1 dot fiunam @ yahoo dot com dot mx
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
 * Este módulo implementa una tabla hash cerrada.
 */

#include "Map.h"

MapPtr Map_New( size_t capacity, size_t empty_val, pHash hash, pCollRes coll_res )
{
	MapPtr map = malloc( sizeof( Map ) );
	// creamos al objeto Map

	if( NULL != map ){
		
		map->table = malloc( sizeof( Entry ) * capacity );
		// creamos al arreglo que servirá de contenedor a la tabla hash

		if( NULL != map->table ){

			for( size_t i = 0; i < capacity; ++i ){ map->table[ i ].key = empty_val; }
			// limpiamos la tabla

			map->size = capacity;
			map->len = 0L;
			map->empty = empty_val;
			map->hash = hash;
			map->coll_res = coll_res;

		} else{
			free( map );
			// si no hay contenedor, entonces no hay mapa

			map = NULL;
		}
	}
	return map;
}

void Map_Delete( MapPtr this )
{
	assert( this );

	free( this->table );
	// devolvemos la memoria del contenedor
	
	free( this );
	// devolvemos la memoria del objeto
}


bool Map_Insert( MapPtr this, size_t id_empleado, float sueldo )
{
	size_t loc = this->hash( id_empleado, this->size );
	// loc = h(x) = g(id_empleado) mod size
	// g() puede ser: division, mid-square, folding, etc.

	while( this->table[ loc ].key != this->empty /*¿y si no hay slots libres?*/ ){
		loc = this->coll_res( loc, this->size );
	}

	this->table[ loc ].key = id_empleado;
	this->table[ loc ].value = sueldo;

	++this->len;

	return true;
}

bool Map_Retrieve( MapPtr this, size_t id_empleado, float* sueldo )
{
	size_t start_loc = this->hash( id_empleado, this->size );
	// loc = h(x) = g(id_empleado) mod size
	// g() puede ser: division, mid-square, folding, etc.

	size_t loc = start_loc;

	bool more_to_search = true;

	do{

		if( this->table[ loc ].key == id_empleado or this->table[ loc ].key == this->empty ){
			more_to_search = false;
		} else{
			loc = this->coll_res( loc, this->size );
		}

	} while( loc != start_loc and more_to_search == true );


	bool found = this->table[ loc ].key == id_empleado;

	if( found == true ){
		*sueldo = this->table[ loc ].value;
	}

	return found;
}

bool Map_Remove( MapPtr this, size_t id_empleado )
{
	/* no olvidar descontar uno a .len!*/

	return false;
}

size_t Map_Iterator( MapPtr this, void (*pfun)( size_t id, float sueldo ) )
{
	size_t cnt = 0;

	for( size_t i = 0; i < this->size; ++i ){
		if( this->table[ i ].key != this->empty ){
			pfun( this->table[ i ].key, this->table[ i ].value );
			++cnt;
		}
	}

	return cnt;
}

size_t Map_Len( MapPtr this )
{
	return this->len;
}

size_t Map_Size( MapPtr this )
{
	return this->size;
}



