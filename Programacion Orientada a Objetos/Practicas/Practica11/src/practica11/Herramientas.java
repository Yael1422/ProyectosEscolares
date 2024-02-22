package practica11;

import javax.swing.JOptionPane;


public class Herramientas {

//++//++//++//++//++//++//++//++//++//++//++//++//++//++
    public double validacion(String preg){//Rutina de validación que verifica que no se ingresen cadenas y que solo acepte valores enteros.
        boolean b,b1;
        double can=0;
        do{
            b=true;
            try{
                do{
                    b1=true;
                    can=Integer.parseInt(JOptionPane.showInputDialog(preg));
                    if(can>0) 	b1=false;
                    else 	JOptionPane.showMessageDialog(null,"Error, ingresa un valor entero.");
                }while(b1==true);
            }
            catch(NumberFormatException e){//Captura de la excepción lanzada en try.
                JOptionPane.showMessageDialog(null,"ERROR, no es válido ingresar texto!!!");
                b=false;
            }
        }while(!b);
        return can;
    }    
    
//++//++//++//++//++//++//++//++//++//++//++//++//++//++
   public int opcionMenu(String opciones,int numOpciones){
        int Op=0;
        do{
            Op=(int) validacion(opciones);
        }while(Op<1||Op>numOpciones);
        return Op;
   }
   
//++//++//++//++//++//++//++//++//++//++//++//++//++//++
    public char menuDesplegable(Object ops[],String m,String tipo){
    	Object op=JOptionPane.showInputDialog(null,m,tipo,3,null,ops,ops[0]);
    	char opcion=op.toString().charAt(0);
    	return opcion;
    }
    
//++//++//++//++//++//++//++//++//++//++//++//++//++//++
    public void msj(String m){
        JOptionPane.showMessageDialog(null, m);
    }
    
//++//++//++//++//++//++//++//++//++//++//++//++//++//++
    public String ingresa(String m){
        return JOptionPane.showInputDialog(m);
    }
    
//++//++//++//++//++//++//++//++//++//++//++//++//++//++
    public int ingresaEntero(String num){
        return Integer.parseInt(JOptionPane.showInputDialog(num));
    }
}
