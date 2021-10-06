class Solution {
public:
    bool areOccurrencesEqual(string s) {
        vector<int> charCount(26, 0);
        int common_count = 0;
        for(char& c : s) {
            int key = c - 'a';
            charCount[key]++;
            common_count = charCount[key];
        }
        for(int i = 0; i < 26; i++) {
            if(charCount[i] == 0)   
                continue;
            if(charCount[i] != common_count)
                return false;
        }
        return true;
    }
};