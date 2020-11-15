class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.empty())    return 0;
        int n = nums.size();
        int prev2 = 0;
        int prev1 = 0;
        for(int i = 0; i < n; i++) {
            int temp = prev1;
            prev1 = max(nums[i] + prev2, prev1);
            prev2 = temp;
        }
        
        return prev1;
    }
};