class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int window_size = p.length();
        int end = 0;
        vector<int> s_table(26, 0);
        vector<int> p_table(26, 0);
        vector<int> result_indices;
        for(char& c : p)        // build table for p
            p_table[c - 'a']++;
        while (end < s.length() && end < window_size) {     // initial table for window
            s_table[s[end] - 'a']++;
            end++;
        }
        for(int i = end; i < s.length(); i++) {
            if(s_table == p_table) {
                result_indices.push_back(i - window_size);
            }
            s_table[s[i - window_size] - 'a']--;
            s_table[s[i] - 'a']++;
        }
        if(s_table == p_table) {
            result_indices.push_back(s.length() - window_size);
        }
        return result_indices;
    }
};