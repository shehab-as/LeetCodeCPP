class Solution {
private:
    string codes[26] = { ".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.." };
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        unordered_set<string> HashSet;
        for(string& word : words) {
            string code = "";
            for(char& c : word) {
                code += codes[(c - 'a')];
            }
            HashSet.insert(code);
        }
        return HashSet.size();
    }
};