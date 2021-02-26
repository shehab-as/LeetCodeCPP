class Solution {
public:
    void FloodFill(vector<vector<char>>& board, const int M, const int N, int r, int c) {
        if(r < 0 || r >= M || c < 0 || c >= N)  return;
        if(board[r][c] == '-')
            board[r][c] = 'O';
        else 
            return;
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};
        for(int d = 0; d < 4; d++) {
            int new_x = r + dx[d];
            int new_y = c + dy[d];
            FloodFill(board, M, N, new_x, new_y);
        }
    }
    void solve(vector<vector<char>>& board) {
        if(board.empty() || board[0].empty())   return;
        int M = board.size();
        int N = board[0].size();
        for(int i = 0; i < M; i++) {
            for(int j = 0; j < N; j++) {
                if(board[i][j] == 'O')
                    board[i][j] = '-';
            }
        }
        // TOP - RIGHT - BOTTOM - LEFT
        for(int c = 0; c < N; c++)
            if(board[0][c] == '-')
                FloodFill(board, M, N, 0, c);
        for(int r = 0; r < M; r++)
            if(board[r][N-1] == '-')
                FloodFill(board, M, N, r, N-1);
        for(int c = 0; c < N; c++)
            if(board[M-1][c] == '-')
                FloodFill(board, M, N, M-1, c);
        for(int r = 0; r < M; r++)
            if(board[r][0] == '-')
                FloodFill(board, M, N, r, 0);
        
        for(int i = 0; i < M; i++) {
            for(int j = 0; j < N; j++) {
                if(board[i][j] == '-')
                    board[i][j] = 'X';
            }
        }
    }
};
