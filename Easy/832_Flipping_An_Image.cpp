class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        for(vector<int>& row : A) {
            reverse(row.begin(), row.end());
            for(int i = 0; i < row.size(); i++) {
                row[i] = row[i] ? 0 : 1;
            }
        }
        return A;
    }
};