class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
		int n = matrix.size();
		vector<vector<bool>> m_row(n, vector<bool>(n, false));
		vector<vector<bool>> m_col(n, vector<bool>(n, false));
		// check row/col at the same time
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				int num = matrix[i][j] - 1;
				if (m_row[i][num] == true) return false;
				if (m_col[num][j] == true) return false;
				m_row[i][num] = true;
				m_col[num][j] = true;
			}
		}
		return true;        
    }
};