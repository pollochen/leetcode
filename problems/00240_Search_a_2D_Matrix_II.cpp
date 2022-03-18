// https://www.cnblogs.com/grandyang/p/4669134.html
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
		int row_cnt = matrix.size();
		int col_cnt = matrix[0].size();
		int row = row_cnt - 1;
		int col = 0;
		while ((row >= 0) && (col <= col_cnt - 1)) {
			int cur = matrix[row][col];
			if (target == cur) return true;
			if (target < cur) row--;
			if (target > cur) col++;
		}
		return false;    
    }
};