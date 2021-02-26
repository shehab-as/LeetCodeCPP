class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        if(nums.empty())    return {};
        unordered_map<int, int> freq;
        for(int& n : nums)
            freq[n]++;
        vector<int> result;
        for(auto it : freq) {
            if(it.second > floor(nums.size()/3))
                result.push_back(it.first);
        }
        return result;
    }
};