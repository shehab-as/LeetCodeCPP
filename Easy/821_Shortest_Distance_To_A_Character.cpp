class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        int N = S.length();
        vector<int> result(S.length(), -N);
        int pos = -N;
        for(int i = 0; i < S.length(); i++) {
            if(S[i] == C)   pos = i;
            result[i] = i - pos;
        }
        for(int i = pos - 1; i >= 0; i--) {
            if(S[i] == C)   pos = i;
            result[i] = min(result[i], pos-i);
        }
        return result;
    }
};