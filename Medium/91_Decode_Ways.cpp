class Solution {
public:
    int numDecodings(string s) {
        vector<int> dp(s.size() + 1);
        dp[0] = 1;
        dp[1] = s[0] == '0' ? 0 : 1;
        for(int i = 2; i <= s.size(); i++) {
            int way1 = 0, way2 = 0;
            string num_str = s.substr(i-2, 2);
            if(s[i-1] != '0') 
                way1 = dp[i-1];
            if(stoi(num_str) <= 26 && stoi(num_str) > 0 && s[i-2] != '0')
                way2 = dp[i-2];
            
            dp[i] = way1 + way2;
        }
        return dp[s.size()];
    }
};
