class Solution {
public:
    string removeOuterParentheses(string S) {
        if(S.empty())   return S;
        string result = "";
        int open_bracks = 0;
        int i = 0;
        for(int j = 0; j < S.length(); j++) {
            if(S[j] == '(') {
                if(open_bracks > 0)
                    result += S[j];
                open_bracks++;
            }
            else {
                open_bracks--;
                if(open_bracks > 0)
                    result += S[j];
            }
        }
        return result;
    }
};