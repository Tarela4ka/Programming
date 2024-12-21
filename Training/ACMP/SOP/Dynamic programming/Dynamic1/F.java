import java.util.Scanner;
import java.math.*;
 
class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int k = scan.nextInt();
        int n = scan.nextInt();
        BigInteger[] dp = new BigInteger[n+1];
        int[] p = new int[k+1];
        for(int i = 1; i <= k; i++){
            p[i] = i;
        }
        dp[0] = BigInteger.ONE;
        for(int i = 1; i <= n; i++){
            dp[i] = BigInteger.ZERO;
            for(int c : p){
                if(c > i) break;
                dp[i] = dp[i].add(dp[i-c]);
            }
        }
        System.out.print(dp[n]);
        scan.close();
    }
}