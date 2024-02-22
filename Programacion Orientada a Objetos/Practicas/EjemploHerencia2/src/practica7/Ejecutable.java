package practica7;


import practica7.Consultor;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

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
    
    public static void main(String[] POO){
        
        prueba1();
        pruebaInstancias();
        pruebaToString();
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
