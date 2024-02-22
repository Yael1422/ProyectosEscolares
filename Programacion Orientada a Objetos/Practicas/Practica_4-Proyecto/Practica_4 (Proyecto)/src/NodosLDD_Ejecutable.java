import java.util.Scanner;

public class NodosLDD_Ejecutable {
    static NodoLDD Lista;//Referencia del nodo para el control de la LDD
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);        
        int opcion;
        OperacionesLDD operaciones = new OperacionesLDD();        
	do{			
            System.out.println("-->LISTA DOBLEMENTE LIGADA EN POO<--");
            System.out.println("1.- Imprimir elementos almacenados.");
            System.out.println("2.- Agregar nuevo nodo.");
            System.out.println("3.- Buscar nodo.");
            System.out.println("4.- Eliminar nodo.");
            System.out.println("5.- Salir.");
            System.out.println("Elegir:");
            opcion = sc.nextInt();
            switch (opcion) {
                case 1:{
                    //if(operaciones.isEmpty()==true)
                    if(operaciones.isEmpty(Lista)==true)
                        System.out.println("LDD vacia!");
                    else
                        //System.out.println(operaciones.cadenaNodos());
                        System.out.println(operaciones.cadenaNodos(Lista));                    
                    break;
    		}
                case 2:{
                    //operaciones.addData(sc);
                    Lista = operaciones.addData(sc,Lista);
                    System.out.println("Número de nodos AGREGADOS hasta el momento: "+operaciones.getNumNodos()+".");                    
                    break;		
		}	
                case 3:{
                    int nodoLlave=0;
                    //if(operaciones.isEmpty()==false){
                    if(operaciones.isEmpty(Lista)==false){
                        System.out.println("Ingrese la llave del nodo a BUSCAR:");
                        nodoLlave = sc.nextInt();
                        //NodoLDD buscado=operaciones.buscar(nodoLlave);
                        NodoLDD buscado=operaciones.buscar(nodoLlave, Lista);
                        System.out.println(buscado);		
                    }else{
                        System.out.println("LDD vacia!");
                    }
                    break;
                }
                case 4:{
                    int nodoLlave=0;
                    //if(operaciones.isEmpty()==false){
                    if(operaciones.isEmpty(Lista)==false){
                        System.out.println("Ingrese la llave del nodo a ELIMINAR:");
                        nodoLlave = sc.nextInt();
                        //operaciones.borrar(nodoLlave);
                        Lista = operaciones.borrar(nodoLlave, Lista);
                        System.out.println("Número de nodos EXISTENTES después de la eliminación: "+operaciones.getNumNodos()+".");					
                    }else{
			System.out.println("LDD vacia!");
                    }
                break;	
                }
                case 5:{
                    //Salir
                    System.out.println("Hasta luego!\n");
                break;
                }
                default:{
                    //Ninguno de los anteriores:
                    System.out.println("Su elecci\u00F3n no es correcta\n");                    
                break; 
                }
            }
            System.out.println("-------------------------------------------");
	}while(opcion!= 5);
	sc.close();
    }
}