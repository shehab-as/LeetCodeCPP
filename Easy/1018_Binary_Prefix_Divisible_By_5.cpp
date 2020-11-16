class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) {
        vector<bool> result(A.size(), false);
        int decimal = 0;
        for(int i = 0; i < A.size(); i++) {
            decimal = ((decimal << 1) + A[i]) % 10;
            result[i] = (decimal % 5 == 0) ? true : false;
        }
        return result;
        
    }
};