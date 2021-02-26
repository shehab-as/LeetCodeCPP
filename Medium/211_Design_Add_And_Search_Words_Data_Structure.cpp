class WordDictionary {
private:
    struct TrieNode {
        TrieNode* children[26];
        bool IsEnd;
        TrieNode() : IsEnd(false) {
            for(int i = 0; i < 26; i++)
                children[i] = nullptr;
        }
    };
    TrieNode* root;
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new TrieNode();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        TrieNode* curr = root;
        for(int i = 0; i < word.length(); i++) {
            if(!curr->children[word[i]-'a'])
                curr->children[word[i]-'a'] = new TrieNode();
            curr = curr->children[word[i]-'a'];
        }
        curr->IsEnd = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool DFS(TrieNode* curr, const string& word, int index) {
        if(index == word.length())  return curr->IsEnd;
        if(word[index] == '.') {
            for(int i = 0; i < 26; i++)
                if(curr->children[i] && DFS(curr->children[i], word, index+1))   
                    return true;
        }
        else
            if(curr->children[word[index]-'a'] && DFS(curr->children[word[index]-'a'], word, index+1))   
                return true;
        return false;   
    }
    bool search(string word) {
        TrieNode* curr = root;
        return DFS(curr, word, 0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */