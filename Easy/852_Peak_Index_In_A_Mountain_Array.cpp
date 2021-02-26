class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int low = 0, high = A.size() - 1;
        while( low <= high ) {
            int m = low + (high - low)/2;
            if(A[m] < A[m + 1])
                low = m + 1;
            else
                high = m - 1;
        }
        return low;
    }
};