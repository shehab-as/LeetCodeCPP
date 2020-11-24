class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        if(grid.empty() || grid[0].empty()) return 0;
        int M = grid.size();
        int N = grid[0].size();
        vector<int> Rows(M, 0), Cols(N, 0);
        int count = 0;
        for(int i = 0; i < M; i++) {
            for(int j = 0; j < N; j++) {
                if(grid[i][j]) {
                    Rows[i]++;
                    Cols[j]++;
                }
            }
        }
        for(int i = 0; i < M; i++) {
            for(int j = 0; j < N; j++) {
                if(grid[i][j] && (Rows[i] > 1 || Cols[j] > 1))
                    count++;
            }
        }
        return count;
    }
};