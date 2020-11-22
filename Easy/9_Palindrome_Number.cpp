class Solution {
public:
    // Treating it as a string.
    bool isPalindrome(string x) {
        int i = 0, j = x.length() - 1;
        while( i <= j ) {
            if(x[i] != x[j])    return false;
            i++;    
            j--;
        }
        return true;
    }
    // Treating it as an integer.
    bool isPalindrome(int x) {
        if(x < 0)   return false;
        int temp = x;
        long int y = 0;
        while(x) {
            y = (y * 10) + (x % 10);
            x /= 10;
        }
        x = temp;
        return x == y;
    }
};