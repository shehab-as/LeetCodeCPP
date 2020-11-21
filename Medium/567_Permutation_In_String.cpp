class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> s1_hmp (26, 0);
        vector<int> s2_hmp (26, 0);
        int window_size = s1.length();
        if(s2.length() < window_size)   {
            return false;
        }
        for(int i = 0; i < s2.length() && i < window_size; i++) {
            s1_hmp[s1[i] - 'a']++;
            s2_hmp[s2[i] - 'a']++;
        }
        for(int i = window_size; i < s2.length(); i++) {
            if(s1_hmp == s2_hmp) {
                return true;
            }
            s2_hmp[s2[i-window_size] - 'a']--;
            s2_hmp[s2[i] - 'a']++;
        }
        return s1_hmp == s2_hmp;
    }
};