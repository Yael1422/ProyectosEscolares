
package gimnasio;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.logging.Level;
import java.util.logging.Logger;

public class ArchivoUsuario {
    private File archivo;
    
    public void crearArchivo(){
        archivo = new File("Usuarios.txt");
        
        try {
            if(archivo.createNewFile()){
                
            }
        } catch (IOException ex) {
            System.err.println("Error, "+ex);
        }
    }
    
    public void escribirTexto(Usuario persona){
        try {
            FileWriter escribir = new FileWriter(archivo, true);
            escribir.write(persona.getNombre()+"\t"+persona.getContraseña()+"\t"+persona.getEdad()+"\t"+persona.getAltura()+"\t"+persona.getPeso()+"\r\n");
            escribir.close();
        } catch (IOException ex) {
            System.err.println("Error, "+ex);
        }
    }
}
