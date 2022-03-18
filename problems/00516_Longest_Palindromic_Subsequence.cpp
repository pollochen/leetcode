// https://www.cnblogs.com/grandyang/p/6493182.html
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        if (n == 1) return 1;
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = 1; i < n; i++) {
            dp[i][i] = 1;
            for (int j = i-1; j >= 0; j--) {
                if (s[i] == s[j]) dp[i][j] = dp[i-1][j+1] + 2;
                else dp[i][j] = max(dp[i-1][j], dp[i][j+1]);
            }
        }
        return dp[n-1][0];
    }
};