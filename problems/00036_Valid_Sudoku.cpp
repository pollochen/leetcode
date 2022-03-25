// https://www.cnblogs.com/grandyang/p/4421217.html
// Runtime: 35 ms, faster than 44.84% of C++ online submissions for Valid Sudoku.
// Memory Usage : 18 MB, less than 75.32 % of C++ online submissions for Valid Sudoku.
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
		bool m_row[9][9];
		bool m_col[9][9];
		bool m_box[9][9];
		memset(m_row, false, sizeof(m_row));
		memset(m_col, false, sizeof(m_col));
		memset(m_box, false, sizeof(m_box));

		// check row/col/box at the same time
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				char ch = board[i][j];
				if (ch == '.') continue;
				int  num = ch - '1'; // num  = [0 - 8]
				int idx_box_i = (i / 3) * 3 + j / 3;
				if (m_row[i][num] == true) return false;
				if (m_col[num][j] == true) return false;
				if (m_box[idx_box_i][num] == true) return false;
				m_row[i][num] = true;
				m_col[num][j] = true;
				m_box[idx_box_i][num] = true;
			}
		}
		return true;
    }
};