class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        while(low < high) {
            int m = low + (high - low)/2;
            if(nums[m] <= nums[m+1])
                low = m + 1;
            else 
                high = m;
        }
        return low;
    }
};