
package rez1;

import java.awt.BorderLayout;
import java.awt.Color;
import static javax.swing.GroupLayout.Alignment.CENTER;
import org.jfree.chart.ChartFactory;
import org.jfree.chart.ChartPanel;
import org.jfree.chart.JFreeChart;
import org.jfree.chart.plot.CategoryPlot;
import org.jfree.chart.plot.PlotOrientation;
import org.jfree.data.category.DefaultCategoryDataset;

public class Graph extends javax.swing.JFrame {

  
    public Graph() {
        initComponents();
    }

   
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jButton1 = new javax.swing.JButton();
        jPanel1 = new javax.swing.JPanel();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        setPreferredSize(new java.awt.Dimension(800, 600));
        getContentPane().setLayout(new javax.swing.BoxLayout(getContentPane(), javax.swing.BoxLayout.LINE_AXIS));

        jButton1.setText("SHOW");
        jButton1.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton1ActionPerformed(evt);
            }
        });
        getContentPane().add(jButton1);

        jPanel1.setBackground(new java.awt.Color(153, 204, 255));
        jPanel1.setLayout(new java.awt.BorderLayout());
        getContentPane().add(jPanel1);

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void jButton1ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButton1ActionPerformed
        
        double huff = 0.5 ;
        double lzw = 0.6 ;
        double lz77 = 0.8 ;
        double rle = 0.4 ;
        
        DefaultCategoryDataset barChartData = new DefaultCategoryDataset() ;
        barChartData.setValue(huff,"Compression Ratio", "Huffman");
        barChartData.setValue(lzw,"Compression Ratio", "LZW");
        barChartData.setValue(rle,"Compression Ratio", "RLE");
        barChartData.setValue(lz77,"Compression Ratio", "LZ77");
        
        JFreeChart barChart = ChartFactory.createBarChart("Compression Test","Algorithms", "Compression Ratio", barChartData,PlotOrientation.VERTICAL,false,true,false) ;
        
        CategoryPlot barChrt = barChart.getCategoryPlot() ;
        barChrt.setRangeGridlinePaint(Color.ORANGE);
        
        ChartPanel barPanel = new ChartPanel(barChart) ;
        jPanel1.removeAll() ;
        jPanel1.add(barPanel) ;
        
        jPanel1.validate();
    }//GEN-LAST:event_jButton1ActionPerformed

   
    public static void main(String args[]) {
       
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new Graph().setVisible(true);
            }
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton jButton1;
    private javax.swing.JPanel jPanel1;
    // End of variables declaration//GEN-END:variables
}
