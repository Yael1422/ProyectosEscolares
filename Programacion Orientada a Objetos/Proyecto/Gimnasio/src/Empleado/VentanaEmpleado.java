
package Empleado;

import Empleado.VentanaEliminarUsuario;
import Empleado.VentanaEliminarEmpleado;
import Empleado.VentanaBuscarUsuario;
import Empleado.VentanaBuscarEmpleado;
import Empleado.VentanaAgregarUsuario;
import Empleado.VentanaAgregarEmpleado;
import com.mysql.jdbc.Connection;
import gimnasio.MenúPrincipal;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import javax.swing.JOptionPane;

public class VentanaEmpleado extends javax.swing.JFrame {

    public static final String URL = "jdbc:mysql://localhost:3306/gimnasio?autoReconnet=true&useSSL=false";
    public static final String usuario = "root";
    public static final String contraseña = "P315252884";
    
    public VentanaEmpleado() {
        initComponents();
    }

    
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jPanel1 = new javax.swing.JPanel();
        tituloBienvenida = new javax.swing.JLabel();
        botonAgregarUsuario = new javax.swing.JButton();
        botonCerrarSesion = new javax.swing.JButton();
        botonAgregarEmpleado = new javax.swing.JButton();
        botonVerUsuarios = new javax.swing.JButton();
        botonBuscarUsuario = new javax.swing.JButton();
        botonVerEmpleados = new javax.swing.JButton();
        botonBuscarEmpleado = new javax.swing.JButton();
        botonBorrarUsuario = new javax.swing.JButton();
        botonBorrarEmpleado = new javax.swing.JButton();
        botonEditarUsuario = new javax.swing.JButton();
        botonEditarEmpleado = new javax.swing.JButton();
        jLabel1 = new javax.swing.JLabel();
        identificador = new javax.swing.JLabel();
        fondo = new javax.swing.JLabel();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        setUndecorated(true);

        jPanel1.setLayout(new org.netbeans.lib.awtextra.AbsoluteLayout());

        tituloBienvenida.setFont(new java.awt.Font("Tahoma", 1, 24)); // NOI18N
        tituloBienvenida.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        tituloBienvenida.setText("¿Qué deseas realizar?");
        jPanel1.add(tituloBienvenida, new org.netbeans.lib.awtextra.AbsoluteConstraints(0, 70, 600, -1));

        botonAgregarUsuario.setBackground(new java.awt.Color(0, 0, 153));
        botonAgregarUsuario.setFont(new java.awt.Font("Tahoma", 0, 14)); // NOI18N
        botonAgregarUsuario.setForeground(new java.awt.Color(255, 255, 255));
        botonAgregarUsuario.setIcon(new javax.swing.ImageIcon(getClass().getResource("/Imagenes/agregar.jpg"))); // NOI18N
        botonAgregarUsuario.setText("Agregar Usuario");
        botonAgregarUsuario.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                botonAgregarUsuarioActionPerformed(evt);
            }
        });
        jPanel1.add(botonAgregarUsuario, new org.netbeans.lib.awtextra.AbsoluteConstraints(40, 300, 210, 30));

        botonCerrarSesion.setBackground(new java.awt.Color(0, 0, 153));
        botonCerrarSesion.setForeground(new java.awt.Color(255, 255, 255));
        botonCerrarSesion.setText("Cerrar Sesión");
        botonCerrarSesion.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                botonCerrarSesionActionPerformed(evt);
            }
        });
        jPanel1.add(botonCerrarSesion, new org.netbeans.lib.awtextra.AbsoluteConstraints(430, 20, -1, -1));

        botonAgregarEmpleado.setBackground(new java.awt.Color(0, 0, 153));
        botonAgregarEmpleado.setFont(new java.awt.Font("Tahoma", 0, 14)); // NOI18N
        botonAgregarEmpleado.setForeground(new java.awt.Color(255, 255, 255));
        botonAgregarEmpleado.setIcon(new javax.swing.ImageIcon(getClass().getResource("/Imagenes/agregar.jpg"))); // NOI18N
        botonAgregarEmpleado.setText("Agregar Empleado");
        botonAgregarEmpleado.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                botonAgregarEmpleadoActionPerformed(evt);
            }
        });
        jPanel1.add(botonAgregarEmpleado, new org.netbeans.lib.awtextra.AbsoluteConstraints(330, 300, 210, 30));

        botonVerUsuarios.setBackground(new java.awt.Color(0, 0, 153));
        botonVerUsuarios.setFont(new java.awt.Font("Tahoma", 0, 14)); // NOI18N
        botonVerUsuarios.setForeground(new java.awt.Color(255, 255, 255));
        botonVerUsuarios.setIcon(new javax.swing.ImageIcon(getClass().getResource("/Imagenes/usuario.jpg"))); // NOI18N
        botonVerUsuarios.setText("Ver Usuarios");
        botonVerUsuarios.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                botonVerUsuariosActionPerformed(evt);
            }
        });
        jPanel1.add(botonVerUsuarios, new org.netbeans.lib.awtextra.AbsoluteConstraints(40, 350, 210, -1));

        botonBuscarUsuario.setBackground(new java.awt.Color(0, 0, 153));
        botonBuscarUsuario.setFont(new java.awt.Font("Tahoma", 0, 14)); // NOI18N
        botonBuscarUsuario.setForeground(new java.awt.Color(255, 255, 255));
        botonBuscarUsuario.setIcon(new javax.swing.ImageIcon(getClass().getResource("/Imagenes/buscar.png"))); // NOI18N
        botonBuscarUsuario.setText("Buscar Usuario (ID)");
        botonBuscarUsuario.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                botonBuscarUsuarioActionPerformed(evt);
            }
        });
        jPanel1.add(botonBuscarUsuario, new org.netbeans.lib.awtextra.AbsoluteConstraints(40, 400, 210, -1));

        botonVerEmpleados.setBackground(new java.awt.Color(0, 0, 153));
        botonVerEmpleados.setFont(new java.awt.Font("Tahoma", 0, 14)); // NOI18N
        botonVerEmpleados.setForeground(new java.awt.Color(255, 255, 255));
        botonVerEmpleados.setIcon(new javax.swing.ImageIcon(getClass().getResource("/Imagenes/empleado.jpg"))); // NOI18N
        botonVerEmpleados.setText("Ver Empleados");
        botonVerEmpleados.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                botonVerEmpleadosActionPerformed(evt);
            }
        });
        jPanel1.add(botonVerEmpleados, new org.netbeans.lib.awtextra.AbsoluteConstraints(330, 350, 210, -1));

        botonBuscarEmpleado.setBackground(new java.awt.Color(0, 0, 153));
        botonBuscarEmpleado.setFont(new java.awt.Font("Tahoma", 0, 14)); // NOI18N
        botonBuscarEmpleado.setForeground(new java.awt.Color(255, 255, 255));
        botonBuscarEmpleado.setIcon(new javax.swing.ImageIcon(getClass().getResource("/Imagenes/buscar.png"))); // NOI18N
        botonBuscarEmpleado.setText("Buscar Empleado (ID)");
        botonBuscarEmpleado.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                botonBuscarEmpleadoActionPerformed(evt);
            }
        });
        jPanel1.add(botonBuscarEmpleado, new org.netbeans.lib.awtextra.AbsoluteConstraints(333, 400, 210, -1));

        botonBorrarUsuario.setBackground(new java.awt.Color(0, 0, 153));
        botonBorrarUsuario.setFont(new java.awt.Font("Tahoma", 0, 14)); // NOI18N
        botonBorrarUsuario.setForeground(new java.awt.Color(255, 255, 255));
        botonBorrarUsuario.setIcon(new javax.swing.ImageIcon(getClass().getResource("/Imagenes/borrar.png"))); // NOI18N
        botonBorrarUsuario.setText("Borrar Usuario (ID)");
        botonBorrarUsuario.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                botonBorrarUsuarioActionPerformed(evt);
            }
        });
        jPanel1.add(botonBorrarUsuario, new org.netbeans.lib.awtextra.AbsoluteConstraints(40, 450, 210, -1));

        botonBorrarEmpleado.setBackground(new java.awt.Color(0, 0, 153));
        botonBorrarEmpleado.setFont(new java.awt.Font("Tahoma", 0, 14)); // NOI18N
        botonBorrarEmpleado.setForeground(new java.awt.Color(255, 255, 255));
        botonBorrarEmpleado.setIcon(new javax.swing.ImageIcon(getClass().getResource("/Imagenes/borrar.png"))); // NOI18N
        botonBorrarEmpleado.setText("Borrar Empleado (ID)");
        botonBorrarEmpleado.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                botonBorrarEmpleadoActionPerformed(evt);
            }
        });
        jPanel1.add(botonBorrarEmpleado, new org.netbeans.lib.awtextra.AbsoluteConstraints(330, 450, 210, -1));

        botonEditarUsuario.setBackground(new java.awt.Color(0, 0, 153));
        botonEditarUsuario.setFont(new java.awt.Font("Tahoma", 0, 14)); // NOI18N
        botonEditarUsuario.setForeground(new java.awt.Color(255, 255, 255));
        botonEditarUsuario.setIcon(new javax.swing.ImageIcon(getClass().getResource("/Imagenes/editar.png"))); // NOI18N
        botonEditarUsuario.setText("Editar Usuario (ID)");
        botonEditarUsuario.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                botonEditarUsuarioActionPerformed(evt);
            }
        });
        jPanel1.add(botonEditarUsuario, new org.netbeans.lib.awtextra.AbsoluteConstraints(40, 500, 210, -1));

        botonEditarEmpleado.setBackground(new java.awt.Color(0, 0, 153));
        botonEditarEmpleado.setFont(new java.awt.Font("Tahoma", 0, 14)); // NOI18N
        botonEditarEmpleado.setForeground(new java.awt.Color(255, 255, 255));
        botonEditarEmpleado.setIcon(new javax.swing.ImageIcon(getClass().getResource("/Imagenes/editar.png"))); // NOI18N
        botonEditarEmpleado.setText("Editar Empleado (ID)");
        botonEditarEmpleado.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                botonEditarEmpleadoActionPerformed(evt);
            }
        });
        jPanel1.add(botonEditarEmpleado, new org.netbeans.lib.awtextra.AbsoluteConstraints(330, 500, 210, -1));

        jLabel1.setIcon(new javax.swing.ImageIcon(getClass().getResource("/Imagenes/imagenAdmin.png"))); // NOI18N
        jPanel1.add(jLabel1, new org.netbeans.lib.awtextra.AbsoluteConstraints(170, 120, 250, 140));

        identificador.setFont(new java.awt.Font("Kristen ITC", 1, 12)); // NOI18N
        identificador.setText("Empleado");
        jPanel1.add(identificador, new org.netbeans.lib.awtextra.AbsoluteConstraints(50, 20, -1, -1));

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

    private void botonAgregarUsuarioActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_botonAgregarUsuarioActionPerformed
        VentanaAgregarUsuario ventana = new VentanaAgregarUsuario();
        
        ventana.setVisible(true);
        
        dispose();
    }//GEN-LAST:event_botonAgregarUsuarioActionPerformed

    private void botonAgregarEmpleadoActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_botonAgregarEmpleadoActionPerformed
        VentanaAgregarEmpleado ventana = new VentanaAgregarEmpleado();
        ventana.setVisible(true);
        
        dispose();
    }//GEN-LAST:event_botonAgregarEmpleadoActionPerformed

    private void botonCerrarSesionActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_botonCerrarSesionActionPerformed
        JOptionPane.showMessageDialog(null, "Hasta luego");
        MenúPrincipal menu = new MenúPrincipal();
        
        menu.setVisible(true);
        
        dispose();
    }//GEN-LAST:event_botonCerrarSesionActionPerformed

    private void botonVerUsuariosActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_botonVerUsuariosActionPerformed
        VentanaVerUsuarios ventana = new VentanaVerUsuarios();
        ventana.setVisible(true);
        
        dispose();
    }//GEN-LAST:event_botonVerUsuariosActionPerformed

    private void botonBuscarEmpleadoActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_botonBuscarEmpleadoActionPerformed
        VentanaBuscarEmpleado ventana = new VentanaBuscarEmpleado();
        ventana.setVisible(true);
        
        dispose();
    }//GEN-LAST:event_botonBuscarEmpleadoActionPerformed

    private void botonVerEmpleadosActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_botonVerEmpleadosActionPerformed
        VentanaVerEmpleados ventana = new VentanaVerEmpleados();
        ventana.setVisible(true);
        
        dispose();
    }//GEN-LAST:event_botonVerEmpleadosActionPerformed

    private void botonEditarUsuarioActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_botonEditarUsuarioActionPerformed
        VentanaModificarUsuario ventana = new VentanaModificarUsuario();
        ventana.setVisible(true);
        
        dispose();
    }//GEN-LAST:event_botonEditarUsuarioActionPerformed

    private void botonBuscarUsuarioActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_botonBuscarUsuarioActionPerformed
        VentanaBuscarUsuario ventana = new VentanaBuscarUsuario();
        ventana.setVisible(true);
        
        dispose();
    }//GEN-LAST:event_botonBuscarUsuarioActionPerformed

    private void botonEditarEmpleadoActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_botonEditarEmpleadoActionPerformed
        VentanaModificarEmpleado ventana = new VentanaModificarEmpleado();
        ventana.setVisible(true);
        
        dispose();
    }//GEN-LAST:event_botonEditarEmpleadoActionPerformed

    private void botonBorrarUsuarioActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_botonBorrarUsuarioActionPerformed
        VentanaEliminarUsuario ventana = new VentanaEliminarUsuario();
        ventana.setVisible(true);
        
        dispose();
    }//GEN-LAST:event_botonBorrarUsuarioActionPerformed

    private void botonBorrarEmpleadoActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_botonBorrarEmpleadoActionPerformed
        VentanaEliminarEmpleado ventana = new VentanaEliminarEmpleado();
        ventana.setVisible(true);
        
        dispose();
    }//GEN-LAST:event_botonBorrarEmpleadoActionPerformed

    
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
    private javax.swing.JButton botonAgregarEmpleado;
    private javax.swing.JButton botonAgregarUsuario;
    private javax.swing.JButton botonBorrarEmpleado;
    private javax.swing.JButton botonBorrarUsuario;
    private javax.swing.JButton botonBuscarEmpleado;
    private javax.swing.JButton botonBuscarUsuario;
    private javax.swing.JButton botonCerrarSesion;
    private javax.swing.JButton botonEditarEmpleado;
    private javax.swing.JButton botonEditarUsuario;
    private javax.swing.JButton botonVerEmpleados;
    private javax.swing.JButton botonVerUsuarios;
    private javax.swing.JLabel fondo;
    private javax.swing.JLabel identificador;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JPanel jPanel1;
    private javax.swing.JLabel tituloBienvenida;
    // End of variables declaration//GEN-END:variables
}
