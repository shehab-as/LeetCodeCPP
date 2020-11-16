class Solution {
public:
    int climbStairs(int n) {
        if(n <= 2)  return n;
        int a = 1, b = 1, c;
        // int dp[n+1];
        // dp[0] = 1, dp[1] = 1;
        for(int i = 2; i <= n; i++) {
            c = a + b;
            a = b;
            b = c;
        }
            
            // dp[i] = dp[i-1] + dp[i-2];
        return c;
    }
};