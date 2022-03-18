// DP, http://web.ntnu.edu.tw/~algo/DynamicProgramming.html
class Solution {
public:
	int minPathSum(vector<vector<int>>& grid) {
		int row_cnt = grid.size();
		int col_cnt = grid[0].size();
		vector<vector<int>> dp(row_cnt, vector<int>(col_cnt, 0));

		dp[0][0] = grid[0][0];

		// init row[0]
		for (int col = 1; col < col_cnt; col++) {
			dp[0][col] = dp[0][col - 1] + grid[0][col];
		}
		// init col[0]
		for (int row = 1; row < row_cnt; row++) {
			dp[row][0] = dp[row-1][0] + grid[row][0];
		}
		for (int row = 1; row < row_cnt; row++) {
			for (int col = 1; col < col_cnt; col++) {
				dp[row][col] = min(dp[row-1][col] + grid[row][col], dp[row][col-1] + grid[row][col]);
			}
		}
		return dp[row_cnt - 1][col_cnt-1];
	}
};