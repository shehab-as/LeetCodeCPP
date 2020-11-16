class Solution {
public:
    string reverseStr(string s, int k) {
        if(s.empty())
            return "";
        if(s.length() <= k) {
            reverse(s.begin(), s.end());
            return s;
        }
        for(int left = 0; left < s.length(); left+=2*k) {
            for(int i = left, j = min(left + k - 1, (int) s.length() - 1); i < j; i++, j--)
                swap(s[i], s[j]);
        }
        return s;
    }
};