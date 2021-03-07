class Solution {
public:
    void rotate(vector<vector<int>>& M) {
        int N = M.size();
        int layers = N/2;
        for(int layer=0; layer < layers; layer++) {
            int first = layer;
            int last = N - 1 - layer;
            for(int i = first; i < last; i++) {
                int offset = i - first;
                int top = M[first][i];
                M[first][i] = M[last-offset][first];
                M[last-offset][first] = M[last][last-offset];
                M[last][last-offset] = M[i][last];
                M[i][last] = top;
            }
        }
    }
};