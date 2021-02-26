class Solution {
public:

    int findMaxForm(vector<string>& strs, int m, int n) {
        int memo[m+1][n+1];
        memset(memo, 0, sizeof(memo));
        int numZeroes, numOnes;
        for(string& s : strs) {
            numZeroes = 0;
            numOnes = 0;
            for(char c : s)
                c == '1' ? numOnes++ : numZeroes++;
            
            for(int i = m; i >= numZeroes; i--) {
                for(int j = n; j >= numOnes; j--) {
                    memo[i][j] = max(memo[i][j], memo[i - numZeroes][j - numOnes] + 1);
                }
            }
        }
        return memo[m][n];
    }
};