class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int T) {
        int n = clips.size();
        vector<int> dp (n+1, -1);
        dp[0] = 0;
        for(int i = 1; i <= n; i++) {
            dp[i] = dp[i-1];
            for(int j = 0; j < n; j++) {
                int start_time = clips[j][0], end_time = clips[j][1];
                if(start_time <= dp[i-1])
                    dp[i] = max(dp[i], end_time);
            }
        }
        
        for(int k = 1; k <= n; k++)
            if(dp[k] >= T) return k;
        return -1;
    }
};