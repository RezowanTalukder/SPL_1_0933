

/*
    *this class is the main class of this project
    *Objects are created from others 4 class to get the size of compressed file
    *FJreeChart is also used in this class
    *user inteface is created in this class also
*/

package rez1;

/*  
    Author
   Md Rezowan Talukder
*/


import java.awt.Color;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.JFileChooser;
import javax.swing.JOptionPane;
import org.jfree.chart.ChartFactory;
import org.jfree.chart.ChartPanel;
import org.jfree.chart.JFreeChart;
import org.jfree.chart.plot.CategoryPlot;
import org.jfree.chart.plot.PlotOrientation;
import org.jfree.data.category.DefaultCategoryDataset;



public class OutForm extends javax.swing.JFrame {

    
    public OutForm() {
        initComponents();
    }

    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jLabel1 = new javax.swing.JLabel();
        jTextField1 = new javax.swing.JTextField();
        jButton1 = new javax.swing.JButton();
        jButton2 = new javax.swing.JButton();
        jPanel1 = new javax.swing.JPanel();
        jButton3 = new javax.swing.JButton();
        jButton4 = new javax.swing.JButton();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        setMinimumSize(new java.awt.Dimension(770, 630));
        getContentPane().setLayout(null);

        jLabel1.setFont(new java.awt.Font("Tahoma", 1, 36)); // NOI18N
        jLabel1.setText("reZ1");
        getContentPane().add(jLabel1);
        jLabel1.setBounds(270, 0, 82, 44);

        jTextField1.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jTextField1ActionPerformed(evt);
            }
        });
        getContentPane().add(jTextField1);
        jTextField1.setBounds(40, 70, 420, 30);

        jButton1.setFont(new java.awt.Font("Tahoma", 0, 14)); // NOI18N
        jButton1.setText("Browse");
        jButton1.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton1ActionPerformed(evt);
            }
        });
        getContentPane().add(jButton1);
        jButton1.setBounds(470, 70, 100, 30);

        jButton2.setFont(new java.awt.Font("Dialog", 1, 18)); // NOI18N
        jButton2.setText("Show Graph");
        jButton2.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton2ActionPerformed(evt);
            }
        });
        getContentPane().add(jButton2);
        jButton2.setBounds(310, 120, 170, 40);

        jPanel1.setLayout(new java.awt.BorderLayout());
        getContentPane().add(jPanel1);
        jPanel1.setBounds(20, 180, 690, 370);

        jButton3.setFont(new java.awt.Font("Dialog", 1, 18)); // NOI18N
        jButton3.setText("Exit");
        jButton3.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton3ActionPerformed(evt);
            }
        });
        getContentPane().add(jButton3);
        jButton3.setBounds(120, 120, 170, 40);

        jButton4.setFont(new java.awt.Font("Dialog", 0, 14)); // NOI18N
        jButton4.setText("help");
        jButton4.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton4ActionPerformed(evt);
            }
        });
        getContentPane().add(jButton4);
        jButton4.setBounds(580, 70, 90, 30);

        pack();
    }// </editor-fold>//GEN-END:initComponents

    
    
    private void jButton1ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButton1ActionPerformed
       
        JFileChooser chooser = new JFileChooser() ;
        chooser.showOpenDialog(null) ;
        
        File f = chooser.getSelectedFile();
        String fileName = f.getAbsolutePath() ;
        jTextField1.setText(fileName) ;
       // fN = fileName ;
        
    }//GEN-LAST:event_jButton1ActionPerformed

    private void jTextField1ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jTextField1ActionPerformed
              
        
    }//GEN-LAST:event_jTextField1ActionPerformed


    
    private void jButton2ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButton2ActionPerformed
        
             
         try {
            
            String fN =jTextField1.getText() ;
            
            System.out.println(fN);
            
            File file = new File(fN);

            double originalFileLength = file.length() ;
            System.out.println("original   "+ file.length());
             
            LZWCompression lzw = new LZWCompression(fN);
            lzw.compressFile(fN) ;
            double lzwS = lzw.getLZWSize(fN) ;
            System.out.println("lzw----"+lzwS);
            
            RLECompress rle = new RLECompress() ;
            rle.compress(fN);
            double rleS = rle.getRLESize() ;
            
            LZ77Compress lz77 = new LZ77Compress() ;
            lz77.compress(fN);           
            double lz77S = lz77.getLZ77Size(fN) ;        
           
            double huffS,huff_final ;
            
            if(originalFileLength>5000){
                 huff_final=1.0 ;
            }
            
            else {
                HuffmanCompression hf = new HuffmanCompression() ;
                hf.compress(fN);
                huffS = hf.getHuffmanSize() ;
                huff_final = originalFileLength/ huffS ;
            }
            
           
            double lzw_final =  originalFileLength/ lzwS ;
            double lz77_final =  originalFileLength/ lz77S  ;
            
            double rle_final =  originalFileLength/ rleS ;

            DefaultCategoryDataset barChartData = new DefaultCategoryDataset() ;
            
            barChartData.setValue(huff_final,"Compression Ratio", "Huffman");
            barChartData.setValue(lzw_final,"Compression Ratio", "LZW");
            barChartData.setValue(rle_final,"Compression Ratio", "RLE");
            barChartData.setValue(lz77_final,"Compression Ratio", "LZ77");

            JFreeChart barChart = ChartFactory.createBarChart("Compression Test","Algorithms", "Compression Ratio",
                    barChartData,PlotOrientation.VERTICAL,false,true,false) ;

            CategoryPlot barChrt = barChart.getCategoryPlot() ;
            barChrt.setRangeGridlinePaint(Color.ORANGE);

            ChartPanel barPanel = new ChartPanel(barChart) ;

            jPanel1.removeAll() ;
            jPanel1.add(barPanel);
            jPanel1.validate(); 
            
                   
                 
        } catch (FileNotFoundException e) {
            System.out.println("File was not found!");
        } catch (IOException ex) {
            Logger.getLogger(OutForm.class.getName()).log(Level.SEVERE, null, ex);
        }
        
                
    }//GEN-LAST:event_jButton2ActionPerformed

    private void jButton3ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButton3ActionPerformed
        setVisible(false);
        System.exit(0) ;
    }//GEN-LAST:event_jButton3ActionPerformed

    private void jButton4ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButton4ActionPerformed
        JOptionPane.showMessageDialog(null, "1.Select a file from drive clicking on Browse\n"
                + "2.select a file and then click on open\n"
                + "3.finally click on show graph to see compression ratio.");
    }//GEN-LAST:event_jButton4ActionPerformed

    
    
    public static void main(String args[]) {
        
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
            java.util.logging.Logger.getLogger(OutForm.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(OutForm.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(OutForm.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(OutForm.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>
      
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new OutForm().setVisible(true);
            }
        });
        
    }
    
    

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton jButton1;
    private javax.swing.JButton jButton2;
    private javax.swing.JButton jButton3;
    private javax.swing.JButton jButton4;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JPanel jPanel1;
    private javax.swing.JTextField jTextField1;
    // End of variables declaration//GEN-END:variables
}
