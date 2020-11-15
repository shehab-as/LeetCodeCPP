class Solution {
public:
    int arrangeCoins(int n) {
        int count = 0;
        int step = 1;
        while(true) {
            if(n < step)    break;
            n -= step;
            step++;
            count++;
        }
        return count;
    }
};