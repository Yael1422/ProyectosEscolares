package practica11;

import java.io.*;
import java.util.ArrayList;
import java.util.Iterator;

public class Serializar {
    ObjectOutputStream oos;
    ObjectInputStream ois;
    FileOutputStream fos;
    FileInputStream fis;
    File archivo;
    Usuarios nvoUsuario;
  
    Herramientas tools = new Herramientas();
    ArrayList<Usuarios> listado = new ArrayList<Usuarios>();
    
    public void capturaDatos(){
        String nombre = tools.ingresa("Ingresa tu nombre");
        String apellido = tools.ingresa("Ingresa un apellido");
        int edad = (int) tools.validacion("Introduce tu edad");
        double peso = tools.validacion("Introduce tu peso");
        String contrasena = tools.ingresa("Introduce tu contrasena");
        nvoUsuario = new Usuarios(nombre, apellido, edad, peso, contrasena);
       
    }
    
    public void escribirArchivo(){
        capturaDatos();
        try{ 
           
            archivo = new File("usuarios.txt");
            fos = new FileOutputStream(archivo);
            oos = new ObjectOutputStream(fos);
            oos.writeObject(nvoUsuario);
            listado.add(nvoUsuario);
            
            
        }
        catch(IOException e){
            e.printStackTrace();
        }finally{
            try{
                if(oos != null) oos.close();
            }
            catch(IOException ex){
                System.out.println("Error al cerrar el archivo");
            }
        }
    }
    
    public void leerArchivo() throws ClassNotFoundException{
        String cadena = "";
        try{
            
            archivo = new File("usuarios.txt");
            fis = new FileInputStream(archivo);
            ois = new ObjectInputStream(fis);
            
           
                
                for(Usuarios nvoUsuario : listado)
                {
                cadena = "\n\t *Nombre: "+nvoUsuario.getNombre();
                cadena += "\n\t *Apellido: "+nvoUsuario.getApellido();
                cadena += "\n\t *Edad: "+nvoUsuario.getEdad();
                cadena += "\n\t *Peso: "+nvoUsuario.getPeso();
                cadena += "\n\t *Contrasena: "+nvoUsuario.getContrasena();
                tools.msj(cadena);
                }
                
            
        }catch(EOFException eof){
            tools.msj("Ya no hay mas registros");
            
        }
        catch(IOException e){
            System.out.println("No se encuentra el archivo");
        }
    }
    
    public void menu() throws ClassNotFoundException{
        String cad = "MENU DE OPCIONES";
        boolean bandera = true;
        cad += "\n\t 1. Leer Archivo";
        cad += "\n\t 2. Escribir Archivo";
        cad += "\n\t 3. Salir";
    
        do{
            int op = tools.opcionMenu(cad, 4);
            switch(op){
                case 1:{
                    leerArchivo();
                    break;
                }
                case 2:{
                    escribirArchivo();
                    break;
                }
                case 3:{
                    System.out.println("Hasta luego");
                    bandera = false;
                    break;
                }
            }                    
        } while(bandera);
    }
}

