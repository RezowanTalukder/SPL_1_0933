package rez1;

import java.io.*;
import java.io.BufferedReader;
import java.io.DataInputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import javax.swing.JOptionPane;

public class LZ77Decompress {
    
    public LZ77Decompress(){
        
    }
    
    public void decompress(){
        try
        {

            FileInputStream f2=new FileInputStream("compress.txt");
            DataInputStream d2=new DataInputStream(f2);
            BufferedReader b=new BufferedReader(new InputStreamReader(d2));

            FileOutputStream fos=new FileOutputStream("decompress.txt");
            DataOutputStream dos=new DataOutputStream(fos);

            int p=0,len=0;
            char n;
            String decomp = "";
            while(f2.available()!=0)
            {
                p=d2.readInt();//pointer
                System.out.println(p);
                len=d2.readInt();//length
                System.out.println(len);
                n=d2.readChar();//nextcharacter
                System.out.println(n);
                if(p==0)
                    decomp+=n;
                else
                {
                    if(n!='0')
                    decomp+=(decomp.substring((decomp.length()-p),((decomp.length()-p)+len))+n);
                    else
                        decomp+=(decomp.substring((decomp.length()-p),((decomp.length()-p)+len)));
                }
            }
            dos.writeChars(decomp);
            System.out.println(decomp);

            b.close();
            dos.close();
        }catch(Exception e){

        }
    }
}
