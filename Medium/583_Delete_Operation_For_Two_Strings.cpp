class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> DP(word1.size() + 1, vector<int>(word2.size() + 1, 0));
        for(int i = word1.size(); i>= 0; i--) {
            for(int j = word2.size(); j>= 0; j--) {
                if ( i < word1.size() || j < word2.size()) {
                    DP[i][j]=(i < word1.size() && j < word2.size() && word1[i] == word2[j])?
                        DP[i+1][j+1] : 1 + min( (i<word1.size() ? DP[i+1][j] : INT_MAX), 
                                              (j<word2.size() ? DP[i][j+1] : INT_MAX));
                }
            }
        }
        return DP[0][0];
    }
};
