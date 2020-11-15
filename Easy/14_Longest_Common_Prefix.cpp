class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string common = "";
        if(strs.empty())
            return "";
        for(int i = 0; i < strs[0].size(); i++) {
            char c = strs[0][i];
            for(int j = 1; j < strs.size(); j++) {
                if(i >= strs[j].size())
                    return common;
                char another_c = strs[j][i];
                if(another_c != c)
                    return common;
            }
            common += c;
        }
        return common;
    }
};