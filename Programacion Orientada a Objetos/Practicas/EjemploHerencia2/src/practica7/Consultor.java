package practica7;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author JOSEEDUARDOVILLAHERR
 */
class Consultor extends Trabajador{
    private int horas;
    private double tarifa;
    
    public Consultor(){}
    // Constructor
    public Consultor(String nombre, String puesto, String NSS, int horas, double tarifa){
        
        //se llama de forma explicita a que se construya el constructor de la clase base
        super(nombre,puesto,NSS); //require los parametros del constructor de la clase base
        this.horas = horas;
        this.tarifa = tarifa;
    } 
    // Paga por horas
    public double calcularPaga(){
        return horas*tarifa;
    } 
    // toString SOBRESCRITO
    public String toString(){
        return "Consultor "+super.toString() + "\tSueldo: $" +calcularPaga();//con super se llama a algun elemento de la clase base solo a elementos visibles
        
    }  
}
