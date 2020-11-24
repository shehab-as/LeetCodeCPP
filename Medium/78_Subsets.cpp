
class Solution {
public:
    void permute(vector<vector<int>>& subsets, vector<int>nums, vector<int> subset, int index) {
        subsets.push_back(subset);
        for(int i = index; i < nums.size(); i++) {
            subset.push_back(nums[i]);
            permute(subsets, nums, subset, i+1);
            subset.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        if(nums.empty())    return {};
        sort(nums.begin(), nums.end());
        vector<vector<int>> subsets;
        permute(subsets, nums, {}, 0);
        return subsets;
    }
};