import java.util.Scanner;

public class OperacionesLDD {
     //Atributos de tipo NodoLDD para referenciar posiciones IMPORTANTES en la LDD.
    private NodoLDD LDD;
    private NodoLDD head=null;
    private NodoLDD tail=null;

    private int numNodos;    
    //Método que evalua si la LDD está o nó vacía.
    public boolean isEmpty(){//Metodo 1
        if(head==null)
            return true;
        else
            return false;
    }
    
    public boolean isEmpty(NodoLDD Lista){
        if((head==null) && (Lista==null))//Metodo 2
            return true;
        else
            return false;
    }
    
    //Método para agregar nodos a la LDD. Cada nodo contendrá una llave (int) y una cadena (String).
    public void addData(Scanner entrada){//Metodo 1
        int nvaLlave;
        String nvoData;
        System.out.print("Ingrese el valor ENTERO para la llave k de este nuevo nodo:");
        nvaLlave = entrada.nextInt();
        System.out.print("Ingrese el dato a agregar en este nuevo nodo "+nvaLlave+":");
        nvoData = entrada.next();
        NodoLDD nvoNodo = new NodoLDD();
        nvoNodo.setLlave(nvaLlave);
        nvoNodo.setItem(nvoData);        
        //Para todo nuevo nodo creado, referenciar sus campos Next y Prev a 'null'.
        nvoNodo.setNext(null);
        nvoNodo.setPrev(null);
        
        if(isEmpty()){              //Caso extremo:
            LDD=head=tail=nvoNodo;  //Posicionar los atributos en el nuevo nodo.
            LDD.setNext(null);      
            LDD.setPrev(null);
            head.setNext(null);      
            head.setPrev(null);
        }else{                      //Caso base: Seguir el esquema mostrado en clase:
            nvoNodo.setNext(head);  //(1)
            head.setPrev(nvoNodo);  //(2)
            head = head.getPrev();  //(3)
            LDD = head;
            //¿Como mover a tail? ¿Sería aquí tal movimiento, o en el método borrar()?
        }
        numNodos++;                 //Incremento del contador del número de nodos.
    }
    
    public NodoLDD addData(Scanner entrada, NodoLDD Lista){//Metodo 2
        int nvaLlave;
        String nvoData;
        System.out.print("Ingrese el valor ENTERO para la llave k de este nuevo nodo:");
        nvaLlave = entrada.nextInt();
        System.out.print("Ingrese el dato a agregar en este nuevo nodo "+nvaLlave+":");
        nvoData = entrada.next();
        NodoLDD nvoNodo = new NodoLDD();
        nvoNodo.setLlave(nvaLlave);
        nvoNodo.setItem(nvoData);        
        //Para todo nuevo nodo creado, referenciar sus campos Next y Prev a 'null'.
        nvoNodo.setNext(null);
        nvoNodo.setPrev(null);
        
        if(isEmpty()){              //Caso extremo:
            Lista=head=tail=nvoNodo;  //Posicionar los atributos en el nuevo nodo.
            Lista.setNext(null);      
            Lista.setPrev(null);
            head.setNext(null);      
            head.setPrev(null);
        }else{                      //Caso base: Seguir el esquema mostrado en clase:
            nvoNodo.setNext(head);  //(1)
            head.setPrev(nvoNodo);  //(2)
            head = head.getPrev();  //(3)
            Lista = head;
            //¿Como mover a tail? ¿Sería aquí tal movimiento, o en el método borrar()?
        }
        numNodos++;                 //Incremento del contador del número de nodos.
        return Lista;
    }
    
    //Método que recorre toda la LDD para concatenar los datos contenidos en cada nodo.
    public String cadenaNodos(){//Metodo 1
        String cadena = "-->DATOS ALMACENADOS EN LA LDD:\n";
        NodoLDD aux = new NodoLDD(); 
        for(aux = LDD; aux!=null; aux=aux.getNext())
            cadena += "Llave: "+aux.getLlave()+". "+"Dato: "+aux.getItem()+"\n";
        
        System.out.println(aux);
        return cadena;
    }
    
    public String cadenaNodos(NodoLDD Lista){//Metodo 2
        String cadena = "-->DATOS ALMACENADOS EN LA LDD:\n";
        NodoLDD aux = new NodoLDD(); 
        for(aux = Lista; aux!=null; aux=aux.getNext())
            cadena += "Llave: "+aux.getLlave()+". "+"Dato: "+aux.getItem()+"\n";
        
        System.out.println(aux);
        return cadena;
    }
    
    //Método para buscar un nodo de acuerdo a la llave "k" a ingresar.
    public NodoLDD buscar(int k){//Metodo 1
        NodoLDD aux=new NodoLDD();
        NodoLDD encontrado=new NodoLDD();
        for(aux=head; aux!=null; aux=aux.getNext()){
            if(k==aux.getLlave()){
                encontrado=aux;
                //break;        //Forma para salir del lazo.
            }
        }    
        if(encontrado.getLlave()==k){ //¡Comparación BUENA!
            System.out.println("El nodo con llave "+k+" SI se encuentra en la LDD"); 
            //System.out.println("El nodo con llave "+encontrado.getLlave()+" SI se encuentra en la LDD");//¡Esto no!
        }else{
            //System.out.println("El nodo con llave "+encontrado.getLlave()+" SI se encuentra en la LDD");//¡Esto no!
            System.out.println("El nodo con llave "+k+" NO se encuentra en la LDD");
            encontrado=null; //Asignación a null para ser retornada (cuando se dé este caso).
        }
        return encontrado;        
    }
    
    public NodoLDD buscar(int k, NodoLDD Lista){//Metodo 2
        NodoLDD aux=new NodoLDD();
        NodoLDD encontrado=new NodoLDD();
        for(aux=head; aux!=null; aux=aux.getNext()){
            if(k==aux.getLlave()){
                encontrado=aux;
                //break;        //Forma para salir del lazo.
            }
        }    
        if(encontrado.getLlave()==k){ //¡Comparación BUENA!
            System.out.println("El nodo con llave "+k+" SI se encuentra en la LDD"); 
            //System.out.println("El nodo con llave "+encontrado.getLlave()+" SI se encuentra en la LDD");//¡Esto no!
        }else{
            //System.out.println("El nodo con llave "+encontrado.getLlave()+" SI se encuentra en la LDD");//¡Esto no!
            System.out.println("El nodo con llave "+k+" NO se encuentra en la LDD");
            encontrado=null; //Asignación a null para ser retornada (cuando se dé este caso).
        }
        return encontrado;        
    }
    
    //Método para eliminar algún nodo de acuerdo a la llave "k" a buscar:
    public void borrar(int k){//Metodo 1
        NodoLDD aux=new NodoLDD();
        aux = buscar(k);        
        if(aux!=null){        //Caso extremo: Eliminar el único nodo de la LDD.
            if(numNodos==1){ //Otra forma: if((aux.getNext==null)&&(aux.getPrev==null))
                LDD=head=tail=null;
            }
            else{           //Caso base (nodos intermedios): Seguir el esquema compartido en clase.
                //1:
                aux.getPrev().setNext(aux.getNext());
                //2:
                aux.getNext().setPrev(aux.getPrev());
                //3:
                aux.setNext(null);
                aux.setPrev(null);
                //Falta el caso de eliminar el nodo head (con nodos intermedios).
                //Falta el caso de eliminar el nodo tail (con nodos intermedios).
                //¿En donde colocarían tales casos?
            }
            System.out.println("El nodo con llave "+k+" ha sido eliminado de la LDD!");
            numNodos--;
        }
    }
    
    public NodoLDD borrar(int k, NodoLDD Lista){//Metodo 2
        NodoLDD aux=new NodoLDD();
        aux = buscar(k, Lista);        
        if(aux!=null){        //Caso extremo: Eliminar el único nodo de la LDD.
            if(numNodos==1){ //Otra forma: if((aux.getNext==null)&&(aux.getPrev==null))
                Lista=head=tail=null;
            }
            else{           //Caso base (nodos intermedios): Seguir el esquema compartido en clase.
                //1:
                aux.getPrev().setNext(aux.getNext());
                //2:
                aux.getNext().setPrev(aux.getPrev());
                //3:
                aux.setNext(null);
                aux.setPrev(null);
                //Falta el caso de eliminar el nodo head (con nodos intermedios).
                //Falta el caso de eliminar el nodo tail (con nodos intermedios).
                //¿En donde colocarían tales casos?
            }
            System.out.println("El nodo con llave "+k+" ha sido eliminado de la LDD!");
            numNodos--;
        }
        return Lista;
    }
    
    //Método para devolver el número de nodos que contiene la LDD.
    public int getNumNodos(){ 
        return numNodos;
    }
}