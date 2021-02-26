class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length())    return false;
        int checkers[26] = {0};
        for(int i = 0; i < s.length(); i++) {
            checkers[s[i] - 'a']++;
            checkers[t[i] - 'a']--;
        }
        for(int &j : checkers) {
            if(j != 0)
                return false;
        }
        return true;
    }
};