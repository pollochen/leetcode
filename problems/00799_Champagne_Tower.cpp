// https://www.cnblogs.com/cnoodle/p/13888712.html
class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
		double dp[101][101];
		memset(dp, 0, sizeof(dp));
		dp[0][0] = poured;
		for (int i = 0; i <= query_row; i++) {
			for (int j = 0; j <= i; j++) {
				if (dp[i][j] > 1) {
					dp[i + 1][j]   += (dp[i][j] - 1) / 2.0;
					dp[i + 1][j+1] += (dp[i][j] - 1) / 2.0;
				}
			}
		}
		return min(1.0, dp[query_row][query_glass]); 
    }
};

void test_799_champagne_tower(void)
{
	Solution s;
	printf("%f\n", s.champagneTower(1, 1, 1));
	printf("%f\n", s.champagneTower(2, 1, 1));
	printf("%f\n", s.champagneTower(100000009, 33, 17));
}