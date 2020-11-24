class Solution {
public:
    void Permute(vector<vector<int>>& res, vector<int>& nums, int index) {
        if( index >= nums.size() ) {
            res.push_back(nums);
            return;
        }
        for(int i = index; i < nums.size(); i++) {
            swap(nums[i], nums[index]);
            Permute(res, nums, index + 1);
            swap(nums[i], nums[index]);
        }
        return;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        Permute(res, nums, 0);
        return res;
    }
};