class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.empty())    return 0;
        int sum = 0;
        int res = nums[0];
        for(int n : nums) {
            sum = max(sum + n, n);
            res = max(res, sum);
        }
        return res;
    }
};