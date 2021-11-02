class Solution {
private:
    int empty_cells = 1, result = 0;
    void DFS(vector<vector<int>>& grid, int r, int c, int count) {
        if(r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() || grid[r][c] == -1) { return; }
        if(grid[r][c] == 2) { 
            if(empty_cells == count) { result++; }
            return;
        }
        grid[r][c] = -1;
        DFS(grid, r + 1, c, count + 1);
        DFS(grid, r - 1, c, count + 1);
        DFS(grid, r, c + 1, count + 1);
        DFS(grid, r, c - 1, count + 1);
        grid[r][c] = 0;
    }
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        if(grid.empty() || grid[0].empty()) { return 0; }
        int start_r = 0, start_c = 0;
        int M = grid.size(), N = grid[0].size();
        
        for(int r = 0; r < M; r++) {
            for(int c = 0; c < N; c++) {
                if(grid[r][c] == 1) {
                    start_r = r;
                    start_c = c;
                } else if(grid[r][c] == 0) {
                    empty_cells++;
                }
            }
        }
        DFS(grid, start_r, start_c, 0);
        return result;
    }
};