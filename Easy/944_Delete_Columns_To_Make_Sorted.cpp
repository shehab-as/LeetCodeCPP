class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        if(A.empty())   return 0;
        int result = 0;
        int N = A[0].length();
        for(int c = 0; c < N; c++) {
            for(int i = 0; i < A.size() - 1; i++) {
                if(A[i][c] > A[i+1][c]) {
                    result++;
                    break;
                }
            }
        }
        return result;
    }
};