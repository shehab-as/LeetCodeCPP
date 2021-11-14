class CombinationIterator {
private:
    int len, mask;
    string s;
public:
    CombinationIterator(string characters, int combinationLength) : s(characters), len(combinationLength) {
        mask = (1 << characters.length()) - 1;
    }
    
    string next() {
        while(mask && __builtin_popcount(mask) != len) { mask--; }
        string next_combination;
        for(int i = 0; i < s.length(); i++) {
            if(mask & (1 << (s.length() - i - 1))) {
                next_combination.push_back(s[i]);
            }
        }
        mask--;
        return next_combination;
    }
    
    bool hasNext() {
        while(mask && __builtin_popcount(mask) != len) { mask--; }
        return mask;
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */