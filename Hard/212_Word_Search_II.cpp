class TrieNode {
public:
    TrieNode *children[26];
    bool isEnd;
    TrieNode() {
        for(int i = 0; i < 26; i++)
            children[i] = nullptr;
        isEnd = false;
    }
};
class Trie {
private:
    TrieNode *root;
public:
    Trie(const vector<string>& words) {
        root = new TrieNode();
        for(string word : words) 
            BuildTrie(word);
    }
    TrieNode* GetRoot() { return root; }
    void BuildTrie(const string& word) {
        TrieNode *curr = root;
        for(int i = 0; i < word.length(); i++) {
            int index = word[i] - 'a';
            if(curr->children[index] == nullptr)
                curr->children[index] = new TrieNode();
            curr = curr->children[index];
        }
        curr->isEnd = true;
    }
};
class Solution {
public:
    void searchWord(vector<vector<char>>& board, int r, int c, TrieNode* root, string word, unordered_set<string>& foundWords) {
        if(r < 0 || r >= board.size() || c < 0 || c >= board[0].size() || board[r][c] == ' ')  return;
        if(root->children[board[r][c] - 'a'] != nullptr) {
            word += board[r][c];
            root = root->children[board[r][c] - 'a'];
            if(root->isEnd)    
                foundWords.insert(word);
            char letter = board[r][c];
            board[r][c] = ' ';
            searchWord(board, r+1, c, root, word, foundWords);
            searchWord(board, r-1, c, root, word, foundWords);
            searchWord(board, r, c+1, root, word, foundWords);
            searchWord(board, r, c-1, root, word, foundWords);
            board[r][c] = letter;
        }
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        if(board.empty() || board[0].empty())   return {};
        unordered_set<string> foundWords;
        Trie trie = Trie(words);
        TrieNode* root = trie.GetRoot();
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[0].size(); j++) {
                searchWord(board, i, j, root, "", foundWords);
            }
        }
        vector<string> result (foundWords.begin(), foundWords.end());
        return result;
    }
};