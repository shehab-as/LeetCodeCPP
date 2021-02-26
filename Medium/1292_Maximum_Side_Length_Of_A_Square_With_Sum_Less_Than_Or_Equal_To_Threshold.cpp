class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int M = mat.size();
        int N = mat[0].size();
        vector<vector<int>> dp(M+1, vector<int>(N+1, 0));
        
        for(int i = 1; i <= M; i++) {
            for(int j = 1; j <= N; j++) {
                dp[i][j] = mat[i-1][j-1] + dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
            }
        }
        int side_len = 0;
        for(int i = 1; i <= M; i++) {
            for(int j = 1; j <= N; j++) {
                int r = min(i, j);
                for(int k = 1; k <= r; k++) {
                    int val = dp[i][j] + dp[i-k][j-k] - dp[i-k][j] - dp[i][j-k];
                    if( val <= threshold ) {
                        side_len = max(side_len, k);
                    }
                }
            }
        }
        return side_len;
    }
};

