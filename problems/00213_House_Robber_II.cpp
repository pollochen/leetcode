// Runtime: 3 ms, faster than 54.37 % of C++ online submissions for House Robber II.
// Memory Usage : 7.8 MB, less than 60.08 % of C++ online submissions for House Robber II.
class Solution {
public:
	int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
		int sum1 = rob_x(nums, 0, nums.size() - 2);
		int sum2 = rob_x(nums, 1, nums.size() - 1);
		return max(sum1, sum2);
	}
	int rob_x(vector<int>& nums, int left, int right) {
		int sum = 0;
		int rob = 0;
		int skip = 0;
		for (int i = left; i <= right; i++) {
			int rob_i = max(rob, skip + nums[i]);
			int skip_i = max(skip, rob);
			rob = rob_i;
			skip = skip_i;
		}
		sum = max(rob, skip);
		return sum;
	}
};
// DP with 2 passes
// Runtime: 0 ms, faster than 100.00 % of C++ online submissions for House Robber II.
// Memory Usage : 7.9 MB, less than 41.04 % of C++ online submissions for House Robber II.
class Solution {
public:
	int rob(vector<int>& nums) {
		if (nums.size() == 1) return nums[0];
		if (nums.size() == 2) return max(nums[0], nums[1]);
		// 2 passes
		// 1 pass is pick [0] and the interval would be [0-n-2]
		int sum1 = rob_x(nums, 0, nums.size() - 2);
		// 2 pass is pick [1] and the interval would be [1-n-1]
		int sum2 = rob_x(nums, 1, nums.size() - 1);
		return max(sum1, sum2);
	}
	// dp implementation
	int rob_x(vector<int>& nums, int left, int right) {
		vector<int> dp(right - left + 1);
		dp[0] = nums[left];
		dp[1] = max(nums[left], nums[left + 1]);
		for (int i = 2; i <= right - left; i++) {
			// dp[i] = max(dp[i-1], dp[i-2] + nums[i])
			dp[i] = max(dp[i - 1], dp[i - 2] + nums[i + left]);
		}
		return dp[right - left];
	}
};