class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        vector<string> result;
        string query = first + " " + second + " ";
        for(int pos = 0; ; pos++) {
            pos = text.find(query, pos);
            if(pos == string::npos) break;
            auto p1 = pos + query.size();
            if(p1 == text.size())   break;
            result.push_back(text.substr(p1, text.find(' ', p1) - p1));
        }
        return result;
    }
};