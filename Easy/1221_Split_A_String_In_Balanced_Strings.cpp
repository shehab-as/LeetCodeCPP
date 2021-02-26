class Solution {
public:
    int balancedStringSplit(string s) {
        int R = 0, L = 0, result = 0;
        for(char& c : s) {
            if(c == 'R')    R++;
            if(c == 'L')    L++;
            if ( R == L )   result++;
        }
        return result;
    }
};