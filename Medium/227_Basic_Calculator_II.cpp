class Solution {
public:
    int calculate(string s) {
        istringstream iss("+" + s);
        char op;
        int var2, var1, ans = 0;
        while(iss >> op >> var2) {
            if(op == '+' || op == '-') {
                var2 = op == '+' ? var2 : -var2;
                ans += var2;
            } 
            else {
                var2 = op == '*' ? var1 * var2 : var1 / var2;
                ans = ans - var1 + var2;        // simulate stack.   
            }
            var1 = var2;
        }
        return ans;
    }
};