/*  Author
    Md Rezowan Talukder
*/

/*
    *this class implement LZ77 algorithm to compress file 
    *FileStream is used so cm compress any type of file

*/

package rez1;
import java.io.*;
import java.io.BufferedReader;
import java.io.DataInputStream;
import java.io.File;
import java.io.FileInputStream;

import java.io.InputStreamReader;


public class LZ77Compress {
    
  
        public LZ77Compress(){

        }

        public static int size ;
        public String outputFile ;
            
        public void compress(String input){
            
            outputFile = input+"_lz77.txt" ;
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

                //size = f1.length() ;

                d1.close();
                data.close();


                }
                catch (Exception ex)
                {
                    System.out.println("Problem in opening file (LZ_77)");
                }
        }
        
        public double getLZ77Size()
        {
            File fi ;
            fi = new File(outputFile);
            System.out.println("lz77   "+fi.length());
            return fi.length() ;
            
        }
}


