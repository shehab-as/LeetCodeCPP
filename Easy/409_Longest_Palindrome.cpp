class Solution {
public:
    int longestPalindrome(string s) {
        int N = s.length();
        unordered_map<char, int> freq;
        for(char& c : s)
            freq[c]++;
        int odds = 0;
        for(auto it : freq) {
            if(it.second % 2 != 0)
                odds++;
        }
        return odds == 0 ? N : N - odds + 1;
    }
};