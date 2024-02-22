package practica7;


import practica7.Consultor;
import javax.swing.JOptionPane; //Para sacar la pantallita y se vea mas elegante


/**
 *
 * @author JOSEEDUARDOVILLAHERR
 */
public class Ejecutable {
    
    //Declaraciòn de referencias y objetos
        static Consultor con = new Consultor(); //Se crea una instancia de la clase derivada
        static String cadena = "";
       //Son variables de clase y se modificn por todas los metodos de la clase
        
        static Empleado emp = new Empleado();
        
    public static void prueba1()
    {
        
        con.setNombre("Braulio");
        con.setNSS("1001");
        con.setPuesto("Consultor 1");
        
        cadena="Prueba Herencia 1:  \n";
        cadena += "*Nombre: "+ con.getNombre() + "\n";
        cadena += "\t--> *Nss de "+ con.getNombre()+ ": "+con.getNSS() + "\n";
        cadena += "\t--> *Puesto de " + con.getNombre() + ": " + con.getPuesto() +"\n";
        
        System.out.print(cadena);
        System.out.println("-----------------------------");  //actividades de practica a)
        
        emp.setNombre("Braulio 2");
        emp.setNSS("1002");
        emp.setPuesto("Empleado 2");
        
        cadena="Prueba Herencia 2 con una variable de tipo empleado:  \n";
        cadena += "*Nombre: "+ emp.getNombre() + "\n";
        cadena += "\t--> *Nss de "+ emp.getNombre()+ ": "+emp.getNSS() + "\n";
        cadena += "\t--> *Puesto de " + emp.getNombre() + ": " + emp.getPuesto() +"\n";
        
        System.out.print(cadena);
        
        
    }
    
    public static void pruebaInstancias()
    {
        System.out.println("PRUEBA DE INSTANCIAS EN LA HERENCIA SIMPLE: ");
        
        if(con instanceof Consultor) //se pregunta si con es una instancia de la clase derivada
            System.out.println("\t "+ con + " es una instancia de Consultor.");
        if(con instanceof Trabajador) //se pregunta si con es una instancia de la clase base
            System.out.println("\t "+ con + " es una instancia de Trabajador.");
        // con no se puede comparar con otro tipo de dato de clase derivada que no sea consultor
        /*if(con instanceof Empleado) 
            System.out.println("\t "+ con + " es una instancia de Empleado.");
        */
        System.out.println("------------------------\n");
        System.out.println("PRUEBA DE INSTANCIAS EN LA HERENCIA SIMPLE 2: ");
        
        if(emp instanceof Empleado) //se pregunta si con es una instancia de la clase derivada
            System.out.println("\t "+ emp + " es una instancia de Empleado.");
        if(emp instanceof Trabajador) //se pregunta si con es una instancia de la clase base
            System.out.println("\t "+ emp + " es una instancia de Trabajador.");
    }
    
    public static void pruebaToString()
    {
        cadena = "Prueba de Sobreescritura de Mètodos (toString)";
        
        con = new Consultor("Otro Braulio", "Consultor 2", "1001",20,500);
        //Reasignacion comn el constructor reasignado de la clase principal
        
        System.out.println(cadena + "\n\t" + con);
        
        System.out.println("\n ------------------------");
        cadena = "Prueba de Sobreescritura de Mètodos (toString) pero con la variable emp de tipo";
        
        emp = new Empleado("Otro Braulio 2 ", "Empleado 3", "1002",20,500);
        //Reasignacion comn el constructor reasignado de la clase principal
        
        System.out.println(cadena + "\n\t" + emp);
    }
    
    public static void vectorPoli()
    {
        String cadena = "PRUEBA DEL VECTOR POLIMORFICO 'Trabajador':\n ";
        Trabajador vPoli[] = new Trabajador[2]; //vectores de objetos personalizado(polimorfico)
        vPoli[0] = new Empleado();
        //con el contructor por defecto de Empleado la posicion 0 se comportara como empleado
        vPoli[0].setNombre("Braulio Polimorfico");
        vPoli[0].setPuesto("Empleado Polimorfico");
        vPoli[0].setNSS("1005");
        
        vPoli[1] = new Consultor("Jose","Consultor Polimorfico", "1001", 20, 600); //usando el consultor personalizado no se usan los metodos set y get 
        
        System.out.println(cadena + vPoli[0] + "\n" + vPoli[1]); // imprimira lo que tienen los toString que se redefinieron en las clases derivadas
                  
    }
    
    public static void menu()
    {
        String m;
        int op=0;
        do
        {
            m= " Prueba de metodos estudiados en el Tema 3. \n ";
            m+= "1.- prueba1() \n 2.- Prueba Instancias() \n 3.- Prueba to String() \n 4.- Vector Poli()\n 5.- Salir: \n";
            op = Integer.parseInt(JOptionPane.showInputDialog(m));
            switch(op)
            {
                case 1:
                    prueba1(); 
                break;
                
                case 2:
                    pruebaInstancias();
                break;
                
                case 3:
                    pruebaToString();
                break;
                
                case 4:
                    vectorPoli();
                break;
                
                case 5:{
                    System.out.println("Hasta Luego");
                    JOptionPane.showMessageDialog(null, "Hasta luego");
                }
                break;
                
                default:{
                    System.out.println("Opcion No valida");
                    JOptionPane.showMessageDialog(null, "Opcion no valida");
                }
                 break;   
            }
            
        }while(op!=5);
    }
    
    public static void main(String[] POO){
        
        menu();
        
        //vectorPoli();
        //prueba1();
        //pruebaInstancias();
        //pruebaToString();
        /*// Declaración de variables
        Trabajador t;
        Empleado e;
        Consultor c;
        // Creación de objetos
        t = new Trabajador ("Juan", "456");
        e = new Empleado ("Jose", "123", 24000.0);
        c = new Consultor ("Juan", "456", 10, 50.0);
        // Salida estándar con toString()
        System.out.println(t);
        System.out.println(e);
        System.out.println(c);
        // Comparación de objetos con equals()
        System.out.println(t.equals(e));
        System.out.println(t.equals(c));
        

*/
    }
}