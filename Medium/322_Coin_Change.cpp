class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int memo[amount+1];
        memo[0] = 0;
        
        for(int i=1; i<=amount; i++)
            memo[i] = INT_MAX;
        
        for(auto coin : coins) {
            for(int i = coin; i <= amount; i++)
            {
                if(memo[i-coin] != INT_MAX)
                    memo[i] = min(memo[i], memo[i-coin] + 1);
            }
        }
        return memo[amount] == INT_MAX ? -1 : memo[amount];
    }
};