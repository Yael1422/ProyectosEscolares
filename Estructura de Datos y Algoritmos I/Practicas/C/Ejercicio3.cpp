#include<stdio.h>
#include<stdlib.h>
struct node{
	int dato;
	struct node *sig;
};
typedef struct node nodo;
struct tipocola{
	nodo *ini ;
	nodo *fin ;
	int tam;
};
void creacola(struct tipocola*q){
	q->ini=NULL;
	q->fin=NULL;
	q->tam=0;
}
int vacia(struct tipocola *q){
	if(q->ini==q->fin&&q->tam==0)
		return 0;
	else
		return 1;
}
int insertar(struct tipocola *q,int dato){
	nodo *nuevonodo;
	nuevonodo=(nodo*)malloc(sizeof(nodo));
	if(nuevonodo==NULL){
		printf("\nError al reservar memoria\n");
		return 1;
	}
	nuevonodo->dato=dato;
	nuevonodo->sig=NULL;
	if(!vacia(q)){
		q->fin=nuevonodo;
		q->ini=nuevonodo;
	}
	else{
	q->fin->sig=nuevonodo;
	q->fin=nuevonodo;
	}
	q->tam++;
	return 0;
}
int eliminar(struct tipocola *q){
	nodo *tmp;
	int dato;
	if(!vacia(q)){
		printf("\npila Vacia\n");
		return -1;
	}
	else{
		tmp=q->ini;
		if(q->ini==q->fin)
			creacola(q);
		else{
			q->ini=q->ini->sig;
			q->tam--;
		}
		dato=tmp->dato;
		free(tmp);
		return dato;
	}
}
void mostrar(struct tipocola  *q){
	nodo *tmp;
	int i;
	tmp=q->ini;
	for(i=0;i<q->tam;i++){
			printf("\n Dato= %d",tmp->dato);
			tmp=tmp->sig;
		}
}
main(){
	int opc,dato;
	struct tipocola co1a;
	creacola(&co1a);
	do{
		printf("\n\tCola con datos ligados\n 1) Insertar\n 2) Eliminar\n 3) Mostrar\n 4) Salir\n");
		scanf("%d",&opc);
		switch(opc){
			case 1:
				printf("Dato a insertar: ");
				scanf("%d",&dato);
				insertar(&co1a,dato);
				break;
			case 2:
				dato=eliminar(&co1a);
				printf("\n Dato fuera de la pila: %d\n",dato);
				break;
			case 3:
				printf("\n");
				mostrar(&co1a);
				printf("\n");
				break;
			case 4:
				break;
		}
	}while(opc<4&&opc>0);
	return 0;
}
