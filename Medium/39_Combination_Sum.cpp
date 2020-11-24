class Solution {
public:
    // [2,3,6,7]
    void GenerateAllCombinations(vector<vector<int>>& result, const vector<int>& candidates, vector<int> curr, int curr_val, int target, int index) {
        if(curr_val == target) {
            result.push_back(curr); // one possible combination added to solution.
            return;
        }
        if( index >= candidates.size() || curr_val > target) {
            return;
        }
        for(int i = index; i < candidates.size(); i++) {
            curr.push_back(candidates[i]);
            GenerateAllCombinations(result, candidates, curr, curr_val + candidates[i], target, i);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        GenerateAllCombinations(result, candidates, {}, 0, target, 0);
        return result;
    }
};