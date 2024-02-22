
package gimnasio;

import Empleado.VentanaEmpleado;
import Usuarios.VentanaUsuario;
import com.mysql.jdbc.Connection;
import static Empleado.VentanaAgregarUsuario.URL;
import static Empleado.VentanaAgregarUsuario.contraseña;
import static Empleado.VentanaAgregarUsuario.usuario;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import javax.swing.JOptionPane;

public class MenúPrincipal extends javax.swing.JFrame {

    
    public static final String URL = "jdbc:mysql://localhost:3306/gimnasio?autoReconnet=true&useSSL=false";
    public static final String usuario = "root";
    public static final String contraseña = "P315252884";
    PreparedStatement ps;
    ResultSet rs;
    
    public MenúPrincipal() {
        initComponents();
        setLocationRelativeTo(null);
    }
    
    public Connection getConnection(){
        Connection conexion = null;
        
        try{
            Class.forName("com.mysql.jdbc.Driver");
            conexion = (Connection) DriverManager.getConnection(URL, usuario, contraseña);
        }catch(Exception ex){
            System.err.println("Error, "+ex);
        }
        return conexion;
    }
    
    public boolean iniciarUsuario(){
        
        String usuarioCorrecto = "";
        String contraseñaCorrecta = "";
        
        Connection conexion = null;
        
        try{
            conexion = getConnection();
            ps = conexion.prepareStatement("select * from Usuarios where Nombre=?");
            ps.setString(1, cajaUsuario.getText());
            
            rs = ps.executeQuery(); //Ejecuta la insersion a la BD
            
            if(rs.next()){
                usuarioCorrecto = rs.getString("Nombre");
                contraseñaCorrecta = rs.getString("Contraseña");
            }else{
                return false;
            }
            conexion.close();
            
        }catch(Exception ex){
            return false;
        }
        
        if(usuarioCorrecto.equals(cajaUsuario.getText())){
            String contraseña = "";
            
            for(int i=0; i<cajaContraseña.getPassword().length; i++){
                contraseña += cajaContraseña.getPassword()[i];
                
            }
            
            if(contraseñaCorrecta.equals(contraseña)){
                return true;
            }
            else{
                return false;
            }
        }
        else{
            return false;
        }
    }
    
    public boolean iniciarEmpleado(){
        
        String usuarioCorrecto = "";
        String contraseñaCorrecta = "";
        
        Connection conexion = null;
        
        try{
            conexion = getConnection();
            ps = conexion.prepareStatement("select * from empleados where Nombre=?");
            ps.setString(1, cajaUsuario.getText());
            
            rs = ps.executeQuery(); //Ejecuta la insersion a la BD
            
            if(rs.next()){
                usuarioCorrecto = rs.getString("Nombre");
                contraseñaCorrecta = rs.getString("Contraseña");
            }
            else{
                return false;
            }
            conexion.close();
            
        }catch(Exception ex){
            System.err.println("Error: "+ex);
        }
        
        if(usuarioCorrecto.equals(cajaUsuario.getText())){
            String contraseña = "";
            
            for(int i=0; i<cajaContraseña.getPassword().length; i++){
                contraseña += cajaContraseña.getPassword()[i];
                
            }
            
            if(contraseñaCorrecta.equals(contraseña)){
                return true;
            }
            else{
                return false;
            }
        }
        else{
            return false;
        }
    }
    
    public boolean iniciarSesion(){
        
        if(iniciarUsuario()){
            VentanaUsuario ventana1 = new VentanaUsuario();
            ventana1.setVisible(true);
        
            dispose();
            return true;
        }
        
        if(iniciarEmpleado()){
            VentanaEmpleado ventanaP = new VentanaEmpleado();
            ventanaP.setVisible(true);
        
            dispose();
            return true;
        }
        return false;
    }
    
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jPanel1 = new javax.swing.JPanel();
        botonIniciarSesion = new javax.swing.JButton();
        cajaUsuario = new javax.swing.JTextField();
        cajaContraseña = new javax.swing.JPasswordField();
        letreroUsuario = new javax.swing.JLabel();
        letreroContraseña = new javax.swing.JLabel();
        botonSalir = new javax.swing.JButton();
        imagen = new javax.swing.JLabel();
        jLabel2 = new javax.swing.JLabel();
        jLabel1 = new javax.swing.JLabel();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        setUndecorated(true);

        jPanel1.setLayout(new org.netbeans.lib.awtextra.AbsoluteLayout());

        botonIniciarSesion.setBackground(new java.awt.Color(0, 0, 153));
        botonIniciarSesion.setFont(new java.awt.Font("Tahoma", 0, 12)); // NOI18N
        botonIniciarSesion.setForeground(new java.awt.Color(255, 255, 255));
        botonIniciarSesion.setText("Iniciar Sesión");
        botonIniciarSesion.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                botonIniciarSesionActionPerformed(evt);
            }
        });
        jPanel1.add(botonIniciarSesion, new org.netbeans.lib.awtextra.AbsoluteConstraints(410, 500, 130, 30));

        cajaUsuario.setFont(new java.awt.Font("Tahoma", 0, 14)); // NOI18N
        jPanel1.add(cajaUsuario, new org.netbeans.lib.awtextra.AbsoluteConstraints(230, 370, 320, 30));

        cajaContraseña.setFont(new java.awt.Font("Tahoma", 0, 14)); // NOI18N
        jPanel1.add(cajaContraseña, new org.netbeans.lib.awtextra.AbsoluteConstraints(230, 430, 320, 30));

        letreroUsuario.setFont(new java.awt.Font("Tahoma", 1, 24)); // NOI18N
        letreroUsuario.setText("USUARIO");
        jPanel1.add(letreroUsuario, new org.netbeans.lib.awtextra.AbsoluteConstraints(50, 370, -1, -1));

        letreroContraseña.setFont(new java.awt.Font("Tahoma", 1, 24)); // NOI18N
        letreroContraseña.setText("CONTRASEÑA");
        jPanel1.add(letreroContraseña, new org.netbeans.lib.awtextra.AbsoluteConstraints(20, 430, -1, -1));

        botonSalir.setBackground(new java.awt.Color(0, 0, 153));
        botonSalir.setFont(new java.awt.Font("Tahoma", 0, 12)); // NOI18N
        botonSalir.setForeground(new java.awt.Color(255, 255, 255));
        botonSalir.setText("Salir");
        botonSalir.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                botonSalirActionPerformed(evt);
            }
        });
        jPanel1.add(botonSalir, new org.netbeans.lib.awtextra.AbsoluteConstraints(500, 20, 70, 30));

        imagen.setIcon(new javax.swing.ImageIcon(getClass().getResource("/Imagenes/muñequito.jpg"))); // NOI18N
        jPanel1.add(imagen, new org.netbeans.lib.awtextra.AbsoluteConstraints(230, 190, 150, 104));

        jLabel2.setFont(new java.awt.Font("Tahoma", 1, 28)); // NOI18N
        jLabel2.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        jLabel2.setText("¡BIENVENIDO A GIMNASIO BODY FIT!");
        jPanel1.add(jLabel2, new org.netbeans.lib.awtextra.AbsoluteConstraints(0, 110, 600, -1));

        jLabel1.setIcon(new javax.swing.ImageIcon(getClass().getResource("/Imagenes/fondoMenuPrincipal.jpg"))); // NOI18N
        jPanel1.add(jLabel1, new org.netbeans.lib.awtextra.AbsoluteConstraints(0, 0, 600, 600));

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(jPanel1, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(jPanel1, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void botonSalirActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_botonSalirActionPerformed
        System.exit(0);
    }//GEN-LAST:event_botonSalirActionPerformed

    private void botonIniciarSesionActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_botonIniciarSesionActionPerformed
        
        if(iniciarSesion()){}
        else{
            JOptionPane.showMessageDialog(null, "Revisa tus datos");
        }
        
    }//GEN-LAST:event_botonIniciarSesionActionPerformed


    public static void main(String args[]) {
        /* Set the Nimbus look and feel */
        //<editor-fold defaultstate="collapsed" desc=" Look and feel setting code (optional) ">
        /* If Nimbus (introduced in Java SE 6) is not available, stay with the default look and feel.
         * For details see http://download.oracle.com/javase/tutorial/uiswing/lookandfeel/plaf.html 
         */
        try {
            for (javax.swing.UIManager.LookAndFeelInfo info : javax.swing.UIManager.getInstalledLookAndFeels()) {
                if ("Nimbus".equals(info.getName())) {
                    javax.swing.UIManager.setLookAndFeel(info.getClassName());
                    break;
                }
            }
        } catch (ClassNotFoundException ex) {
            java.util.logging.Logger.getLogger(MenúPrincipal.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(MenúPrincipal.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(MenúPrincipal.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(MenúPrincipal.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>

        /* Create and display the form */
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new MenúPrincipal().setVisible(true);
            }
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton botonIniciarSesion;
    private javax.swing.JButton botonSalir;
    private javax.swing.JPasswordField cajaContraseña;
    private javax.swing.JTextField cajaUsuario;
    private javax.swing.JLabel imagen;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JLabel jLabel2;
    private javax.swing.JPanel jPanel1;
    private javax.swing.JLabel letreroContraseña;
    private javax.swing.JLabel letreroUsuario;
    // End of variables declaration//GEN-END:variables
}
