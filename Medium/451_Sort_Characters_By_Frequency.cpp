class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> hmp;
        for(char& c : s)
            hmp[c]++;
        vector<pair<int,char>> vs;
        for(auto it : hmp) {
            vs.push_back(make_pair(it.second, it.first));
        }
        
        sort(vs.begin(), vs.end(), [](const pair<int,int>& p1, const pair<int,int>& p2) {
            return p1.first > p2.first;
        });
        string result = "";
        for(auto p : vs) {
            result += string(p.first, p.second);
        }
        return result;
    }
};