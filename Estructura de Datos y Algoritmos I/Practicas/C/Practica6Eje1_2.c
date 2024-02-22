#include<stdio.h>
#include<stdlib.h>

struct nodo
{
	char dato;
	struct nodo *sig
};

struct cola
{
	struct nodo *delante;
	struct nodo *atras;
};

void encolar(struct cola &q, char x, int pos)
{
	struct nodo *aux=crearNodo(x);
	
	if(pos==1)
	{
		if(q.delante==NULL)
		{
			aux->sig=q.delante;
			q.delante=aux;
			q.atras=aux;
		}
		else
		{
			aux->sig=q.delante;
			q.delante=aux;
		}
	}
	else
	{
		if(q.atras==NULL)
		{
			aux->sig=q.atras;
			q.delante=aux;
			q.atras=aux;
		}
		else
		{
			aux->sig=(q.atras)->sig;
			(q.atras)->sig=aux;
		}
		
	}
}

char desencolar(struct cola &q, int pos)
{
	char cc;
	struct nodo *aux=q.delante;
	
	if( pos==1 )
    {
          cc = (q.delante)->dato;
          q.delante = aux->sig;
          delete(aux);
    }
    else 
	{
          cc = (q.atras)->dato;
          
          while( aux->sig!=q.atras )
               aux = aux->sig;
               
          aux->sig = (q.atras)->sig;
          delete(q.atras);
          q.atras = aux;
    }
     
     return cc;
}

void muestraCola( struct cola q )
{
     struct nodo *aux;
     
     aux = q.delante;
          
     while( aux != NULL )
     {
            printf("%d", aux->dato);
            aux = aux->sig;
     }    
}

int main()
{
	struct cola q;
	
	q.delante=NULL;
	q.atras=NULL;
	
	char c,x;
	int op, pos;
	
	do
	{
		printf("¿Que quieres hacer?\n");
		printf("1)Insertar\n2)Eliminar\n3)Mostrar Cola\n4)Salir\n");
		scanf("%d",&op);
		
		switch(op)
		{
			case 1:
				printf("Inserta caracter\n");
				scanf("%c",c);
				
				printf("1)Insertar al inicio\n2)Insertar al final:\t\n");
				scanf("%d",&pos);
				
				encolar(q,c,pos);
				break;
			
			case 2:
				printf("1)Eliminar al inicio\n2)Eliminar al final:\t\n");
				scanf("%d",&pos);
				
				x=desencolar(q,pos);
				break;
				
			case 3:
				printf("\nTu cola es la siguiente\n");
				
				if(q.delante!=NULL)
				{
					muestraCola(q);
				}
				else
				{
					printf("Cola vacia\n");
				}
				break;
				
		}
	} while(op!=4);
}
