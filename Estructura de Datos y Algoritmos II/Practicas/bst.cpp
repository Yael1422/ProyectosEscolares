/*Copyright (C) 
 * 2019 - eda1 dot fiunam @ yahoo dot com dot mx
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


// para compilar:
//     g++ -Wall -std=c++99 -obst.out bst.cpp


#include <iostream>
// para cout, cin, y cerr


//----------------------------------------------------------------------
//  Class Item
//----------------------------------------------------------------------
struct Item
{
	int val = 0;
  // para simplificar hacemos que la 'info' sea p√∫blica

	Item();
	Item( int value );

	bool operator<( Item& rhs ) { return this->val < rhs.val; }
  // le ense√±amos a C++ a comparar objetos Item

	bool operator==( Item& rhs ) { return this->val == rhs.val; }
  // le ense√±amos a C++ a comparar objetos Item

	friend std::ostream& operator<<( std::ostream& os, const Item& item );
  // le ense√±amos a C++ a imprimir objetos Item
};

Item::Item( int value ) : val{ value }
{
	// nada
}

Item::Item() : val{ 0 }
{
	// nada
}

std::ostream& operator<<( std::ostream& os, const Item& item )
{
	os << item.val; 
	// permitimos que el objeto llamador formatee la salida, por eso no ponemos
	// espacios en blanco, saltos de l√≠nea, etc.

	return os;
}




//----------------------------------------------------------------------
//  Class Node
//----------------------------------------------------------------------
struct Node
{
	Item item;
	Node* left = nullptr;
	Node* right = nullptr;
};


//----------------------------------------------------------------------
//  Class Bst
//----------------------------------------------------------------------
class Bst
{
private:
	Node* root = nullptr;
	size_t len = 0L;

	Node* new_node( Item& item );
	Node* insert_node( Node* node, Item& item );

	Node* seek_node( Node* node, Item& item );
	void clear_all( Node* node );

	void inorder( Node* node, void (*pfun)( Item& ) );
	void preorder( Node* node, void (*pfun)( Item& ) );
	void postorder( Node* node, void (*pfun)( Item& ) );

public:
	enum class Dir { INORDER, PREORDER, POSTORDER };
  // la vamos a usar en la funci√≥n Traverse()

	Bst();
	~Bst();

	bool Insert( Item item );

	bool Remove( Item& item );

	bool Seek( Item& item );

	void Traverse( Bst::Dir dir, void (*pfun)( Item& item ) );

	void Delete_all();
};


//----------------------------------------------------------------------
//              Recursive and private functions
//----------------------------------------------------------------------

Node* Bst::new_node( Item& item )
{
	Node* n = new( Node );
	n->item = item;
	n->left = nullptr;
	n->right = nullptr;

	return n;
}

Node* Bst::insert_node( Node* node, Item& item )
{
    if( node == nullptr ){ node = new_node( item ); } 
	// es una hoja
	
	else if( item < node->item ){ node->left = insert_node( node->left, item ); }
	// buscamos en el ¡rbol izquierdo
	
	else{ node->right = insert_node( node->right, item ); }
	// buscamos en el ¡rbol derecho

	return node;
}

Node* Bst::seek_node( Node* node, Item& item )
{
	if (node->item == item)
	{
		return node;
	}
	else if(item < node->item)
	{
		return seek_node(node->left, item);
	}
	else{
		return seek_node(node->right, item);
	}
}

void Bst::clear_all( Node* node )
{
  if( node == nullptr ) return;

  clear_all( node->left );
  clear_all( node->right );
  //std::cerr << "Borrando: " << node->item << std::endl;
  delete node;
}

void Bst::inorder( Node* node, void (*visit)( Item& item ) )
{
	if( node != nullptr)
	{
		inorder(node->left, visit);
		(*visit)(node->item);
		inorder(node->right, visit);
	}
}

void Bst::preorder( Node* node, void (*visit)( Item& item ) )
{
	if( node != nullptr)
	{
		(*visit)(node->item);
		preorder(node->left, visit);
		preorder(node->right, visit);
	}
}

void Bst::postorder( Node* node, void (*visit)( Item& item ) )
{

	if( node != nullptr)
	{
		postorder(node->left, visit);
		postorder(node->right, visit);
		(*visit)(node->item);
	}
}

//----------------------------------------------------------------------
//                  Interfaz implementation
//----------------------------------------------------------------------
Bst::Bst() 
{
  // nada
}

Bst::~Bst()
{
  clear_all( this->root );
  // llamamos a clear_all
}

void Bst::Delete_all()
{
	clear_all( this->root );
  // llamamos a clear_all

  // reiniciamos los atributos de la clase
}


bool Bst::Insert( Item item )
{
  //if( Seek( item ) == true ){ return false; }
	// no se permiten duplicados!
	// øExistir· una mejor forma de hacerlo para no recorrer dos veces el ¡rbol?
	
  if( this->root != nullptr ) { insert_node( this->root, item ); }

  else{ this->root = new_node( item ); }
  // si el ¡rbol est· vacÌo, creamos el nodo raÌz
  // °Este paso es obligatorio, no nos lo podemos saltar!

	++this->len;

	return true;

}

bool Bst::Seek( Item& item )
{
  // buscamos si item ya est· en el ¡rbol
	Node* r = this->root;
    
    return seek_node(r, item) != nullptr;

  // TIP: usar a seek_node()

}

// recorremos el √°rbol en la direcci√≥n dada por dir. En cada nodo visitado aplicamos visit
void Bst::Traverse( Bst::Dir dir, void (*visit)( Item& item ) )
{

  if( this->root != nullptr ){
		switch( dir ){
			case Dir::INORDER:   inorder(   this->root, visit ); break;
			case Dir::PREORDER:  preorder(  this->root, visit ); break;
			case Dir::POSTORDER: postorder( this->root, visit ); break;
		}
	}

}

// esta es la funci√≥n que vamos a usar en cada 'visita'
void print( Item& item )
{
	std::cout << item.val << std::endl;

  // ¬øfunciona?
  // std::cout << item << std::endl;
}

int main()
{
	Bst arbol;

//  int datos[] = { 30, 15, 45, 7, 22, 37, 52, 4, 10, 18, 26, 34, 40 };
  int datos[] = { 100, 20, 200, 10, 30, 150, 300 };

  for( int x : datos ){ arbol.Insert( Item( x ) ); }

// muevan la siguiente l√≠nea conforme vayan avanzando con la escritura de las funciones

  std::cout << "\n=== INORDER ===\n";
	arbol.Traverse( Bst::Dir::INORDER, print );

  std::cout << "\n=== PREORDER ===\n";
	arbol.Traverse( Bst::Dir::PREORDER, [](Item& item){ std::cout << item << std::endl; } );

  std::cout << "\n=== POSTORDER ===\n";
	arbol.Traverse( Bst::Dir::POSTORDER, [](Item& item){ std::cout << item << std::endl; } );


  int val;
  std::cout << "Valor a buscar\n? ";
  std::cin >> val;

  Item item( val );

  std::cout << "El valor " << val << (arbol.Seek( item ) == true ? " s√≠ " : " no ") << "se encuentra\n";


  // ¬øy d√≥nde est√° el destructor?

}
