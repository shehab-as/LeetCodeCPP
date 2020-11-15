class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        
        string result = "";
        bool carry = false;
        for(int i = 0, j = 0; i < a.length() || j < b.length(); i++, j++) {
            int binary_a = (i < a.length()) ? a[i] - '0' : 0;
            int binary_b = (j < b.length()) ? b[j] - '0' : 0;
            
            if (binary_a + binary_b > 1) {
                result += (carry) ? '1' : '0';
                carry = true;
            }
            else if(binary_a + binary_b > 0 && carry)
                result += '0';
            else {
                result += (carry) ? '1' : (binary_a + binary_b) + '0';
                carry = false;
            }
        }
        if(carry)   result += '1';
        reverse(result.begin(), result.end());
        return result;
    }
};