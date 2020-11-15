class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hmp;
        for(int i = 0; i < nums.size(); i++) {
            auto it = hmp.find(target - nums[i]);
            if(it != hmp.end()) 
                return {i, it->second};
            hmp[nums[i]] = i;
        }
        return {};
    }
};