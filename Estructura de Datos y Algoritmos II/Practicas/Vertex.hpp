#pragma once

#include <iostream>
// para cin, cout, cerr. (leer del teclado e imprimir en la pantalla)
 
#include <string>
// para declarar y procesar cadenas
  
#include <list>
// para las listas enlazadas

class Vertex
{
	public:
		enum class Colors { BLACK, GRAY, WHITE };
	
	private:
		std::string		name;  ///< campo de texto. Se utilizará como key

	// aquí van más campos relacionados con la naturaleza de la información del
	// nodo. P. ej., Estudiante: promedio, semestre. Persona: dirección, edad; 
	// etc.

	std::list<Vertex> neighbors; ///< lista de vértices adyacentes
	int	distance{ 0 };
    Colors	color{ Colors::BLACK }
    std::string	predecesor;

public:

	Vertex( std::string name ); 
	std::string get_name() const;
	void add_neighbor( Vertex v ); 
	void print_neighbors();
	
	void print();

	std::list<Vertex> get_neighbors();
	
	void set_distance( int distance );
	void set_color( Vertex::Colors color );
	void set_predecesor( std::string predecesor ); int get_distance();
	Colors get_color();
	std::string get_predecesor();

	void set_discovery_time( size_t time ){ this->discovery_time = time; }
	size_t get_discovery_time(){ return this->discovery_time; }

	void set_finish_time( size_t time){ this->finish_time = time; }
	size_t get_finish_time(){ return this->finish_time; }
    
    bool is_greater( Vertex& rhs )  //Indica cuando un vertice es mayor a otro
    {
    	return this->finish_time > rhs.finish_time;
    }
};