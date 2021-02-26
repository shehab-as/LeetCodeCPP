class Solution {
public:
    bool checkValidString(string s) {
       int max_diff = 0, min_diff = 0;
        for(char& c : s) {
            max_diff += (c == '(' || c == '*') ? 1 : -1;
            min_diff += (c == ')' || c == '*') ? -1 : 1;
            min_diff = max(0, min_diff);
            if(max_diff < 0)    return false;
        }
        return min_diff == 0;
    }
};