class Solution {
public:
    void jump(const vector<int>& nums, int i, vector<int>& dp) {
        if(i == 0) {
            dp[i] = true;
            return;
        }
        dp[i] = false;
        for(int k = i - 1; k >= 0; k--) {
            if(dp[k] == -1) 
                jump(nums, i-1, dp);
            if(dp[k] == true && (nums[k] + k >=i))
                dp[i] = true;
            if(dp[i] == true)   return;
        }
    }
    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        jump(nums, nums.size() - 1, dp);
        return dp[nums.size() - 1];
    }
};