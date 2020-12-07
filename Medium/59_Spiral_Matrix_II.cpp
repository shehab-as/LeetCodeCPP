class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> Matrix(n, vector<int>(n, 0));
        int k = 1;
        int top_i = 0, left_i = 0;
        int right_i = n - 1, bottom_i = n - 1;
        
        while(top_i <= bottom_i || left_i <= right_i) {
            // left -> right
            for(int i = left_i; i <= right_i; i++)
                Matrix[top_i][i] = k++;
            top_i++;
            // top -> bottom
            for(int j = top_i; j <= bottom_i; j++)
                Matrix[j][right_i] = k++;
            right_i--;
            // right -> left
            for(int i = right_i; i >= left_i; i--)
                Matrix[bottom_i][i] = k++;
            bottom_i--;
            // bottom -> top
            for(int j = bottom_i; j >= top_i; j--)
                Matrix[j][left_i] = k++;
            left_i++;
        }
        return Matrix;
        
    }
};