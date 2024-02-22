/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author poo01alu30
 */
package practica6;

public class Operaciones {
    private Numero n1 = new Numero();
    private Numero n2 = new Numero ();
    
    //Metodos encapsulados
    public Numero getN1() {
        return n1;
    }

    public void setN1(Numero n1) {
        this.n1 = n1;
    }

    public Numero getN2() {
        return n2;
    }

    public void setN2(Numero n2) {
        this.n2 = n2;
    }
    
    public void decAbin(){  //Metodo que convierte el numero de decimal a binario
        
        int numero ;
        String binario = "";  //Cadena que nos imprimira el resultado en binario
        
        //Entero n1
        numero = n1.getEntDec();  //Solicita el numero entero decimal y lo guarda en la variable
        if(numero > 0){  //Compara que el numero no sea negativo
            while(numero > 0){  //Compara que el numero no se haga 0
                if (numero % 2 == 0){  //Si el modulo es 0, entonces realiza lo siguiente
                    binario = "0" + binario;
                } else{  //Contrario
                    binario = "1" + binario;
                }
                numero = (int) numero/2;  //Divide el numero para pasar al siguiente digito decimal
            }
        } else if (numero == 0){  //Si el numero es 0, devuelve su binario
            binario = "0";
        } else {  //Si el numero es negativo, arroja el mensaje
            binario = "Introduce unicamente numeros positivos";
        }
        n1.setEntBin(binario);  //Guarda el resultado binario en el numero n1 en su campo entero binario
        
        
        //Realiza lo mismo en los demas numeros, tanto fraccionarios como enteros
        
        //Fraccionario n1
        numero = n1.getFraccDec();
        binario = Integer.toBinaryString(numero);
        n1.setFraccBin(binario);
        
        System.out.println("Numero binario: "+n1.getEntBin()+"."+n1.getFraccBin());
        
        //Entero n2
        numero = n2.getEntDec();
        binario = "";
        if(numero > 0){
            while(numero > 0){
                if (numero % 2 == 0){
                    binario = "0" + binario;
                } else{
                    binario = "1" + binario;
                }
                numero = (int) numero/2;
            }
        } else if (numero == 0){
            binario = "0";
        } else {
            binario = "Introduce unicamente numeros positivos";
        }
        n2.setEntBin(binario);
        
        //Fraccionario n2
        numero = n2.getFraccDec();
        binario = Integer.toBinaryString(numero);
        n2.setFraccBin(binario);
        
        System.out.println("Numero binario: "+n2.getEntBin()+"."+n2.getFraccBin());
    }
}
