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
// para std::cout y std::cin

#include <utility>
// para std::pair


const size_t m_order = 20;
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
    Node* left;
    Node* right;

   static const size_t max = m_order - 1;
   // número máximo de CLAVES en el nodo

   static const size_t min = max / 2;
   // número mínimo de CLAVES en el nodo
};

Node::Node()
{
   /*Duda de porque tengo que comentarlo aqu�
   for( int k : this->keys ) k = 0;
   for( auto c : this->children ) c = nullptr;
   */
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

  if (this->root == nullptr){
      this->root = new Node;
      this->root->keys[0] = key;
      this->root->cnt = 1;
   } else {
      if (this->root->cnt == max){
         Node* tmp = this->root;     
        this->root = new Node();
        this->root->children[0] = tmp;
        this->root->leaf = false;
        this->root = split_node(this->root,0);
      }  
      this->root = insert_node(this->root,key); 

   }
return (this->root != nullptr);
}

Node* B_tree::insert_node( Node* node, int key )
{
  size_t i;
   i = node->cnt;
   if (node->leaf == true)
   {
          while (i>=0 and key< node->keys[i-1])
          {
          node->keys[i ] = node->keys [i -1];
          --i;
         }
      node->keys[i] = key;
      ++ node->cnt;
      // aqui se escribiria el nodo en el disco 
   } else {
         while ( i >= 0 and key < node->keys[i-1])
         {
          --i;
         // lee el disco
       }
       ++i;
      if (node->children[i]->cnt == max ){
        node->leaf = false;
        split_node(node, i);

      if (key > node->keys[i]){
         ++ i;
         }
       }
   insert_node(node->children[i],key);
   }
   return node;
}

Node* B_tree::split_node( Node* parent, size_t index )
{
 
parent->left = parent->children[index];
parent->right= new Node();
parent->right->leaf = parent->left->leaf;
parent->right->cnt = Node::min;
for (size_t j = 0 ; j< (Node::min) ; ++j){
   parent->right->keys[j] = parent->left->keys[j + (Node::min) +1];
}
if (parent->left->leaf == false){
   for (size_t j = 0 ; j<= (Node::min) ; ++j){
      parent->right->children[j] = parent->left->children[j + (Node::min) + 1];

   }
}
parent->left->cnt = Node::min;
size_t j= parent->cnt + index ;
while (j > index){
  parent->keys[j] = parent->keys[j-1];
  --j;
}
parent->keys[index] = parent->left->keys[Node::min];
++ parent->cnt;
return parent;
}

void B_tree::Traverse( void (*visit)(int key) )
{
 if( root != nullptr ){
    traverse_node( root, visit );
  } else{ std::cout << "Árbol vacío\n"; }
}

void B_tree::traverse_node( Node* node, void (*visit)( int key ) )
{
 if( node->leaf == true ){
      for( size_t i = 0; i < node->cnt; ++i ){
         visit( node->keys[ i ] );
      }
   } else{
      for( size_t i = 0; i <= node->cnt; ++i ){
         traverse_node( node->children[ i ], visit );
         if( i < node->cnt )
            visit( node->keys[ i ] );
      }
   }
}

void B_tree::Delete_all()
{
  if (this->root != nullptr){
   delete_tree(this->root);
}
}

void B_tree::delete_tree( Node* node )
{
  if (node->leaf == true){
      free(node);
   }else{
      size_t i= 0;
   while (node->children[i] != nullptr){
      delete_tree(node->children[i]);
      node->children[i]= nullptr;
      ++i;
   }
   free(node);
}

/*bool B_tree::Delete( int key )
{
}*/
}

int main(){
   B_tree arbol( m_order );

   while( 1 ){
    int key;
    std::cout << "$ ";
    std::cin >> key;

    if( key >= 0 ) {
      arbol.Insert( key );
      arbol.Traverse( [](int key){ std::cout << key << ", "; } );
      std::cout << "\n";
    } else{
      return 0;
    }
  }

#if 0 
  int keys[] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130, 140, 150, 160, 170,
    180, 190, 200, 210, 220, 230, 240, 250, 260 };

  for( int k : keys ){
    arbol.Insert( k );
  }
#endif  
}
