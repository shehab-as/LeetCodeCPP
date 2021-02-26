class Solution {
public:    
    int orangesRotting(vector<vector<int>>& grid) {
        int M = grid.size(), N = grid[0].size();
        queue<pair<int,int>> q;
        int total_mins = 0, count = 0, second_count = 0;
        for(int i = 0; i < M; i++) {
            for(int j = 0; j < N; j++) {
                count += grid[i][j] != 0 ? 1 : 0;
                if(grid[i][j] == 2) 
                    q.push({i,j});
            }
        }
        int dir[2][4] = {{-1,0,1,0}, {0,1,0,-1}};
        while(!q.empty()) {
            int sz = q.size();
            second_count += sz;
            while(sz--) {
                int r = q.front().first, c = q.front().second;
                q.pop();
                for(int k = 0; k < 4; k++) {
                    int r2 = r + dir[0][k], c2 = c + dir[1][k];
                    if(r2 < 0 || r2 >= M || c2 < 0 || c2 >= N || grid[r2][c2] != 1)  continue;
                    grid[r2][c2] = 2;
                    q.push({r2, c2});
                }
            }
            if(!q.empty())  total_mins++;
        }
        
        return count != second_count ? -1 : total_mins;
    }
};