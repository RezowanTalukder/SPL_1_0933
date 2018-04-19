
package rez1;

import static java.awt.PageAttributes.MediaType.C;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.Scanner;


public class ReZ1 {

   
    public static void main(String[] args) throws IOException {
        try {
            

            Scanner input = new Scanner(System.in);

            System.out.println("Enter the name of your (input.txt) file : ");

            String str = input.nextLine();

            File file = new File(str);

            Scanner fileScanner = new Scanner(file);
            
            LZWCompression lzw = new LZWCompression();
            lzw.compress(str);
            double lzwS = lzw.getLZWSize() ;
            
            RLECompress rle = new RLECompress() ;
            rle.compress(str);
            double rleS = rle.getRLESize() ;
            
            LZ77Compress lz77 = new LZ77Compress() ;
            lz77.compress(str);
            
            
            double lz77S = lz77.getLZ77Size() ;        

   
            System.out.println(lzwS+"  "+rleS+"  "+lz77S);
            
            
            
            
        } catch (FileNotFoundException e) {
            System.out.println("File was not found!");
        }
    }
    
}
