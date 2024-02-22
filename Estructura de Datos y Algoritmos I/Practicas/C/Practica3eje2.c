#include <stdio.h>
#include <stdlib.h>
#define es 3
#define n 5
struct DatosEstudiantes{
    char nombre[30];
    int edad;
    char sexo[1];
    int notas[n];
};
struct registroEstudiantes{
    int numeroCuenta;
    struct DatosEstudiantes estudiantes;
}estudiante[es];  
void llenaes(struct registroEstudiantes *estudiantes);
void muestraRE(struct registroEstudiantes *estudiantes);
main(){
printf("\tEste programa te permite llenar la informaci%cn de 3 estudiantes \n\tcon sus respectivas notas y las muestra realizado con estructuras anidadas.\n",162);
struct DatosEstudiantes;
struct registroEstudiantes *e;
llenaes (e);
muestraRE(e); 
getchar();
return 0;     
}
void llenaes(struct registroEstudiantes *estudiantes){
    int i,j=0,a=12;
    for(i=0;i<es;i++){
    	fflush(stdin);
    	printf("\nDatos del estudiante %d:",i+1);
        printf("\nIngrese el nombre: ");
        gets(estudiante[i].estudiantes.nombre);
        printf("\nIngrese el numero de cuenta: ");
        scanf("%d",&estudiante[i].numeroCuenta);
        printf("\nIngrese la edad: ");
        scanf("%d",&estudiante[i].estudiantes.edad);
        printf("\nIngrese el sexo insertando M(masculino) o F(fememino): ");
        getchar();
        gets(estudiante[i].estudiantes.sexo);
        printf("\nIngrese las notas del estudiante:(menores de 11 y enteros): ");
			for(j=0;j<n;j++){
        		printf("\nNota %d : ",j+1);
        		scanf("%d",&estudiante[i].estudiantes.notas[j]);
        		if(estudiante[i].estudiantes.notas[j]>10){
        			printf("Dato erroneo, vuelva a iniciar el programa");
        			getchar();
        			exit(0);
        		}
        		}
        	}
    	}
void muestraRE(struct registroEstudiantes *estudiantes){
	int i,j;
    for(i=0;i<es;i++){
    	printf("\nEstudiante %d:",i+1);
    	printf("\nNombre: %s",estudiante[i].estudiantes.nombre);
        printf("\nEdad: %d",estudiante[i].estudiantes.edad);
        printf("\nSexo: %s",estudiante[i].estudiantes.sexo);
        printf("\nNumero de cuenta: %d",estudiante[i].numeroCuenta);
        printf("\nNotas:",estudiante[i].estudiantes.notas[n]);
        for(j=0;j<n;j++){
        	printf("\nNota %d: ",j+1);
        	printf("%d",estudiante[i].estudiantes.notas[j]);
    	}    
	}
}
