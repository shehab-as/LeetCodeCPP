class Solution {
private:
    bool isValidSolution(const vector<string>& board, int r, int c, const int& N) {
       for(int i = r; i >= 0; i--)  // column check
           if(board[i][c] == 'Q')   return false;
        for(int i = r, j = c; i >= 0 && j >= 0; i--, j--)   // left diagonal check
            if(board[i][j] == 'Q')  return false;
        for(int i = r, j = c; i >= 0 && j < N; i--, j++)    // right diagonal check
            if(board[i][j] == 'Q')  return false;
        return true;
    }
    void DFS(vector<string>& board, vector<vector<string>>& res, int row, const int& N) {
        if( row == N ) {
            res.push_back(board);
            return;
        }
        for(int i = 0; i < N; i++) {
            if(isValidSolution(board, row, i, N)) {
                board[row][i] = 'Q';
                DFS(board, res, row+1, N);
                board[row][i] = '.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        if(n <= 0)  return {{}};
        vector<string> board(n, string(n, '.'));
        vector<vector<string>> result;
        DFS(board, result, 0, n);
        return result;
    }
};