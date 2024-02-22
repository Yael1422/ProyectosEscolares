#include <stdio.h>
main(){
int i,j,m,n,k;
printf("\n Este programa calcula la transpuesta de 2 matrices ");
for(k=0;k<2;k++){
printf("\n Inserte la cantidad de rengoles que tiene la matriz %d: ",k+1);
scanf("%d",&m);
printf("\n Inserte la cantidad de columnas que tiene la matriz %d: ",k+1);
scanf("%d",&n);
int A[m][n],a1[m*n];
int T[m][n];
int *a,*t,cont=-1;
for(i=0;i<m;i++){
		for(j=0;j<n;j++){
		printf("\t Inserte el elemento (%hd,%hd) de la matriz \n\t",i+1,j+1);
		scanf("%d",&A[i][j]);
		}
	}
a=&A[0][0];
t=&T[0][0];
for(i=0;i<m;i++){
	for(j=0;j<n;j++){
		cont=cont+1;
		a1[cont]=A[i][j];
	}
}
cont=-1;
for(i=0;i<m;i++){
	for(j=0;j<n;j++){
	cont=cont+1;
	T[j][i]=a1[cont];
	}
}
	printf("\n La matriz ingresada de [%d][%d] es:\n",m,n);
	for(i=0;i<(m);i++){
		printf("\n\t");
		for(j=0;j<n;j++){
		printf("%d\t",A[i][j]);
		}
	}
	printf("\nLa transpuesta de la matriz ingresada de [%d][%d] es:\n",n,m);
	for(i=0;i<(n);i++){
		printf("\n\t");
		for(j=0;j<m;j++){
			printf("%d\t",T[i][j]);
		}
	}
	getchar();
}
getchar();
return 0;
}
