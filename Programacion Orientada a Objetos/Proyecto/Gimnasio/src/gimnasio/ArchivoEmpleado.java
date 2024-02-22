
package gimnasio;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.logging.Level;
import java.util.logging.Logger;

public class ArchivoEmpleado {
    private File archivo;
    
    public void crearArchivo(){
        archivo = new File("Empleado.txt");
        
        try {
            if(archivo.createNewFile()){
                
            }
        } catch (IOException ex) {
            System.err.println("Error, "+ex);
        }
    }
    
    public void escribirTexto(Empleado empleado){
        try {
            FileWriter escribir = new FileWriter(archivo, true);
            escribir.write(empleado.getNombre()+"\t"+empleado.getContraseña()+"\t"+empleado.getEdad()+"\r\n");
            escribir.close();
        } catch (IOException ex) {
            System.err.println("Error, "+ex);
        }
    }
}
