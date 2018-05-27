
package rez1;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.nio.file.StandardOpenOption;
import java.util.regex.Matcher;
import java.util.regex.Pattern;


public class RLECompress {
    
        public RLECompress(){
            
        }
        
        public static String outputFile ;
        
        public static void encode(String source,String fName) {
                    StringBuffer dest = new StringBuffer();
                    for (int i = 0; i < source.length(); i++) {
                        int runLength = 1;
                        while (i + 1 < source.length() && source.charAt(i) == source.charAt(i + 1)) {
                            runLength++;
                            i++;
                        }
                        
                        dest.append(runLength);
                        dest.append(source.charAt(i));
                    }
                    //return dest.toString();
                    try{
                        //System.out.println(dest.toString());
                        outputFile = fName+"_rle.txt" ;
                        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter(outputFile,true))) ;
                        Files.write(Paths.get(outputFile),dest.toString().getBytes(), StandardOpenOption.APPEND) ;
                       // size = dest.length() ;
                        //out.println(dest.toString().getBytes());
                    }catch(Exception e){
                        //
                    }
                    
                    
           }
     
/*
        public static void decode(String source) {
            StringBuffer dest = new StringBuffer();
            Pattern pattern = Pattern.compile("[0-9]+|[a-zA-Z]");
            Matcher matcher = pattern.matcher(source);
            while (matcher.find()) {
                int number = Integer.parseInt(matcher.group());
                matcher.find();
                while (number-- != 0) {
                    dest.append(matcher.group());
                }
            }
            //return dest.toString();
            
            try{
                        System.out.println(dest.toString());
                        //
                        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("rlenew.txt",true))) ;
                        Files.write(Paths.get("rlenew.txt"),dest.toString().getBytes(), StandardOpenOption.APPEND) ;
                        //out.println(dest.toString().getBytes());
                    }catch(Exception e){
                        //
                    }
        }
       
        
        */
        
        
       public double getRLESize()
        {
            File fi ;
            fi = new File(outputFile);
            
            return fi.length() ;
            
        }
        
        public static void compress(String fName) throws FileNotFoundException, IOException {
           
            String example = null ;
            FileReader in = new FileReader(fName) ;
            BufferedReader br = new BufferedReader(in) ;
            while((example=br.readLine())!=null){
                encode(example,fName);
            }
            
            
            
            
           /*
             in = new FileReader("rle.txt") ;
             br = new BufferedReader(in) ;
            
            while((example=br.readLine())!=null){
                decode(example);
            }
            

            */
            
            
        }
 
}