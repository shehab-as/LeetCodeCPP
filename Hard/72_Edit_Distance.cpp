class Solution {
public:
    int minDistance(string word1, string word2) {
        int M = word1.length(), N = word2.length();
        int DP[M+1][N+1];
        for(int i = 0; i <= M; i++)
            for(int j = 0; j <= N; j++)
                DP[i][j] = 0;
        
        for(int i = 0; i <= M; i++) {
            for(int j = 0; j <= N; j++) {
                if(i == 0)
                    DP[i][j] = j;
                else if(j == 0)
                    DP[i][j] = i;
                else 
                    DP[i][j] = (word1[i-1] == word2[j-1]) ? DP[i-1][j-1] :
                    min(min(DP[i-1][j], DP[i][j-1]), DP[i-1][j-1]) + 1;
            }
        }
        return DP[M][N];
    }
};