// https://www.cnblogs.com/grandyang/p/4028713.html
class Solution {
public:
	int maxProduct(vector<int>& nums) {
		int result = nums[0]; // one element is ok
		int f[20001]; // max
		int g[20001]; // min

		if (nums.size() == 1) return nums[0];

		f[0] = g[0] = nums[0];

		for (int i = 1; i < nums.size(); i++) {
			f[i] = max(max(f[i - 1] * nums[i], g[i - 1] * nums[i]), nums[i]);
			g[i] = min(min(f[i - 1] * nums[i], g[i - 1] * nums[i]), nums[i]);
			result = max(f[i], result);
		}
		return result;
	}
};

void test_152_Maximum_Product_Subarray(void)
{
	Solution s;
	printf("%d\n", s.maxProduct(vector<int>{2, -1, 1, 1}));
	printf("%d\n", s.maxProduct(vector<int>{-1, -2, -9, -6}));
	printf("%d\n", s.maxProduct(vector<int>{2, 3, -2, 4}));
	printf("%d\n", s.maxProduct(vector<int>{-2, 0 ,-1}));
}