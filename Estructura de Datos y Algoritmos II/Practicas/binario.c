
#include <stdio.h>
// para las operaciones con archivos 

#include <string.h>
// para strcpy()

#include <stdlib.h>
// para exit()

typedef struct Item
{
   char name[80];
   int age;
   float income;
   int children;
} Item;

int main()
{
   char nombre_archivo[ 80 ];

   printf( "Introduzca el nombre del archivo de trabajo\n$ " );
   scanf( "%s", nombre_archivo );

   FILE* file_out = fopen( nombre_archivo, "wb" ); //<1>

   if( file_out == NULL ){
      printf( "El archivo %s no pudo ser abierto para escritura.\n", nombre_archivo );
      exit( -1 );
   }

   Item person;

   strcpy( person.name, "Homer J Simpson" );
   person.age = 40;
   person.income = 2000.5;
   person.children = 3;

   fwrite( &person, sizeof( Item ), 1, file_out ); //<2>

   fclose( file_out );


   FILE* file_in = fopen( nombre_archivo, "rb" ); //<3>

   if( file_in == NULL ){
      printf( "El archivo %s no pudo ser abierto para lectura.\n", nombre_archivo );
      exit( -1 );
   }

   Item other_person;

   fread( &other_person, sizeof( Item ), 1, file_in ); //<4>

   printf( "%s,%d,%f,%d\n", 
         other_person.name, 
         other_person.age, 
         other_person.income, 
         other_person.children );

   fclose( file_in );
}
