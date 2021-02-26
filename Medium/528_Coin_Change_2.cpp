class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp (amount + 1, 0);
        dp[0] = 1;
        int N = coins.size();
        for(int i = 0; i < N; i++) {
            for(int j = coins[i]; j <= amount; j++) {
                dp[j] += dp[j - coins[i]];
                // cout<<"Coin: "<<j<<" | dp[Coin]: "<<dp[j]<<endl;
            }
        }
        return dp[amount];
    }
};