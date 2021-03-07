class Solution {
public:
    void setZeroes(vector<vector<int>>& A) {
        int M = A.size();
        int N = A[0].size();
        vector<pair<int,int>> indices;
        for(int i=0; i < M; i++)
        {
            for(int j=0; j < N; j++)
            {
                if(A[i][j] == 0)
                    indices.push_back(make_pair(i,j));
            }
        }
        for(auto index : indices) {
            for(int j = 0; j < N; j++) {
                A[index.first][j] = 0;
            }
            for(int i = 0; i < M; i++) {
                A[i][index.second] = 0;
            }
        }
    }
};