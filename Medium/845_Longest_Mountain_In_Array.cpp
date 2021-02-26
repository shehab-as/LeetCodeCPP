class Solution {
public:
    int longestMountain(vector<int>& A) {
        if(A.size() < 3) {
            return 0;
        }
        int len = 0;
        int N = A.size();
        for(int i = 1; i < N - 1; i++) {
            if(A[i] > A[i-1] && A[i] > A[i+1]) {
                int start = i - 1, end = i + 1;
                while(start >= 1 && A[start] > A[start-1])
                    start--;
                while(end < (N - 1) && A[end] > A[end+1])
                    end++;
                len = max(len, end - start + 1);
            }
        }
        return len;
    }
};