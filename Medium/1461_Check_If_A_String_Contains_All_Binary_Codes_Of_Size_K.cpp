class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<string> HashSet; 
        int len = s.length();
        
        for(int j = 0; j <= len - k; j++) {
            string binaryCode = s.substr(j, k);
            HashSet.insert(binaryCode);
        }
        
        return HashSet.size() == pow(2, k);
    }
};