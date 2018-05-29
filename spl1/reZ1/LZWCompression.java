
/*
    *LZW algorithm is implemented using 
    *files are read using buffer and algorithm implemented in bytes
    *thus work for any type of file
*/

package rez1;

/*  Author
    Md Rezowan Talukder
*/

import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.FileWriter;
import java.io.InputStreamReader;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.util.HashMap;
import java.util.logging.Level;
import java.util.logging.Logger;

public class LZWCompression {

    public HashMap compdic, decompdic;
    String fileName  ;
    short lastcode = 0, dlastcode = 0;

    LZWCompression(String f) {
        compdic = new HashMap<String, Integer>();
        decompdic = new HashMap<Integer, String>();
        createDictionary(f);
    }

    public void createDictionary(String f) {
       fileName = f ;
        
        try {
            short code;
            char ch;
            FileInputStream fis = new FileInputStream(fileName);
            InputStreamReader rdr = new InputStreamReader(fis, "utf-8");
            while ((code = (short) rdr.read()) != -1) {
                ch = (char) code;

                if (!compdic.containsKey(ch)) {
                    compdic.put("" + ch, code);
                    decompdic.put(code, "" + ch);
                    if (code > lastcode) {
                        lastcode = code;
                        dlastcode = code;
                    }
                }
            }
            fis.close();
        } catch (Exception ex) {
            Logger.getLogger(LZWCompression.class.getName()).log(Level.SEVERE, null, ex);
        }
    }

    public void compressFile(String f) {
        fileName = f ;
        
        try {
            short code, codeword;
            char c;
            String s;

        
            FileInputStream fis = new FileInputStream(fileName);
            InputStreamReader rdr = new InputStreamReader(fis, "utf-8");
            FileOutputStream fos = new FileOutputStream(fileName + "_lzw.txt");
            ObjectOutputStream fout = new ObjectOutputStream(fos);

            s = (char) rdr.read() + "";
            while ((code = (short) rdr.read()) != -1) {
                c = (char) code;

                if (!compdic.containsKey(s + c)) {
                    codeword = Short.parseShort(compdic.get(s).toString());

                    fout.writeShort(codeword);
                    compdic.put(s + c, ++lastcode);
                    s = "" + c;
                } else {
                    s = s + c;
                }
            }

            codeword = Short.parseShort(compdic.get(s).toString());
            fout.writeShort(codeword);
            fout.writeShort(00);

            fout.close();
            fis.close();

        } catch (Exception ex) {
            Logger.getLogger(LZWCompression.class.getName()).log(Level.SEVERE, null, ex);
        }
    }

   public double getLZWSize(String f) {
       File fi ;
       fi = new File(f + "_lzw.txt");
       return fi.length() ;
    }

    public void compress(String f) {
        LZWCompression lzw = new LZWCompression(f);
        lzw.compressFile(f);
     
    }
}