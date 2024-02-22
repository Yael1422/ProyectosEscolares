#include<stdio.h>
#include<stdlib.h>

struct Alumno
{
	char *nom;
	int numCuenta;
	int edad;
};

typedef struct Alumno alumnos;

struct node
{
   struct Alumno dato;
   struct node  *sig;
};

typedef struct node nodo;

struct tipoLista
{
	nodo *ini;
	nodo *fin;
	int tam;
};

typedef struct tipoLista lista;

void creaLista(lista *lis)
{
    lis->ini=NULL;
    lis->fin=NULL;
    lis->tam=0;    
}

int vacia(lista *lis)
{
	if(lis->ini==NULL && lis->fin==NULL && lis->tam==0)
	   return 0;
	else
	    return 1;
}

alumnos llenarDatos(alumnos dato)
{
	dato.nom=(char*)malloc(sizeof(char));
	printf("Ingresa nombre: ");
	gets(dato.nom);
	//scanf("%s",&dato.nom);
	printf("Numero de cuenta: ");
	scanf("%d",&dato.numCuenta);
	printf("Edad: ");
	scanf("%d",&dato.edad);
	return dato;
}

int insertarInicio (lista *lis, alumnos dato)
{
	nodo *nuevoNodo;
	nuevoNodo=(nodo *)malloc(sizeof(nodo));
	if(nuevoNodo==NULL)
	{
 		return 1;
	}  
	nuevoNodo->dato=dato;
    if( !vacia(lis))
	{
		nuevoNodo->sig=NULL;
    	lis->fin=nuevoNodo;
		lis->ini=nuevoNodo;		
    }
    else
	{
    	nuevoNodo->sig=lis->ini;
	   	lis->ini=nuevoNodo;	
    }
       	
	lis->tam++;
    return 0;
}

int  insertarFinal(lista *lis, alumnos dato)
{
    nodo  *nuevoNodo;
   
    nuevoNodo=(nodo *)malloc(sizeof(nodo));
    if(nuevoNodo==NULL)
	{
  	  return 1;
    }  
    
	nuevoNodo->dato=dato;
    nuevoNodo->sig=NULL;

	if( !vacia(lis))
	{

    	lis->fin=nuevoNodo;
        lis->ini=nuevoNodo;

    }
    else
	{
        lis->fin->sig=nuevoNodo;
        lis->fin=nuevoNodo;
    }
    lis->tam++;
    return 0;
}

int insertarPos(lista *lis, alumnos dato, int pos )
{
	int i;
	nodo *tmp, *nuevoNodo;

    if(pos < 0 || pos >lis->tam)
	{
    	printf("esa posición no existe debe ser de 1 a %d", lis->tam);
    	return -1;
    }
    
	nuevoNodo=(nodo *)malloc(sizeof(nodo));
    if(nuevoNodo==NULL)
	{
       	return -2;
    }  
    nuevoNodo->dato=dato;
    tmp=lis->ini;
    
	for(i=1;i<=pos;i++)
	{
    	tmp=tmp->sig;
    }
    if(tmp->sig==NULL)
	{
    	printf("\n usar insertar al final");   
        return -1;
    }
    nuevoNodo->sig=tmp->sig;
    tmp->sig=nuevoNodo;
    lis->tam++;
    return 0;
}

alumnos eliminarInicio(lista *lis)
{
	nodo *tmp;
	alumnos dato;
	if(!vacia(lis))
	    printf("Pila vacia\n");
	    
	tmp=lis->ini;
       
	if(lis->ini==lis->fin)
	    creaLista(lis);
	
	else
	{
    	lis->ini=lis->ini->sig;
	   	lis->tam--;	
	}
	 
 	lis->tam--;
    dato=tmp->dato;
	free(tmp);
	return  dato;
}

alumnos eliminarPos(lista *lis, int pos)
{
	nodo *tmp,*actual;
    alumnos dato;
    int i;

    if(!vacia(lis))
	{
    	printf("\n lista vacía");
    }
    
	if(pos < 0 || pos > lis->tam) 
	{
    	printf ("\nPosicion no valida");
    }
    
	if(lis->ini==lis->fin)
    	creaLista(lis);
    else
	{      
    	tmp=lis->ini;
        for(i=1;i<=pos;i++)
            tmp=tmp->sig;
        if(tmp->sig==NULL)
		{
            printf("\nLa posicion dada es de ultimo elemento, para borrarlo colocar posicion del penultimo");
        }
        tmp=actual->sig;
        actual->sig=actual->sig->sig;
        lis->tam--;  
    }
    dato=tmp->dato;
    free(tmp);
    return  dato;
}

void mostrar( lista *lis, alumnos dato )
{
	int i=1;
	nodo *tmp;
	tmp=lis->ini;
	while(tmp!=NULL)
	{
		printf("\nAlumno %d\n\n",i);
		printf("\n Nombre: %s ",tmp->dato.nom);
		printf("\n Numero de cuenta: %d ",tmp->dato.numCuenta);
		printf("\n Edad: %d ",tmp->dato.edad);
		tmp=tmp->sig;
		i++;
	}	
}

void Buscar(lista *lis, int ncb, alumnos dato)
{
	int i=1,j;
	nodo *tmp;
	tmp=lis->ini;
	while(tmp!=NULL){
		if(ncb==tmp->dato.numCuenta){
			printf("\nAlumno en la posicion: %d",i);
			printf("\nNumero de cuenta: %d",tmp->dato.numCuenta);
			printf("\nNombre: %s",tmp->dato.nom);
			printf("\nEdad: %d",tmp->dato.edad);
		}
		i++;
		tmp=tmp->sig;
	}
}

void eliminarlista(lista *lis)
{
	while(lis->ini!=NULL)
	{
 		free(lis);
 		lis->ini=lis->ini->sig;
	}
}

int main()
{
	alumnos datos,dato;
	lista l1;
	int opc=6,op,pos,i,ncb;
	creaLista(&l1);
	do
 	{ 
		printf("\n");
	 	printf("1) Insertar un elemento \n");
	 	printf("2) Suprimir un elemento\n");
	 	printf("3) Buscar elemento \n");
	 	printf("4) Mostrar todos los  Elementos de la lista\n");
	 	printf("5) Eliminar todos los  Elementos de la lista\n");
	 	printf("6) Salida\n");
	 	fflush(stdin);
	 	printf("Dame Opcion:\n");
	 	scanf("%d",&opc);
     	fflush(stdin);
     	printf("opcion %d", opc);
   		switch(opc)
  		{
   			case 1:
    			printf("\n 1) Insertar inicio \n 2) Fin  \n 3) Despues posicion dada\n " );
    			scanf("%d",&op);
    			dato=llenarDatos(datos);
     			if(op==1)
         			insertarInicio(&l1,dato);
     			if (op==2)
        			insertarFinal(&l1,dato);
     			if(op==3)
				 {
        			printf("\nIngresa posicion ");
        			scanf("%d",&pos);
        			insertarPos(&l1,dato,pos);
      			}  
 				break;
   			
			case 2:
          		printf("\n 1) Eliminar inicio \n 2) Eliminar dada una posicion ");
          		scanf("%d",&op);
         		if(op==1)
            		eliminarInicio(&l1);
         		if(op==2)
				{
             		printf("\nDame la pos ");
             		scanf("%d", &pos);
             		eliminarPos(&l1,pos);
          		}
 	  			break;
     			
			case 3:
       			printf("\n�Que numero de cuenta quieres buscar?\n");
       			scanf("%i",&ncb);
       			Buscar(&l1,ncb,dato);
    			break;

    		case 4:
     			printf("\n");
     			mostrar(&l1,dato);
 	 			break;
    		
			case 5:
    			eliminarlista(&l1);
    			printf("\nLista eliminada",dato);
    			break;
    
			case 6:
	   			break;	
    	} 
    	
 	}while(opc != 6 );
	
	return 0;
}
