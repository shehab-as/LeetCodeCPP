class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.rbegin(), g.rend());
        sort(s.rbegin(), s.rend());
        int content = 0;
        int i, j = 0;
        for(i = 0; i < g.size(); i++) {
            if(j >= s.size())   break;
            if(s[j]>=g[i]) {
                content++;
                j++;
            }
        }
        return content;
    }
};