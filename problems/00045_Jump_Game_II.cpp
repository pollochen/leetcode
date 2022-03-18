class Solution {
public:
	int jump(vector<int>& nums) {
		int n = nums.size();
        if (n == 1) { return 0; }
		int idx = n - 1;
		int result = 0;
		while (idx != 0) {
			int target = idx;
			for (int i = target - 1; i >= 0; i--) {
				int step = nums[i];
				if (i + step >= target) {
					idx = i;
				}
			}
			result++;
		}
		return result;
	}
};

void test_00045_Jump_Game_II(void)
{
	Solution s;
	printf("%d\n", s.jump(vector<int>{0}));
	printf("%d\n", s.jump(vector<int>{2, 3, 1, 1, 4}));
	printf("%d\n", s.jump(vector<int>{2, 3, 0, 1, 4}));
}