#include <stdio.h>
#include <math.h>
struct punto{
float x;
float y;
};
void creaPunto(struct punto *p,int i);
void imprimeP(struct punto p);
void sumaP(struct punto *p1,struct punto *p2,struct punto *p3,int i);
void distancia(struct punto *p1,struct punto *p2,int i);
int main(){
struct punto p1,p2,p3; 
    creaPunto(&p1,1);
    creaPunto(&p2,2);
    imprimeP(p1);
    imprimeP(p2);
    sumaP(&p1,&p2,&p3,1);
    distancia(&p1,&p2,1);
return 0;
}
void creaPunto(struct punto *p,int i){
    printf("\nIntroduce coordenada en x del punto %d: ",i);
    scanf("%f",&p->x);
    printf("\nIntroduce coordenada en y del punto %d: ",i);
    scanf("%f",&p->y);
}
void imprimeP(struct punto p){
    printf("\nEl punto es (%.2f,%.2f)",p.x,p.y);
}
void sumaP(struct punto *p1,struct punto *p2,struct punto *p3,int i){
    p3->x =p1->x+p2->x;
    p3->y =p1->y+p2->y;
    printf("\nLa suma del punto %d y el punto %d es (%.2f,%.2f)\n",i,i+1,p3->x,p3->y);
}
void distancia(struct punto *p1,struct punto *p2,int i){
    float distancia=0;
    distancia= sqrt(pow(p1->x-p2->x,2)+pow(p1->y-p2->y,2));
    printf("\nLa distancia del punto %d y el punto %d es de %.2f\n",i,i+1,distancia);
}
