class Solution {
public:
    int integerBreak(int n) {
        int dp[n+1];
        dp[0] = 0;
        dp[1] = 1;
        for(int i = 2; i <= n; i++) {
            dp[i] = 0;
            for(int l = 1; l <= i-1; l++) {
                dp[i] = max(dp[i], l*max(i-l, dp[i-l]));
            }
        }
        return dp[n];
    }
};