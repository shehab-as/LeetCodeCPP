class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> T;
        for(int i = 1; i <= numRows; i++) {
            vector<int> row;
            for(int j = 0; j < i; j++)
                row.push_back(1);
            T.push_back(row);
        }
        for(int i = 2; i < numRows; i++) {
            for(int j = 1; j < i; j++)
                T[i][j] = T[i-1][j-1] + T[i-1][j];
        }
        return T;
    }
};