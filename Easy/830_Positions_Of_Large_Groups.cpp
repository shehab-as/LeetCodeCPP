class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        if(s.empty()) {
            return {};
        }
        int len = s.length();
        vector<vector<int>> result;
        int start = 0;
        char c = s[0];
        for(int i = 1; i < len; i++) {
            if(s[i] != c) {
                if(i - start >= 3) {
                    result.push_back({start, i-1});
                }
                start = i;
                c = s[i];
            }
        }
        if(len - start >= 3) {
            result.push_back({start, len - 1});
        }
        return result;
    }
};