class Solution {
public:
    bool isPowerOfThree(int n) {
        int i = 0;
        long long x = pow(3.0, i);
        while(x<=n)
        {
            if(n == x)
                return true;
            i++;
            x = pow(3.0, i);
        }
        return false;
    }
};