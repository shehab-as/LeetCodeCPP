class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        for(int i = A.size() - 1; i >= 0 && K > 0; i--) {
            A[i] += K;
            K = A[i] / 10;
            A[i] %= 10;
        }
        
        for(; K > 0; K /= 10)
            A.insert(A.begin(), K % 10);
        
        return A;
    }
};