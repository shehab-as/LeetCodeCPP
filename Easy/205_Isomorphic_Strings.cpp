class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, int>freqA;
        unordered_map<char, int>freqB;
        for(int i = 0; i < s.length(); i++) {
            if(freqA[s[i]] != freqB[t[i]])  return false;
            freqA[s[i]] = i + 1;
            freqB[t[i]] = i + 1;
        }
        return true;
    }
};