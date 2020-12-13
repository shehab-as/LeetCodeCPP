class Solution {
public:
    int maxCoins(vector<int>& nums) {
        if(nums.empty())    return 0;
        if(nums.size() == 1)    return nums[0];
        int N = (int) nums.size();
        vector<vector<int>> DP(N+1, vector<int>(N+1, 0));
        
        for(int len = 1; len <= N; len++) {
            for(int l = 0; l <= N - len; l++) {
                int r = l + len - 1;
                for(int k = l; k <= r; k++) {
                    int leftVal = 1;
                    int rightVal = 1;
                    if(l > 0)
                        leftVal = nums[l-1];
                    if(r < N - 1)
                        rightVal = nums[r+1];
                    int before = 0, after = 0;
                    if(l != k)
                        before = DP[l][k-1];
                    if(r != k)
                        after = DP[k+1][r];
                    DP[l][r] = max(leftVal * nums[k] * rightVal + before + after, DP[l][r]);
                }
            }
        }
        return DP[0][N-1];
    }
};