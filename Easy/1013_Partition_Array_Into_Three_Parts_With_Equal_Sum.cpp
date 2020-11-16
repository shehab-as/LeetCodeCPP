class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        int total = accumulate(A.begin(), A.end(), 0);
        if(total % 3 != 0)    return false;
        int segments = 0;
        for(int i = 0, sum = 0; i < A.size() && segments < 2; i++) {
            sum += A[i];
            if(sum == (total / 3)) {
                sum = 0;
                segments++;
            }
        }
        return segments == 2;
    }
};