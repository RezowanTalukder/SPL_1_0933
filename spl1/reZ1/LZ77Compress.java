
/*
    *this class implement LZ77 algorithm to compress file 
    *FileStream is used so cm compress any type of file

*/

package rez1;

/*  Author
    Md Rezowan Talukder
*/


import java.io.*;
import java.io.BufferedReader;
import java.io.File;



public class LZ77Compress {
    
         public static final int DEFAULT_BUFF_SIZE = 1024;
         protected int mBufferSize;
         protected Reader mIn;
         protected PrintWriter mOut;
         protected StringBuffer mSearchBuffer;
  
        public LZ77Compress() {
             this(DEFAULT_BUFF_SIZE);
        }
  
        public LZ77Compress(int buffSize) {
              mBufferSize = buffSize;
              mSearchBuffer = new StringBuffer(mBufferSize);
         }


        
        
         private void trimSearchBuffer() {
             if (mSearchBuffer.length() > mBufferSize) {
                     mSearchBuffer=mSearchBuffer.delete(0,  mSearchBuffer.length() - mBufferSize);
                }
         }
            
        public void compress(String infile) throws IOException {
                
                mIn = new BufferedReader(new FileReader(infile));
                mOut = new PrintWriter(new BufferedWriter(new FileWriter(infile+"_lz77.txt")));

                int nextChar;
                String currentMatch = "";
                int matchIndex = 0, tempIndex = 0;

                
                while ((nextChar = mIn.read()) != -1) {
                  
                        tempIndex = mSearchBuffer.indexOf(currentMatch + (char)nextChar);

                        if (tempIndex != -1) {
                             currentMatch += (char)nextChar;
                             matchIndex = tempIndex;
                        } 
                        
                        else {

                          String codedString = "~"+matchIndex+"~"+currentMatch.length()+"~"+(char)nextChar;
                          String concat = currentMatch + (char)nextChar;

                          if (codedString.length() <= concat.length()) {
                                mOut.print(codedString);
                                mSearchBuffer.append(concat); 
                                currentMatch = "";
                                matchIndex = 0;
                          } 
                          else {

                                currentMatch = concat; matchIndex = -1;
                                
                                while (currentMatch.length() > 1 && matchIndex == -1) {
                                    mOut.print(currentMatch.charAt(0));
                                    mSearchBuffer.append(currentMatch.charAt(0));
                                    currentMatch = currentMatch.substring(1, currentMatch.length());
                                    matchIndex = mSearchBuffer.indexOf(currentMatch);
                                }
                          }

                          trimSearchBuffer();
                        }
                }
                
                if (matchIndex != -1) {
                    
                  String codedString = "~"+matchIndex+"~"+currentMatch.length();
                  
                  if (codedString.length() <= currentMatch.length()) {
                         mOut.print("~"+matchIndex+"~"+currentMatch.length());
                  } 
                  else {
                        mOut.print(currentMatch);
                  }
                }
               
                
                mIn.close();
                
                mOut.flush(); mOut.close();
        }
        
        public double getLZ77Size(String f)
        {
            File fi ;
            fi = new File(f+"_lz77.txt");
            System.out.println("lz77   "+fi.length());
            return fi.length() ;
            
        }
}


