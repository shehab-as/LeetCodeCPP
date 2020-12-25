class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        if(matrix.empty() || matrix[0].empty()) return {};
        int M = matrix.size();
        int N = matrix[0].size();
        vector<int> result (M * N);
        int row = 0, col = 0;
        for(int pos = 0; pos < M * N; pos++) {
            result[pos] = matrix[row][col];
            // upwards.
            if((row + col) % 2 == 0) {
                if(col == N - 1)    row++;
                else if(row == 0)   col++;
                else {
                    row--;
                    col++;
                }
            }
            else {
                if(row == M - 1)    col++;
                else if(col == 0)   row++;
                else {
                    row++;
                    col--;
                }
            }
        }
        return result;
    }
};