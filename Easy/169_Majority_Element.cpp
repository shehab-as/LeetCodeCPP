class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> freq;
        for(int& n : nums)
            freq[n]++;
        int major = nums[0];
        for(auto it : freq) {
            if(it.second > floor(nums.size() / 2))
                major = it.first;
        }
        return major;
    }
};