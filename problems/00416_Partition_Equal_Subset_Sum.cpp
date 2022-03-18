// slow version https://leetcode.com/problems/partition-equal-subset-sum/discuss/1836185/Simple-easy-C%2B%2B-Well-Explained-Solution
class Solution {
public:
	bool canPartition(vector<int>& nums) {
		if (nums.size() == 1) return false;
		int sum = 0;
		for (auto num : nums) {
			sum += num;
		}
		if ((sum % 2) == 1) return false;

		// find if nums can sum to target (sum/2)
		int target = sum / 2;
		// 2D DP
		int row_cnt = nums.size() + 1;
		int col_cnt = target + 1;

		// init, col[0] = true, row[0] = false
		vector<vector<bool>> dp(row_cnt, vector<bool>(col_cnt, false));
		for (int row = 0; row < row_cnt; row++) {
			dp[row][0] = true;
		}
		for (int row = 1; row < row_cnt; row++) {
			for (int col = 1; col < col_cnt; col++) {
				// row and col start from 1 but nums starts from 0
				// [row - 1] -> index of nums
				// col -> target sum
				int num = nums[row - 1];
				if (num <= col) {
					dp[row][col] = dp[row - 1][col] || dp[row - 1][col - num];
				} else {
					dp[row][col] = dp[row - 1][col];
				}
			}
		}
		return dp[row_cnt-1][col_cnt-1];
    }
};

// fast version https://www.cnblogs.com/grandyang/p/5951422.html
class Solution {
public:
	bool canPartition(vector<int>& nums) {
		if (nums.size() == 1) return false;
		int sum = 0;
		for (auto num : nums) {
			sum += num;
		}
		if ((sum % 2) == 1) return false;

		// find if nums can sum to target (sum/2)
		int target = sum / 2;
		// 1D DP
		vector<bool> dp(target+1, false);
		dp[0] = true;
		for (int i = 0; i < nums.size(); i++) {
			int num = nums[i];
			for (int j = target; j >= num; j--) {
				dp[j] = dp[j] || dp[j - num];
			}
		}
		return dp[target];
	}
};

void test_00416_Partition_Equal_Subset_Sum(void)
{
	Solution s;
	printf("%d\n", s.canPartition(vector<int>{1}));
	printf("%d\n", s.canPartition(vector<int>{1, 2}));
	printf("%d\n", s.canPartition(vector<int>{1, 1}));
	printf("%d\n", s.canPartition(vector<int>{1, 5, 11, 5}));
	printf("%d\n", s.canPartition(vector<int>{1, 2, 3, 5}));
	printf("%d\n", s.canPartition(vector<int>{3, 3, 3, 4, 5}));
	printf("%d\n", s.canPartition(vector<int>{1, 2, 5}));
	printf("%d\n", s.canPartition(vector<int>{2, 2, 3, 5}));
}