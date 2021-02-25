/*    O(M + N) Time Complexity     */
class Solution {
public:

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty()) return false;
        int M = matrix.size(), N = matrix[0].size();
        int i = 0, j = N - 1;
        while( i < M && j >= 0 ) {
            if(target == matrix[i][j])  return true; 
            if(target > matrix[i][j])
                i++;
            else
                j--;
        }
        return false;
    }
};


/*      O(M * LogN) Time Complexity     */

class Solution {
public:
    bool IsFoundInRow(vector<int>& row, int target) {
        int start = 0, end = row.size() - 1;
        while(start <= end) {
            int m = start + (end - start) / 2;
            if(row[m] == target)    return true;
            if(target > row[m])
                start = m + 1;
            else 
                end = m - 1;
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(vector<int>& row : matrix) {
            if(IsFoundInRow(row, target))   return true;
        }
        return false;
    }
};