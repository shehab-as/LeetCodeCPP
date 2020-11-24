class Solution {
public:
    int uniquePaths(int m, int n) {
        // vector<vector<int>> DP( m, vector<int>( n, 0) );
        vector<int> DP (m * n, 0);
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if( i == 0 || j == 0 )
                    DP[(j * m) + i] = 1;
                else
                    DP[(j * m) + i] = DP[((j-1) * m) + i] + DP[(j * m) + (i - 1)];
            }
        }
        return DP[(m * n) - 1];
    }
};
