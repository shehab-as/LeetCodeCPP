class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> Rows;
        for(int r = 0; r <= rowIndex; r++) {
            vector<int> row(r+1, 1);
            Rows.push_back(row);
        }
        for(int r = 2; r <= rowIndex; r++) {
            for(int c = 1; c < Rows[r].size() - 1; c++)
                Rows[r][c] = Rows[r-1][c-1] + Rows[r-1][c];
        }
        return Rows[rowIndex];
    }
};