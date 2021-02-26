class Solution {
public:
    int CountNeighbours(const vector<vector<int>>& grid, int x, int y) {
        int count = 0;
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};
        for(int k = 0; k < 4; k++) {
            int x2 = x + dx[k], y2 = y + dy[k];
            if(x2 < 0 || x2 >= grid.size() || y2 < 0 || y2 >= grid[0].size())   continue;
            if(grid[x2][y2])
                count++;
        }
        return count;
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        if(grid.empty() || grid[0].empty()) return 0;
        int perimeter = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j])
                    perimeter += (4 - CountNeighbours(grid, i, j));
            }
        }
        return perimeter;
    }
};