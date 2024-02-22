#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define a 5
struct nodo{
	char dato;
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
int mostrar(struct pila*s){
	struct nodo *tmp;
		tmp=s->tope;
		do{
			printf("%c",tmp->dato);
			tmp=tmp->sig;
		}
		while(tmp!=NULL);
		return 0;
}
main(){
	struct pila pila1,pila2;
	int opc,i,cantletras;
	char palabra[30],dato;
	printf("\n Este programa invierte cadenas mediante pilas de datos ligados.");
	do{
		printf("\n 1) Invertir una palabra\n 2) Salir\n");
		scanf("%d",&opc);
		switch(opc){
			case 1:
				getchar();
				printf("\n Ingrese la palabra que desea invertir: ");
				gets(palabra);
				cantletras=strlen(palabra);
				creaPila(&pila1);
				creaPila(&pila2);
				for(i=0;i<cantletras;i++){
					push(&pila1,palabra[i]);	
				}
				printf("\n La cadena a invertir es:\t");
				printf("%s",palabra);
				printf("\n La cadena invertida es:\t");
				mostrar(&pila1);
			case 2:
					break;
		}
	}while(opc<2&&opc>0);
	return 0;
}
