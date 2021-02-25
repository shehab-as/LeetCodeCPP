class Solution {
public:
    int scoreOfParentheses(string S) {
        stack<int> Stk;
        int score = 0;
        for(char& c : S) {
            if(c == '(') {
                Stk.push(score);
                score = 0;
            } 
            else {
                score = Stk.top() + max(score * 2, 1);
                Stk.pop();
            }
        }
        return score;
    }
};