class Solution {
public:
    int hammingDistance(int x, int y) {
        int count = 0;
        while (x || y) {
            int b_x = x & 1;
            int b_y = y & 1;
            if(b_x != b_y)  count++;
            x >>= 1;
            y >>= 1;
        }
        return count;
    }
};