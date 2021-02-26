class Solution {
public:
    void exploreIsland(const vector<vector<char>>& g, vector<vector<bool>>& visited, int i, int j) {
        visited[i][j] = true;
        int ROWS[] = {-1, 0, 0, 1};
        int COLS[] = {0, -1, 1, 0};
        for(int k = 0; k < 4; k++) {
            int i2 = i+ROWS[k], j2 = j+COLS[k];
            if(i2 >= 0 && i2 < g.size() && j2 >= 0 && j2 < g[0].size() && (g[i2][j2] == '1' && !visited[i2][j2]) )
                exploreIsland(g, visited, i2, j2);
        }
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty())    return 0;
        int rows = grid.size(), cols = grid[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        int count = 0;               
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(grid[i][j] == '1' && !visited[i][j]) {
                    exploreIsland(grid, visited, i, j);
                    count++;
                }
            }
        }
        return count;
    }
};