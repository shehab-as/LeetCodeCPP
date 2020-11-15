class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        while(low <= high) {
            int m = low + (high-low/2);
            if(nums[m] == target)
                return m;
            if(nums[m] < target)
                low = m + 1;
            else
                high = m - 1;
        }
        return low;
    }
};