package practica11;

import javax.swing.*;
import java.io.Serializable;

class Usuarios implements Serializable{
    
    private String nombre;
    private String apellido;
    private int edad;
    private double peso;
    private String contrasena;
    
    
    public Usuarios( String nombre, String apellido, int edad, double peso, String contrasena){
        this.nombre = nombre;
        this.apellido = apellido;
        this.edad = edad;
        this.peso= peso;
        this.contrasena = contrasena;
    }

    Usuarios() {
        throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
    }
        
    public void setNombre(){
        this.nombre = nombre;
    }
        
    public String getNombre(){
        return nombre;
    }
        
    public void setEdad(){
        this.edad = edad;
    }
        
    public int getEdad(){
        return edad;
    }
        
    public void setPeso(){
        this.peso = peso;
    }
        
    public double getPeso(){
        return peso;
    }
        
    public void setContrasena(){
        this.contrasena = contrasena;
    }
        
    public String getContrasena(){
        return contrasena;
    }
    
    public void setApellido(){
        this.apellido = apellido;
    }
        
    public String getApellido(){
        return apellido;
    }
    
    public static void main(String[] args) throws ClassNotFoundException{
        Serializar obj = new Serializar();
        obj.menu();
        
    }
}
    