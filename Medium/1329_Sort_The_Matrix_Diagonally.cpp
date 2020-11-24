class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int M = mat.size();
        int N = mat[0].size();
        for(int k = 0; k < M - 1; k++) {
            for(int i = 0; i < M - 1; i++) {
                for(int j = 0; j < N - 1; j++) {
                    if(mat[i][j] > mat[i+1][j+1])
                        swap(mat[i][j], mat[i+1][j+1]);
                }
            }
        }
        return mat;
    }
};

// class Solution {
// public:
//     vector<vector<int>> diagonalSort(vector<vector<int>>& mat) 
//     {
//         for(int k = 0; k + 1 < mat.size(); k++)
//              for(int i = 0; i + 1 < mat.size(); i++)
//                 for(int j = 0; j + 1 < mat[i].size(); j++)
//                     if(mat[i][j] > mat[i + 1][j + 1])
//                         swap(mat[i][j], mat[i + 1][j + 1]);   
//         return mat;
//     }
// };