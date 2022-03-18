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