#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <stdbool.h>
// bool, true, false
#include <iso646.h>
// and, or, not

 
#include <string>
#include <string.h>
#include <bits/stdc++.h> 
//Hora
#include <iomanip>
#include <ctime>
#include <sstream>
//#include "hora.cpp"
//FinHora




struct usuario{
	std::string nombre;
	long celular;
	std::string contrasenia;
	 /*
	  historial.push_back()
	 for (std::string x : historial) 
        cout << x << " ";

	  */
};

struct dato{
	int longitud;
	int numUsuarios;
};

#include "redimensionar.cpp"
#include "ordenar.cpp"
#include "Buscar.cpp"
#include "mapa.cpp"
#include "LecturayEscritura.cpp"
#include "lectura.cpp"



void registrarUsuario(int &numUsuarios, usuario *usus, int numElementos){
	int inf =0;
	int sup= numElementos - 1;
	std::string buscar;

	std:: cout <<"\nDime tu nombre de usuario\t";
	std:: cin>> buscar;

	int pos  =  Bbinaria_recursiva(usus, buscar, inf,sup,(sup+inf)/2);
	if(pos == -1){
		usus[numUsuarios].nombre = buscar;
		std:: cout << "\nDime tu número celular\t";
		std:: cin>> usus[numUsuarios].celular;

		std:: cout << "\nDime tu contrasenia\t";
		std:: cin>> usus[numUsuarios].contrasenia;

		std:: cout <<"\nRegistro exitoso\n";
		
		numUsuarios++;

	}else{
		std:: cout << "\nYA existe ese nombre de usuario";
	}

	
}



void ingresar(int numElementos, usuario *usus){
	int inf =0;
	int sup= numElementos - 1;

	std::string buscar;

	std:: cout <<"\nDime tu nombre de usuario\t";
	std:: cin>> buscar;

	int pos = 0;
	pos  =  Bbinaria_recursiva(usus, buscar, inf,sup,(sup+inf)/2);
	std:: cout <<"\n"<<usus[pos].nombre;
	if (pos != -1){
		std::string contrasenia = "";
		int intentos = 0;
		do{
			std:: cout <<"\nDime tu contrasenia \t";
			std:: cin>> contrasenia;
			std:: cout <<usus[pos].contrasenia;

			if((usus[pos].contrasenia).compare(contrasenia) == 0){
				intentos = 10;
			}else{
				std:: cout <<"\nContrasenia incorrecta intentos:" +intentos;
			}
			intentos++;
		}while(intentos < 3);
		//std:: cout<<"intentos: " <<intentos;
		if(intentos == 11){
			std:: cout <<"\nBienvenido" + buscar + "!!!";
			mapa();

		}else{
			std:: cout <<"\nse acabaron tus intentos!!!";
		}
		

	}else{
		std:: cout <<"\nUsuario "+ buscar + " no encontrado";
	}
}



void menu(usuario *usus, int &longitud, int &numUsuarios){
	char salir = 0;
	do{
		std::vector<std::string> opciones;
	 
		opciones.push_back("1)Registrar");
		opciones.push_back("2)Ingresar");
		opciones.push_back("3)Mostrar");
		opciones.push_back("4)Salir de la aplicación");
		opciones.push_back("Digite la opción \t");
		for (std::string x : opciones) {
	       	std::cout <<"\n"<< x;
		}
		int opc;
		std:: cin>>opc;
		switch (opc){
			case(1):{
				if((numUsuarios+1 ) == longitud){	redimensionar(usus, longitud);	}
				registrarUsuario(numUsuarios,usus,longitud+1);	
				Heap_Sort( usus, longitud);
				break;
			}
			case(2):{	ingresar(longitud+1,usus); break;}
			case(4):{	salir = 1; break;}
			case(3):{
				for(int i = 0; i < longitud ; i++){
					std::cout <<"\n"<<usus[i].nombre;
					std::cout <<"\t"<<usus[i].celular;
					std::cout <<"\t"<<usus[i].contrasenia;				 
				}
				break;
			}
		}



	  

	}while(salir == 0);


}
int main(){
	//std::cout<< horas()<<"\n";
	dato datos;

	datos.longitud = 5;
	datos.numUsuarios = 0;

	read_bin_datos( "aplicacion.bin", datos);

	int longitud = datos.longitud;
	int numUsuarios = datos.numUsuarios;

	usuario *usus  = new usuario[longitud];


	
	#pragma omp parallel for shared(usus, longitud)
	for(int i=0;i<longitud;++i){
		usus[i].nombre = "zzzzzzzzzzzzzzzzzzzzzzz";
		usus[i].celular = 99999999999;
		usus[i].contrasenia = "zzzzzzzzzzzzzzzzzzz";
	}
	inicio(usus,numUsuarios);


	

	menu(usus, longitud, numUsuarios);

	datos.longitud = longitud;
	datos.numUsuarios = numUsuarios;
	
	fin(usus,longitud);
	write_bin_datos( "aplicacion.bin", datos);	

}


