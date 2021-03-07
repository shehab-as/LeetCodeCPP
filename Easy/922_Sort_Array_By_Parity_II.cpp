class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        vector<int> res(A.size());
        int i_e = 0;
        int i_o = 1;
        for(int i=0; i<A.size(); i++) {
            if(A[i] % 2 == 0) {
                res[i_e] = A[i];
                i_e += 2;
            }
            else {
                res[i_o] = A[i];
                i_o += 2;
            }
        }
        return res;
        
    }
};