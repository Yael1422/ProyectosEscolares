
#include <stdio.h>
// para las operaciones con archivos 

#include <string.h>
// para memset()

#include <stdlib.h>
// para exit()


int main()
{
   char nombre_archivo[ 80 ];

   printf( "Introduzca el nombre del archivo de trabajo\n$ " );
   scanf( "%s", nombre_archivo );

   FILE* file_out = fopen( nombre_archivo, "w" );

   if( file_out == NULL ){
      printf( "El archivo %s no pudo ser abierto para escritura.\n", nombre_archivo );
      exit( -1 );
   }

   char name[80] = "Homer J Simpson";
   int age = 40;
   float income = 2000.5;
   int children = 3;

   fprintf( file_out, "%s,%d,%.2f,%d\n", name, age, income, children ); //<1>

   fclose( file_out );


   FILE* file_in = fopen( nombre_archivo, "r" );

   if( file_in == NULL ){
      printf( "El archivo %s no pudo ser abierto para lectura.\n", nombre_archivo );
      exit( -1 );
   }

   memset( name, 0, 80 );
   age = 0;
   income = 0.0f;
   children = 0;

   fscanf( file_in, "%79[^,],%d,%f,%d\n", name, &age, &income, &children ); //<2>

   printf( "%s,%d,%f,%d\n", name, age, income, children );

   fclose( file_in );
}
