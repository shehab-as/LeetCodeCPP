class Solution {
public:
    int singleNonDuplicate(vector<int>& A) {
        int low = 0, high = A.size() - 1;
        while( low < high ) {
            int mid = low + (high - low) / 2;
            if( mid % 2 == 0 ) {
                if(A[mid] == A[mid+1])
                    low = mid + 1;
                else
                    high = mid;
            }
            else {  // mid % 2 != 0
                if(A[mid] == A[mid-1])
                    low = mid + 1;
                else 
                    high = mid;
            }
        }
        return A[low];
    }
};
