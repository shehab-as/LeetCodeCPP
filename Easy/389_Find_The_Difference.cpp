class Solution {
public:
    char findTheDifference(string s, string t) {
        int checkers[26] = {0};
        char added_char = ' ';
        for(int i=0; i<s.length(); i++)
            checkers[s[i] - 'a']++;
        for(int j=0; j<t.length(); j++) {
            if(!checkers[t[j] - 'a']) {
                added_char = t[j];
                break;
            }
            else
                checkers[t[j] - 'a']--;
        }
        return added_char;
    }
};