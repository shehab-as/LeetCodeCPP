class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size(), cols = matrix[0].size();
        int r = rows - 1;
        int c = 0;
        while(r >= 0 && c < cols) {
            if(target == matrix[r][c])  return true;
            if(target < matrix[r][c])   r--;
            else
                c++;
        }
        return false;
    }
};