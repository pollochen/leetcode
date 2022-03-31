// Runtime: 9 ms, faster than 6.01 % of C++ online submissions for House Robber.
// Memory Usage : 7.6 MB, less than 76.02 % of C++ online submissions for House Robber.
class Solution {
public:
    int rob(vector<int>& nums) {
        int sum = 0;
        int rob = 0;
        int skip = 0;
        for (int i = 0; i < nums.size(); i++) {
            int rob_i = max(rob, skip + nums[i]);
            int skip_i = max(skip, rob);
            rob = rob_i;
            skip = skip_i;
        }
        sum = max(rob, skip);
        return sum;
    }
};

// DP,  dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
// Runtime: 4 ms, faster than 34.71 % of C++ online submissions for House Robber.
// Memory Usage : 7.9 MB, less than 6.73 % of C++ online submissions for House Robber.
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 0);

        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);

        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < n; i++) {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        return dp[n - 1];
    }
};