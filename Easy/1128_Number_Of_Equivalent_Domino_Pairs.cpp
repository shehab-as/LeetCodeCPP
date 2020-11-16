class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        map<pair<int,int>,int>freq;
        int equiv = 0;
        for(auto& d : dominoes) {
            int a = d[0], b = d[1];
            if(a > b)   
                swap(a, b);
            equiv += freq[{a, b}]++;
        }
        return equiv;
    }
};