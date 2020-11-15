class Solution {
public:
    bool is_vowel(char c) {
        c = tolower(c);
        return c == 'a' || c == 'e' || c == 'o' || c == 'i' || c == 'u';
    }
    string reverseVowels(string s) {
        int start = 0, end = s.length() - 1;
        while(start < end) {
            while(start < end && !is_vowel(s[start])) 
                start++;
            while(start < end && !is_vowel(s[end]))    
                end--;
            swap(s[start++], s[end--]);
        }
        return s;
    }
};