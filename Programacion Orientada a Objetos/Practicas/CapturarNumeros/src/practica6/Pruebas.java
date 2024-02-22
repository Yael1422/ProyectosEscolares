package practica6;

import java.util.Scanner;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author poo01alu30
 */
public class Pruebas {
    private static Operaciones op = new Operaciones();
    
    public static void capturarNumeros(){
        Scanner sc = new Scanner(System.in);
        int captura = 0;
        
        System.out.println("Ingrese la parte ENTERA de n1:");
        captura = sc.nextInt();
        op.getN1().setEntDec(captura);
        
        System.out.println("Ingrese la parte FRACCIONARIA de n1:");
        captura = sc.nextInt();
        op.getN1().setFraccDec(captura);       
        
        System.out.println("Ingrese la parte ENTERA de n2:");
        captura = sc.nextInt();
        op.getN2().setEntDec(captura);
        
        System.out.println("Ingrese la parte FRACCIONARIA de n2:");
        captura = sc.nextInt();
        op.getN2().setFraccDec(captura); 
        
        System.out.println("Numeros capturados con exito");
        System.out.println("n1 = " +op.getN1().getEntDec()+"."+op.getN1().getFraccDec());
        System.out.println("n2 = " +op.getN2().getEntDec()+"."+op.getN2().getFraccDec());
        
        op.decAbin();
    }
    
    public static void main(String[] POO){
        capturarNumeros();
    }
}