class Solution {
public:
    void gen_combinations(vector<vector<int>>& res, vector<int> comb, int i, int k, int n) {
        if(comb.size() == k) {
            res.push_back(comb);
            return;
        }
        if(i > n)   
            return;
        for(int j = i; j <= n; j++) {
            comb.push_back(j);
            gen_combinations(res, comb, j+1, k, n);
            comb.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        gen_combinations(res, {}, 1, k, n);
        return res;
    }
};
