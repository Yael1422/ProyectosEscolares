/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package practica_12;

class Mensaje{
    private String mensaje;
    private boolean ocupado;
    
    public Mensaje(){
        mensaje="Ping";
        ocupado=false;
        
    }
    public synchronized String getMensaje(){
        while(ocupado==true){
            try{
                wait();
            }catch(InterruptedException ie){
                System.out.println("Fue Capturada la excepcion de tipo --InterruptedException--\n ");
                
            }
        }
        ocupado=true;
        if((mensaje.compareTo("Ping")==0)){
            mensaje="Pong";
        }else if((mensaje.compareTo("Pong")==0)){
            mensaje="Pang";
        }else if((mensaje.compareTo("Pang")==0)){
            mensaje="Ping";
        }
        ocupado=false;
        notify();
        return mensaje;
    }
}
class Ping extends Thread{
    Mensaje men;
    
    public Ping(Mensaje men){
        this.men=men;
    }
    
    public void run(){
        for(int i=0;i<5;i++){
            System.out.println("Hilo 1 Interaccion "+i+ " "+men.getMensaje());
        }
    }
    
}
class Pong extends Thread{
    Mensaje men;
    
    public Pong(Mensaje men){
        this.men=men;
    }
    
    public void run(){
        for (int i=0;i<5;i++){
            System.out.println("Hilo 2 Interaccion "+i+ " "+men.getMensaje());
        }
    }
    
}
//Actividad adicional
class Pang extends Thread{
    Mensaje men;
    
    public Pang(Mensaje men){
        this.men=men;
    }
    
    public void run(){
        for (int x=0;x<5;x++){
            System.out.println("Hilo 3 Interaccion "+x+ " "+men.getMensaje());
        }
    }
    
}

public class Practica_12{
    public static void main(String[] EMMA){
        Mensaje msj=new Mensaje();
        Ping hilo1=new Ping(msj);
        Pong hilo2=new Pong(msj);
        Pang hilo3=new Pang(msj);
        hilo1.start();
        hilo2.start();
        hilo3.start();
        
        
    }
}

    

