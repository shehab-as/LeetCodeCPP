// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int low = 1, high = n;
        while (low <= high) {
            int m = low + (high-low)/2;
            if(isBadVersion(m)) {
                high = m - 1;
            }
            else low = m + 1;
        }
        return low;
    }
};