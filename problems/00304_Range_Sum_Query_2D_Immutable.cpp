// https://leetcode.com/problems/range-sum-query-2d-immutable/solution/
// Approach #3 (Caching Rows)
// Runtime: 1048 ms, faster than 5.04% of C++ online submissions for Range Sum Query 2D - Immutable.
// Memory Usage: 154 MB, less than 5.08% of C++ online submissions for Range Sum Query 2D - Immutable.
class NumMatrix {
    vector<vector<int>> m_dp;
    vector<vector<int>> m_matrix;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int row_cnt = matrix.size();
        int col_cnt = matrix[0].size();
        vector<vector<int>> dp(row_cnt, vector<int>(col_cnt, 0));
        for (int row = 0; row < row_cnt; row++) {
            dp[row][0] = matrix[row][0];
            for (int col = 1; col < col_cnt; col++) {
                dp[row][col] = dp[row][col-1] + matrix[row][col];
            }
        }

        m_dp = dp;
        m_matrix = matrix;
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int result = 0;
        for (int row = row1; row <= row2; row++) {
            result += (m_dp[row][col2] - m_dp[row][col1] + m_matrix[row][col1]);
        }
        return result;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */