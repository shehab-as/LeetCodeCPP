class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total = 0;
        for(int& e : nums) {
            total += e;
        }
        if(total & 1)  return false;
        int target = total / 2;
        int N = nums.size();
        vector<bool> dp(target+1, false);
        dp[0] = true;
        
        for(int& num : nums) {
            for(int i = target; i > 0; i--) {
                if( i >= num ) {
                    dp[i] = dp[i] || dp[i-num];
                }
            }
        }
        return dp[target];
    }
};