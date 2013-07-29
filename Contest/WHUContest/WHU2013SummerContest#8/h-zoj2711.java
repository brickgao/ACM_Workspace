import java.io.*;
import java.util.*;
import java.math.*;
import java.text.*;

public class Main {

    public static void main(String[] args) throws Exception{
        int flag = 0;
        Scanner cin = new Scanner(System.in);
        BigInteger rec[][][];
        rec = new BigInteger[70][70][70];
        for(int i = 0; i <= 60; ++ i)
            for(int j = 0; j <= 60; ++ j)
                for(int k = 0; k <= 60; ++ k)
                    rec[i][j][k] = BigInteger.valueOf(0);
        rec[0][0][0] = BigInteger.valueOf(1);
        for(int i = 0; i <= 60; ++ i)
            for(int j = 0; j <= i; ++ j)
                for(int k = 0; k <= j; ++ k) {
                    if(i >= 1)
                        rec[i][j][k] = rec[i][j][k].add(rec[i - 1][j][k]);
                    if(j >= 1)
                        rec[i][j][k] = rec[i][j][k].add(rec[i][j - 1][k]);
                    if(k >= 1)
                        rec[i][j][k] = rec[i][j][k].add(rec[i][j][k - 1]);
                }
        while(cin.hasNext()) {
            int n;
            n = cin.nextInt();
            System.out.println(rec[n][n][n]);
            System.out.println();
        }
    }
}
