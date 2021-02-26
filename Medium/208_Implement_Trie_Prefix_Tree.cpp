class Trie {
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
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* curr = root;
        for(int i = 0; i < word.length(); i++) {
            if(curr->children[word[i] - 'a'] == nullptr)
                curr->children[word[i] - 'a'] = new TrieNode();
            curr = curr->children[word[i] - 'a'];
        }
        curr->IsEnd = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* curr = root;
        for(int i = 0; i < word.length(); i++) {
            if(curr->children[word[i] - 'a'] == nullptr)  return false;
            curr = curr->children[word[i] - 'a'];
        }
        return curr->IsEnd;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for(int i = 0; i < prefix.length(); i++) {
            if(curr->children[prefix[i] - 'a'] == nullptr)  return false;
            curr = curr->children[prefix[i] - 'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */