class Solution {
public:
    vector<int> grayCode(int n) {
        if(n == 0)  return {0};
        vector<int> result;
        int total_size = pow(2, n);
        for(int i = 0; i < total_size; i++) {
            int number = (i >> 1) ^ i;
            result.push_back(number);
        }
        return result;
    }
};
