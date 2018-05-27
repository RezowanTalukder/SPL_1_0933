package rez1;

import java.io.*;
import java.util.*;

public class LZWCompression {

    public LZWCompression(){
        
    }
    public HashMap<String, Integer> dictionary = new HashMap<>();
    public int dictSize = 256;
    public String str = "";
    public byte inputByte;
    public byte[] buffer = new byte[3];
    public boolean onleft = true;
    public static int len ;

    //String fi = null ;
    public void compress(String uncompressed) throws IOException {
        
        for (int i = 0; i < 256; i++) {
            dictionary.put(Character.toString((char) i), i);
        }

       
        RandomAccessFile read = new RandomAccessFile(uncompressed, "r");
        String outputFile =  uncompressed+"_lzw.txt" ;
        RandomAccessFile out = new RandomAccessFile(outputFile , "rw");
        
       // System.out.println("file name thik ase");
        
       // RandomAccessFile out = new RandomAccessFile(uncompressed.concat(".lzw"), "rw");
        
        //fi = uncompressed ;

        try {
            
            inputByte = read.readByte();
            
            int i = new Byte(inputByte).intValue();
            if (i < 0) {
                i += 256;
            }
            char ch = (char) i;
            str = "" + ch;

            // Reads Characters
            
            while (true) {
                inputByte = read.readByte();
                i = new Byte(inputByte).intValue();

                if (i < 0) {
                    i += 256;
                }
                //System.out.print(i + ", ");
                ch = (char) i;

                
                if (dictionary.containsKey(str + ch)) {
                    str = str + ch;
                }
                
                else {
                    String s12 = to12bit(dictionary.get(str));

                    if (onleft) {
                        buffer[0] = (byte) Integer.parseInt(s12.substring(0, 8), 2);
                        buffer[1] = (byte) Integer.parseInt(s12.substring(8, 12) + "0000", 2);
                    }
                    
                    else {
                        buffer[1] += (byte) Integer.parseInt(s12.substring(0, 4), 2);
                        buffer[2] = (byte) Integer.parseInt( s12.substring(4, 12), 2);
                        
                        for (int b = 0; b < buffer.length; b++) {
                            out.writeByte(buffer[b]);
                            buffer[b] = 0;
                        }
                    }
                    
                    onleft = !onleft;

                    
                    if (dictSize < 4096) {
                        dictionary.put(str + ch, dictSize++);
                    }

                    // Set str to ch
                    str = "" + ch;
                }
            }
           
        } catch (IOException e) {
           
            System.out.println(out.length()) ;
            len = (int) out.length() ;
            read.close();
            out.close();
        }
    }

    public String to12bit(int i) {
        String str = Integer.toBinaryString(i);
        while (str.length() < 12) {
            str = "0" + str ;
        }
        return str;
    }
    
    
    public double getLZWSize()
    {   
            return len ;
    }

}

// Exception


 /*
            String str12bit = to12bit(dictionary.get(str));
            if (onleft) {
                buffer[0] = (byte) Integer.parseInt(str12bit.substring(0, 8), 2);
                buffer[1] = (byte) Integer.parseInt(str12bit.substring(8, 12) + "0000", 2);
                out.writeByte(buffer[0]);
                out.writeByte(buffer[1]);
            } else {
                buffer[1] += (byte) Integer.parseInt(str12bit.substring(0, 4), 2);
                buffer[2] = (byte) Integer.parseInt(str12bit.substring(4, 12), 2);

                for (int b = 0; b < buffer.length; b++) {
                    out.writeByte(buffer[b]);
                    buffer[b] = 0;
                }
            }
                    
            */
