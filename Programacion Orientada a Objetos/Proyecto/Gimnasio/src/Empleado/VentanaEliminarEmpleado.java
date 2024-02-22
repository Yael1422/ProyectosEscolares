
package Empleado;

import Empleado.VentanaAgregarUsuario;
import com.mysql.jdbc.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import javax.swing.JOptionPane;

public class VentanaEliminarEmpleado extends javax.swing.JFrame {

    public static final String URL = "jdbc:mysql://localhost:3306/gimnasio?autoReconnet=true&useSSL=false";
    public static final String usuario = "root";
    public static final String contraseña = "P315252884";
    PreparedStatement ps;
    ResultSet rs;
    
    public VentanaEliminarEmpleado() {
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
        cajaIdEmpleado.setText(null);
        cajaNombre.setText(null);
        cajaContraseña.setText(null);
        cajaEdad.setText(null);
    }
    
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jPanel1 = new javax.swing.JPanel();
        botonBuscarEmpleado = new javax.swing.JButton();
        letreroNombre = new javax.swing.JLabel();
        letreroEliminarEmpleado = new javax.swing.JLabel();
        cajaNombre = new javax.swing.JTextField();
        letreroContraseña = new javax.swing.JLabel();
        cajaContraseña = new javax.swing.JTextField();
        letreroEdad = new javax.swing.JLabel();
        cajaEdad = new javax.swing.JTextField();
        botonRegresar = new javax.swing.JButton();
        letreroIdEmpleado = new javax.swing.JLabel();
        cajaIdEmpleado = new javax.swing.JTextField();
        jLabel2 = new javax.swing.JLabel();
        botonLimpiar = new javax.swing.JButton();
        botonEliminar = new javax.swing.JButton();
        jLabel1 = new javax.swing.JLabel();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        setUndecorated(true);
        setResizable(false);

        jPanel1.setLayout(new org.netbeans.lib.awtextra.AbsoluteLayout());

        botonBuscarEmpleado.setBackground(new java.awt.Color(0, 0, 153));
        botonBuscarEmpleado.setFont(new java.awt.Font("Tahoma", 0, 10)); // NOI18N
        botonBuscarEmpleado.setForeground(new java.awt.Color(255, 255, 255));
        botonBuscarEmpleado.setText("Buscar Empleado");
        botonBuscarEmpleado.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                botonBuscarEmpleadoActionPerformed(evt);
            }
        });
        jPanel1.add(botonBuscarEmpleado, new org.netbeans.lib.awtextra.AbsoluteConstraints(180, 360, -1, -1));

        letreroNombre.setFont(new java.awt.Font("Tahoma", 0, 14)); // NOI18N
        letreroNombre.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        letreroNombre.setText("Nombre");
        jPanel1.add(letreroNombre, new org.netbeans.lib.awtextra.AbsoluteConstraints(10, 160, 70, -1));

        letreroEliminarEmpleado.setFont(new java.awt.Font("Tahoma", 1, 18)); // NOI18N
        letreroEliminarEmpleado.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        letreroEliminarEmpleado.setText("Eliminar Empleado");
        jPanel1.add(letreroEliminarEmpleado, new org.netbeans.lib.awtextra.AbsoluteConstraints(0, 60, 300, -1));
        jPanel1.add(cajaNombre, new org.netbeans.lib.awtextra.AbsoluteConstraints(90, 160, 200, -1));

        letreroContraseña.setFont(new java.awt.Font("Tahoma", 0, 14)); // NOI18N
        letreroContraseña.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        letreroContraseña.setText("Contraseña");
        jPanel1.add(letreroContraseña, new org.netbeans.lib.awtextra.AbsoluteConstraints(10, 210, -1, -1));

        cajaContraseña.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                cajaContraseñaActionPerformed(evt);
            }
        });
        jPanel1.add(cajaContraseña, new org.netbeans.lib.awtextra.AbsoluteConstraints(90, 210, 200, -1));

        letreroEdad.setFont(new java.awt.Font("Tahoma", 0, 14)); // NOI18N
        letreroEdad.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        letreroEdad.setText("Edad");
        jPanel1.add(letreroEdad, new org.netbeans.lib.awtextra.AbsoluteConstraints(10, 260, 70, -1));
        jPanel1.add(cajaEdad, new org.netbeans.lib.awtextra.AbsoluteConstraints(90, 260, 200, -1));

        botonRegresar.setBackground(new java.awt.Color(0, 0, 153));
        botonRegresar.setForeground(new java.awt.Color(255, 255, 255));
        botonRegresar.setText("Regresar");
        botonRegresar.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                botonRegresarActionPerformed(evt);
            }
        });
        jPanel1.add(botonRegresar, new org.netbeans.lib.awtextra.AbsoluteConstraints(220, 10, -1, -1));

        letreroIdEmpleado.setFont(new java.awt.Font("Tahoma", 0, 14)); // NOI18N
        letreroIdEmpleado.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        letreroIdEmpleado.setText("ID");
        jPanel1.add(letreroIdEmpleado, new org.netbeans.lib.awtextra.AbsoluteConstraints(10, 110, 70, -1));
        jPanel1.add(cajaIdEmpleado, new org.netbeans.lib.awtextra.AbsoluteConstraints(90, 110, 200, -1));

        jLabel2.setIcon(new javax.swing.ImageIcon(getClass().getResource("/Imagenes/modificarUsuario.png"))); // NOI18N
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
        jPanel1.add(botonLimpiar, new org.netbeans.lib.awtextra.AbsoluteConstraints(20, 360, -1, -1));

        botonEliminar.setBackground(new java.awt.Color(0, 0, 153));
        botonEliminar.setFont(new java.awt.Font("Tahoma", 0, 12)); // NOI18N
        botonEliminar.setForeground(new java.awt.Color(255, 255, 255));
        botonEliminar.setText("Eliminar");
        botonEliminar.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                botonEliminarActionPerformed(evt);
            }
        });
        jPanel1.add(botonEliminar, new org.netbeans.lib.awtextra.AbsoluteConstraints(110, 310, -1, -1));

        jLabel1.setIcon(new javax.swing.ImageIcon(getClass().getResource("/Imagenes/fondoMenuPrincipal.jpg"))); // NOI18N
        jLabel1.setText("d");
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

    private void botonBuscarEmpleadoActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_botonBuscarEmpleadoActionPerformed
        Connection conexion = null;
        
        try{
            conexion = getConnection();
            ps = conexion.prepareStatement("select * from empleados where idEmpleado=?");
            ps.setString(1, cajaIdEmpleado.getText());
            
            rs = ps.executeQuery(); //Ejecuta la insersion a la BD
            
            if(rs.next()){
                cajaNombre.setText(rs.getString("Nombre"));
                cajaContraseña.setText(rs.getString("Contraseña"));
                cajaEdad.setText(rs.getString("Edad"));
            }
            else{
                JOptionPane.showMessageDialog(null, "Error al buscar el registro");
                limpiarCajas();
            }
            conexion.close();
            
        }catch(Exception ex){
            System.err.println("Error: "+ex);
        }
        
    }//GEN-LAST:event_botonBuscarEmpleadoActionPerformed

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

    private void botonEliminarActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_botonEliminarActionPerformed
        Connection conexion = null;
        
        try{
            conexion = getConnection();
            ps = conexion.prepareStatement("delete from empleados where idEmpleado = ?");
            ps.setString(1, cajaIdEmpleado.getText());
            
            int resultado = ps.executeUpdate(); //Ejecuta la insersion a la BD
            
            if(resultado>0){
                JOptionPane.showMessageDialog(null, "Registro eliminado correctamente");
                limpiarCajas();
            }
            else{
                JOptionPane.showMessageDialog(null, "Error al eliminar el registro");
                limpiarCajas();
            }
            conexion.close();
            
        }catch(Exception ex){
            System.err.println("Error: "+ex);
        }
    }//GEN-LAST:event_botonEliminarActionPerformed

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
    private javax.swing.JButton botonBuscarEmpleado;
    private javax.swing.JButton botonEliminar;
    private javax.swing.JButton botonLimpiar;
    private javax.swing.JButton botonRegresar;
    private javax.swing.JTextField cajaContraseña;
    private javax.swing.JTextField cajaEdad;
    private javax.swing.JTextField cajaIdEmpleado;
    private javax.swing.JTextField cajaNombre;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JLabel jLabel2;
    private javax.swing.JPanel jPanel1;
    private javax.swing.JLabel letreroContraseña;
    private javax.swing.JLabel letreroEdad;
    private javax.swing.JLabel letreroEliminarEmpleado;
    private javax.swing.JLabel letreroIdEmpleado;
    private javax.swing.JLabel letreroNombre;
    // End of variables declaration//GEN-END:variables
}
