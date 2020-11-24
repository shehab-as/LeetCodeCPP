class Solution {
public:
    bool IsVowel(const char& c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    int maxVowels(string s, int k) {
        int window;
        int curr_vowels = 0;
        int max_vowels = 0;
        for(window = 0; window < k; window++) {
            if(IsVowel(s[window]))
                curr_vowels++;
        }
        for(int i = window; i < s.length(); i++) {
            max_vowels = max(max_vowels, curr_vowels);
            curr_vowels -= IsVowel(s[i-window]) ? 1 : 0;
            curr_vowels += IsVowel(s[i]) ? 1 : 0;
        }
        return max(max_vowels, curr_vowels);
    }
};