class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> res(nums.size(), 0);
        int low = 0, high = nums.size()-1;
        int idx = nums.size()-1;
        while(low <= high) {
            if(nums[low]*nums[low] <= nums[high]*nums[high]) {
                res[idx--] = nums[high]*nums[high];
                high--;
            } else {
                res[idx--] = nums[low]*nums[low];
                low++;
            }
        }
        return res;
    }
};