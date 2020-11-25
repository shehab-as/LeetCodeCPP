class Solution {
public:
    int smallestRepunitDivByK(int K) {
        if(K % 2 == 0 || K % 5 == 0)
            return -1;
        int N = 0;
        int len = 0;
        for(len = 1; len <= K; len++) {
            N = ((N * 10) + 1) % K;
            if(N % K == 0)    return len;
        }
        return -1;
    }
};
