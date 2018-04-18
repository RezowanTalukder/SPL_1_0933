package rez1;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileReader;
import java.util.regex.Matcher;
import java.util.regex.Pattern;


public class RLECompression {
    
    
        
    
        public static String encode(String fileName) {
            
            
            
            try{
                /*
                byte[] buffer = new byte[10000] ;
                
                FileInputStream inp = new FileInputStream(fileName) ;
                int nRead = 0 ;
                while(nRead = inp.read(buffer)!=-1){
                    
                }
                
              */
                
                
                
                FileReader fileReader = new FileReader(fileName) ;
                BufferedReader br = new BufferedReader(fileReader) ;
                String source = null , dest = null ;
                while((source= br.readLine())!=null){
                        dest = null ;
                        //int runLength = 0 ;
                        for (int i = 0; i < source.length(); i++) {
                        int runLength = 1 ;
                        while (i + 1 < source.length()&& source.charAt(i) == source.charAt(i + 1)) {
                            runLength++ ;
                            i++ ;
                        }
                        dest.append(runLength);
                        dest.append(source.charAt(i));
                    }
                }
                
            }catch(Exception e){
                
            }
            
            StringBuffer dest = new StringBuffer();
            
            return dest.toString();
        }

        public static String decode(String source) {
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
            return dest.toString();
        }

        public static void main(String[] args) {
            String example = "aaaaabbbbbcccccr" ;
            System.out.println(encode(example));
            System.out.println(decode(encode(example)));
        }
 
}