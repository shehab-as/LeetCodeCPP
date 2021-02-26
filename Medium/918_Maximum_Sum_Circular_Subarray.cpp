class Solution {
public:
    int Kadane(vector<int>& A) {
        int max_so_far = A[0], max_ending_here = A[0];
        for(int i = 1; i < A.size(); i++) {
            max_ending_here = max(A[i], max_ending_here + A[i]);
            max_so_far = max(max_so_far, max_ending_here);
        }
        return max_so_far;
    }
    int maxSubarraySumCircular(vector<int>& A) {
        bool all_negatives = true;
        for(int e : A) {
            if(e > 0 ) {
                all_negatives = false;
                break;
            }
        }
        int max_kadane = Kadane(A);         // case 1.
        if(all_negatives)   return max_kadane;
        int max_wrap = 0;
        for(int i = 0; i < A.size(); i++) {
            max_wrap += A[i];
            A[i] = -A[i];
        }
        max_wrap += Kadane(A);     // case 2.
        return max(max_kadane, max_wrap);
    }
};

