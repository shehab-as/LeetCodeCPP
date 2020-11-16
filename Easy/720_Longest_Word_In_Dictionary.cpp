class Solution {
public:
    string longestWord(vector<string>& words) {
        if(words.empty())   return "";
        sort(words.begin(), words.end());
        unordered_set<string> built_words;
        string result;
        for(string& word : words) {
            if(word.size() == 1 || built_words.count(word.substr(0, word.length()-1))) {
                result = (word.length() > result.length()) ? word : result;
                built_words.insert(word);
            }
        }
        return result;
    }
};