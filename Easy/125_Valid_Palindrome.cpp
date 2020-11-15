class Solution {
public:
    bool isPalindrome(string s) {
        if(s.empty())   return true;
        string compressed = "";
        for(char& c : s) {
            if(isalnum(c))
                compressed += tolower(c);
        }
        for(int i = 0, j = compressed.length() - 1; i < j; i++, j--) {
            if(compressed[i] != compressed[j])
                return false;
        }
        return true;
    }
};