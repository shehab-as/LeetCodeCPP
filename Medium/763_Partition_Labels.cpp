class Solution {
public:
    vector<int> partitionLabels(string S) {
        int *last = new int[26];
        for(int i = 0; i < S.length(); i++)
            last[S[i] - 'a'] = i;
        vector<int> result;
        int j = 0, anchor = 0;
        for(int i = 0; i < S.length(); i++) {
            j = max(j, last[S[i] - 'a']);
            if(i == j) {
                result.push_back(i - anchor + 1);
                anchor = i + 1;
            }
        }
        return result;
    }
};