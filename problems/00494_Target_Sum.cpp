// https://leetcode.com/problems/target-sum/solution/
// faster version (52.20%), recursion with memorization
class Solution {
public:
	int divide(vector<int>& nums, int start, int sum, int target, vector<vector<int>> &mem, int base) {
		int idx = sum + base;

		if (start == nums.size()) {
			if (sum == target) {
				return 1;
			} else {
				return 0;
			}
		}

		if (mem[start][idx] != INT_MIN) {
			return mem[start][idx];
		}

		int cnt_plus  = divide(nums, start + 1, sum + nums[start], target, mem, base);
		int cnt_minus = divide(nums, start + 1, sum - nums[start], target, mem, base);
		int ret = cnt_plus + cnt_minus;
		mem[start][idx] = ret;
		return ret;
	}

	int findTargetSumWays(vector<int>& nums, int target) {
		int size = nums.size();
		int sum = 0;
		for (auto num : nums) sum += num;
		vector<vector<int>> mem(size, vector<int>(sum * 2 + 1, INT_MIN));
		return divide(nums, 0, 0, target, mem, sum);
	}
};

// slow version (11.36%)
class Solution {
public:
	int divide(vector<int>& nums, int start, int sum, int target) {
		if (start == nums.size()) {
			if (sum == target) {
				return 1;
			} else {
				return 0;
			}
		}

		int cnt_plus  = divide(nums, start + 1, sum + nums[start], target);
		int cnt_minus = divide(nums, start + 1, sum - nums[start], target);
		return cnt_plus + cnt_minus;
	}

	int findTargetSumWays(vector<int>& nums, int target) {
		return divide(nums, 0, 0, target);
	}
};