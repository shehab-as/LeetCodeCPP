class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        if(mat.empty() || mat[0].empty())   
            return 0;
        int sum = 0;
        int M = mat.size();
        int N = mat[0].size();
        for(int i = 0, j = 0; i < M && j < N; i++, j++) {
            sum += mat[i][j];
        }
        for(int i = 0, j = N-1; i < M && j >= 0; i++, j--) {
            sum += (i != j) ? mat[i][j] : 0;
        }
        return sum;
    }
};