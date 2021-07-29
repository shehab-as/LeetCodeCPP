class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        if(mat.empty() || mat[0].empty()) { return {}; }
        const int M = mat.size(), N = mat[0].size();
        int dirs[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
        vector<vector<int>> result(M, vector<int>(N, -1));
        queue<pair<int,int>> Q;
        for(int r = 0; r < M; r++) {
            for(int c = 0; c < N; c++) {
                if(mat[r][c] == 0) {
                    result[r][c] = 0;
                    Q.push({r,c});
                }
            }
        }
        while(!Q.empty()) {
            auto pos = Q.front();
            Q.pop();
            for(auto dir : dirs) {
                int neighbor_r = pos.first + dir[0], neighbor_c = pos.second + dir[1];
                if(neighbor_r >= 0 && neighbor_r < M && neighbor_c >= 0 && neighbor_c < N 
                   && result[neighbor_r][neighbor_c] == -1) {
                    result[neighbor_r][neighbor_c] = result[pos.first][pos.second] + 1;
                    Q.push({neighbor_r, neighbor_c});
                }
            }
        }
        return result;
    }
};