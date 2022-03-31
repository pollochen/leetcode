// https://leetcode.com/problems/01-matrix/solution/
// DP with 2 passes
// Runtime: 60 ms, faster than 96.98% of C++ online submissions for 01 Matrix.
// Memory Usage: 27.6 MB, less than 82.14% of C++ online submissions for 01 Matrix.
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int row_cnt = mat.size();
        int col_cnt = mat[0].size();
        vector<vector<int>> dp(row_cnt, vector<int>(col_cnt, 500000)); // initial value should be > 10000

        // first pass: from (top, left) -> (bottom, right)
        for (int row = 0; row < row_cnt; row++) {
            for (int col = 0; col < col_cnt; col++) {
                if (mat[row][col] == 0) {
                    // mark this node as 0
                    dp[row][col] = 0;
                } else {
                    // from left
                    if (col > 0) dp[row][col] = min(dp[row][col - 1] + 1, dp[row][col]);
                    // from top
                    if (row > 0) dp[row][col] = min(dp[row-1][col] + 1, dp[row][col]);
                }
            }
        }
        // second pass: from (bottom, right) -> (top, left)
        for (int row = row_cnt - 1; row >= 0; row--) {
            for (int col = col_cnt - 1; col >= 0; col--) {
                if (mat[row][col] == 0) {
                    // mark this node as 0
                    dp[row][col] = 0;
                } else {
                    // from right
                    if (col < col_cnt - 1) dp[row][col] = min(dp[row][col + 1] + 1, dp[row][col]);
                    // from bottom
                    if (row < row_cnt - 1) dp[row][col] = min(dp[row + 1][col] + 1, dp[row][col]);
                }
            }
        }
        return dp;
    }
};