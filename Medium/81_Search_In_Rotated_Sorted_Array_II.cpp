class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int len = nums.size();
        int start = 0, end = len - 1, m;
        while(start <= end) {
            m = (start + end) >> 1;
            if(nums[m] == target)   return true;
            if(nums[m] == nums[start] && nums[m] == nums[end]) {
                start++;
                end--;
            }
            // sorted part.
            else if(nums[start] <= nums[m]) {
                if(target >= nums[start] && target < nums[m])
                    end = m - 1;
                else 
                    start = m + 1;
            }
            // rotated part.
            else {
                if(target > nums[m] && target <= nums[end])
                    start = m + 1;
                else 
                    end = m - 1;
            }
        }
        return false;
    }
};