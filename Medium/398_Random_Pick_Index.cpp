class Solution {
private:
    vector<int> _nums;
public:
    Solution(vector<int>& nums) : _nums(nums) {}
    
    int pick(int target) {
        int count = 0;
        int index = -1;
        for(int i = 0; i < _nums.size(); i++) {
            if(_nums[i] != target)   continue;
            if(count == 0) {
                index = i;
                count++;
            }
            else {
                count++;
                if(rand() % count == 0)
                    index = i;
            }
        }
        return index;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
