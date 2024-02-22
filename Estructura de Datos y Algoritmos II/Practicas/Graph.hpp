#pragma once

#include <iostream>
// para cin, cout, cerr. (leer del teclado e imprimir en la pantalla)

#include <string>
// para declarar y procesar cadenas

#include <list>
// para los arreglos []

#include <map>
// para los diccionarios (tablas hash)

#include "Vertex.hpp"
// la clase Graph _usa_ a la clase Vertex

class Graph
{
  private: 
    std::map<std::string, Vertex> vertices; ///< lista de vértices en el grafo 
    // asociamos un vértice (value) a una cadena (key):
    // vertices[ string ] = a_vertex

    static size_t time;

  public:
    Graph();
    //  Graph( std::vector<Vertex> vertices );
      
    bool add_vertex( Vertex v );
    bool add_edge( std::string edge1, std::string edge2 );
      
    std::map<std::string, Vertex> get_vertices();
    // devuelve la "lista" de vértices (en realidad es una tabla hash), pero la podemos pensar de esa manera
    
    Vertex& get_vertex( std::string name );
    // devuelve el valor asociado a la clave 'name'; no queremos exponer que es un 'map'
    
    
    void print();
    
    static void clear_time(){ Graph::time = 0; }
    static void inc_time(){ ++Graph::time; }
    static size_t get_time(){ return Graph::time; }

    void bfs( std::string name );
    
    void dfs( std::string name );

    std::vector<int>* dfs_to( std::string name );
  };

  size_t Graph::time = 0;
 