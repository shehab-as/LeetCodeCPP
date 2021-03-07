class Solution {
public:
    bool judgeSquareSum(int c) {
        int a, b;
        for(b=0; b<=sqrt(c); b++)
        {
            a = sqrt(c - (b*b));
            if((a*a + b*b) == c)
                return true;
        }
        return false;
    }
};