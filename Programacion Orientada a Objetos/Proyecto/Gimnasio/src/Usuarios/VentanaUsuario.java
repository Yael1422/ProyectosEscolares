
package Usuarios;

import Usuarios.MenuRutina;
import com.mysql.jdbc.Connection;
import gimnasio.MenúPrincipal;
import Empleado.VentanaEmpleado;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import javax.swing.JOptionPane;

public class VentanaUsuario extends javax.swing.JFrame {

    public static final String URL = "jdbc:mysql://localhost:3306/gimnasio?autoReconnet=true&useSSL=false";
    public static final String usuario = "root";
    public static final String contraseña = "315252884";
    
    public VentanaUsuario() {
        initComponents();
    }

    
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jPanel1 = new javax.swing.JPanel();
        tituloBienvenida = new javax.swing.JLabel();
        botonCerrarSesion = new javax.swing.JButton();
        jLabel1 = new javax.swing.JLabel();
        indicador = new javax.swing.JLabel();
        botonSolicitarRutina = new javax.swing.JButton();
        botonPagarMensualidad = new javax.swing.JButton();
        fondo = new javax.swing.JLabel();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        setUndecorated(true);

        jPanel1.setLayout(new org.netbeans.lib.awtextra.AbsoluteLayout());

        tituloBienvenida.setFont(new java.awt.Font("Tahoma", 1, 24)); // NOI18N
        tituloBienvenida.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        tituloBienvenida.setText("¿Qué deseas realizar?");
        jPanel1.add(tituloBienvenida, new org.netbeans.lib.awtextra.AbsoluteConstraints(0, 70, 600, -1));

        botonCerrarSesion.setBackground(new java.awt.Color(0, 0, 153));
        botonCerrarSesion.setForeground(new java.awt.Color(255, 255, 255));
        botonCerrarSesion.setText("Cerrar Sesión");
        botonCerrarSesion.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                botonCerrarSesionActionPerformed(evt);
            }
        });
        jPanel1.add(botonCerrarSesion, new org.netbeans.lib.awtextra.AbsoluteConstraints(430, 20, -1, -1));

        jLabel1.setIcon(new javax.swing.ImageIcon(getClass().getResource("/Imagenes/vato.jpg"))); // NOI18N
        jPanel1.add(jLabel1, new org.netbeans.lib.awtextra.AbsoluteConstraints(170, 120, 250, 140));

        indicador.setFont(new java.awt.Font("Kristen ITC", 1, 12)); // NOI18N
        indicador.setText("Usuario");
        jPanel1.add(indicador, new org.netbeans.lib.awtextra.AbsoluteConstraints(50, 20, -1, -1));

        botonSolicitarRutina.setBackground(new java.awt.Color(0, 0, 153));
        botonSolicitarRutina.setFont(new java.awt.Font("Tahoma", 0, 14)); // NOI18N
        botonSolicitarRutina.setForeground(new java.awt.Color(255, 255, 255));
        botonSolicitarRutina.setIcon(new javax.swing.ImageIcon(getClass().getResource("/Imagenes/rutina.jpg"))); // NOI18N
        botonSolicitarRutina.setText("Solicitar Rutina");
        botonSolicitarRutina.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                botonSolicitarRutinaActionPerformed(evt);
            }
        });
        jPanel1.add(botonSolicitarRutina, new org.netbeans.lib.awtextra.AbsoluteConstraints(200, 400, 210, -1));

        botonPagarMensualidad.setBackground(new java.awt.Color(0, 0, 153));
        botonPagarMensualidad.setFont(new java.awt.Font("Tahoma", 0, 14)); // NOI18N
        botonPagarMensualidad.setForeground(new java.awt.Color(255, 255, 255));
        botonPagarMensualidad.setIcon(new javax.swing.ImageIcon(getClass().getResource("/Imagenes/pagar.jpg"))); // NOI18N
        botonPagarMensualidad.setText("Pagar Mensualidad");
        botonPagarMensualidad.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                botonPagarMensualidadActionPerformed(evt);
            }
        });
        jPanel1.add(botonPagarMensualidad, new org.netbeans.lib.awtextra.AbsoluteConstraints(200, 350, 210, -1));

        fondo.setIcon(new javax.swing.ImageIcon(getClass().getResource("/Imagenes/fondoMenuPrincipal.jpg"))); // NOI18N
        jPanel1.add(fondo, new org.netbeans.lib.awtextra.AbsoluteConstraints(0, 0, -1, 600));

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
        setLocationRelativeTo(null);
    }// </editor-fold>//GEN-END:initComponents

    private void botonCerrarSesionActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_botonCerrarSesionActionPerformed
        JOptionPane.showMessageDialog(null, "Hasta luego");
        MenúPrincipal menu = new MenúPrincipal();
        
        menu.setVisible(true);
        
        dispose();
    }//GEN-LAST:event_botonCerrarSesionActionPerformed

    private void botonPagarMensualidadActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_botonPagarMensualidadActionPerformed
        JOptionPane.showMessageDialog(null, "¡¡Mensualidad pagada exitosamente!!");
    }//GEN-LAST:event_botonPagarMensualidadActionPerformed

    private void botonSolicitarRutinaActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_botonSolicitarRutinaActionPerformed
        MenuRutina menu = new MenuRutina();
        menu.setVisible(true);
        
        dispose();
    }//GEN-LAST:event_botonSolicitarRutinaActionPerformed

    
    public Connection getConnection(){
        Connection conexion = null;
        
        try{
            Class.forName("com.mysql.jdbc.Driver");
            conexion = (Connection) DriverManager.getConnection(URL, usuario, contraseña);
            JOptionPane.showMessageDialog(null, "Conexión exitosa");
        }catch(Exception ex){
            System.err.println("Error, "+ex);
        }
        return conexion;
    }
    
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
            java.util.logging.Logger.getLogger(VentanaEmpleado.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(VentanaEmpleado.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(VentanaEmpleado.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(VentanaEmpleado.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>

        /* Create and display the form */
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new VentanaEmpleado().setVisible(true);
            }
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton botonCerrarSesion;
    private javax.swing.JButton botonPagarMensualidad;
    private javax.swing.JButton botonSolicitarRutina;
    private javax.swing.JLabel fondo;
    private javax.swing.JLabel indicador;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JPanel jPanel1;
    private javax.swing.JLabel tituloBienvenida;
    // End of variables declaration//GEN-END:variables
}
