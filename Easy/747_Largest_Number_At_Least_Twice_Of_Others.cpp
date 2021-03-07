class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int largest = INT_MIN, index = -1;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] > largest) {
                largest = nums[i];
                index = i;
            }
        }
        for(int j = 0; j < nums.size(); j++) {
            if((nums[j] * 2) > largest && nums[j] != largest)
                index = -1;
        }
        return index;
    }
};