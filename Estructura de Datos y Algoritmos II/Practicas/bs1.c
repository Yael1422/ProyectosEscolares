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
#include <string.h>
#include <stdbool.h>
#include <iso646.h>
#include <assert.h>

typedef struct
{
	char   nombre[32];
	size_t semestre;
	size_t ID;
	float  promedio;
} Alumno;

enum Atributos
{
	POR_NOMBRE,
	POR_SEMESTRE,
	POR_ID,
	POR_PROMEDIO,
};


void print_datos_uno( Alumno* a, char* text )
{
	printf( "%s: %ld, %s, %ld, %f\n\n",
		 text,
		 a->ID,
		 a->nombre,
		 a->semestre,
		 a->promedio );
}

void print_datos_muchos( Alumno grupo[], size_t tam )
{
	for( size_t i = 0; i < tam; ++i ){
		printf( "%ld, %s, %ld, %f\n",
			 grupo[ i ].ID,
			 grupo[ i ].nombre,
			 grupo[ i ].semestre,
			 grupo[ i ].promedio );
	}
	printf( "\n" );
}

void asignar( Alumno* destino, const Alumno* fuente ) //<1>
{
	strcpy( destino->nombre, fuente->nombre );
	destino->semestre = fuente->semestre;
	destino->ID = fuente->ID;
	destino->promedio = fuente->promedio;
}

void intercambiar( Alumno* primero, Alumno* segundo )
{
	Alumno tmp;

	asignar( &tmp, primero );
	asignar( primero, segundo );
	asignar( segundo, &tmp );
}

bool comparar_completo( const Alumno* primero, const Alumno* segundo )
{
	return strcmp( primero->nombre, segundo->nombre ) == 0 and
		primero->semestre == segundo->semestre and
		primero->ID == segundo->ID and
		primero->promedio == segundo->promedio;
}


bool es_igual( const Alumno* primero, const Alumno* segundo, int atributo )
{
	switch( atributo ){
		case POR_NOMBRE:    return strcmp( primero->nombre, segundo->nombre ) == 0;
		case POR_SEMESTRE:	return primero->semestre == segundo->semestre;
		case POR_ID:        return primero->ID == segundo->ID;
		case POR_PROMEDIO:  return primero->promedio == segundo->promedio;
		default:
			printf( "Atributo desconocido.\n" );
			assert( 0 );
	}
}

bool es_mayor( const Alumno* primero, const Alumno* segundo, int atributo )
{
	switch( atributo ){
		case POR_NOMBRE:    return strcmp( primero->nombre, segundo->nombre ) > 0;
		case POR_SEMESTRE:	return primero->semestre > segundo->semestre;
		case POR_ID:        return primero->ID > segundo->ID;
		case POR_PROMEDIO:  return primero->promedio > segundo->promedio;
		default:
			printf( "Atributo desconocido.\n" );
			assert( 0 );
	}
}

bool busqueda_sec_por_ID( Alumno list[], size_t len, size_t id, size_t* index )
{
	bool found = false;

	for(size_t i=0; i<len and found==false; ++i)
	{
		if(list[i].ID==id)
		{
			found=true;
			*index = i;
		}
	}
	return found;
}

bool busqueda_sec_por_Nombre( Alumno list[], size_t len, char* nombre, size_t* index )
{
	bool found = false;
	
	for(size_t i=0; i<len and found==false; ++i)
	{
		if( strcmp(list[i].nombre, nombre) != 0 );
		else
		{
			found = true;
			*index = i;
		}
	}
	return found;
}

#define MAX_GROUP 5
// nuestro grupo tendrá MAX_GROUP alumnos

int main()
{
	Alumno* grupo04=malloc( sizeof(Alumno) * MAX_GROUP );

	strcpy(grupo04[0].nombre, "Juan");
	grupo04[0].semestre=5;
	grupo04[0].ID=123;
	grupo04[0].promedio=7.4;
	
	strcpy(grupo04[1].nombre, "Pedro");
	grupo04[1].semestre=6;
	grupo04[1].ID=456;
	grupo04[1].promedio=7.0;

	strcpy(grupo04[2].nombre, "Maria");
	grupo04[2].semestre=1;
	grupo04[2].ID=789;
	grupo04[2].promedio=10;

	strcpy(grupo04[3].nombre, "Pancy");
	grupo04[3].semestre=9;
	grupo04[3].ID=135;
	grupo04[3].promedio=9.2;

	strcpy(grupo04[4].nombre, "Roca");
	grupo04[4].semestre=8;
	grupo04[4].ID=791;
	grupo04[4].promedio=4.1;


	//Busqueda secuencial por ID

	printf("Introduzca un ID para buscarlo en la lista:\n");
	size_t id;
	size_t index;
	scanf("%ld",&id);
	if( busqueda_sec_por_ID( grupo04, MAX_GROUP, id, &index ) == true )
	{
		print_datos_uno( &grupo04[index], "Found: " );
	}
	else
	{
		printf("No se encontro ninguna coincidencia\n");
	}
	
	
	//Busqueda secuencial por Nombre
	printf("Introduzca un Nombre para buscarlo en la lista:\n");
	
	char *cadena = (char *)malloc (30);
	scanf("%s", cadena);
	
	 if( busqueda_sec_por_Nombre( grupo04, MAX_GROUP, cadena, &index) == true )
	{
		print_datos_uno( &grupo04[index], "Found: " );
	}
	else
	{
		printf("No se encontro ninguna coincidencia\n");
	}
	
	
	free(grupo04);
}

