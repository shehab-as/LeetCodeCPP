class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int M = (int) grid.size(), N = (int) grid[0].size();
        vector<vector<int>> DP(N, vector<int>(N));
        
        for(int row = 0; row < M; row++) {
            vector<vector<int>> currDP (N, vector<int>(N));
            for(int c1 = 0; c1 < min(N, row + 1); c1++) {
                for(int c2 = max(0, N - 1 - row); c2 < N; c2++) {
                    int prev_max = 0;
                    for(int offset1 = max(0, c1 - 1); offset1 <= min(N-1, c1+1); offset1++) {
                        for(int offset2 = max(0, c2 - 1); offset2 <= min(N-1, c2+1); offset2++) {
                            prev_max = max(prev_max, DP[offset1][offset2]);
                        }
                    }
                    if (c1 == c2)
                        currDP[c1][c2] = prev_max + grid[row][c1];
                    else 
                        currDP[c1][c2] = prev_max + grid[row][c1] + grid[row][c2];
                }
            }
            DP = currDP;
        }
        int res = 0;
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                res = max(res, DP[i][j]);
            }
        }
        return res;
    }
};