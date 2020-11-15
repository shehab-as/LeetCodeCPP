class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> HashMap;
        unordered_map<int, int>::iterator it;
        for(int i = 0; i < nums.size(); i++) {
            it = HashMap.find(nums[i]);
            if(it != HashMap.end()) {
                if(i - k <= it->second)
                    return true;
                it->second = i;
            }
            else {
                HashMap.insert(pair<int,int>{nums[i], i});
            }
        }
        return false;
    }
};