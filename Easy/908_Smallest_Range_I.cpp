class Solution {
public:
    int smallestRangeI(vector<int>& A, int K) {
        int low = A[0];
        int high = A[0];
        for(int i=1; i<A.size(); i++)
        {
            low = min(A[i], low);
            high = max(A[i], high);
        }
        return max(0, high - low - 2*K);
    }
};