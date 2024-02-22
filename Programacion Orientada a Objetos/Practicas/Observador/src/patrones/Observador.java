//Programa adaptado de: Sarcar, V. (2019). Java Design Patterns. In Java Design Patterns. https://doi.org/10.1007/978-1-4842-4078-6
package patrones;

import java.util.ArrayList;
import java.util.List;

//--////--////--////--////--////--////--////--////--////--////--////--////--////--////--////--////--//
interface Observer{
    void update(int updatedValue);
}

//--////--////--////--////--////--////--////--////--////--////--////--////--////--////--////--////--//
class ObserverType1 implements Observer{
    String nameOfObserver;
    public ObserverType1(String name){
        this.nameOfObserver = name;
    }   
    @Override
    public void update(int updatedValue) {
        System.out.println(nameOfObserver+" ha recibido una alerta, y el valor actual de 'updatedValue' es: "+ updatedValue);
    }
}

//--////--////--////--////--////--////--////--////--////--////--////--////--////--////--////--////--//
class ObserverType2 implements Observer{
    String nameOfObserver;
    public ObserverType2(String name){
            this.nameOfObserver = name;
    }
    @Override
    public void update(int updatedValue) {
        System.out.println(nameOfObserver+" ha recibido una alerta, y el valor actual de 'updatedValue' es: "+ updatedValue);
    }
}

//--////--////--////--////--////--////--////--////--////--////--////--////--////--////--////--////--//
interface SubjectInterface{
    void register(Observer anObserver);
    void unregister(Observer anObserver);
    void notifyRegisteredUsers(int notifiedValue);
}

//--////--////--////--////--////--////--////--////--////--////--////--////--////--////--////--////--//
class Subject implements SubjectInterface{
    private int flag;
    List<Observer> observerList = new ArrayList<Observer>();    //Creación de una lista de los 'n' observadores.
    //--////--////--////--////--////--////--//
    public int getFlag() {
        return flag;
    }
    //--////--////--////--////--////--////--//
    public void setFlag(int flag) {
        this.flag = flag;        
        //Valor de bandera cambiado, por lo que hay que notificar a los usuarios/observadores.
        notifyRegisteredUsers(flag);
    }
    //--////--////--////--////--////--////--//
    @Override
    public void register(Observer anObserver){
        observerList.add(anObserver);
    }
    //--////--////--////--////--////--////--//
    @Override
    public void unregister(Observer anObserver) {
        observerList.remove(anObserver);		
    }
    @Override
    public void notifyRegisteredUsers(int updatedValue){
        observerList.forEach((observer) -> {observer.update(updatedValue);});
    }
}

//--////--////--////--////--////--////--////--////--////--////--////--////--////--////--////--////--//
public class Observador {
    public static void main(String[] args) {
        System.out.println(" -->PROGRAMA MUESTRA SOBRE EL USO DEL DISEÑO DE PATRÓN DE COMPORTAMIENTO TIPO OBSERVER <--\n");
        //Declaración de los siguientes observadores:
        Observer myObserver1 = new ObserverType1("El observador");
        Observer myObserver2 = new ObserverType1("El chismoso");
        Observer myObserver3 = new ObserverType2("El inspector");
        //Alta de los observadores declarados:
        subject.register(myObserver1);
        subject.register(myObserver2);
        subject.register(myObserver3);
        //Bandera de configuración fijada hacia TODOS los observadores:
        System.out.println("\n Bandera de configuración fijada = 5.");
        subject.setFlag(5);           
        //Baja del observador 2:
        subject.unregister(myObserver2);
        //Bandera de configuración fijada hacia TODOS los observadores:
        System.out.println("\n Bandera de configuración fijada = 50.");
        subject.setFlag(50);
        //Alta (otra vez) del observador 2:
        subject.register(myObserver2);
        //Bandera de configuración fijada hacia TODOS los observadores:
        System.out.println("\n Bandera de configuración fijada = 100.");
        subject.setFlag(100);
    }
}