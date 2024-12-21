import java.util.Scanner;
import java.math.*;

class Main {
    public static BigInteger factorial(int n){
        BigInteger ans = BigInteger.ONE;
        if (n == 0) return BigInteger.ZERO;
        else {
            for(int i = 1; i <= n; i++){
                ans = ans.multiply(new BigInteger(String.valueOf(i)));
            }
            return ans;
        }
    }
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        BigInteger[][] dp = new BigInteger[n][n];
        // System.out.print(factorial(10));
        for(int i = 0; i < n; i++){
            dp[i][0] = factorial(i).multiply(new BigInteger(String.valueOf(i)));
        }
        for(int i = 1; i < n; i++){
            for(int j = 1; j <= i; j++){
                dp[i][j] = dp[i][j-1].subtract(dp[i-1][j-1]);
            }
        }
        System.out.print(dp[n-1][n-1]);
    }
}