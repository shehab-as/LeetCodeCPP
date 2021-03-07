class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> hashset;
        for(string& word : wordDict)
            hashset.insert(word);
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        for(int i = 1; i <= s.size(); i++) {
            for(int j = i - 1; j >= 0; j--) {
                if(dp[j]) {
                    string word = s.substr(j, i-j);
                    if(hashset.find(word) != hashset.end()) {
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        return dp[s.size()];
    }
};
