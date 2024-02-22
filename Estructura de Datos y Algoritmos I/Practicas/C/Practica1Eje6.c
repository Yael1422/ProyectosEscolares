#include <stdio.h>//biblioteca que contiene las funciones principales de c
int realizarcuadro(int x);//funci�n que realiza el cuadro m�gico
main(){//inicia func�n principal
	int grado,suma,res=1;//declaraci�n de las variables usadas en la funci�n principal
	while(res==1){//ciclo para repetir el programa
	printf("\tEste programa realiza cuadros m%cgicos dependiendo del grado que es dado por el usuario \n",160); //imprime mensaje
	printf("\tDEBE DE SER IMPAR PARA QUE FUNCIONE EL ALGROTIMO Y UN LIMITE DE GRADO 50 \n");//imprime mensaje
	printf("\tIngrese el grado en que desea que sea el cuadro m%cgico:",160);//imprime mensaje
	scanf("%d",&grado);//guarda el grado del cuadro m�gico ingresado por el usuario
	suma= (grado*((grado*grado)+1))/2;//realiza la operaci�n para calcular la constante m�gica que ser�a la suma total del cuadro m�gico 
	printf("\tLa matriz ser%ca de [%d][%d]\n",161,grado,grado);//imprime mensaje
	printf("\tSu suma debe dar %d en cada rengl%Cn,columna y diagonal principal.\n\n",suma,162);//imprime mensaje
	if (grado%2!=0){//condicional que indica si el n�mero ingresado es impar para realizar el algoritmo
		realizarcuadro(grado);//funci�n que realiza, imprime y comprueba el cuadro m�gico
	}//cierra condici�n si
	else{//si no cumple el condicional anterior
		printf("\tEl numero no es impar \n");//imprime mensaje
		printf("\tEl algoritmo para realizar el cuadro no funcionar%ca \n",161);//imprime mensaje
		printf("\tVuelva a iniciar el programa :( \n");//imprime mensaje
	}//cierra condici�n si no
res=0;//iguala la variable res a cero para que no se repita el programa si el usuario no ingresa nada
printf("\n\tDeseas repetir el programa? 1=Si, Otra tecla=No\n");//imprime mensaje
scanf("%d", &res);//lee si el usuario quiere repetir el programa
}//cierra ciclo para repetir el programa
getchar();//mantiene est�tica de la ejecuci�n
return 0; //termina ejecuci�n devolviendo a cero
}//cierra funci�n principal

int realizarcuadro(int x){ //incia funci�n que realiza, imprime y comprueba el cuadro m�gico
	int a[50][50],ren,col,med,numero,suma;//declaraci�n de las variables usadas en la funci�n del caudro m�gico
	med=(x/2);//calcula la mitad del numero impar dado por el usuario
	med=med+1;//le suma uno a esa mitad para comezar el algoritmo
	for(ren=1;ren<=x;ren++){//inicia ciclo desplazando los renglones
		for(col=1;col<=x;col++){//incia ciclo desplazando columnas
			a[ren][col]=0;//le da el valor de cero a cada uno de los espacios en el arreglo bidimensional
		}//cierra ciclo
	}//cierra ciclo
	for(ren=1,col=med,numero=1;numero<=(x*x);){//inicia ciclo de condiciones para desplazarse a trav�s del cuadro m�gico que lo va resolviendo
			if(col<=x && ren>0){//condici�n que revisa si ese lugar se encuentra dentro de los renglones y del cuadro
				if(a[ren][col]==0)//condici�n que revisa si ese lugar en el arreglo sigue siendo igual a cero
				a[ren][col]=numero;//le da el valor de numero a ese lugar en el arreglo
				numero++;//suma uno a numero
				ren--;//resta un rengl�n 
				col++;//suma una columna
			}//cierra primera condici�n
			if(ren<1 && col>x){//Revisa si ese lugar se encuentra fuera de los renglones del cuadro por arriba y fuera de las columnas por la derecha
				ren=ren+2;//suma dos rengl�nes
				col--;//resta una columna
			}//cierra segunda condici�n
			if(ren<1){//condici�n que revisa si ese lugar se encuentra fuera de los renglones del cuadro por arriba  
				ren=x;//valor del rengl�n se va al �ltimo del cuadro
			}//cierra tercera condici�n
			if(col>x){//condici�n que revisa si ese lugar se encuentra fuera de las columnas del cuadro por la derecha
				col=1;//valor de la columna se va a la primera del cuadro
			 }//cierra cuarta condici�n
			if(a[ren][col]!=0){//condici�n que revisa si ese lugar del arreglo se encuentra con un valor diferente a cero
				ren=ren+2;//suma dos renglones
				col--;//resta una columna
			}//cierra quinta condici�n
	}	//cierra ciclo de condiciones del cuadro m�gico
printf("El cuadro m%cgico generado es: \n\t",160);//imprime mensaje
	for(ren=1;ren<=x;ren++){//inicia ciclo desplazando los renglones
		printf("\n\t");//imprime mensaje
		for(col=1;col<=x;col++){//inicia ciclo desplazando las columnas
			printf("%d\t",a[ren][col]);//imprime mensaje que contiene a todos los valores del arreglo bidimensional
		}//cierra ciclo
	}//cierra ciclo
	printf(" \n Presione enter para comprobar el cuadro");//imprime mensaje
	getchar();//atrapa el enter introducido anteriormente
	getchar();//mantiene est�tica de la ejecuci�n
	suma=0;//valor de la variable suma a cero
	printf(" \n Comprobaci%cn",162);//imprime mensaje
	for(col=1;col<=x;col++){//inicia ciclo desplazando las columnas
			for(ren=1;ren<=x;ren++){//inicia ciclo desplazando los renglones
			suma=suma+a[ren][col];//realiza la suma de las columnas de la matriz
		}	//cierra ciclo
	printf(" \n La suma de la columna %d de la matriz es:%d\n",col,suma);//imprime mensaje
	suma=0;//valor de la variable suma a cero
	}//cierra ciclo
		for(ren=1;ren<=x;ren++){//inicia ciclo desplazando los renglones
			for(col=1;col<=x;col++){//inicia ciclo desplazando las columnas
				suma=suma+a[ren][col];//realiza la suma de los renglones de la matriz
			}//cierra ciclo
		printf(" \n La suma del renglon %d de la matriz es:%d\n",ren,suma);//imprime mensaje
		suma=0;//valor de la variable suma a cero
		}//cierra ciclo
	suma=0;	//valor de la variable suma a cero
 	for(ren = 1, col = 1; ren <=x && col <=x; ren++, col++){//inicia ciclo desplazando las columnas y renglones de arriba hacia abajo
  		suma=suma+a[ren][col];//realiza la suma de la diagonal de arriba hacia abajo de la matriz
 	}//cierra ciclo
	printf(" \n La suma de la primer diagonal principal de la matriz es:%d\n",suma);//imprime mensaje
	suma=0;//valor de la variable suma a cero
	for(ren=x,col=1; ren >=1 && col <=x; ren--, col++){//inicia ciclo desplazando las columnas y renglones de abajo hacia arriba
  		suma=suma+a[ren][col];//realiza la suma de la diagonal de abajo hacia arriba de la matriz
 	}//cierra ciclo
	printf(" \n La suma de la segunda diagonal principal de la matriz es:%d\n",suma);//imprime mensaje
}//cierra funci�n que realiza, imprime y comprueba el cuadro m�gico
