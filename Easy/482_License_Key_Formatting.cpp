class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        string raw_S = "";
        for(char& c : S) {
            if(isalnum(c))
                raw_S += c;
        }
        string result = "";
        int count = 0;
        for(int i = raw_S.length() - 1; i >= 0; i--) {
            if(isalpha(raw_S[i]))
                result += toupper(raw_S[i]);
            else
                result += raw_S[i];
            count++;
            if(count == K && i > 0) {
                count = 0;
                result += '-';
            }
        }
        reverse(result.begin(), result.end());
        return result;
    }
};