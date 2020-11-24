class Solution {
public:
    string arrangeWords(string text) {
        if(text.empty()) {
            return "";
        }
        istringstream iss(text);
        string word;
        vector<pair<int, string>> word_pairs;
        while(getline(iss, word, ' ')) {
            transform(word.begin(), word.end(), word.begin(), [](unsigned char c){ return tolower(c); });
            word_pairs.push_back({word.length(), word});
        }
        stable_sort(word_pairs.begin(), word_pairs.end(), [](const pair<int, string>& p1, const pair<int, string>& p2) {
            return p1.first < p2.first;
        });
        string result = "";
        for(auto word_p : word_pairs) {
            result += word_p.second + " ";
        }
        result.pop_back();
        result[0] = toupper(result[0]);
        return result;
    }
};