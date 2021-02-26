class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        vector<int> dp = {0, 0, 0}, dp2;
        for(int e : nums) {
            dp2 = dp;
            for(int i : dp2) {
                dp[(i + e) % 3] = max(dp[(i + e) % 3], i + e);
            }
        }
        return dp[0];
    }
};