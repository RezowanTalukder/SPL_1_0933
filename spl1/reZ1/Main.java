/*
    *this is the main class of this project
 */
package rez1;

/**
 *
 * @author Md Rezowan Talukder
 */
public class Main {
    public static void main(String []args)
    {
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new OutForm().setVisible(true);
            }
        });
    }
}
