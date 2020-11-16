class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int len1 = 0, len2;
        for(len2 = 0; len2 < nums.size(); len2++) {
            if(nums[len2] != val) {
                nums[len1++] = nums[len2];
            }
        }
        return len1;
    }
};