#include <iostream>
#include <vector>
#include <string>

struct Alumno
{
	char nombre[32];
	int semestre;
	float promedio;

	friend std::ostream& operator << ( std::ostream& ios, const Alumno item );
	
};

std::ostream& operator<<(std::ostream& ios, const Alumno item)
{
	std::cout << "\n";
	std::cout << "Nombre: " << item.nombre << std::endl;
	std::cout << "Semestre: " << item.semestre << std::endl;
	std::cout << "Promedio: " << item.promedio << std::endl;
	
	return ios;
}

int menu()
{
	while( 1 )
	{
		std::cout << "\n";
		std::cout << "0) Salir\n";
		std::cout << "1) Imprimir Lista\n";
		std::cout << "2) Agregar un registro\n";
		std::cout << "3) Editar un elemento\n";
		std::cout << "4) Guardar en XML\n";
		std::cout << "5) Leer XML bruto\n";
		std::cout << "6) Guardar en formato CSV\n";
		std::cout << "7) Leer en formato CSV\n";
		std::cout << "8) Guardar en formato binario\n";
		std::cout << "9) Leer en formato binario\n";

		int opcion;
		std::cout << "$ \n";
		std::cin >> opcion;

		if( 0 <= opcion and opcion <= 4 ) {
			return opcion;
		} else{
			std::cout << "Opción no válida\n";
		}
	}
	return 0;
}

/*
int imprimir( std::vector lista ) 
{
				
}

int editar( std::vector lista )
{
}

int agregar( std::vector lista )
{
}


bool guardarXML ( FILE* handler, const std::vector lista)
{
	
}

bool leerXML ( FILE* handler, std::vector lista)
{
	
}



bool guardarCSV ( FILE* handler, const std::vector lista)
{
	
}

bool leerCSV ( FILE* handler, std::vector lista)
{
	
}



bool guardarBin ( FILE* handler, const std::vector lista)
{
	
}

bool leerBin ( FILE* handler, std::vector lista)
{
	
}

*/

int main()
{
	std::vector<Alumno> grupo04;

	grupo04.push_back( Alumno { "Homero Simpson", 6, 5.0 } );
	grupo04.push_back( Alumno { "Lisa Simpson", 10, 10.0 } );
	grupo04.push_back( Alumno { "Bart Simpson", 4, 7.5 } );

	std::string base_name;
	
	std::cout << "Introduce el nombre del archivo:	";
	std::cin >> base_name;
	printf("%s\n", base_name.c_str() );
	
	while( 1 )
	{
		switch( menu() ){
			
			case 0: return 0;
			
			case 1: 
				for( auto a : grupo04 ){ std::cout <<a; }	
				break;
			
			case 2:
				std::cout << "Pendiente...n";
				break;
			
			case 3:
				std::cout << "Pendiente...n";
				break;
			
			case 4:
			{
				std::string file_name = base_name + ".xml";
				FILE* file_out = fopen( file_name.c_str(), "w" );
				
				if( file_out == NULL ) { 
					std:: cout << "Error abriendo el archivo\n"; 
				} else{
					char cadenota[1024];
					
					for( auto a : grupo04 ){
						snprintf( cadenota, 1023,
								"<alumno>\n" 
								"\t<nombre> %s </nombre>\n"
								"\t<semestre> %d </semestre>\n"
								"\t<promedio> %0.2f </promedio>\n"
								"</alumno>\n",
								a.nombre, a.semestre, a.promedio );

						fputs( cadenota, file_out );
					}
					fclose( file_out );
				}
			}
				break;
			default:
				break;
		}
	}

}
