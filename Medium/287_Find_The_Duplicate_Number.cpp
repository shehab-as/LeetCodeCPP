class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int N = nums.size();
        for(int i = 0; i < N; i++) {
            if(nums[abs(nums[i])] > 0) {
                nums[abs(nums[i])] = -nums[abs(nums[i])];
            }
            else
                return abs(nums[i]);
        }
        return -1;
    }
};