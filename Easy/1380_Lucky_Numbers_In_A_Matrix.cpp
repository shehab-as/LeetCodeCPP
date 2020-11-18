class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        if(matrix.empty() || matrix[0].empty()) return {};
        int M = matrix.size(), N = matrix[0].size();
        vector<int> Min_Row, Max_Col;
        for(int i = 0; i < M; i++) {
            int curr_min = INT_MAX;
            for(int j = 0; j < N; j++) {
                curr_min = min(curr_min, matrix[i][j]);
            }
            Min_Row.push_back(curr_min);
        }
        for(int i = 0; i < N; i++) {
            int curr_max = INT_MIN;
            for(int j = 0; j < M; j++) {
                curr_max = max(curr_max, matrix[j][i]);
            }
            Max_Col.push_back(curr_max);
        }
        
        vector<int> result;
        for(int i = 0; i < M; i++) {
            for(int j = 0; j < N; j++) {
                int element = matrix[i][j];
                int min_row_element = Min_Row[i];
                int max_col_element = Max_Col[j];
                if(element == min_row_element && element == max_col_element)
                    result.push_back(element);
            }
        }
        return result;
        
    }
};