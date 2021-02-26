class Solution {
public:
    int search(vector<int>& nums, int target) {
        int N = nums.size();
        int s = 0, e = N - 1;
        while ( s <= e ) {
            int m = s + (e-s)/2;
            if(nums[m] == target)   return m;
            if(nums[s] <= nums[m]) {  // first half sorted
                if(target >= nums[s] && target < nums[m])   e = m - 1;
                else    s = m + 1;
            }
            else { 
                if(target <= nums[e] && target > nums[m])    s = m + 1;
                else    e = m - 1;
            }
        }
        return -1;
    }
};