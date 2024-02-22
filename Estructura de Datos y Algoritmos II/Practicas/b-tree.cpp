#include <iostream>
// para std::cout y std::cin

#include <utility>
// para std::pair

#include <math.h>


const size_t m_order = 4;
// orden máximo (máximo número de hijos en el nodo) porque así está definido en
// los libros. Internamente al programa utilizamos en número de claves


// no la vamos a usar en este ejemplo, pero la he dejado aquí para futuras actualizaciones
struct Item
{
   int key;
};



//----------------------------------------------------------------------
//  Class Node
//----------------------------------------------------------------------
struct Node
{
	Node();
   	// constructor por defecto: pondrá a ceros a keys y children. Es muy probable
   	// que esto no sea necesario, pero lo haremos por seguridad

   	int keys[ m_order ];
   	// las primeras m_order - 1 entradas son válidas; la última entrada se usa
   	// cuando se parte el nodo (según [DESHPANDE03]).

   	Node* children[ m_order + 1 ];
   	// siempre hay un hijo más que claves

   	size_t cnt = 0;
   	// lleva la cuenta de las claves insertadas en el nodo

   	bool leaf = true;

   	static const size_t max = m_order - 1;
   	// número máximo de CLAVES en el nodo

    static const size_t min = max / 2;

   	// número mínimo de CLAVES en el nodo

    bool is_full();

    friend class B_tree;
};

bool Node::is_full(){
    return cnt < max;
}

Node::Node()
{
   for( int k : this->keys ) k = 0;
   for( auto c : this->children ) c = nullptr;
}

//----------------------------------------------------------------------
//  Class B_tree
//----------------------------------------------------------------------
class B_tree
{
private:
   Node* root = nullptr;

   size_t len = 0L;
   // cantidad de nodos actualmente en el árbol

   size_t max = 0;
   // número de hijos por nodo

   // las siguientes funciones son todas recursivas

   Node* insert_node( Node* node, int key );
   Node* split_node( Node* node, size_t index );
   Node* delete_node( Node* node, int key );
   std::pair<Node*, size_t> seek_node( Node* node, int key );
   void traverse_node( Node* node, void (*visit)( int key ) );
   void delete_tree( Node* node );

public:
   explicit B_tree( size_t m_order );
   ~B_tree();


   // las siguientes funciones son todas activadoras

   bool Insert( int key );
   bool Delete( int key );
   bool Seek( int key );
   void Traverse( void (*visit)(int key) );
   void Delete_all();
};

B_tree::B_tree( size_t m_order ) : max{ m_order }
{
   // nada (por el momento)
}

B_tree::~B_tree()
{
   // llamar a ::Delete_all()
}

bool B_tree::Insert( int key )
{
    if( this->root == nullptr)
	{
        this->root = new Node();
        this->root->keys[ 0 ] = key;
        this->root->cnt = 1;
    }
    else
    {
	    if(this->root->cnt == max)
	    {
            Node* tmp = this->root;

            this->root = new Node();
            this->root->children[0] = tmp;
            this->root->leaf = false;
            this->root = split_node( root, 0 );
        }
        this->root = insert_node( root, key );
	}

    return( this->root != nullptr);
}

Node* B_tree::insert_node( Node* node, int key )
{
    size_t i = node->cnt;

    if (node->leaf == true )
	{
    	while( i>= 0 && key < node->keys [ i - 1 ])
		{
            node->keys[ i ] = node->keys [ i - 1 ];
            i--;
        }
        node->keys[ i ] = key;
        node->cnt++;

    }
    else
	{
        while( i >= 0 && key < node->keys [ i-1 ])
		{
			i--;
		}
        if( node->children[ i ]->cnt == max)
		{
            node->leaf = false;
            split_node( node, i );
            if( key > node->keys[ i ] ){ i++; }
        }
        insert_node( node->children[ i ], key );
    }
    return node;
}

Node* B_tree::split_node( Node* parent, size_t index )
{
    int min =( m_order / 2);
    Node * left;
    left = parent->children[ index ];
    // left es un apuntador

    Node * right = new Node();
    right->leaf = left->leaf;
    right->cnt = min;

    for(int j=0;j < parent->min; j++)
	{
		right->keys[ j ] = left->keys [ j + min +1 ];
	}

    if (left->leaf == false)
	{
        for(int j=0;j <= parent->min ; j++)
		{
			right->children [ j ] = left->children[ j + min + 1 ];
		}
    }
    left->cnt = min;
    int j = parent->cnt + index;

    while( j > index )
	{
        parent->children [ j + 1 ] = parent->children[ j ];
        j--;
    }
    parent->children[ index + 1 ] = right;
    j = parent->cnt + index;

    while( j > index )
	{
        parent->keys[ j ] = parent->keys[ j - 1 ];
        j--;
    }
    parent->keys[ index ] = left->keys[ min ];
    ++parent->cnt;

    return parent;

}


void B_tree::Traverse( void (*visit)(int key) )
{
	if( root != nullptr )
	{
    	traverse_node( root, visit );
  	}
	else
	{
		std::cout << "Árbol vacío\n";
	}
}

void B_tree::traverse_node( Node* node, void (*visit)( int key ) )
{
 	if( node->leaf == true )
	{
    	for( size_t i = 0; i < node->cnt; ++i )
		{
        	visit( node->keys[ i ] );
      	}
   	}
   	else
	{
		for( size_t j = 0; j <= node->cnt; ++j )
		{
         	traverse_node( node->children[ j ], visit );
        	if( j < node->cnt )
        	{
            	visit( node->keys[ j ] );
    		}
   		}
	}
}

void B_tree::Delete_all()
{
	if (this->root != nullptr)
	{
        delete_tree( this->root );
    }
}

void B_tree::delete_tree( Node* node )
{
    if( node->leaf == true )
	{
        free( node );
    }
	else
	{
    	int i=0;
        while( node->children[ i ] != nullptr)
		{
            delete_tree( node->children[ i ]);
            node->children[ i ] = nullptr;
            i++;
        }
        free( node );
    }
}

bool B_tree::Delete( int key )
{
}

int main()
{
    B_tree arbol( m_order );

    while( 1 )
	{
    	int key;
    	std::cout << "$ ";
    	std::cin >> key;

    	if( key >= 0 )
		{
      		arbol.Insert( key );
      		arbol.Traverse( [](int key){ std::cout << key << ", "; } );
      		std::cout << "\n";
    	}
		else
		{
    	  	return 0;
    	}
  	}

	#if 0
 	int keys[] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130, 140, 150, 160, 170, 180, 190, 200, 210, 220, 230, 240, 250, 260 };

  	for( int k : keys )
	{
    	arbol.Insert( k );
  	}
	#endif
}
