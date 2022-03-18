// https://www.cnblogs.com/grandyang/p/4800552.html
class Solution {
public:
    int numSquares(int n) {
		vector<int> dp(n + 1, INT_MAX-1);
		dp[0] = 0;
		for (int i = 0; i <= n; i++) {
			// step 1 position (0 - n)
			for (int j = 1; (i + j * j) <= n; j++) {
				// update position [i + 1], [i + 4], [i + 9], [i + 16] .... [i + n^2]
				// for example dp[i + 4] should be from dp[i] in most cases
				dp[i + j * j] = min(dp[i + j * j], dp[i] + 1);
			}
		}
		return dp[n];
    }
};

void test_279_Perfect_Squares(void)
{
	Solution s;
	printf("%d\n", s.numSquares(12));
	printf("%d\n", s.numSquares(13));
}
