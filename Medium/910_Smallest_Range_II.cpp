class Solution {
public:
    int smallestRangeII(vector<int>& A, int K) {
        sort(A.begin(), A.end());
        int N = (int) A.size();
        int res = A[N - 1] - A[0];
        int left = A[0] + K, right = A[N - 1] - K;
        for(int i = 0; i < N - 1; i++) {
            int maxi = max(A[i] + K, right);
            int mini = min(left, A[i + 1] - K);
            res = min(res, maxi - mini);
        }
        return res;
    }
};