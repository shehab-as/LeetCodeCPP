class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.empty())  {
            return 0;
        }
        int M = matrix.size();
        int N = matrix[0].size();
        // vector<vector<int>> DP (M+1, vector<int>(N+1, 0)); 
        int DP[M+1][N+1];
        for(int i = 0; i < M; i++)  DP[i][0] = 0;
        for(int j = 0; j < N; j++)  DP[0][j] = 0;
        int max_entry = 0;
        for(int i = 0; i < M; i++) {
            for(int j = 0; j < N; j++) {
                if(matrix[i][j] != '0')
                    DP[i+1][j+1] = min(DP[i][j], min(DP[i+1][j], DP[i][j+1])) + 1;
                else
                    DP[i+1][j+1] = 0;
                max_entry = max(max_entry, DP[i+1][j+1]);
            }
        }
        return max_entry * max_entry;
    }
};