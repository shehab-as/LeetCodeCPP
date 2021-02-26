class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        if(pairs.empty()) {
            return 0;
        }
        sort(pairs.begin(), pairs.end(), [](const vector<int>& p1, const vector<int>& p2) {
            return p1[1] < p2[1];
        });
        
        int longest_len = 1;
        int b = pairs[0][1];
        for(int i = 1; i < pairs.size(); i++) {
            int c = pairs[i][0];
            if( b < c ) {
                longest_len++;
                b = pairs[i][1];
            }
        }
        return longest_len;
    }
};
