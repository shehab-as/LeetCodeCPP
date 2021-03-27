class Solution {
public:    
    int countSubstrings(string s) {
        int N = s.length();
        int count = 0;
        int dp[N][N];
        
        memset(dp, 0, sizeof(dp));
        
        for(int i = 0; i < N; i++) {
            dp[i][i] = 1;
            count++;
        }
        
        for(int right = 1; right < N; right++) {
            for(int left = 0; left < right; left++) {
                if(s[left] == s[right] && (left+1 == right || dp[left+1][right-1])) {
                    dp[left][right] = 1;
                    count++;
                }
            }
        }
        return count;
    }
};
