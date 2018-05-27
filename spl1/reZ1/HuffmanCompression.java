
package rez1;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.nio.file.StandardOpenOption;
import java.util.HashMap;
import java.util.Map;
import java.util.PriorityQueue;
import java.util.Comparator;
import java.util.Scanner;

 class Node{
           int frequency;
           char input;
           Node left;
           Node right;
}

         

public class HuffmanCompression {
    
            
           Node node ;
    
            public static String outputFile ;
            public char []a ;
            public int []freq ;
            public char []input ;
            
            class HuffCom implements Comparator<Node>{
                public int compare(Node o1, Node o2) {
                    if(o1.frequency < o2.frequency){
                        return -1;
                    }else{
                        return 1;
                    }
                }       
            }
    

            
        public void createCode(Node node,Map<Character,String> map,StringBuffer buff){
            if(node == null){
                return;
            }

            if(node.left == null && node.right == null){
                map.put(node.input,buff.toString());
                return;
            }
            
            buff.append("0");
            createCode(node.left,map,buff);
            buff.deleteCharAt(buff.length()-1);
            buff.append("1");
            createCode(node.right,map,buff);
            buff.deleteCharAt(buff.length()-1);
            
        }
       
        
    
            public Map<Character,String> huffman(char[] input, int freq[]){
            
                HuffCom comparator = new HuffCom();
                PriorityQueue<Node> heap = new PriorityQueue<Node>(input.length,comparator);
                for(int i=0; i < input.length; i++){
                    node = new Node();
                    node.frequency = freq[i];
                    node.input = input[i];
                    heap.offer(node);
                }

                while(heap.size() > 1){
                    Node node1 = heap.poll();
                    Node node2 = heap.poll();
                    node = new Node();
                    node.left = node1;
                    node.right = node2;
                    node.frequency = node1.frequency + node2.frequency;
                    heap.offer(node);
                }

                Map<Character,String> map = new HashMap<Character,String>();
                StringBuffer buff = new StringBuffer();
                createCode(heap.poll(),map,buff);
                return map;

        }

        public double getHuffmanSize() throws IOException
        {
            File fi ;
            fi = new File(outputFile);
            
            return fi.length() ;
        }

        public void compress(String fileName) throws FileNotFoundException, IOException{
            String fileN = fileName ;       
            String content = new Scanner(new File(fileN)).useDelimiter("\\Z").next();
            
            input = content.toCharArray() ;
            
            a = new char[99999];
            freq = new int[99999];
        
            int index = 0 ;
            
            
            for(int i=0;i<content.length();i++)
		{
			int count=0;
			char ch=content.charAt(i);
			for(int k=0;k<index;k++){
				if(a[k]!=ch)
					count++;
			}
			if(count==index) //element not present
			{
				
				a[index]=ch;
				freq[index]=1;
				index++;
			}
                        
                        //element present
			
                        else     
			{
				int j;
				for( j=0;j<index;j++)
				{
					if(a[j]==ch)
					break;
				}
                                
				freq[j]++;
				
			}
			
		}
            
            /*
            for(int i=0 ;i<index ;i++){
                System.out.println("here : "+input[i]+"  "+freq[i]);
            }
            */
            
            
            Map<Character,String> code = huffman(input, freq);
            
           // System.out.println(code);
            
  
            
            outputFile = fileName+"_huffman.txt" ;
            
            PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter(outputFile,true))) ;
            Files.write(Paths.get(outputFile),code.toString().getBytes(), StandardOpenOption.APPEND) ;
        }

    }

