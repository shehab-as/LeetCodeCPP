class Solution {
public:
    bool wordPattern(string pattern, string str) {
        vector<string> words;
        string word;
        istringstream stream(str);
        
        while(stream >> word) 
            words.push_back(word);
        
        if (pattern.size() != words.size())
            return false;
        
        unordered_map<char, string> hmp;        
        unordered_set<string> SET;
        
        for(int i=0; i<pattern.length(); i++) {
            char c = pattern[i];
            word = words[i];
            
            // If the HashMap already has the entry for the key (c) and is not equal to the value (word). 
            if(hmp.find(c) != hmp.end() && hmp[c] != word)
                return false;
            // If the HashMap doesn't have the entry for the key (c) but the value (word) is already recorded.
            if(hmp.find(c) == hmp.end() && SET.find(word) != SET.end())
                return false;
            
            // Add (key, value) in the HashMap and record (value) in the set.
            hmp[c] = word;
            SET.insert(word);
        }
        return true;
    }
};