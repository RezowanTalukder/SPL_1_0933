
package bankingclient;


import java.io.*;
import java.net.*;


public class BankingClient
{
    PrintStream streamToServer;
    BufferedReader streamFromServer;
    Socket toServer;
    public BankingClient()
    {
    	System.out.println("Welcome to Client");
        connectToServer();
    }
    private void connectToServer()
    {
        try{
            String name;
            //toServer = new Socket("192.168.0.106",1001);
            toServer = new Socket("localhost",1069);
            streamFromServer = new BufferedReader(new InputStreamReader((toServer.getInputStream())));
            streamToServer = new PrintStream(toServer.getOutputStream());
            
            System.out.println("Enter Connection Name");
            
            String str = "" ;
            
            /*
            while( ! str.equals("quit"))
            {
                BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
                name = reader.readLine(); 
                streamToServer.println(name);
                str = streamFromServer.readLine();
                
                System.out.println("The Server Says: "+str);
                
                
                System.out.println("Enter your massage: ");
                
                name = reader.readLine() ;
                streamToServer.println(name);
                
            }
            
            */
        }
        catch(Exception e)
        {
                System.out.println("Exception "+e);
        }       
    }
    public static void main(String args[])
    {
        new BankingClient();
    }
}