class Solution {
public:
    bool detectCapitalUse(string word) {
        int count_uppers = 0;
        for(char& c : word) {
            if(isupper(c))  count_uppers++;
        }
        return (count_uppers == 0) || 
            (count_uppers == word.length()) || 
            (count_uppers == 1 && isupper(word[0]));
    }
};