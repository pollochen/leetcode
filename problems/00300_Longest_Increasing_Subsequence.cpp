// https://www.cnblogs.com/grandyang/p/4938187.html
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int result = 0;
        vector<int> dp(n, 1);
        for (int i = 0; i < n; i++) {
            // scan interval [0, 0], [0, 1], .... [0, n-1]
            for (int j = 0; j < i; j ++) {
                // we need to compare [0, ....i-1]
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[j] + 1, dp[i]);
                }
            }
            // dp[n-1] might not have maximum value, we need to check every dp[i]
            result = max(dp[i], result);
        }
        return result;
    }
};

vector<int> int_array_to_vector(int *nums, int count)
{
    vector<int> result;
    for (int i = 0; i < count; i++) {
        result.push_back(nums[i]);
    }
    return result;
}

void test_300_Longest_Increasing_Subsequence(void)
{
    int nums_1[] = {0,3,1,6,2,2,7};
    int nums_2[] = {10,9,2,5,3,7,101,18};
    int nums_3[] = {7,7,7,7,7,7,7};
    int nums_4[] = {1,3,6,7,9,4,10,5,6};
    Solution s;
    printf("%d\n", s.lengthOfLIS(int_array_to_vector(nums_1, sizeof(nums_1) / sizeof(int))));
    printf("%d\n", s.lengthOfLIS(int_array_to_vector(nums_2, sizeof(nums_2) / sizeof(int))));
    printf("%d\n", s.lengthOfLIS(int_array_to_vector(nums_3, sizeof(nums_3) / sizeof(int))));
    printf("%d\n", s.lengthOfLIS(int_array_to_vector(nums_4, sizeof(nums_4) / sizeof(int))));
}