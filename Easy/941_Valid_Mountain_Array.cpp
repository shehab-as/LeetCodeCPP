class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        if(A.size() < 3) {
            return false;
        }
        int N = A.size();
        int peak = -1, peak_index = 0;
        for(int i = 0; i < N; i++) {
            if(A[i] > peak) {
                peak = A[i];
                peak_index = i;
            }
        }
        for(int j = 0; j < peak_index - 1; j++) {
            if(A[j] >= A[j+1])  return false;
        }
        for(int j = peak_index; j < N - 1; j++) {
            if(A[j] <= A[j+1])  return false;
        }
        return A[0] < peak && peak > A[N-1];
    }
};