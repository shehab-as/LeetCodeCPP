class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hashmap;
        for(int i = 0; i < strs.size(); i++) {
            string copy = strs[i];
            sort(copy.begin(), copy.end());
            hashmap[copy].push_back(strs[i]);
        }
        vector<vector<string>> groups;
        for(auto it : hashmap) 
            groups.push_back(it.second);
        return groups;
    }
};