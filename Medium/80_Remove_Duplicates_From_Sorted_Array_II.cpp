class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty())    return 0;
        int size = 0, current_element = -1, current_count = 1;
        for(int j = 0; j < nums.size(); j++) {
            if(nums[j] == current_element) {
                if(current_count == 2)   continue;
                current_count++;
            }
            else {
                current_element = nums[j];
                current_count = 1;
            }
            nums[size++] = nums[j];
        }
        return size;
    }
};
