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


#ifndef  MAP_INC
#define  MAP_INC

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include <iso646.h>
#include <stdint.h>

#include "Entry.h"

typedef size_t (*pHash)(size_t key, size_t max);

typedef size_t (*pCollRes)( size_t index, size_t max);
// para este ejemplo los tipos de key e index coinciden, pero no será así
// cuando key en pHash sea diferente a entero, p. ej. cuando la clave sea una
// cadena

typedef struct
{
	Entry* table; ///< Es la tabla hash

	size_t size; ///< Es el número máximo de elementos en la tabla
	
	size_t len; ///< Es el número actual de elementos en la tabla

	size_t empty; ///< es el valor que 'key' interpretará como vacío

	pHash hash; ///< es la función hash

	pCollRes coll_res; ///< es la función de resolución de colisiones.
} Map;

typedef Map* MapPtr;

/**
 * @brief Crea un nuevo mapa.
 *
 * @param size El máximo número de elementos que se podrán guardar.
 * @param empty El valor que indicará que el slot está vacío. Depende de cada
 * aplicación.
 * @param hash Es una función hash inyectada por el usuario.
 * @param coll_res Es una función de resolución de colisiones inyectada por el usuario.
 *
 * @return Una referencia a un nuevo objeto Map. NULL en caso de que falle la asignación de memoria.
 */
//MapPtr Map_New( size_t capacity, size_t empty, size_t (*hash)( size_t key, size_t max) )
MapPtr Map_New( size_t capacity, size_t empty, pHash hash, pCollRes coll_res );

/**
 * @brief Destruye a un objeto Map.
 *
 * @param this Referencia a un objeto Map.
 */
void Map_Delete( MapPtr this );

/**
 * @brief Inserta un elemento en el mapa.
 *
 * Para este ejemplo, key es el id de empleado, mientras que value es el sueldo del mismo. Esta función debe pensarse de la siguiente manera:
 *
 * table[ id_empleado ] = sueldo;
 *
 * @param this        Referencia a un objeto Map.
 * @param id_empleado Índice del registro.
 * @param sueldo      Valor del registro.
 *
 * @return true si el elemento pudo ser insertado en el mapa; false en cualquier otro caso.
 */
bool Map_Insert( MapPtr this, size_t id_empleado, float sueldo );

/**
 * @brief Busca y devuelve el valor asociado a la clave.
 *
 * Esta función debe pensarse de la siguiente manera:
 *
 * sueldo = table[ id_empleado ]
 *
 * @param this        Referencia a un objeto Map.
 * @param id_empleado Índice del registro (key).
 * @param sueldo      Aquí se guardará el valor del registro (value).
 *
 * @return true si el valor asociado a la clave está en almacenado en la tabla. false en cualquier otro caso (sueldo no está definido para esta situación).
 */
bool Map_Retrieve( MapPtr this, size_t id_empleado, float* sueldo );


/**
 * @brief Elimina el registro asociado a la clave.
 *
 * @param this        Referencia a un objeto Map.
 * @param id_empleado Índice del registro (key).
 *
 * @return true si el registro existía. false en cualquier otro caso.
 */
bool Map_Remove( MapPtr this, size_t id_empleado );

/**
 * @brief Itera sobre todos los elementos del mapa, aplicando pfun() en cada uno
 * de ellos.
 *
 * @param this Referencia a un objeto Map.
 * @param pfun Función inyectada que operará sobre cada uno de los elementos del
 * mapa. 
 *
 * @return El número de elementos recorridos. 
 */
size_t Map_Iterator( MapPtr this, void (*pfun)( size_t id, float sueldo ) );


/**
 * @brief Devuelve el número de elementos actualmente almacenados en la tabla.
 *
 * @param this Referencia a un objeto Map.
 *
 * @return El número de elementos actualmente almacenados en la tabla.
 */
size_t Map_Len( MapPtr this );

/**
 * @brief Devuelve el número máximo de elementos que se pueden almacenar en la tabla.
 *
 * @param this Referencia a un objeto Map.
 *
 * @return El número máximo de elementos que se pueden almacenar en la tabla.
 */
size_t Map_Size( MapPtr this );

#endif   /* ----- #ifndef MAP_INC  ----- */
