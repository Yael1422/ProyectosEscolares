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


#include <iostream>
// para cin, cout, cerr. (leer del teclado e imprimir en la pantalla)

#include <string>
// para declarar y procesar cadenas

#include <list>
// para los arreglos []

#include <map>
// para los diccionarios (tablas hash)


//----------------------------------------------------------------------
//  Class Vertex
//----------------------------------------------------------------------
class Vertex
{
public:
	enum class Colors { BLACK, GRAY, WHITE };

private:
	std::string name; ///< campo de texto. Se utiliza como key

	// aquí van más campos relacionados con la naturaleza de la información del
	// nodo. P. ej., Estudiante: promedio, semestre. Persona: dirección, edad;
	// etc.

	std::list<Vertex> neighbors; ///< lista de vértices adyacentes

	int distance{ 0 };

	Colors color{ Colors::BLACK };

	std::string predecesor;

public:
	Vertex( std::string name );

	std::string get_name() const;

	void add_neighbor( Vertex v );

	void print_neighbors();

	void set_distance( int distance );
	void set_color( Vertex::Colors color );
	void set_predecesor( std::string predecesor);

	int get_distance();
	Colors get_color();
	std::string get_predecesor();

	void print();
};

Vertex::Vertex( std::string _name ) : name{ _name }
{
	// nada (por el momento)
}

void Vertex::add_neighbor( Vertex v )
{
	this->neighbors.push_back( v );
}


std::string Vertex::get_name() const
{
	return this->name;
}

void Vertex::print_neighbors()
{
	for( auto v : this->neighbors ) 
		std::cout << v.get_name() << "-> ";
	std::cout << "Nil";
}

void Vertex::set_distance( int distance )
{
	this->distance = distance;
}
void Vertex::set_color( Vertex::Colors color )
{
	this->color = color;
}
void Vertex::set_predecesor( std::string predecesor)
{
	this->predecesor = predecesor;
}


int Vertex::get_distance()
{
	return this->distance;
}
Vertex::Colors Vertex::get_color()
{
	return this->color;
}
std::string Vertex::get_predecesor()
{
	return this->predecesor;
}

void Vertex::print()
{
	std::string color_as_string;

	switch( this->color ) 
	{
		case Vertex::Colors::BLACK: color_as_string = "BLACK"; break;
		case Vertex::Colors::GRAY: color_as_string = "GRAY"; break;
		case Vertex::Colors::WHITE: color_as_string = "WHITE"; break;
	}

	std::cout << "Nombe " << this->name << std::endl;
	std::cout << "Distancia " << this->distance << std::endl;
	std::cout << "Color " << color_as_string << std::endl;
	std::cout << "Predecesor " << this->predecesor << std::endl;

	print_neighbors();

}
//----------------------------------------------------------------------
//  Class Graph
//----------------------------------------------------------------------
class Graph
{
private:
	std::map<std::string, Vertex> vertices; ///< lista de vértices en el grafo
	// asociamos un vértice (value) a una cadena (key):
	// vertices[ string ] = a_vertex

public:
	Graph();
//	Graph( std::vector<Vertex> vertices ); 

	bool add_vertex( Vertex v );
	bool add_edge( std::string edge1, std::string edge2 );

	void print();
};

Graph::Graph()
{
	// nada (por el momento)
}

bool Graph::add_vertex( Vertex v )
{
	auto ret = vertices.insert( { v.get_name(), v } );
	// 'map' no permite duplicados, así que no hay necesidad de buscarlos
	
	return ret.second;
}

bool Graph::add_edge( std::string edge1, std::string edge2 )
{
	bool res = false;
	// uno, o ambos nodos, no existen

	auto v1 = this->vertices.find( edge1 );
	auto v2 = this->vertices.find( edge2 );

	if( v1 != this->vertices.end() and v2 != this->vertices.end() ){

		v1->second.add_neighbor( v2->second );
		v2->second.add_neighbor( v1->second );

		return true;
	}

	return res;
}

void Graph::print()
{
	for( auto v : this->vertices ){
		std::cout << "\n" << v.second.get_name() << ": ";
		v.second.print_neighbors();
	}
	std::cout << "\n";
}

bool Graph::add_edge_directed ( std::string edge1, std::string edge2 )
{
	bool resultado = false;

    auto v1 = this->vertices.find( edge1 );
    auto v2 = this->vertices.find( edge2 );
    
    if( v1 != this->vertices.end() and v2 != this->vertices.end() )
    {
        v1->second.add_neighbor( v2->second );
        return true;
	}
	
	return resultado;
}


void Graph::bsf(Graph g, Vertex start)
{
	std::list<Vertex*> q;
	
	for ( auto& v : this->vertices )
	{
		v.second.set_color( Vertex::Colors::BLACK );
		v.second.set_distance( 0 );
		v.second.set_predecesor( "Nil" );
	}
	
	for ( auto& m : this->vertices )
	{
		q.push_back ( &m.second ); break;
	}
	
	star.set_color ( Vertex::Colors::GRAY );

	while ( ! q.empty() )
	{
		Vertex* u = (q.front());
		std:: cout << " u: "; u->print();
		q.pop_front();
		
		for( Vertex w : u->get_neighbors())
		{
			std:: cout << " w: ";
			w.print();
			auto v1 = this->vertices.find( w.get_name() );
			Vertex* w1 = &( v1->second );
			
			if ( w1->get_color() == Vertex::Colors::BLACK )
			{
                w1->set_color( Vertex::Colors::GRAY );
                w1->set_distance( u->get_distance() + 1 );
                w1->set_predecesor( u->get_name() );
                q.push_back( w1 );
                std:: cout << " entro: ";
				w1->print();
			}
		}
		
		u->set_color( Vertex::Colors::WHITE );
		std::cout << "Fin del while" << std::endl;
	}
	
	for( auto v : this->vertices )
	{
        v.second.print();
	}
}
		
		
int main()
{
	Graph g;

	g.add_vertex( Vertex( "A" ) );
	g.add_vertex( Vertex( "B" ) );
	g.add_vertex( Vertex( "C" ) );
	g.add_vertex( Vertex( "D" ) );
	g.add_vertex( Vertex( "E" ) );
	g.add_vertex( Vertex( "F" ) );
	g.add_vertex( Vertex( "G" ) );
	g.add_vertex( Vertex( "H" ) );
	g.add_vertex( Vertex( "I" ) );
	g.add_vertex( Vertex( "J" ) );
	g.add_vertex( Vertex( "K" ) );
	

	g.add_edge( "A", "B" );
	g.add_edge( "A", "E" );
	g.add_edge( "B", "C" );
	g.add_edge( "B", "F" );
	g.add_edge( "D", "H" );
	g.add_edge( "E", "I" );
	g.add_edge( "F", "I" );
	g.add_edge( "F", "G" );
	g.add_edge( "B", "C" );
	g.add_edge( "G", "J" );
	g.add_edge( "G", "K" );
	g.add_edge( "K", "H" );
	

	g.print();

}
