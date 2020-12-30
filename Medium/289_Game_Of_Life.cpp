class Solution {
private:
        bool shouldBecomeDead(const int& live_neighbors) {
        // a live cell.
        if(live_neighbors < 2)  return true;
        if(live_neighbors > 3)  return true;
        return false;
    }
    
    bool shouldBecomeAlive(const int& live_neighbors) {
        // a dead cell.
        if(live_neighbors == 3)  return true;
        return false;
    }
public:
    void gameOfLife(vector<vector<int>>& board) {
        if(board.empty() || board[0].empty())
            return;
        int M = board.size(), N = board[0].size();
        vector<vector<int>> board_copy (M, vector<int> (N, 0));
        // copy
        for(int r = 0; r < M ; r++) {
            for(int c = 0; c < N; c++) {
                board_copy[r][c] = board[r][c];
            }
        }
        // go to next state.
        int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
        int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
        for(int r = 0; r < M; r++) {
            for(int c = 0; c < N; c++) {
                // count neighbors.
                int live_neighbors = 0;
                for(int k = 0; k < 8; k++) {
                    int r2 = r + dx[k], c2 = c + dy[k];
                    if(r2 < 0 || r2 >= M ||c2 < 0 || c2 >= N)   continue;
                    live_neighbors += board_copy[r+dx[k]][c+dy[k]] ? 1 : 0;
                }
                // next state.
                if(board_copy[r][c] == 1)
                    board[r][c] = shouldBecomeDead(live_neighbors) ? 0 : 1;
                else
                    board[r][c] = shouldBecomeAlive(live_neighbors) ? 1 : 0;
            }
        }
        return;
    }
};