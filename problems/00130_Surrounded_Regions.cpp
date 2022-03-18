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