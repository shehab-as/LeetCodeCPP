class Solution {
public: 
    bool isNumber(string s) {
        bool foundDigit = false, foundE = false, foundDot = false;
        int countSigns = 0;
        for(int i = 0; i < s.length(); i++) {
            char ch = s[i];
            if( isdigit(ch) ) {           
                foundDigit = true;
            }
            else if(ch == '+' || ch == '-') {
                if( countSigns == 2 ) {
                    return false;
                }
                if( i > 0 && s[i-1] != 'e' && s[i-1] != 'E' ) {
                    return false;
                }
                if( i == s.length() - 1 ) {
                    return false;
                }
                countSigns++;
            }
            else if( ch == '.' ) {
                if( foundE || foundDot ) {
                    return false;
                }
                if( i == s.length() - 1 && !foundDigit ) {
                    return false;
                }
                foundDot = true;
            }
            else if( ch == 'e' || ch == 'E' ) {
                if( foundE || !foundDigit || i == s.length() - 1 ) {
                    return false;
                }
                foundE = true;
            } 
            else {    //invalid char.
                return false;
            }
        }
        return true;
    }
};