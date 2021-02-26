class Solution {
public:
    string reverseWords(string s) {
        if(s.empty()) {
            return "";
        }
        string result = "";
        istringstream iss(s);
        string word;
        while(getline(iss, word, ' ')) {
            reverse(word.begin(), word.end());
            result += word + " ";
        }
        result.pop_back();
        return result;
    }
};