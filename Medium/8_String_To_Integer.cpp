class Solution {
public:
    int myAtoi(string A) {
        if(A.empty())   return 0;
        long long result = 0;
        int start = 0;
        int sign = 1;
        while(start + 1 < A.length() && isspace(A[start])) { start++; }
        if(A[start] == '-' || A[start] == '+') {
            sign = 44 - A[start++];
        }
        for(int i = start; i < A.length(); i++) {
            if(!isdigit(A[i])) { break; }
            result = (result * 10) + (A[i] - '0');
            if(result > INT_MAX) {
                return sign == -1 ? INT_MIN : INT_MAX;
            }
        }
        return result * sign;
    }
};