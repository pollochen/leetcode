// https://www.cnblogs.com/grandyang/p/4323301.html
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Search a 2D Matrix.
// Memory Usage : 9.6 MB, less than 52.32 % of C++ online submissions for Search a 2D Matrix.
bool searchMatrix(vector<vector<int>>& matrix, int target) {
	int row_cnt = matrix.size();
	int col_cnt = matrix[0].size();
	// binary search
	int size = row_cnt * col_cnt;
	int left = 0;
	int right = size - 1;
	while (left < right) {
		int mid = (left + right) / 2;
		int val = matrix[mid / col_cnt][mid % col_cnt];
		if (val == target) return true;
		if (val < target) {
			left = mid + 1;
		} else {
			right = mid + 1;
		}
	}
	return false;
}