class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int M = grid.size(), N = grid[0].size();
        vector<vector<int>> shifted_grid(M, vector<int>(N, 0));
        k = k % (M * N);
        while(k--) {
            for(int i = 0; i < M; i++) {
                for(int j = 1; j < N; j++) {
                    shifted_grid[i][j] = grid[i][j-1];
                }
            }
            for(int i = 0; i < M - 1; i++)
                shifted_grid[i+1][0] = grid[i][N-1];
            
            shifted_grid[0][0] = grid[M-1][N-1];
            grid = shifted_grid;
        }
        return grid;
    }
};

