class Solution {
public:
    string reverseWords(string s) {
        istringstream iss(s);
        string word;
        vector<string> words;
        while(iss >> word) {
            words.push_back(word);
        }
        if(words.empty())   return "";
        reverse(words.begin(), words.end());
        string result = "";
        for(auto word : words)
            result += word + " ";
        result.pop_back();
        return result;
    }
};