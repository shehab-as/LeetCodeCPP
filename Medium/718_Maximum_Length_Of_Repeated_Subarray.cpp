class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        if(A.empty() || B.empty()) {
            return 0;
        }
        int M = A.size(), N = B.size();
        // vector<vector<int>> dp(M+1, vector<int>(N+1, 0));
        int dp[M+1][N+1];
        memset(dp, 0, sizeof(dp));
        int global_max = 0;
        for(int i = 1; i <= M; i++) {
            for(int j = 1; j <= N; j++) {
                dp[i][j] = A[i-1] == B[j-1] ? dp[i-1][j-1] + 1 : 0;
                global_max = max(global_max, dp[i][j]);
            }
        }
        return global_max;
    }
};


/*
   1 2 3 2 1
3  0 0 1 0 0
2  0 1 0 2 0
1  1 0 0 0 3
4  0 0 0 0 0
7  0 0 0 0 0
*/