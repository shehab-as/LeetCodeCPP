class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int bit_Index = 0;
        while(m != n) {
            m >>= 1;
            n >>= 1;
            bit_Index++;
        }
        
        return m << bit_Index; 
    }
};