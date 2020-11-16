class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(t.length() < s.length()) return false;
        int idx_s = 0;
        int idx_t = 0;
        while(idx_s < s.length() && idx_t < t.length()) {
            if(s[idx_s] == t[idx_t])
                idx_s++;
            idx_t++;
        }
        return idx_s == s.length();
    }
};