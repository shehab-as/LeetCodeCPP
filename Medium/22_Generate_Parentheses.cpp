class Solution {
public:
    void generate_all(vector<string>& res, string curr, int left, int right) {
        if(left == 0 && right == 0) {
            res.push_back(curr);
            return;
        }
        if(left > 0)
            generate_all(res, curr + '(', left - 1, right);
        if(left < right)
            generate_all(res, curr + ')', left, right - 1);
    }
    
    vector<string> generateParenthesis(int n) {
        if(!n)  return {};
        vector<string> res;
        generate_all(res, "", n, n);
        return res;
    }
};
