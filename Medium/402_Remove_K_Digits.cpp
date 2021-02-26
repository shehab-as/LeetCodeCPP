class Solution {
public:
    string removeKdigits(string num, int k) {
        string res = "";
        int n = num.length(), keep = n - k;
        for(char c : num) {
            while(k && res.length() && res.back() > c) {
                res.pop_back();
                k--;
            }
            res.push_back(c);
        }
        res.resize(keep);
        res.erase(0, res.find_first_not_of('0'));
        return res.empty() ? "0" : res;
    }
};
