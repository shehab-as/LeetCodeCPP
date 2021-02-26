class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int N = nums.size();
        int M = pow(2, N);
        sort(nums.begin(), nums.end());
        vector<vector<int>> subsets;
        set<string> visited;
        for(int i = 0; i < M; i++) {
            vector<int> subset;
            string key = "";
            for(int j = 0; j < N; j++) {
                if( (i >> j) & 1 ) {
                    subset.push_back(nums[j]);
                    key += to_string(nums[j]);
                }
            }
            if(visited.find(key) == visited.end())
                subsets.push_back(subset);
            visited.insert(key);
        }
        return subsets;
    }
};
