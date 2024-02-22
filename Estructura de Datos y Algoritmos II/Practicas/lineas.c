
#include <stdio.h>
// para las operaciones con archivos

#include <stdlib.h>
// para exit()


int main()
{
   char nombre_entrada[ 80 ];
   printf( "Introduzca el nombre del archivo de entrada\n$ " );
   scanf( "%s", nombre_entrada );

   FILE* file_in = fopen( nombre_entrada, "r" );

   if( file_in == NULL ){
      printf( "El archivo %s no pudo ser abierto.\n", nombre_entrada );
      exit( -1 );
   }

   char nombre_salida[ 80 ];
   printf( "Introduzca el nombre del archivo de salida\n$ " );
   scanf( "%s", nombre_salida );

   FILE* file_out = fopen( nombre_salida, "w" );

   if( file_out == NULL ){
      printf( "El archivo %s no pudo ser abierto.\n", nombre_salida );
      exit( -1 );
   }

   char texto[ 81 ];
   while( !feof( file_in ) ){
      fgets( texto, 81, file_in );
      fputs( texto, file_out );
   }

   fclose( file_in );
   fclose( file_out );
}
