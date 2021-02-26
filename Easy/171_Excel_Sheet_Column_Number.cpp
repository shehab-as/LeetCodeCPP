class Solution {
public:
    int titleToNumber(string s) {
        int len = s.length();
        int Number = 0;
        for(int i = 0; i < s.length(); i++) {
            Number += (s[i] - 'A' + 1) * pow(26, len - i - 1);
        }
        return Number;
    }
};