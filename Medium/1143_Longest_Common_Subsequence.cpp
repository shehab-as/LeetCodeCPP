class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int N1 = (int) text1.length();
        int N2 = (int) text2.length();
        vector<vector<int>> DP(N1 + 1, vector<int>(N2 + 1, 0));
        
        for(int i = 0; i <= N1; i++) {
            for(int j = 0; j <= N2; j++) {
                if( i == 0 || j == 0 )
                    DP[i][j] = 0;
                else if(text1[i-1] == text2[j-1])
                    DP[i][j] = DP[i-1][j-1] + 1;
                else 
                    DP[i][j] = max(DP[i-1][j], DP[i][j-1]);
            }
        }
        return DP[N1][N2];
    }
};