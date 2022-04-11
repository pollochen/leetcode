// https://www.cnblogs.com/grandyang/p/4555831.html
class Solution {
public:
	void mark_dollor(vector<vector<char>>& board, int row, int col, int row_cnt, int col_cnt)
	{
		board[row][col] = '$';
		// up
		if (((row - 1) >= 0) && (board[row - 1][col] == 'O')) {
			mark_dollor(board, row-1, col, row_cnt, col_cnt);
		}
		// down
		if (((row + 1) < row_cnt) && (board[row + 1][col] == 'O')) {
			mark_dollor(board, row + 1, col, row_cnt, col_cnt);
		}
		// left
		if (((col - 1) >= 0) && (board[row][col-1] == 'O')) {
			mark_dollor(board, row, col - 1, row_cnt, col_cnt);
		}
		// right
		if (((col + 1) < col_cnt) && (board[row][col + 1] == 'O')) {
			mark_dollor(board, row, col + 1, row_cnt, col_cnt);
		}
	}
	void solve(vector<vector<char>>& board) {
		int row_cnt = board.size();
		int col_cnt = board[0].size();
		int row, col;
		// search boarder for 'O' and replace with '$'
		// row[0] & row[m-1] 
		for (col = 0; col < col_cnt; col++) {
			if (board[0][col] == 'O') {
				mark_dollor(board, 0, col, row_cnt, col_cnt);
			}
			if (board[row_cnt-1][col] == 'O') {
				mark_dollor(board, row_cnt - 1, col, row_cnt, col_cnt);
			}
		}
		// col[0] & col[n-1] 
		for (row = 0; row < row_cnt; row++) {
			if (board[row][0] == 'O') {
				mark_dollor(board, row, 0, row_cnt, col_cnt);
			}
			if (board[row][col_cnt-1] == 'O') {
				mark_dollor(board, row, col_cnt-1, row_cnt, col_cnt);
			}
		}

		// search 'O' and replace with 'X'
		for (col = 0; col < col_cnt; col++) {
			for (row = 0; row < row_cnt; row++) {
				if (board[row][col] == 'O') board[row][col] = 'X';
			}
		}
		// search '$' and replace with 'O'
		for (col = 0; col < col_cnt; col++) {
			for (row = 0; row < row_cnt; row++) {
				if (board[row][col] == '$') board[row][col] = 'O';
			}
		}
	}
};

// Runtime: 5 ms, faster than 99.37% of C++ online submissions for Surrounded Regions.
// Memory Usage: 13.9 MB, less than 13.86% of C++ online submissions for Surrounded Regions.
class Solution {
public:
    // dfs: replace target with modify if current char is target
    void mark_x(vector<vector<char>>& board, int row, int col, char target, char modify) {
        int row_cnt = board.size();
        int col_cnt = board[0].size();
                    //  U  D,  L  R
        int dr[4] = {  -1, 1,  0, 0};
        int dc[4] = {   0, 0, -1, 1};
        int nr, nc;
        board[row][col] = modify;
        for (int dir = 0; dir < 4; dir++) {
            nr = row + dr[dir];
            nc = col + dc[dir];
            if (nr >= 0 && nr < row_cnt && nc >= 0 && nc < col_cnt && board[nr][nc] == target) {
                board[nr][nc] = modify;
                mark_x(board, nr, nc, target, modify);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int row_cnt = board.size();
        int col_cnt = board[0].size();
        // scan row_0 and row_n, dfs replace 'O' with 'Y'
        for (int col = 0; col < col_cnt; col++) {
            if (board[0][col] == 'O') {
                mark_x(board, 0, col, 'O', 'Y');
            }
            if (board[row_cnt - 1][col] == 'O') {
                mark_x(board, row_cnt - 1, col, 'O', 'Y');
            }
        }
        // scan col_0 and col_n, dfs replace 'O' with 'Y'
        for (int row = 1; row < row_cnt -1; row++) {
            if (board[row][0] == 'O') {
                mark_x(board, row, 0, 'O', 'Y');
            }
            if (board[row][col_cnt-1] == 'O') {
                mark_x(board, row, col_cnt-1, 'O', 'Y');
            }
        }
        // scan [row 1, row n-1][col 1 , col n-1], dfs replace 'O' with 'X'
        for (int row = 1; row < row_cnt -1; row++) {
            for (int col = 1; col < col_cnt -1; col++) {
                if (board[row][col] == 'O') {
                    mark_x(board, row, col, 'O', 'X');
                }
            }
        }
        // scan [row 0, row n-1][col 0 , col n-1], replace 'Y' with 'O'
        for (int row = 0; row < row_cnt; row++) {
            for (int col = 0; col < col_cnt; col++) {
                if (board[row][col] == 'Y') {
                    board[row][col] = 'O';
                }
            }
        }
    }
};

void print_matrix_char(vector<vector<char>> matrix)
{
	printf("[");
	for (int i = 0; i < matrix.size(); i++) {
		printf("[");
		for (int j = 0; j < matrix[i].size(); j++) {
			printf("%c, ", matrix[i][j]);
		}
		printf("], ");
	}
	printf("]\n");
}

void test_130_surrounded_regions_1(void)
{
	vector<vector<char>> board{
		{ 'X', 'X', 'X', 'X'},
		{ 'X', 'O', 'O', 'X' },
		{ 'X', 'X', 'O', 'X' },
		{ 'X', 'O', 'X', 'X' },
	};
	Solution s;
	s.solve(board);
	print_matrix_char(board);
}
void test_130_surrounded_regions_2(void)
{
	vector<vector<char>> board{
		{ 'X' },
	};
	Solution s;
	s.solve(board);
	print_matrix_char(board);
}