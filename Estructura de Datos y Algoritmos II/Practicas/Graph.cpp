#include "Graph.hpp"

Graph::Graph()
{
    // nada (por el momento)
}

bool Graph::add_vertex( Vertex v )
{
	auto ret = vertices.insert( { v.get_name(), v } );
	// 'map' no permite duplicados, así que no hay necesidad de buscarlos

	return ret.second;
}

bool Graph::add_edge( std::string edge1, std::string edge2 )
{
	bool res = false;
	// uno, o ambos nodos, no existen

	auto v1 = this->vertices.find( edge1 );
	auto v2 = this->vertices.find( edge2 );

	if( v1 != this->vertices.end() and v2 != this->vertices.end() )
	{
		v1->second.add_neighbor( v2->second );
        v2->second.add_neighbor( v1->second );
		
		res = true; 
	}
	
	return res; 
}

void Graph::print()
{
	for( auto v : this->vertices )
	{
		std::cout << "\n" << v.second.get_name() << ": "; 
		v.second.print_neighbors();
	}
    std::cout << "\n";
 }