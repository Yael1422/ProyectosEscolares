/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Usuarios;
/**
 *
 * @author gandh
 */
public class MenuRutina extends javax.swing.JFrame {

    /**
     * Creates new form MenuRutina
     */
    public MenuRutina() {
        initComponents();
        setLocationRelativeTo(null);
    }

    /**
     * This method is called from within the constructor to initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is always
     * regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jPanel1 = new javax.swing.JPanel();
        botonAumentarPeso = new javax.swing.JButton();
        botonBajarPeso = new javax.swing.JButton();
        botonMantenerPeso = new javax.swing.JButton();
        botonRegresar = new javax.swing.JButton();
        fondo = new javax.swing.JLabel();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        setLocationByPlatform(true);
        setUndecorated(true);

        jPanel1.setLayout(new org.netbeans.lib.awtextra.AbsoluteLayout());

        botonAumentarPeso.setBackground(new java.awt.Color(0, 0, 153));
        botonAumentarPeso.setForeground(new java.awt.Color(255, 255, 255));
        botonAumentarPeso.setIcon(new javax.swing.ImageIcon(getClass().getResource("/Imagenes/aumentarpeso.jpg"))); // NOI18N
        botonAumentarPeso.setText("Aumentar Peso");
        botonAumentarPeso.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                botonAumentarPesoActionPerformed(evt);
            }
        });
        jPanel1.add(botonAumentarPeso, new org.netbeans.lib.awtextra.AbsoluteConstraints(0, 0, 200, 60));

        botonBajarPeso.setBackground(new java.awt.Color(0, 0, 153));
        botonBajarPeso.setForeground(new java.awt.Color(255, 255, 255));
        botonBajarPeso.setIcon(new javax.swing.ImageIcon(getClass().getResource("/Imagenes/bajarPeso.jpg"))); // NOI18N
        botonBajarPeso.setText("Bajar Peso");
        botonBajarPeso.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                botonBajarPesoActionPerformed(evt);
            }
        });
        jPanel1.add(botonBajarPeso, new org.netbeans.lib.awtextra.AbsoluteConstraints(0, 60, 200, 60));

        botonMantenerPeso.setBackground(new java.awt.Color(0, 0, 153));
        botonMantenerPeso.setForeground(new java.awt.Color(255, 255, 255));
        botonMantenerPeso.setIcon(new javax.swing.ImageIcon(getClass().getResource("/Imagenes/mantenerPeso.png"))); // NOI18N
        botonMantenerPeso.setText("Mantener Peso");
        botonMantenerPeso.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                botonMantenerPesoActionPerformed(evt);
            }
        });
        jPanel1.add(botonMantenerPeso, new org.netbeans.lib.awtextra.AbsoluteConstraints(0, 120, 200, 60));

        botonRegresar.setBackground(new java.awt.Color(0, 0, 153));
        botonRegresar.setForeground(new java.awt.Color(255, 255, 255));
        botonRegresar.setIcon(new javax.swing.ImageIcon(getClass().getResource("/Imagenes/regresar.png"))); // NOI18N
        botonRegresar.setText("Regresar");
        botonRegresar.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                botonRegresarActionPerformed(evt);
            }
        });
        jPanel1.add(botonRegresar, new org.netbeans.lib.awtextra.AbsoluteConstraints(0, 180, 200, 60));

        fondo.setIcon(new javax.swing.ImageIcon(getClass().getResource("/Imagenes/fondoMenuPrincipal.jpg"))); // NOI18N
        jPanel1.add(fondo, new org.netbeans.lib.awtextra.AbsoluteConstraints(0, 0, 390, 30));

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(jPanel1, javax.swing.GroupLayout.PREFERRED_SIZE, 200, Short.MAX_VALUE)
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(jPanel1, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void botonAumentarPesoActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_botonAumentarPesoActionPerformed
        VentanaVerRutinaAP ventana1 = new VentanaVerRutinaAP();
        ventana1.setVisible(true);
        
        dispose();
    }//GEN-LAST:event_botonAumentarPesoActionPerformed

    private void botonRegresarActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_botonRegresarActionPerformed
        VentanaUsuario ventana2 = new VentanaUsuario();
        ventana2.setVisible(true);
        
        dispose();
    }//GEN-LAST:event_botonRegresarActionPerformed

    private void botonBajarPesoActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_botonBajarPesoActionPerformed
        VentanaVerRutinaBP ventana3 = new VentanaVerRutinaBP();
        ventana3.setVisible(true);
        
        dispose();
    }//GEN-LAST:event_botonBajarPesoActionPerformed

    private void botonMantenerPesoActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_botonMantenerPesoActionPerformed
        VentanaVerRutinaMP ventana4 = new VentanaVerRutinaMP();
        ventana4.setVisible(true);
        
        dispose();
    }//GEN-LAST:event_botonMantenerPesoActionPerformed

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
            java.util.logging.Logger.getLogger(MenuRutina.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(MenuRutina.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(MenuRutina.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(MenuRutina.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>

        /* Create and display the form */
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new MenuRutina().setVisible(true);
            }
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton botonAumentarPeso;
    private javax.swing.JButton botonBajarPeso;
    private javax.swing.JButton botonMantenerPeso;
    private javax.swing.JButton botonRegresar;
    private javax.swing.JLabel fondo;
    private javax.swing.JPanel jPanel1;
    // End of variables declaration//GEN-END:variables
}