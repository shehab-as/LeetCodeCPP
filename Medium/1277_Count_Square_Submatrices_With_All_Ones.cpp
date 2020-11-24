class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int M = matrix.size(), N = matrix[0].size();
        int result = 0;
        for(int i = 0; i < M; i++) {
            for(int j = 0; j < N; j++) {
                if(i && j && matrix[i][j]) {
                    matrix[i][j] = min(matrix[i-1][j-1], min(matrix[i-1][j], matrix[i][j-1])) + 1;
                }
                result += matrix[i][j];
            }
        }
        return result;
    }
};