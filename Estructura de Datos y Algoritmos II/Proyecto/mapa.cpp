#include <stdio.h>

#include <iostream>

#include "sqlite3.h" 

#include <string>

#include <bits/stdc++.h> 


#define INFINITO 1.0E+38

struct cantidades{
	float distancia;
	float tiempo;
};

struct calle{
	cantidades cantidad;
	std::string nombre;
};

typedef struct 
{
	int ultimaCalle;
	cantidades cantidad;
	std::string nombreCalle;
}EstadoVertice;


/*================================================================================================*/
int minimo(int *F,  EstadoVertice *D, int n);
void caminoMinimos (EstadoVertice *D, calle ** matPesos, int n, int *F, int Inicio);
int minimoTiempo(int *F, EstadoVertice *D, int n);
void caminoMinimosTiempo (EstadoVertice *D, calle ** matPesos, int n, int *F, int Inicio);
void cerrarCalle(int A, int B, calle** calles);
void cerrarCalles(int A, int B, calle** calles);
void pasarpor(int A, int B, int C, calle** calles, EstadoVertice* D,int numCalles, int *F);

std::string ruta(int Fin, EstadoVertice *D, std::string *lugar);
/*================================================================================================*/
int minimo(int *F, EstadoVertice *D, int n)
{
	double mx;
	int j, v;
	mx = INFINITO;
	#pragma omp parallel for shared(F, D, n, mx, v) private(j)
	for(j = 1; j<n; j++){
		if (!F[j] && (mx >= D[j].cantidad.distancia))
		{
			 #pragma omp critical
			{
				if (!F[j] && (mx >= D[j].cantidad.distancia))
				{	
					mx = D[j].cantidad.distancia;
					v = j;
				}
			}
		}

	}// --- Implicit barrier	
	return v;
}
/*================================================================================================*/
void caminoMinimos (EstadoVertice * D, calle ** matPesos, int numCalles, int *F, int Inicio){
	int v;
	int s = Inicio; /*vértice origen*/

	/*valores iniciales de la tabla D Se marca en F el origen */
	F[s] = 1;
	#pragma omp parallel for shared(F, D, matPesos, numCalles)
	for(int i=0; i<numCalles;++i)
	{
		if(s!=i){
			F[i]=0;
		}
		D[i].cantidad.distancia = matPesos[s][i].cantidad.distancia;
		//std:: cout << "\n"<< D[i].cantidad.distancia;
		D[i].ultimaCalle = s;
		D[i].nombreCalle = matPesos[s][i].nombre;
	}// --- Implicit barrier

	for(int i = 0; i<numCalles;++i)
	{
		v = minimo(F,D,numCalles); // selecciona vértice no marcado de menor cantidad.distancia 
		F[v] = 1; 
		//actualiza cantidad.distancia de vértices no marcados 
		
		#pragma omp parallel 
		{
			#pragma omp for 
			for(int w = 0; w<numCalles ;++w ){
			if(!F[w]){
				if((D[v].cantidad.distancia + matPesos[v][w].cantidad.distancia) <= D[w].cantidad.distancia)
				{
					#pragma omp critical
					{
						if((D[v].cantidad.distancia + matPesos[v][w].cantidad.distancia) <= D[w].cantidad.distancia)
						{
							
							D[w].cantidad.distancia = D[v].cantidad.distancia + matPesos[v][w].cantidad.distancia;
							D[w].ultimaCalle = v;
							D[w].nombreCalle = matPesos[v][w].nombre;
						}
					}
				}
			}
		}

		}
				
	}

	
	
}
/*================================================================================================*/
int minimoTiempo(int *F, EstadoVertice *D, int n){
	double mx;
	int j, v;

	mx = INFINITO;
	#pragma omp parallel for shared(F, D, n, mx, v) private(j)
	for(j = 1; j<n; j++)
		if (!F[j] && (mx >= D[j].cantidad.tiempo))
		{
			 #pragma omp critical
			{
				if (!F[j] && (mx >= D[j].cantidad.tiempo))
				{	
					mx = D[j].cantidad.tiempo;
					v = j;
				}
			}
			
		}
	return v;
}

/*================================================================================================*/
void caminoMinimosTiempo (EstadoVertice* D, calle ** matPesos, int numCalles, int *F, int Inicio){
	int v,w,i;
	int s = Inicio; /*vértice origen*/

	/*valores iniciales de la tabla D Se marca en F el origen */

	F[s] = 1;
	#pragma omp parallel for shared(s,F,D,matPesos,numCalles)
	for(i=0; i<numCalles;++i)
	{
		if(s!=i)
			F[i]=0;
		D[i].cantidad.tiempo = matPesos[s][i].cantidad.tiempo ;
			//std:: cout << "\n"<< D[i].cantidad.tiempo;
		D[i].ultimaCalle = s;
		D[i].nombreCalle = matPesos[s][i].nombre;
		
		
	}
	for(i = 0; i<numCalles;++i) {
		v = minimoTiempo(F,D,numCalles); // selecciona vértice no marcado de menor cantidad.tiempo 

		F[v] = 1; 
		//actualiza cantidad.tiempo de vértices no marcados
		#pragma omp parallel 
		{
			#pragma omp for 
			for(w = 0; w<numCalles; ++w)
			{
				if(!F[w])
				{
					if((D[v].cantidad.tiempo + matPesos[v][w].cantidad.tiempo ) <= D[w].cantidad.tiempo)
					{
						#pragma omp critical
						{
							if((D[v].cantidad.tiempo + matPesos[v][w].cantidad.tiempo ) <= D[w].cantidad.tiempo)
							{
								
								D[w].cantidad.tiempo = D[v].cantidad.tiempo + matPesos[v][w].cantidad.tiempo ;
								D[w].ultimaCalle = v;
								D[w].nombreCalle = matPesos[v][w].nombre;
							}
						}
					}
				}
			}
		}
	}
}

/*================================================================================================*/


void llenar(int numCalles, calle** calles, std::string* lugar){
	lugar[0] = "Lomas de Chapultepec";
	lugar[1] = "Tacuba";
	lugar[2] = "Roma";
	lugar[3] = "UNAM";
	lugar[4] = "Centro Histórico";
	lugar[5] = "Bosques de Aragón";
	lugar[6] = "Coapa";
	lugar[7] = "Chalco";
	#pragma omp parallel for shared(calles, numCalles, lugar)
	for (int i = 0; i<numCalles;++i){
	  	for (int j = 0; j<numCalles;j++){
	  		if(j==i){
	  			calles[i][j].cantidad.distancia = 0;
	  			calles[i][j].cantidad.tiempo = 0;
	  			calles[i][j].nombre = "Mismo lugar";
	  		}
	  		else{
	  			calles[i][j].cantidad.distancia = INFINITO;
	  			calles[i][j].cantidad.tiempo = INFINITO;
	  			calles[i][j].nombre = "Sin calle";
	  		}
	  	}
  	}

	calles[0][1].nombre = "Calz Legiria";
  	calles[0][1].cantidad.distancia = 6.6 ;
	calles[0][1].cantidad.tiempo = 20;
	calles[1][0].nombre = "Calz Legiria";
  	calles[1][0].cantidad.distancia = 6.6 ;
	calles[1][0].cantidad.tiempo = 20;

	calles[0][2].nombre = "Autopista Urbana Nte.";
  	calles[0][2].cantidad.distancia = 9.5;
	calles[0][2].cantidad.tiempo = 15;
	calles[2][0].nombre = "Autopista Urbana Nte.";
  	calles[2][0].cantidad.distancia = 9.5;
	calles[2][0].cantidad.tiempo = 15;

	calles[1][4].nombre = "Eje Central Lázaro Cárdenas";
  	calles[1][4].cantidad.distancia =5.6 ;
	calles[1][4].cantidad.tiempo = 16;
	calles[4][1].nombre = "Eje Central Lázaro Cárdenas";
  	calles[4][1].cantidad.distancia =5.6 ;
	calles[4][1].cantidad.tiempo = 16;

	calles[2][4].nombre = "Eje 1 Nte.";
  	calles[2][4].cantidad.distancia =7.4 ;
	calles[2][4].cantidad.tiempo = 25;
	calles[4][2].nombre = "Eje 1 Nte.";
  	calles[4][2].cantidad.distancia =7.4 ;
	calles[4][2].cantidad.tiempo = 25;

	calles[3][2].nombre = "Av. Insurgentes Sur";
  	calles[3][2].cantidad.distancia = 13.1;
	calles[3][2].cantidad.tiempo = 27;
	calles[2][3].nombre = "Av. Insurgentes Sur";
  	calles[2][3].cantidad.distancia = 13.1;
	calles[2][3].cantidad.tiempo = 27;

	calles[3][6].nombre = "Canal de Miramontes";
  	calles[3][6].cantidad.distancia = 13.4;
	calles[3][6].cantidad.tiempo = 20;
	calles[6][3].nombre = "Canal de Miramontes";
  	calles[6][3].cantidad.distancia = 13.4;
	calles[6][3].cantidad.tiempo = 20;

	calles[4][5].nombre = "Av. Oceanía";
  	calles[4][5].cantidad.distancia = 13.6;
	calles[4][5].cantidad.tiempo = 24;
	calles[5][4].nombre = "Av. Oceanía";
  	calles[5][4].cantidad.distancia = 13.6;
	calles[5][4].cantidad.tiempo = 24;

	calles[4][6].nombre = "Calz. de Tlalpan";
  	calles[4][6].cantidad.distancia = 17.3;
	calles[4][6].cantidad.tiempo = 31;
	calles[6][4].nombre = "Calz. de Tlalpan";
  	calles[6][4].cantidad.distancia = 17.3;
	calles[6][4].cantidad.tiempo = 31;

	calles[5][7].nombre = "Autopista México - Puebla";
  	calles[5][7].cantidad.distancia = 39.7;
	calles[5][7].cantidad.tiempo = 59;
	calles[7][5].nombre = "Autopista Puebla - México";
  	calles[7][5].cantidad.distancia = 39.7;
	calles[7][5].cantidad.tiempo = 59;

	/*calles[][].nombre = "";
  	calles.cantidad.distancia = ;
	calles.cantidad.tiempo = ;**/

	calles[6][7].nombre = "Tláhuac";
  	calles[6][7].cantidad.distancia = 29.8;
	calles[6][7].cantidad.tiempo = 75;
	calles[7][6].nombre = "Tláhuac";
  	calles[7][6].cantidad.distancia = 29.8;
	calles[7][6].cantidad.tiempo = 75;
}

/*================================================================================================*/
int create(std::string primerFila)
{
	sqlite3 *db;
   int rc = sqlite3_open("datosGPS.sqlite3", &db);
   if( rc ) {
      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
      return(0);
   } else {
      fprintf(stderr, "Opened database successfully\n");
   }
   const char* sql = primerFila.c_str();
   char* err_msg = NULL;

   rc = sqlite3_exec( db, sql, NULL, 0, &err_msg );

   if( rc != SQLITE_OK ){
      fprintf( stderr, "SQL error: %s\n", err_msg );
      sqlite3_free( err_msg );
   } else{
      fprintf( stdout, "Tabla creada!\n" );
   }
   sqlite3_close(db);	
   return 1;
}
/*================================================================================================*/

int insert(std::string ingresar)
{
	 sqlite3 *db;

   int rc = sqlite3_open("datosGPS.sqlite3", &db);

   if( rc ) {
      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
      return(0);
   } else {
      fprintf(stderr, "Opened database successfully\n");
   }
   const char* sql = ingresar.c_str();

   char* err_msg = NULL;

   rc = sqlite3_exec( db, sql, NULL, 0, &err_msg );

   if( rc != SQLITE_OK ){
      fprintf( stderr, "SQL error: %s\n", err_msg );
      sqlite3_free( err_msg );
   } else{
      fprintf( stdout, "Datos insertados!\n" );
   }

   int last_id = sqlite3_last_insert_rowid( db );
   fprintf( stdout, "El último ID insertado es: %d\n", last_id );

   sqlite3_close(db);

   return 1;
}





void cerrarCalle(int A, int B, calle** calles){
	calles[A][B].cantidad.distancia = INFINITO;
	calles[A][B].cantidad.tiempo = INFINITO;
}

void cerrarCalles(int A, int B, calle** calles){
	calles[A][B].cantidad.distancia = INFINITO;
	calles[B][A].cantidad.distancia = INFINITO;

	calles[A][B].cantidad.tiempo = INFINITO;
	calles[B][A].cantidad.tiempo = INFINITO;
}



void pasarporTiempo(int A, int B, int C, calle** calles, EstadoVertice* D,int numCalles, int *F, std::string *lugar){
	std::string camino = "";
	caminoMinimosTiempo(D, calles, numCalles, F, A); 
	if(D[B].cantidad.tiempo < D[C].cantidad.tiempo){
		camino = ruta(B, D,lugar);
		caminoMinimosTiempo (D, calles, numCalles, F, B);
		camino = ruta(C, D,lugar) + camino; 
	}else{
		camino = ruta(C, D,lugar);
		caminoMinimosTiempo (D, calles, numCalles, F, C);
		camino = ruta(B, D,lugar) + camino;  
	}
	
}


void crear(int numCalles, std::string *lugar){
	//==========================================================================
	std::string primerFila = "";

	primerFila += "DROP TABLE IF EXISTS datos; "
               "CREATE TABLE datos( "
               "id INTEGER PRIMARY KEY NOT NULL, "
               "nombre TEXT"
               ;

    for (int i = 0; i< numCalles; ++i){
    	primerFila +=", '"+lugar[i] + "' TEXT ";
    }
	primerFila += ");";

	create(primerFila);
}

void ingresar(int numCalles, std::string *lugar, calle **calles)
{
	//=========================================================================
	std::string estandar = "INSERT INTO datos(nombre";
	for (int i = 0; i< numCalles; ++i){
    	estandar +=", '"+lugar[i] + "'";
    }
    estandar += + ") VALUES(";
    std::string ingresar = "";
    for (int i = 0; i<numCalles;++i){
    	ingresar +=estandar+"'"+lugar[i]+"'";
  		for (int j = 0; j<numCalles;j++){
  			ingresar += ", '"+std::to_string(calles[j][i].cantidad.distancia)+","+std::to_string(calles[j][i].cantidad.tiempo)+","+calles[j][i].nombre+"'";
  		}
  		ingresar += "); ";
  	}

  	insert(ingresar);

	/*std::string ingresar = "INSERT INTO datos( nombre, promedio, semestre) VALUES( 'aaaa', 8.5, 3 ); "
               "INSERT INTO alumnos( nombre, promedio, semestre) VALUES( 'bbbb', 9.5, 4 ); "
               "INSERT INTO alumnos( nombre ) VALUES( 'dddd' ); "
               ;*/
  	//=========================================================================


}


/*================================================================================================*/
void rutaCortaTiempo(EstadoVertice *D, calle ** calles, int numCalles, int *marcado, int Inicio, std::string *lugar){
	caminoMinimosTiempo(D, calles, numCalles, marcado, Inicio);
  	//std:: cout<<"\n\nPor Tiempo_____________________________";
  	/*for (int j = 0; j<numCalles;j++){
  		//std:: cout <<" \n"<<lugar[j]<<": ";
  		switch(D[j].ultimaCalle){
  			case 0:{	std:: cout <<"Tiempo:" <<D[j].cantidad.tiempo ;	break;}
  			case 1:{	std:: cout <<"Tiempo:" <<D[j].cantidad.tiempo ;	break;}
  			case 2:{	std:: cout <<"Tiempo:" <<D[j].cantidad.tiempo ;	break;}
  			case 3:{	std:: cout <<"Tiempo:" <<D[j].cantidad.tiempo ;	break;}
  			case 4:{	std:: cout <<"Tiempo:" <<D[j].cantidad.tiempo ;	break;}
  			case 5:{	std:: cout <<"Tiempo:" <<D[j].cantidad.tiempo ;	break;}
  			case 6:{	std:: cout <<"Tiempo:" << D[j].cantidad.tiempo;	break;}
  			case 7:{	std:: cout <<"Tiempo:" <<D[j].cantidad.tiempo ;break;}
  			default:{  				std:: cout<<"Error\n";  			}
  		}
  		//std:: cout<<" " << lugar[D[j].ultimaCalle]<<"\n";
	}*/
}
/*================================================================================================*/
void rutaCortaDistancia(EstadoVertice *D, calle ** calles, int numCalles, int *marcado, int Inicio, std::string *lugar){
	caminoMinimos(D, calles, numCalles, marcado, Inicio);
	//std:: cout<<"\n\nPor Distancia_____________________________";
	/*for (int j = 0; j<numCalles;j++){
  		std:: cout <<" \n"<<lugar[j]<<": ";
  		switch(D[j].ultimaCalle){
  			case 0:{	std:: cout <<"Distancia:" <<D[j].cantidad.distancia ;	break;}
  			case 1:{	std:: cout <<"Distancia:" <<D[j].cantidad.distancia ;	break;}
  			case 2:{	std:: cout <<"Distancia:" <<D[j].cantidad.distancia ;	break;}
  			case 3:{	std:: cout <<"Distancia:" <<D[j].cantidad.distancia ;	break;}
  			case 4:{	std:: cout <<"Distancia:" <<D[j].cantidad.distancia ;	break;}
  			case 5:{	std:: cout <<"Distancia:" <<D[j].cantidad.distancia ;	break;}
  			case 6:{	std:: cout <<"Distancia:" << D[j].cantidad.distancia;	break;}
  			case 7:{	std:: cout <<"Distancia:" <<D[j].cantidad.distancia ;break;}
  			default:{  				std:: cout<<"Error\n";  			}
  		}
  		//std:: cout<<" " << lugar[D[j].ultimaCalle]<<"\n";
	}*/
	/*for (int j = 0; j<numCalles;j++){
		std:: cout<<"\n"<<j<<":"<<D[j].nombreCalle;
	}*/
}

/*================================================================================================*/
std::string ruta(int Fin, EstadoVertice *D, std::string *lugar){
	std::string camino = "";
	int i = Fin;
	camino = lugar[i] + "\nHasta pronto!!!";
	while((D[i].nombreCalle).compare("Mismo lugar") != 0){
		camino= "\nsiga por " + D[i].nombreCalle +"\nse encuentra en " + camino;
		camino= lugar[D[i].ultimaCalle] + camino;
		i = D[i].ultimaCalle;
	}
	return camino;
}
/*================================================================================================*/

void mostrarLugares(std::string *lugar, int numLugares)
{
	for(int i = 0; i< numLugares; i++){
		std::cout << "\n" << i+1 << ") "<< lugar[i];
	}
	std::cout << "\n";
}


/*================================================================================================*/

void mapa(){

	char salir = 0;
	int Inicio = 0;
	int Fin = 0;
	int numCalles = 8;

	calle **calles = new calle*[numCalles];
	for(int i=0;i<numCalles;++i){
	    calles[i]= new calle[numCalles];
	}
	std::string *lugar  = new std::string[numCalles];
	EstadoVertice *D = new EstadoVertice[numCalles];
	int *marcado = new int[numCalles];

	llenar(numCalles, calles, lugar);
	crear(numCalles, lugar);
	ingresar( numCalles,lugar, calles);

	do{
		std::vector<std::string> opciones;
	 	
		opciones.push_back("1)Viajar por tiempo");
		opciones.push_back("2)Viajar por distancia");
		opciones.push_back("3)Salir de cuenta");
		opciones.push_back("Digite la opción \t");
		for (std::string x : opciones) {
	       	std::cout <<"\n"<< x;
		}
		int opc;
		std:: cin>>opc;
		
		switch (opc){
			case(1):{
				mostrarLugares(lugar, numCalles);
				std:: cout <<"\nDime el lugar de inicio\t";
				std:: cin>> Inicio;
				Inicio--;
				std:: cout <<"\nDime el lugar de Fin\t";
				std:: cin>> Fin;
				Fin--;
				rutaCortaTiempo(D, calles, numCalles, marcado, Inicio, lugar);
				std::string camino = "\n\nRUTA por tiempo en "+std::to_string(D[Fin].cantidad.tiempo)+" min\n"+ruta(Fin, D,lugar);
				std::cout <<camino<<"\n";

							

				break;
			}
			case(2):{
				mostrarLugares(lugar, numCalles);
				std:: cout <<"\nDime el lugar de inicio\t";
				std:: cin>> Inicio;
				Inicio--;
				std:: cout <<"\nDime el lugar de Fin\t";
				std:: cin>> Fin;
				Fin--;
				rutaCortaDistancia(D, calles, numCalles, marcado, Inicio, lugar);
				std::string camino ="\n\nRUTA por distancia en "+std::to_string(D[Fin].cantidad.distancia)+" km\n"+ ruta(Fin, D,lugar);
				std::cout <<camino<<"\n";

				 break;
			}
			case(3):{	salir = 1; break;}
		}




	}while(salir == 0);

	delete [] calles;
	delete [] lugar;
	delete [] D;
	delete [] marcado;
}