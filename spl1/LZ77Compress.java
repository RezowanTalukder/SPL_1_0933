
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

public class LZ77Compress {
    
    public LZ77Compress(){
        
    }
    
    
    String outputFile = "lz77HH.txt" ;
            
        public void compress(String input){
            
            //outputFile = input+".lz77" ;
           // System.out.println(outputFile);
           
            try
            {
            FileInputStream file=new FileInputStream(input);
            DataInputStream data=new DataInputStream(file);
            BufferedReader br=new BufferedReader(new InputStreamReader(data));

           
            FileOutputStream f1=new FileOutputStream(outputFile);
            DataOutputStream d1=new DataOutputStream(f1);

            while((input=br.readLine())!=null)
            {
                    int pointer=0,len1=0;
                    char o='0',nc='0';
                    String w,y=null,x=null;
                    int i,j=0,z,l=0;

                    for(i=0;i<=input.length();i++)
                    {
                        w=null;
                        w=input.substring(0,i);
                        j=i+1;
                       do{
                           y=input.substring(i,j);
                           z=w.lastIndexOf(y);
                           if(z!=-1)
                           {
                               l=z;
                                j++;

                                if(j>input.length())
                                {
                                    i=input.length();
                                    pointer=w.length()-l;
                                    len1=y.length();
                                    nc='0';
                                    d1.writeInt(pointer);
                                    d1.writeInt(len1);
                                    d1.writeChar(nc);
                                    break;
                                }
                           }
                           else
                           {
                               i=w.length()+(y.length()-1);
                               if(y.length()==1)
                               {
                                   pointer=0;
                                   len1=0;
                               }
                               else
                               {
                                   pointer=w.length()-l;
                                   len1=y.length()-1;

                               }
                               nc=y.charAt(y.length()-1);
                               d1.writeInt(pointer);
                               d1.writeInt(len1);
                               d1.writeChar(nc);
                               break;
                           }
                        } while(z!=-1);
              }
            
            }
            
            d1.close();
            data.close();
            
            
            }
            catch (Exception ex)
            {
                // Do nothig
            }
        }
        
        public double getLZ77Size()
        {
            File fi ;
            fi = new File(outputFile);
            
            return (fi.length()/1024);
            
        }
}


