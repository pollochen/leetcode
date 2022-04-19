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
// DP
// Runtime: 516 ms, faster than 21.62% of C++ online submissions for Jump Game II.
// Memory Usage: 17.2 MB, less than 35.71% of C++ online submissions for Jump Game II.
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, INT_MAX); // min steps in step[i]

        dp[0] = 0;
        // scan from 0
        for (int i = 0; i < n; i++) {
            int x = nums[i];
            // check the min steps for dp[i+1], dp[i+2],...
            for (int j = 1; j <= x; j++) {
                if (i + j < n) {
                    dp[i+j] = min(dp[i+j], dp[i] + 1);
                } else {
                    break;
                }
            }
        }
        return dp[n-1];
    }
};