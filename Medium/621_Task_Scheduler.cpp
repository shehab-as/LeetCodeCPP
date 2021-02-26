class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int char_map[26] = {0};
        for(char c : tasks) char_map[c-'A']++;
        sort(begin(char_map), end(char_map));
        
        int max_val = char_map[25] - 1;
        int idle_slots = max_val * n;
        
        for(int i = 24; i >= 0; i--)
            idle_slots -= min(char_map[i], max_val);
        
        return idle_slots > 0 ? idle_slots + tasks.size() : tasks.size();
        
    }
};