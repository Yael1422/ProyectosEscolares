
#include <stdio.h>
// para las operaciones con archivos 

#include <string.h>
// para strcpy()

#include <stdlib.h>
// para exit()

bool write_bin_datos( std::string nombre_base, const dato lista ){
	std::string file_name = nombre_base;
	FILE* file_out = fopen( file_name.c_str(), "wb" );
   if( file_out == NULL ){
      return false;
   }
   fwrite( &lista, sizeof( dato ), 1, file_out );
   fclose( file_out );
   return true;
}

bool read_bin_datos( std::string nombre_base, dato & lista ){
	std::string file_name = nombre_base;
	FILE* file_in = fopen( file_name.c_str(), "rb" );
   if( file_in == NULL ){
      return false;
   }
   fread( &lista, sizeof( dato ), 1, file_in );

   //for(auto a : lista){ std::cout<<a; }

   fclose( file_in );
   return true;
}

bool read_csv( std::string nombre_base, usuario *lista,int longitud ){
   std::string file_name = nombre_base +".csv";
   char nombre[79];
   char contrasenia[79];
   long m = 0;
   int cont = 0;

   FILE* file_in = fopen( file_name.c_str(), "r" );
   if( file_in == NULL ){
      return false;
   }
   //std::cout<<"\n"<<longitud<<"\n";
   while(cont<longitud){
      
      fscanf( file_in, "%79[^,],%ld,%79[^\n]", nombre, &m, contrasenia );
      //printf("%s %ld %s\n", nombre, m, contrasenia );
      lista[cont].nombre = std::string(nombre);
      lista[cont].celular = m;
      lista[cont].contrasenia = std::string(contrasenia);
      cont++;
   }
   fclose( file_in );
   return true;
}

bool write_csv( std::string nombre_base, const std::vector<usuario> lista ){
   std::string file_name = nombre_base +".csv";
   FILE* file_out = fopen( file_name.c_str(), "w" );
   if( file_out == NULL ){
       return false;
   }
   for (auto a: lista){
      fprintf( file_out, "%s,%ld,%s\n", (a.nombre).c_str(), a.celular, (a.contrasenia).c_str() );
   }
   fclose( file_out );
   return true;
}