
class Solution {
public:
	bool is_all_one(vector<vector<char>>& matrix, int i, int j)
	{
		if (matrix[i][j] == '1' && matrix[i - 1][j] == '1' && matrix[i][j - 1] == '1' && matrix[i - 1][j - 1] == '1') {
			return true;
		} else {
			return false;
		}
	}
	int get_min_dp(vector<vector<int>>& dp, int i, int j)
	{
		int ret = min(dp[i][j-1], dp[i-1][j]);
		ret = min(ret, dp[i-1][j - 1]);
		return ret;
	}
	int maximalSquare(vector<vector<char>>& matrix) {
		int row_cnt = matrix.size();
		int col_cnt = matrix[0].size();
		int result = 1;

		int flag_all_zero = true;
		for (int i = 0; i < row_cnt; i++) {
			for (int j = 0; j < col_cnt; j++) {
				if (matrix[i][j] == '1') {
					flag_all_zero = false;
					break;
				}
			}
			if (flag_all_zero == false) break;
		}
		if (flag_all_zero == true) return 0;
        
        vector<vector<int>> dp(row_cnt, vector<int>(col_cnt, 1));
		for (int i = 1; i < row_cnt; i++) {
			for (int j = 1; j < col_cnt; j++) {
				if (is_all_one(matrix, i, j) == true) {
					dp[i][j] = get_min_dp(dp, i, j) + 1;
				}  else {
					dp[i][j] = 1;
				}
    			result = max(result, dp[i][j]);
			}
		}
		return result * result;
	}
};

void test_00221_Maximal_Square(void)
{
	Solution s;
	printf("%d\n", s.maximalSquare(vector<vector<char>>{{'1', '1', '1', '1', '0'}, { '1', '1', '1', '1', '0' }, { '1', '1', '1', '1', '1' }, { '1', '1', '1', '1', '1' }, { '0', '0', '1', '1', '1' }}));
}
