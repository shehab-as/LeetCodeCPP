class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        unordered_map<int, long> DP;
        sort(arr.begin(), arr.end());
        long result = 0, MOD = pow(10, 9) + 7;
        for(int i = 0; i < arr.size(); ++i) {
            DP[arr[i]] = 1;
            for(int j = 0; j < i; ++j) {
                if(arr[i] % arr[j] != 0)    continue;
                DP[arr[i]] = (DP[arr[i]] + DP[arr[j]] * DP[arr[i] / arr[j]]) % MOD;
            }
            result = (result + DP[arr[i]]) % MOD;
        }
        return result;
    }
};