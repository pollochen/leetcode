class Solution {
public:
	vector<int> productExceptSelf(vector<int>& nums) {
		int size = nums.size();
		vector<int> result(nums.size());
		long x = 1;
		// do multiply from i to 0
		for (int i = size - 1; i >= 1; i--) {
			x = x * nums[i];
			result[i] = x;
		}
		result[0] = result[1];

		x = nums[0];
		// do multiply from 0 to i
		for (int i = 1; i < nums.size() - 1; i++) {
			result[i] = x * result[i + 1];
			x = x * nums[i];
		}
		result[nums.size() - 1] = x;
		return result;
	}
};