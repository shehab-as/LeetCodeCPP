class Solution {
public:
    bool DFS(vector<vector<char>>& board, int x, int y, int index, string& word) {
        if(x < 0 || x >= board.size() || y < 0 || y >= board[0].size() || word[index] != board[x][y])    
            return false;
        if(index == word.length() - 1) 
            return true;
        int dxy[4][2] = {{-1,0}, {0,1}, {1,0}, {0,-1}};
        char temp = board[x][y];
        board[x][y] = '*';  //mark visit.
        bool search_next = DFS(board, x-1, y, index+1, word)
            || DFS(board, x, y+1, index+1, word)
            || DFS(board, x+1, y, index+1, word)
            || DFS(board, x, y-1, index+1, word);
        board[x][y] = temp; // reset.
        return search_next;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int M = board.size();
        int N = board[0].size();
        for (int i = 0; i < M; i++) {
            for(int j = 0; j < N; j++) {
                if(DFS(board, i, j, 0, word))   
                    return true;
            }
        }
        return false;
    }
};