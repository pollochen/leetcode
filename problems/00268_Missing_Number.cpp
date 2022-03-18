class Solution {
public:
	int missingNumber(vector<int>& nums) {
		int sum1 = 0;
		int size = nums.size();
		for (int i = 0; i < size; i++) {
			sum1 += nums[i];
		}
		int sum2 = ((size) * (size + 1)) / 2;
		return sum2 - sum1;
	}
};