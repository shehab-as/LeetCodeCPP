class Solution {
public:
    string reverseOnlyLetters(string S) {
        int left = 0, right = S.length() - 1;
        while(left < right) {
            if(isalpha(S[right]) && isalpha(S[left]))
                swap(S[right--], S[left++]);
            else if(!isalpha(S[left]))
                left++;
            else // if(!isalpha(S[right]))
                right--;
        }
        return S;
        
    }
};