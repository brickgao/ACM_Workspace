import java.io.*;
import java.util.*;
import java.math.*;
import java.text.*;

public class Main {

    public static void main(String[] args) throws Exception{
        int flag = 0;
        Scanner cin = new Scanner(System.in);
        while(cin.hasNext()) {
            if(flag == 1)    System.out.println("");
            flag = 1;
            BigInteger m, n, ans;
            m = cin.nextBigInteger();
            n = cin.nextBigInteger();
            ans = m.gcd(n);
            System.out.println(ans);
        }
    }
}

