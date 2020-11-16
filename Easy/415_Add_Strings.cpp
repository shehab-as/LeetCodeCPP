class Solution {
public:
    string addStrings(string num1, string num2) {
        
        string result = "";
        int carry = 0;
        int i = 0;
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        while(i < num1.length() || i < num2.length() || carry) {
            int a = (i < num1.length()) ? num1[i] - '0' : 0;
            int b = (i < num2.length()) ? num2[i] - '0' : 0;
            result += (a + b + carry > 9) ? (a + b + carry - 10) + '0' : (a + b + carry) + '0';
            carry = (a + b + carry > 9) ? 1 : 0;
            i++;
        }
        
        reverse(result.begin(), result.end());
        return result;
        
    }
};