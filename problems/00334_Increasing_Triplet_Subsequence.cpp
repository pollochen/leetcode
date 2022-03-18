// https://www.cnblogs.com/grandyang/p/5194599.html
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        int m1 = INT_MAX;
        int m2 = INT_MAX;
        for (int i = 0; i < n; i++) {
            int x = nums[i];
            if (m1 >= x) m1 = x;
            else if (m2 >= x) m2 = x;
            else return true;
        }
        return false;
    }
};

// TLE version
    bool increasingTriplet(vector<int>& nums) {
        vector<int> dp(n, 1);
        for (int i = 0; i < n; i++) {
            // scan interval [0, 0], [0, 1], .... [0, n-1]
            for (int j = 0; j < i; j++) {
                // we need to compare [0, ....i-1] with [i]
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[j] + 1, dp[i]);
                }
            }
            if (dp[i] >= 3) {
                return true;
            }
        }
        return false;
        return false;
    }

void test_00334_Increasing_Triplet_Subsequence(void)
{
    int nums_1[] = {1,2,3,4,5};
    int nums_2[] = {5,4,3,2,1};
    int nums_3[] = {2,1,5,0,4,6};
    int nums_4[] = {1,3,6,7,9,4,10,5,6};
    Solution s;
    printf("%d\n", s.increasingTriplet(int_array_to_vector(nums_1, sizeof(nums_1) / sizeof(int))));
    printf("%d\n", s.increasingTriplet(int_array_to_vector(nums_2, sizeof(nums_2) / sizeof(int))));
    printf("%d\n", s.increasingTriplet(int_array_to_vector(nums_3, sizeof(nums_3) / sizeof(int))));
    printf("%d\n", s.increasingTriplet(int_array_to_vector(nums_4, sizeof(nums_4) / sizeof(int))));

}