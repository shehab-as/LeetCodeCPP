class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size() < 2) return 0;
        sort(nums.begin(), nums.end());
        int max_gap = 0;
        for(int i = 0; i < nums.size()-1; i++)
            max_gap = max(max_gap, nums[i+1] - nums[i]);
        return max_gap;
    }
};