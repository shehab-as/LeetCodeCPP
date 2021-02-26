class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int M = obstacleGrid.size();
        int N = obstacleGrid[0].size();
        int memo[M][N];
        for(int i = 0; i < M; i++) {
            if(obstacleGrid[i][0] || (i > 0 && memo[i-1][0] == 0))
                memo[i][0] = 0;
            else
                memo[i][0] = 1;
        }
        for(int j = 0; j < N; j++) {
            if(obstacleGrid[0][j] || (j > 0 && memo[0][j-1] == 0))
                memo[0][j] = 0;
            else 
                memo[0][j] = 1;
        }
        
        for(int i = 1; i < M; i++) {
            for(int j = 1; j < N; j++) {
                if(obstacleGrid[i][j]) 
                    memo[i][j] = 0;
                else 
                    memo[i][j] = memo[i-1][j] + memo[i][j-1];
            }
        }
        return memo[M-1][N-1];
    }
};