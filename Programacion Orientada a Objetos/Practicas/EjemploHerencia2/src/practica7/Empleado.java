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
public class Empleado extends Trabajador{
    private double sueldo;
    private int horas;
    private double impuestos;
    private final int PAGAS = 14;
    
    public Empleado(){}
    // Constructor
    public Empleado(String nombre, String puesto, String NSS , int horas, double sueldo){
        super(nombre,puesto,NSS);
        //super();
        this.sueldo = sueldo;
        this.horas = horas;
        //this.impuestos = 0.3 * sueldo;
    } 
    // Nómina
    public double calcularPaga (){
        return (sueldo-impuestos)/PAGAS;
    } 
    // toString SOBRESCRITO
    public String toString (){
        return "Empleado "+super.toString(); // Con super se llama a algun elemento visible de la clase trabajador
    }
}
