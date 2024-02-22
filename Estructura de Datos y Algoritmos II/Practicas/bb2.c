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

#define MAX_GROUP 9


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


//Por ID
bool bbinaria_recur( Alumno list[], size_t inf, size_t sup, size_t key, size_t* index )
{
    size_t centro = ( sup + inf ) / 2;
    bool found = false;
    
    if( list[centro].ID == key )
    {
        found = true;
        *index=centro;
    }
    if( inf > sup)
    {
        found = false;
    }
    if( list[centro].ID < key )
    {
        bbinaria_recur( list, centro+1, sup, key, index );
    }
    if( list[centro].ID > key )
    {
        bbinaria_recur( list, inf, centro-1, key, index );
    }
    
    return found;
}


bool busqueda_bin_por_ID( Alumno list[], size_t len, size_t id, size_t* index )
{
	bool found;
	int inf=0;
	int sup=MAX_GROUP-1;
	
	if(bbinaria_recur(list, inf, sup, id, index)==true);
	{
		found = true;
	}
	return found;
	
}


//Por nombre
bool bbinaria_recur_nombre( Alumno list[], size_t inf, size_t sup, char* key, size_t* index )
{
    size_t centro = ( sup + inf ) / 2;
    bool found = false;
    
    if( inf > sup)
    {
        found = false;
    }
    
    int resultado = strcmp(key, list[centro].nombre);
    
    if( resultado == 0 )
    {
    	found = true;
        *index=centro;
    }
    if( resultado < 0 )
    {
    	bbinaria_recur_nombre( list, centro+1, sup, key, index );
    }
    if( resultado > 0 )
    {
        bbinaria_recur_nombre( list, inf, centro-1, key, index );
    }
    
    return found;
}


bool busqueda_bin_por_Nombre( Alumno list[], size_t len, char* nombre, size_t* index )
{
	bool found;
	int inf=0;
	int sup=MAX_GROUP-1;
	
	if(bbinaria_recur_nombre(list, inf, sup, nombre, index)==true);
	{
		found = true;
	}
	return found;
}


//Funciones necesarias para realizar ordenamiento
void swap( int* val1, int* val2 )
{
    int tmp=*val1;
    *val1=*val2;
    *val2=tmp;
}


void OrdenaBurbuja(Alumno list[], size_t len)
{
	 bool done=false;
    
    for(size_t i=0; i<len-1 && done==false;++i)
    {
        done=true;
        
        for(size_t j=len-1; j>i; --j)
        {
            if(list[j].ID < list[j-1].ID)
            {
                swap(&list[j].ID, &list[j-1].ID);
                done=false;
            }
        }
    }
}


void Ordena_Alumnos_por_ID(Alumno list[], size_t len )  //Metodo burbuja
{
   OrdenaBurbuja(list, len);
}


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

	strcpy(grupo04[3].nombre, "Zua");
	grupo04[3].semestre=9;
	grupo04[3].ID=135;
	grupo04[3].promedio=9.2;

	strcpy(grupo04[4].nombre, "Roca");
	grupo04[4].semestre=8;
	grupo04[4].ID=791;
	grupo04[4].promedio=4.1;
    
    strcpy(grupo04[5].nombre, "Roberto");
    grupo04[5].semestre=1;
    grupo04[5].ID=321;
    grupo04[5].promedio=3.2;
    
    strcpy(grupo04[6].nombre, "Manolo");
    grupo04[6].semestre=4;
    grupo04[6].ID=654;
    grupo04[6].promedio=8.2;
    
    strcpy(grupo04[7].nombre, "Rosalia");
    grupo04[7].semestre=10;
    grupo04[7].ID=987;
    grupo04[7].promedio=6.4;
    
    strcpy(grupo04[8].nombre, "Nando");
    grupo04[8].semestre=2;
    grupo04[8].ID=531;
    grupo04[8].promedio=9.9;

    
    //Ordenando los datos de manera manual
    Alumno* grupo04ord=malloc( sizeof(Alumno) * MAX_GROUP );
    
    strcpy(grupo04ord[0].nombre, "Juan");
    grupo04ord[0].semestre=5;
    grupo04ord[0].ID=123;
    grupo04ord[0].promedio=7.4;
    
    strcpy(grupo04ord[1].nombre, "Zua");
    grupo04ord[1].semestre=9;
    grupo04ord[1].ID=135;
    grupo04ord[1].promedio=9.2;
    
    strcpy(grupo04ord[2].nombre, "Roberto");
    grupo04ord[2].semestre=1;
    grupo04ord[2].ID=321;
    grupo04ord[2].promedio=3.2;
    
    strcpy(grupo04ord[3].nombre, "Pedro");
    grupo04ord[3].semestre=6;
    grupo04ord[3].ID=456;
    grupo04ord[3].promedio=7.0;
    
    strcpy(grupo04ord[4].nombre, "Nando");
    grupo04ord[4].semestre=2;
    grupo04ord[4].ID=531;
    grupo04ord[4].promedio=9.9;
    
    strcpy(grupo04ord[5].nombre, "Manolo");
    grupo04ord[5].semestre=4;
    grupo04ord[5].ID=654;
    grupo04ord[5].promedio=8.2;
    
    strcpy(grupo04ord[6].nombre, "Maria");
    grupo04ord[6].semestre=1;
    grupo04ord[6].ID=789;
    grupo04ord[6].promedio=10;
    
    strcpy(grupo04ord[7].nombre, "Roca");
    grupo04ord[7].semestre=8;
    grupo04ord[7].ID=791;
    grupo04ord[7].promedio=4.1;
    
    strcpy(grupo04ord[8].nombre, "Rosalia");
    grupo04ord[8].semestre=10;
    grupo04ord[8].ID=987;
    grupo04ord[8].promedio=6.4;

    
	//Busqueda Binaria por ID
	printf("Introduzca un ID para buscarlo en la lista:\n");
	size_t id;
	size_t index;
	scanf("%ld",&id);
	if( busqueda_bin_por_ID( grupo04ord, MAX_GROUP, id, &index ) == true )
	{
		print_datos_uno( &grupo04ord[index], "Found: " );
	}
	else
	{
		printf("No se encontro ninguna coincidencia\n");
	}


	//Ordenamiento de grupo (Metodo Bubble Sort)
	Ordena_Alumnos_por_ID(grupo04, MAX_GROUP);
	printf("\nOrdenando grupo por ID\n");
	for(int i=0; i< MAX_GROUP;i++)
	{
		print_datos_uno( &grupo04ord[i], "Alumno" );
	}
	
	
	//Busqueda Binaria por Nombre
	printf("\nIntroduce un nombre para buscarlo en la lista:\n");
	char *cadena = (char *)malloc (30);
	scanf("%s", cadena);
	
	 if( busqueda_bin_por_Nombre( grupo04, MAX_GROUP, cadena, &index) == true )
	{
		print_datos_uno( &grupo04[index], "Found: " );
	}
	else
	{
		printf("No se encontro ninguna coincidencia\n");
	}
	
	
	free(grupo04);
    free(grupo04ord);
	
}

