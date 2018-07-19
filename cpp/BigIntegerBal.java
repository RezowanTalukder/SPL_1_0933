import java.math.BigInteger;
import java.util.Scanner;
 
public class BigIntegerBal
{
    public static void main(String args[]) throws Exception
    {
        BigInteger A = BigInteger.ZERO ,B ;
        String str = "123456789" ;
        A = new BigInteger("1234") ;
        B = A.add(new BigInteger(str)) ;

        System.out.println(B) ;
    }
}