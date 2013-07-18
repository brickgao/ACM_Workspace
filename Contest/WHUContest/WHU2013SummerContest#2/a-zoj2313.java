import java.io.*;
import java.util.*;
import java.math.*;
import java.text.*;

public class Main {

    public static void main(String[] args) throws Exception{
        int t;
        Scanner cin = new Scanner(System.in);
        t = cin.nextInt();
        for(int T = 0; T < t; ++ T) {
            BigInteger n, tmp;
            if(T > 0)   System.out.println("");
            n = cin.nextBigInteger();
            tmp = n.divide(BigInteger.valueOf(2));
            if(n.mod(BigInteger.valueOf(2)) == BigInteger.valueOf(0)) {
                tmp = tmp.subtract(BigInteger.valueOf(1));
                if(tmp.mod(BigInteger.valueOf(2)) == BigInteger.valueOf(0))
                    tmp = tmp.subtract(BigInteger.valueOf(1));
                System.out.println(tmp);
            }
            else {
                System.out.println(tmp);
            }
        }
    }
}

