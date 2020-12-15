class Solution {
public:
    void DFS(string& s, vector<vector<string>>& result, vector<string> path, int index, vector<vector<bool>>& DP) {
        if(index == s.length()) {
            result.push_back(path);
            return;
        }
        for(int i = index; i < s.length(); i++) {
             // abca --> a == a 
            if(s[index] != s[i])    continue;  
            // abca  --> b != c 
            if(i - 1 > index + 1 && !DP[index + 1][i - 1])  continue; 
            DP[index][i] = true;
            path.push_back(s.substr(index, i - index + 1));
            DFS(s, result, path, i + 1, DP);
            path.pop_back();
        }
    }
    
    vector<vector<string>> partition(string s) {
        if(s.empty()) {
            return {};
        }
        vector<vector<bool>> DP (s.length(), vector<bool>(s.length(), false));
        vector<vector<string>> result;
        DFS(s, result, {}, 0, DP);
        return result;
    }
};