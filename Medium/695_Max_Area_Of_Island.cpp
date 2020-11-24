class Solution {
public:
    void DFS(vector<vector<int>>& grid, const int M, const int N, int r, int c, int& curr_area) {
        if( r < 0 || r >= M || c < 0 || c >= N || !grid[r][c] || grid[r][c] == '*') {
            return;
        }
        curr_area++;
        grid[r][c] = '*';
        int rows[] = {-1, 0, 1, 0};
        int cols[] = {0, 1, 0, -1};
        for(int k = 0; k < 4; k++)
            DFS(grid, M, N, r + rows[k], c + cols[k], curr_area);
        return;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if(grid.empty() || grid[0].empty()) {
            return 0;
        }
        int M = grid.size(), N = grid[0].size();
        int max_area = 0;
        for(int i = 0; i < M; i++) {
            for(int j = 0; j < N; j++) {
                if(grid[i][j]) {
                    int curr_area = 0;
                    DFS(grid, M, N, i, j, curr_area);
                    max_area = max(max_area, curr_area);
                }
            }
        }
        return max_area;
    }
};