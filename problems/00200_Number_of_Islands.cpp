// Runtime: 31 ms, faster than 95.33% of C++ online submissions for Number of Islands.
// Memory Usage : 12.3 MB, less than 83.94 % of C++ online submissions for Number of Islands.
class Solution {
public:
	void mark_zero(vector<vector<char>>& board, int row, int col, int row_cnt, int col_cnt)
	{
		board[row][col] = '0';
		// up
		if (((row - 1) >= 0) && (board[row - 1][col] == '1')) {
			mark_zero(board, row - 1, col, row_cnt, col_cnt);
		}
		// down
		if (((row + 1) < row_cnt) && (board[row + 1][col] == '1')) {
			mark_zero(board, row + 1, col, row_cnt, col_cnt);
		}
		// left
		if (((col - 1) >= 0) && (board[row][col - 1] == '1')) {
			mark_zero(board, row, col - 1, row_cnt, col_cnt);
		}
		// right
		if (((col + 1) < col_cnt) && (board[row][col + 1] == '1')) {
			mark_zero(board, row, col + 1, row_cnt, col_cnt);
		}
	}
	int numIslands(vector<vector<char>>& grid) {
		int row_cnt = grid.size();
		int col_cnt = grid[0].size();
		int row, col;
		int result = 0;
		// search grid for '1' and replace with '0'
		for (row = 0; row < row_cnt; row++) {
			for (col = 0; col < col_cnt; col++) {
				if (grid[row][col] == '1') {
					result++;
					mark_zero(grid, row, col, row_cnt, col_cnt);
				}
			}
		}
		return result;
	}
};

void test_200_number_of_islands_1(void)
{
	vector<vector<char>> board{
		{ '1', '1', '1', '1', '0' },
		{ '1', '1', '0', '1', '0' },
		{ '1', '1', '0', '0', '0' },
		{ '0', '0', '0', '0', '0' },
	};
	Solution s;
	printf("%d\n", s.numIslands(board));
}

void test_200_number_of_islands_2(void)
{
	vector<vector<char>> board{
		{ '1', '1', '0', '0', '0' },
		{ '1', '1', '0', '0', '0' },
		{ '0', '0', '1', '0', '0' },
		{ '0', '0', '0', '1', '1' },
	};
	Solution s;
	printf("%d\n", s.numIslands(board));
}