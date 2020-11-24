class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.empty())    return 0;
        int M = grid.size(), N = grid[0].size();
        int memo[M][N];
        memo[0][0] = grid[0][0];
        for(int i = 1; i < M; i++)
            memo[i][0] = memo[i-1][0] + grid[i][0];
        for(int j = 1; j < N; j++)
            memo[0][j] = memo[0][j-1] + grid[0][j];
        
        for(int i = 1; i < M; i++) {
            for(int j = 1; j < N; j++) {
                memo[i][j] = min(memo[i-1][j], memo[i][j-1]) + grid[i][j];
            }
        }
        return memo[M-1][N-1];
    }
};