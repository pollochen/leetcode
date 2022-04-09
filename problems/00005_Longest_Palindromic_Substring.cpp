// https://leetcode.com/problems/longest-palindromic-substring/solution/
// dp
// Runtime: 607 ms, faster than 18.74% of C++ online submissions for Longest Palindromic Substring.
// Memory Usage: 30.2 MB, less than 31.32% of C++ online submissions for Longest Palindromic Substring.
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        int max_len = 1;
        int start = 0;
        int end = 0;
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for (int row = n-1; row >= 0; row--) {
            dp[row][row] = true;
            for (int col = row + 1; col < n; col++) {
                if ((col - row) == 1){
                    if (s[col] == s[row]) dp[row][col] = true;
                } else {
                    if (s[col] == s[row] && dp[row+1][col-1] == true) {
                        dp[row][col] = true;
                    }
                }
                if (dp[row][col] == true) {
                    int len = col - row + 1;
                    if (len > max_len) {
                        max_len = len;
                        start = row;
                        end = col;
                    }
                }
            }
        }
        return s.substr(start, max_len);
    }
};

// dp with optimization
// Runtime: 329 ms, faster than 34.83% of C++ online submissions for Longest Palindromic Substring.
// Memory Usage: 29.9 MB, less than 37.80% of C++ online submissions for Longest Palindromic Substring.
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        int max_len = 1;
        int start = 0;
        int len;
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for (int row = n-1; row >= 0; row--) {
            dp[row][row] = true;
            for (int col = row + 1; col < n; col++) {
                if ((s[col] == s[row]) && (((col - row) == 1) || (dp[row+1][col-1] == true))) {
                    dp[row][col] = true;                    
                    len = col - row + 1;
                    if (len > max_len) {
                        max_len = len;
                        start = row;
                    }
                }             
            }
        }
        return s.substr(start, max_len);
    }
};