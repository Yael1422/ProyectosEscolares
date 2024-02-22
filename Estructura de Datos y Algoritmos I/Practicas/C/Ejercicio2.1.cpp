#include<stdio.h>
#include<stdlib.h>
#define a 5
struct nodo{
	float dato;
	struct nodo *sig;
};
struct pila{
	struct nodo *tope ;
	int numElem;
};
void creaPila(struct pila*s){
	s->tope=NULL;
	s->numElem=0;
}
int llena(struct pila*s){
	if(s->tope==NULL&&s->numElem==a)
		return 0;
	else
		return 1;
}
int vacia(struct pila*s){
	if(s->tope==NULL&&s->numElem==0)
		return 0;
	else
		return 1;
}
int push(struct pila *s,float dato){
	struct nodo *n;
	n=(struct nodo*)malloc(sizeof(struct nodo));
	if(n==NULL){
		printf("\nError al reservar memoria\n");
		return 1;
	}
	n->dato=dato;
	n->sig=s->tope;
	s->tope=n;
	s->numElem+=1;
	return 0;
}
float pop(struct pila*s){
	struct nodo *tmp;
	float dato;
	if(!vacia(s)){
		printf("\npila Vacia\n");
		return -1.0;
	}
	else{
		dato=s->tope->dato;
		tmp=s->tope;
		s->tope=s->tope->sig;
		s->numElem=1;
		free(tmp);
		return dato;
	}
}
int mostrar(struct pila*s){
	struct nodo *tmp;
	if (!vacia(s)){
		printf("\npila Vacia\n");
		return 1;
	}
		tmp=s->tope;
		do{
			printf("\n Dato= %f",tmp->dato);
			tmp=tmp->sig;
		}
		while(tmp!=NULL);
		return 0;
}
main(){
	float dato;
	struct pila pila1,pila2;
	creaPila(&pila1);
	creaPila(&pila2);
	printf("\nIntroduce dato: ");
	scanf("%f",&dato);
	push(&pila1,dato);
	dato=7.5;
	push(&pila1,dato);
	printf("\n\tPila 1:");
	mostrar(&pila1);
    dato=pop(&pila1);
	push(&pila2,dato);
	printf("\n\tPop realizado de pila 1 a pila 2:");
	printf("\n\tPila 2:");
	mostrar(&pila2);
}
