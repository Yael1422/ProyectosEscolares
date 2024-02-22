#include<stdio.h>
#include<stdlib.h>
#define n 4
struct Cola{
	int ini,fin,numElem;
	int *fila;
};
typedef struct Cola tq;
tq* creaQ(){
	tq *q;
	q=(tq*)malloc(sizeof(tq));
	q->ini=0;
	q->fin=0;
	q->numElem=0;
	q->fila=(int*)malloc(n*sizeof(int));
	return q;
}
int llena(tq *q){
	if(q->ini==q->fin&&q->numElem==n)
		return 0;
	else
		return 1;
}
int vacia(tq *q){
	if(q->ini==q->fin&&q->numElem==0)
		return 0;
	else
		return 1;
}
void insertar(tq *q,int dato){
	if(!llena(q))
		printf("\nCola LLENA\n");
	else{
		q->fila[q->fin]=dato;
		q->fin=(q->fin+1)%n;
		q->numElem ++;
	}
}
void eliminar(tq *q){
	if(!vacia(q)){
		printf("\nCola Vacia\n");
	}
	else{
		printf("\n Dato fuera de la cola: %d\n",q->fila[q->ini]);
		q->ini=(q->ini+1)%n;
		q->numElem--;
	}
}
void imprimeCola(tq *q){
	int i;
	int indice=q->ini;
	if(!vacia(q)){
		printf("\nCola Vacia\n");
	}
	else{
		for(i=0;i<q->numElem;i++){
			printf("%d	",q->fila[indice]);
			indice=(indice+1)%n;
		}
	}
}
void liberaCola(tq *q){
	free(q->fila);
	free(q);
}
main(){
	int opc,dato;
	tq*cola;
	cola=creaQ();
	do{
		printf(" 1) Insertar a cola\n 2) Eliminar de cola\n 3) Muestra cola\n 4) Salir\n");
		scanf("%d",&opc);
		switch(opc){
			case 1:
				printf("Dato a insertar: ");
				scanf("%d",&dato);
				insertar(cola,dato);
				break;
			case 2:
				eliminar(cola);
				break;
			case 3:
				printf("\n");
				imprimeCola(cola);
				printf("\n");
				break;
			case 4:
				break;
		}
	}while(opc<4&&opc>0);
	liberaCola(cola);
	return 0;
}
