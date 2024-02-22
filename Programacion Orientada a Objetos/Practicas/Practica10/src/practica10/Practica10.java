/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package practica10;
import java.util.Scanner;
import javax.swing.JOptionPane;
/**
 *
 * @author poo01alu10
 */
public class Practica10 {

    int k; 
    double coeficientes[] = new double[3];
    double d;
    String cad;
    Herramientas tools = new Herramientas();
  
    
    public void ingresaEc()
    {
        JOptionPane.showMessageDialog(null,"Ingresaras los valores de a(x\u00B2) , b(x) y c para la ecuacion de segundo grado\n");
       
        coeficientes[0]=tools.validacion("Ingresa el valor de a:\t");
        
        coeficientes[1]=tools.validacion("Ingresa el valor de b:\t");
        
        coeficientes[2]=tools.validacion("Ingresa el valor de c:\t");
         
    }
    
    public void imprimeEc()
    {
        JOptionPane.showMessageDialog(null,"\tLa ecuacion es: \n");
        
        JOptionPane.showMessageDialog(null,coeficientes[0]+"x\u00B2"+" + "+coeficientes[1]+"x"+" + "+coeficientes[2]);
    }
    
    public void calcularD()throws raicesRealesComplejas, raicesRealesRepetidas
    {
        double a=coeficientes[0];
        double b=coeficientes[1];
        double c=coeficientes[2];
        double resultado1;
        double resultado2;
        
        double D = ((b*b)-(4*a*c));
        if(D==0)
        {
            throw new raicesRealesRepetidas();
        }
        if(D<0)
        {
              throw new raicesRealesComplejas();
        }
        if(D>0)
        {
            D=Math.sqrt(D);
            resultado1= ((-b)+ D)/(2*a);
            resultado2= ((-b)- D)/(2*a);
            JOptionPane.showMessageDialog(null, "La primer raiz es: "+ resultado1);
            JOptionPane.showMessageDialog(null, "La segunda raiz es: "+ resultado2);
        }
    }
    
    public static void main(String[] args)  {
        
        int resp=0;
        String respu="";
        Practica10 principal = new Practica10();
        Scanner sc = new Scanner(System.in);
        Herramientas t = new Herramientas();
        do{
            
            try{
                principal.ingresaEc();
                principal.imprimeEc();
                principal.calcularD();
                
            }catch(raicesRealesComplejas rc){
               t.msj("Las raices son complejas");
                
            }catch(raicesRealesRepetidas rp){
                t.msj("Discriminante igual a 0");
            }
            
            respu = JOptionPane.showInputDialog("Quieres ingresar otra ecuacion: \n1.- Si\nOtro.- No");
            resp = Integer.parseInt(respu);
            
        }while(resp==1);
        
    }
    
}

 class raicesRealesComplejas extends Exception{
    
    public raicesRealesComplejas()
    {
        super("El discriminante es menor a 0");
    }
    
}

class raicesRealesRepetidas extends Exception{
    
    public raicesRealesRepetidas()
    {
        super("El discriminante es igual a 0");
    }
    
}
