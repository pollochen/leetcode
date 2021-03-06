class Solution {
public:
    int uniquePaths(int m, int n) {
		vector<vector<int>> dp(m, vector<int>(n, 0));
		// initial values
		for (int i = 0; i < m; i++) dp[i][0] = 1;
		for (int i = 1; i < n; i++) dp[0][i] = 1;

		// start
		for (int j = 1; j < n; j++) {
			for (int i = 1; i < m; i++) {
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			}
		}
		return dp[m - 1][n - 1];
    }
};