class Solution {
public:
    string minWindow(string s, string t) {
        if(!s.length() || !t.length())
            return "";
        vector<int> map_t(256, 0);
        int required = t.length();
        int formed = 0;
        int left = 0, right = 0, window_start = 0, window_size = INT_MAX;
        
        for(char c : t)
            map_t[c]++;
        
        while(right < s.length()) {
            if(map_t[s[right]] > 0) 
                formed++;
    
            map_t[s[right]]--;
            right++;
            while(formed == required) {
                if(right - left < window_size) {
                    window_start = left;
                    window_size = right - left;
                }
                if(map_t[s[left]] == 0)
                    formed--;
                map_t[s[left]]++;
                left++;
            }
            
        }
        return window_size == INT_MAX ? "" : s.substr(window_start, window_size);
    }
};
