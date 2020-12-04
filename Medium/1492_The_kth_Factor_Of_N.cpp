class Solution {
public:
    int kthFactor(int n, int k) {
        if( k > n ) return -1;
        int kthfactor = -1;
        for(int i = 1; i <= n && k; i++) {
            if(n % i == 0) {
                kthfactor = i;
                k--;
            }
        }
        return k == 0 ? kthfactor : -1;
    }
};