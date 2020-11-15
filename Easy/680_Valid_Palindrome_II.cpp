class Solution {
public:
    bool find_valid(string& s, int start, int end) {
        int a = start, b = end;
        while(a <= b) {
            if(s[a] == s[b]) {
                a++;
                b--;
            }
            else return false;
        }
        return true;
        
    }
    bool validPalindrome(string s) {
        int start = 0, end = s.length() - 1;
        while(start <= end) {
            if(s[start] == s[end]) {
                start++;
                end--;
            }
            else {
                return find_valid(s, start+1, end) || find_valid(s, start, end-1);
            }
        }
        return true;
    }
};