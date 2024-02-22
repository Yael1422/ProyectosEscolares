
package Empleado;

import Empleado.VentanaAgregarUsuario;
import com.mysql.jdbc.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import javax.swing.JOptionPane;

public class VentanaBuscarUsuario extends javax.swing.JFrame {

    public static final String URL = "jdbc:mysql://localhost:3306/gimnasio?autoReconnet=true&useSSL=false";
    public static final String usuario = "root";
    public static final String contraseña = "P315252884";
    PreparedStatement ps;
    ResultSet rs;
    
    public VentanaBuscarUsuario() {
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
    
    public void limpiarCajas(){
        cajaIdPersona.setText(null);
        cajaNombre.setText(null);
        cajaContraseña.setText(null);
        cajaEdad.setText(null);
        cajaAltura.setText(null);
        cajaPeso.setText(null);
    }
    
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jPanel1 = new javax.swing.JPanel();
        botonBuscarUsuario = new javax.swing.JButton();
        letreroNombre = new javax.swing.JLabel();
        LetreroBuscarUsuario = new javax.swing.JLabel();
        cajaNombre = new javax.swing.JTextField();
        letreroContraseña = new javax.swing.JLabel();
        cajaContraseña = new javax.swing.JTextField();
        letreroEdad = new javax.swing.JLabel();
        cajaEdad = new javax.swing.JTextField();
        cajaPeso = new javax.swing.JTextField();
        cajaAltura = new javax.swing.JTextField();
        letreroAltura = new javax.swing.JLabel();
        letreroPeso = new javax.swing.JLabel();
        botonRegresar = new javax.swing.JButton();
        letreroIdPersona = new javax.swing.JLabel();
        cajaIdPersona = new javax.swing.JTextField();
        jLabel2 = new javax.swing.JLabel();
        botonLimpiar = new javax.swing.JButton();
        jLabel1 = new javax.swing.JLabel();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        setUndecorated(true);
        setResizable(false);

        jPanel1.setLayout(new org.netbeans.lib.awtextra.AbsoluteLayout());

        botonBuscarUsuario.setBackground(new java.awt.Color(0, 0, 153));
        botonBuscarUsuario.setForeground(new java.awt.Color(255, 255, 255));
        botonBuscarUsuario.setText("Buscar Usuario");
        botonBuscarUsuario.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                botonBuscarUsuarioActionPerformed(evt);
            }
        });
        jPanel1.add(botonBuscarUsuario, new org.netbeans.lib.awtextra.AbsoluteConstraints(100, 350, -1, -1));

        letreroNombre.setFont(new java.awt.Font("Tahoma", 0, 14)); // NOI18N
        letreroNombre.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        letreroNombre.setText("Nombre");
        jPanel1.add(letreroNombre, new org.netbeans.lib.awtextra.AbsoluteConstraints(10, 150, 70, -1));

        LetreroBuscarUsuario.setFont(new java.awt.Font("Tahoma", 1, 18)); // NOI18N
        LetreroBuscarUsuario.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        LetreroBuscarUsuario.setText("Buscar Usuario");
        jPanel1.add(LetreroBuscarUsuario, new org.netbeans.lib.awtextra.AbsoluteConstraints(0, 60, 300, -1));
        jPanel1.add(cajaNombre, new org.netbeans.lib.awtextra.AbsoluteConstraints(90, 150, 200, -1));

        letreroContraseña.setFont(new java.awt.Font("Tahoma", 0, 14)); // NOI18N
        letreroContraseña.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        letreroContraseña.setText("Contraseña");
        jPanel1.add(letreroContraseña, new org.netbeans.lib.awtextra.AbsoluteConstraints(10, 190, -1, -1));

        cajaContraseña.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                cajaContraseñaActionPerformed(evt);
            }
        });
        jPanel1.add(cajaContraseña, new org.netbeans.lib.awtextra.AbsoluteConstraints(90, 190, 200, -1));

        letreroEdad.setFont(new java.awt.Font("Tahoma", 0, 14)); // NOI18N
        letreroEdad.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        letreroEdad.setText("Edad");
        jPanel1.add(letreroEdad, new org.netbeans.lib.awtextra.AbsoluteConstraints(10, 230, 70, -1));
        jPanel1.add(cajaEdad, new org.netbeans.lib.awtextra.AbsoluteConstraints(90, 230, 200, -1));
        jPanel1.add(cajaPeso, new org.netbeans.lib.awtextra.AbsoluteConstraints(90, 270, 200, -1));
        jPanel1.add(cajaAltura, new org.netbeans.lib.awtextra.AbsoluteConstraints(90, 310, 200, -1));

        letreroAltura.setFont(new java.awt.Font("Tahoma", 0, 14)); // NOI18N
        letreroAltura.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        letreroAltura.setText("Altura");
        jPanel1.add(letreroAltura, new org.netbeans.lib.awtextra.AbsoluteConstraints(10, 270, 70, -1));

        letreroPeso.setFont(new java.awt.Font("Tahoma", 0, 14)); // NOI18N
        letreroPeso.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        letreroPeso.setText("Peso");
        jPanel1.add(letreroPeso, new org.netbeans.lib.awtextra.AbsoluteConstraints(10, 310, 70, -1));

        botonRegresar.setBackground(new java.awt.Color(0, 0, 153));
        botonRegresar.setForeground(new java.awt.Color(255, 255, 255));
        botonRegresar.setText("Regresar");
        botonRegresar.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                botonRegresarActionPerformed(evt);
            }
        });
        jPanel1.add(botonRegresar, new org.netbeans.lib.awtextra.AbsoluteConstraints(220, 10, -1, -1));

        letreroIdPersona.setFont(new java.awt.Font("Tahoma", 0, 14)); // NOI18N
        letreroIdPersona.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        letreroIdPersona.setText("ID");
        jPanel1.add(letreroIdPersona, new org.netbeans.lib.awtextra.AbsoluteConstraints(10, 110, 70, -1));

        cajaIdPersona.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                cajaIdPersonaActionPerformed(evt);
            }
        });
        jPanel1.add(cajaIdPersona, new org.netbeans.lib.awtextra.AbsoluteConstraints(90, 110, 200, -1));

        jLabel2.setIcon(new javax.swing.ImageIcon(getClass().getResource("/Imagenes/buscarUsuario.png"))); // NOI18N
        jPanel1.add(jLabel2, new org.netbeans.lib.awtextra.AbsoluteConstraints(10, 10, 40, 40));

        botonLimpiar.setBackground(new java.awt.Color(0, 0, 153));
        botonLimpiar.setFont(new java.awt.Font("Tahoma", 0, 10)); // NOI18N
        botonLimpiar.setForeground(new java.awt.Color(255, 255, 255));
        botonLimpiar.setText("Limpiar");
        botonLimpiar.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                botonLimpiarActionPerformed(evt);
            }
        });
        jPanel1.add(botonLimpiar, new org.netbeans.lib.awtextra.AbsoluteConstraints(10, 370, -1, -1));

        jLabel1.setIcon(new javax.swing.ImageIcon(getClass().getResource("/Imagenes/fondoMenuPrincipal.jpg"))); // NOI18N
        jPanel1.add(jLabel1, new org.netbeans.lib.awtextra.AbsoluteConstraints(0, 0, 300, 400));

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

    private void botonBuscarUsuarioActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_botonBuscarUsuarioActionPerformed
        Connection conexion = null;
        
        try{
            conexion = getConnection();
            ps = conexion.prepareStatement("select * from usuarios where idPersona=?");
            ps.setString(1, cajaIdPersona.getText());
            
            rs = ps.executeQuery(); //Ejecuta la insersion a la BD
            
            if(rs.next()){
                cajaNombre.setText(rs.getString("Nombre"));
                cajaContraseña.setText(rs.getString("Contraseña"));
                cajaEdad.setText(rs.getString("Edad"));
                cajaAltura.setText(rs.getString("Altura"));
                cajaPeso.setText(rs.getString("Peso"));
            }
            else{
                JOptionPane.showMessageDialog(null, "Error al buscar el registro");
                limpiarCajas();
            }
            conexion.close();
            
        }catch(Exception ex){
            System.err.println("Error: "+ex);
        }
        
    }//GEN-LAST:event_botonBuscarUsuarioActionPerformed

    private void cajaContraseñaActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_cajaContraseñaActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_cajaContraseñaActionPerformed

    private void botonRegresarActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_botonRegresarActionPerformed
        VentanaEmpleado ventana = new VentanaEmpleado();
        ventana.setVisible(true);
        
        dispose();
    }//GEN-LAST:event_botonRegresarActionPerformed

    private void botonLimpiarActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_botonLimpiarActionPerformed
        limpiarCajas();
    }//GEN-LAST:event_botonLimpiarActionPerformed

    private void cajaIdPersonaActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_cajaIdPersonaActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_cajaIdPersonaActionPerformed

    /**
     * @param args the command line arguments
     */
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
            java.util.logging.Logger.getLogger(VentanaAgregarUsuario.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(VentanaAgregarUsuario.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(VentanaAgregarUsuario.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(VentanaAgregarUsuario.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>
        //</editor-fold>

        /* Create and display the form */
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new VentanaAgregarUsuario().setVisible(true);
            }
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JLabel LetreroBuscarUsuario;
    private javax.swing.JButton botonBuscarUsuario;
    private javax.swing.JButton botonLimpiar;
    private javax.swing.JButton botonRegresar;
    private javax.swing.JTextField cajaAltura;
    private javax.swing.JTextField cajaContraseña;
    private javax.swing.JTextField cajaEdad;
    private javax.swing.JTextField cajaIdPersona;
    private javax.swing.JTextField cajaNombre;
    private javax.swing.JTextField cajaPeso;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JLabel jLabel2;
    private javax.swing.JPanel jPanel1;
    private javax.swing.JLabel letreroAltura;
    private javax.swing.JLabel letreroContraseña;
    private javax.swing.JLabel letreroEdad;
    private javax.swing.JLabel letreroIdPersona;
    private javax.swing.JLabel letreroNombre;
    private javax.swing.JLabel letreroPeso;
    // End of variables declaration//GEN-END:variables
}
