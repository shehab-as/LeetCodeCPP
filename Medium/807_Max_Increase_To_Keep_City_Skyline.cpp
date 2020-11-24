class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        if(grid.empty())    return 0;
        int rows = grid.size(), cols = grid[0].size();
        vector<int> Heightrows, Heightcols;
        for(int i = 0; i < rows; i++) {
            int largest = *max_element(grid[i].begin(), grid[i].end());
            Heightrows.push_back(largest);
            largest = 0;
            for(int j = 0; j < cols; j++) {
                largest = max(grid[j][i], largest);
            }
            Heightcols.push_back(largest);
        }
        int sum = 0;
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                sum += min(Heightrows[i], Heightcols[j]) - grid[i][j];
            }
        }
        return sum;
    }
};