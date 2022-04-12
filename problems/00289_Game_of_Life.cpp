// brute force, use another matrix and copy back
// Runtime: 6 ms, faster than 17.56% of C++ online submissions for Game of Life.
// Memory Usage: 7 MB, less than 58.55% of C++ online submissions for Game of Life.
class Solution {
public:
    
    int next_state(vector<vector<int>>& board, int row, int col) {
        int live_count = 0;
        int row_cnt = board.size();
        int col_cnt = board[0].size();
                    // up down left right UL  UR  DL DR
        int dc[8] = {  0,    0, -1,    1, -1,  1, -1, 1};
        int dr[8] = { -1,    1,  0,    0, -1, -1,  1, 1};
        int nc, nr;
        
        for (int i = 0; i < 8; i++) {
            nc = col + dc[i];
            nr = row + dr[i];
            if (nc < col_cnt && nc >= 0 && nr < row_cnt && nr >= 0) {
                if (board[nr][nc] == 1) live_count++;
            }
        }
        
        if (board[row][col] == 1) {
            // live node
            if ((live_count < 2) || (live_count > 3)) return 0;
            else return 1;
        } else {
            // dead node
            if (live_count == 3) return 1;
            else return 0;
        }
    }
    
    void gameOfLife(vector<vector<int>>& board) {
        int row_cnt = board.size();
        int col_cnt = board[0].size();
        vector<vector<int>> result(row_cnt, vector<int>(col_cnt, 0));
        
        for (int row = 0; row < row_cnt; row++) {
            for (int col = 0; col < col_cnt; col++) {
                result[row][col] = next_state(board, row, col);
            }
        }
        
        board = result;
        return;
    }
};

// brute force, reuse board matrix
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Game of Life.
// Memory Usage: 7 MB, less than 58.55% of C++ online submissions for Game of Life.
class Solution {
public:
    // bit[0]: current state
    // bit[1]: next state
    int next_state(vector<vector<int>>& board, int row, int col) {
        int live_count = 0;
        int row_cnt = board.size();
        int col_cnt = board[0].size();
                    // up down left right UL  UR  DL DR
        int dc[8] = {  0,    0, -1,    1, -1,  1, -1, 1};
        int dr[8] = { -1,    1,  0,    0, -1, -1,  1, 1};
        int nc, nr;
        
        for (int i = 0; i < 8; i++) {
            nc = col + dc[i];
            nr = row + dr[i];
            if (nc < col_cnt && nc >= 0 && nr < row_cnt && nr >= 0) {
                if (board[nr][nc] & 0x01) live_count++;
            }
        }
        
        if (board[row][col] & 0x01) {
            // live node
            if ((live_count < 2) || (live_count > 3)) return 0;
            else return 1;
        } else {
            // dead node
            if (live_count == 3) return 1;
            else return 0;
        }
    }
    
    void gameOfLife(vector<vector<int>>& board) {
        int row_cnt = board.size();
        int col_cnt = board[0].size();
        
        // calculate next states
        for (int row = 0; row < row_cnt; row++) {
            for (int col = 0; col < col_cnt; col++) {
                board[row][col] |= next_state(board, row, col) << 1;
            }
        }
        // publish next states by shifting right one bit
        for (int row = 0; row < row_cnt; row++) {
            for (int col = 0; col < col_cnt; col++) {
                board[row][col] = board[row][col] >> 1;
            }
        }
        
        return;
    }
};