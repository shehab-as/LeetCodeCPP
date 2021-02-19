class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        if(mat.empty() || mat[0].empty()) {
            return 0;
        }
        int M = mat.size(), N = mat[0].size();
        vector<pair<int,int>> ones;
        for(int r = 0; r < M; r++) {
            for(int c = 0; c < N; c++) {
                if(mat[r][c] == 1) {
                    ones.push_back({r, c});
                }
            }
        }
        int specials = 0;
        // check for validity.
        for(auto p : ones) {
            bool valid = true;
            int row = p.first, col = p.second;
            for(int r = 0; r < M; r++) {
                if( r == row )  continue;
                if( !valid )    break;
                if( mat[r][col] == 1) {
                    valid = false;
                }
            }
            for(int c = 0; c < N; c++) {
                if( c == col )  continue;
                if( !valid )    break;
                if( mat[row][c] == 1) {
                    valid = false;
                }
            }
            specials += valid ? 1 : 0;
        }
        return specials;
    }
};