struct TrieNode {
    vector<TrieNode*> children;
    vector<int> indices;
    TrieNode() : children(26) {
        for(int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
};

class Trie {
private:
    TrieNode* root;
public:
    Trie() { root = new TrieNode(); }
    void Insert(string word, int index) {
        TrieNode* curr = root;
        for(char c : word) {
            int key = c - 'a';
            if(!curr->children[key]) {
                curr->children[key] = new TrieNode();
            }
            curr = curr->children[key];
            curr->indices.push_back(index);
        }
    }
    
    vector<int> Search(string word) {
        TrieNode* curr = root;
        for(char c : word) {
            int key = c - 'a';
            if(!curr->children[key]) {
                return {};
            }
            curr = curr->children[key];
        }
        return curr->indices;
    }
};

class WordFilter {
private:
    Trie prefixTree;
    Trie suffixTree;
public:
    WordFilter(vector<string>& words) {
        for(int i = 0; i < words.size(); i++) {
            prefixTree.Insert(words[i], i);
            reverse(words[i].begin(), words[i].end());
            suffixTree.Insert(words[i], i);
        }
    }
    
    int f(string prefix, string suffix) {
        vector<int> prefixList = prefixTree.Search(prefix);
        reverse(suffix.begin(), suffix.end());
        vector<int> suffixList = suffixTree.Search(suffix);
        
        int i = (int) prefixList.size() - 1;
        int j = (int) suffixList.size() - 1;
        
        while( i >= 0 && j >= 0 ) {
            if(prefixList[i] == suffixList[j])  return prefixList[i];
            if(prefixList[i] > suffixList[j])   i--;
            else    j--;
        }
        return -1;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */