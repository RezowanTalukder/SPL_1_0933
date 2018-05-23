
package rez1;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.HashMap;
import java.util.Map;
import java.util.PriorityQueue;
import java.util.Comparator;
import java.util.Scanner;

public class HuffmanCompression {



    class Node{
        int freq;
        char input;
        Node left;
        Node right;
    }

    class HuffCom implements Comparator<Node>{
        public int compare(Node o1, Node o2) {
            if(o1.freq < o2.freq){
                return -1;
            }else{
                return 1;
            }
        }

    }

    public class HuffmanEncoding {

        public Map<Character,String> huffman(char[] input, int freq[]){
            HuffCom comparator = new HuffCom();
            PriorityQueue<Node> heap = new PriorityQueue<Node>(input.length,comparator);
            for(int i=0; i < input.length; i++){
                Node node = new Node();
                node.freq = freq[i];
                node.input = input[i];
                heap.offer(node);
            }

            while(heap.size() > 1){
                Node node1 = heap.poll();
                Node node2 = heap.poll();
                Node node = new Node();
                node.left = node1;
                node.right = node2;
                node.freq = node1.freq + node2.freq;
                heap.offer(node);
            }

            Map<Character,String> map = new HashMap<Character,String>();
            StringBuffer buff = new StringBuffer();
            createCode(heap.poll(),map,buff);
            return map;

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
       

        public void huffmanMain(String fileName) throws FileNotFoundException{
            HuffmanEncoding huff = new HuffmanEncoding();
            char input[] = {'a','b','c','d','e','f'};
            int freq[] = {5,9,12,13,16,45};
            Map<Character,String> code = huff.huffman(input, freq);
            System.out.println(code);
            
            String content = new Scanner(new File("filename")).useDelimiter("\\Z").next();
            
            for(int i=0 ;i<content.length() ;i++){
                //char ch = content[i] ;
                //freq[ch]++ ;
            }
            
            /*
           // char input[] ;
           // int freq[] ;
            
            File file = new File(fileName) ;
            
            char ch ;
            
            String content = new Scanner(new File("filename")).useDelimiter("\\Z").next();
            
            Map<char,Integer>mp = new  HashMap<char,Integer>();
            
            while(file.hasNext)
            {
                
            }
            */
           
        }

    }
}
