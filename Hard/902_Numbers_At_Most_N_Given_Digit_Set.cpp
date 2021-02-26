class Solution {
public:
    // "1", "3", "5", "7",      D_SIZE = 4
    // 100                      N_SIZE = 3
    // 4^1 + 4^2 + 4^3
    int atMostNGivenDigitSet(vector<string>& D, int N) {
        string N_string = to_string(N);
        int N_len = N_string.length();
        int d_size = D.size();
        int count = 0;
        
        for(int i = 1; i < N_len; i++) {
            count += pow(d_size, i);
        }
        
        for(int i = 0; i < N_len; i++) {
            bool sameNum = false;
            for(string& d : D) {
                if(d[0] < N_string[i])
                    count += pow(d_size, N_len - i - 1);
                else if(d[0] == N_string[i])
                    sameNum = true;
            }
            if(!sameNum)    return count;
        }
        return count + 1;
    }
};