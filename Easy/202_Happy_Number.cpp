class Solution {
public:
    bool isHappy(int n) {
        int iterations = 0;
        int curr = 0;
        while(iterations < 10) {
            while(n > 0) {
                int d = n % 10;
                n /= 10;
                curr += (d*d);
            }
            if(curr == 1)   return true;
            n = curr;
            curr = 0;
            iterations++;
        }
        return false;
    }
};