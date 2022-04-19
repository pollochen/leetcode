// recurrsion with memorization
// Runtime: 320 ms, faster than 75.70% of C++ online submissions for Word Search.
// Memory Usage: 8 MB, less than 36.23% of C++ online submissions for Word Search.
class Solution {
public:
    bool dfs(vector<vector<char>>& board, int row, int col, int pos, string word)
    {
        if (pos == word.length()-1) {
            return true;
        }

        if (pos > word.length() -1 ) {
            return false;
        }

        int row_cnt = board.size();
        int col_cnt = board[0].size();

        char target = word[pos+1];
        bool bret;

        // check 4 directions

        // down
        if (row + 1 < row_cnt) {
            char ch = board[row+1][col];
            if (ch == target) {
                board[row+1][col] = '~';
                bret = dfs(board, row+1, col, pos+1, word);
                board[row+1][col] = ch;
                if (bret == true) return true;
            }
        }

        // right
        if (col + 1 < col_cnt) {
            char ch = board[row][col+1];
            if (ch == target) {
                board[row][col+1] = '~';
                bret = dfs(board, row, col+1, pos+1, word);
                board[row][col+1] = ch;
                if (bret == true) return true;
            }
        }

        // up
        if (row - 1 >= 0) {
            char ch = board[row-1][col];
            if (ch == target) {
                board[row-1][col] = '~';
                bret = dfs(board, row-1, col, pos+1, word);
                board[row-1][col] = ch;
                if (bret == true) return true;
            }
        }

        // left
        if (col - 1 >= 0) {
            char ch = board[row][col-1];
            if (ch == target) {
                board[row][col-1] = '~';
                bret = dfs(board, row, col-1, pos+1, word);
                board[row][col-1] = ch;
                if (bret == true) return true;
            }
        }


        return false;

    }

    bool exist(vector<vector<char>>& board, string word) {
        int row_cnt = board.size();
        int col_cnt = board[0].size();
        for (int row = 0; row < row_cnt; row++) {
            for (int col = 0; col < col_cnt; col++) {
                if (board[row][col] == word[0]) {
                    char ch = board[row][col];
                    board[row][col] = '~';
                    if (dfs(board, row, col, 0, word) == true) return true;
                    board[row][col] = ch;
                }
            }
        }
        return false;
    }
};