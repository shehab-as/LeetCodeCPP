class Solution {
public:
    int readVal(const string& s, int& i) {
        int val = 0;
        while(i < s.length() && isdigit(s[i])) {
            val = (val * 10) + (s[i++] - '0');
        }
        return val;
    }
    string decodeString(const string& s, int& i) {
        string res = "";
        while(i < s.length() && s[i] != ']') {
            if(isdigit(s[i])) {
                int val = readVal(s, i);
                i++;    // '['
                string t = decodeString(s, i);
                i++;    // ']'
                for(int j = 0; j < val; j++)
                    res += t;
            }
            else
                res += s[i++];
        }
        return res;
    }
    string decodeString(string s) {
        int i = 0;
        return decodeString(s, i);
    }
};