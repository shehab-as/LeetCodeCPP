class Solution {
public:
    void Permute(vector<vector<int>>& res, vector<int> nums, vector<int>& curr, int index) {
        if(index >= nums.size()) {
            res.push_back(curr);
            return;
        }
        unordered_set<int> vis;
        for(int i = index; i < nums.size(); i++) {
            if(vis.find(nums[i]) != vis.end())  { continue; }
            curr.push_back(nums[i]);
            vis.insert(nums[i]);
            swap(nums[i], nums[index]);
            Permute(res, nums, curr, index + 1);
            curr.pop_back();
            swap(nums[i], nums[index]);
        }
        return;
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> curr;
        Permute(result, nums, curr, 0);
        return result;
    }
};