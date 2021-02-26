class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> Stk;
        int i = 0, j = 0;
        while( i < pushed.size() || j < popped.size() ) {
            // can't either push or pop. Stuck.
            if( !Stk.empty() && Stk.top() != popped[j] && i >= pushed.size() ) {
                return false;
            }
            if( (Stk.empty() || Stk.top() != popped[j]) && i < pushed.size() ) {
                Stk.push(pushed[i]);
                i++;
            }
            else {
                while( (!Stk.empty() && Stk.top() == popped[j]) && j < popped.size() ) {
                    Stk.pop();
                    j++;
                }
            }
        }
        return Stk.empty();
    }
};