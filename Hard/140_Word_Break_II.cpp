class Solution {
private:
    unordered_set<string> wordSet;
public:
    void genSentence(vector<string>& res, const vector<int>& dp, const string& s, int pos, string curr_s) {
        for(int i = pos + 1; i < dp.size(); i++) {
            if(dp[i]) {
                string new_word = s.substr(pos, i - pos);
                if(wordSet.count(new_word)) {
                    if(i + 1 == dp.size()) {
                        res.push_back(curr_s + new_word);
                        return;
                    }
                    genSentence(res, dp, s, i, curr_s + new_word + " ");
                }
            }
        }
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        copy(wordDict.begin(), wordDict.end(), inserter(wordSet, wordSet.end()));
        int N = s.size();
        vector<int> dp(N+1, 0);
        dp[0] = 1;

        for(int i = 1; i <= N; i++) {
            for(int j = i - 1; j >= 0; j--) {
                if(dp[j]) {
                    string word = s.substr(j, i-j);
                    if(wordSet.count(word)) {
                        dp[i] = 1;
                        break;
                    }
                }
            }
        }

        vector<string> res;
        if(dp[N])
            genSentence(res, dp, s, 0, "");
        return res;
    }
};