// https://www.cnblogs.com/grandyang/p/7404777.html
class Solution {
public:
    int countSubstrings(string s) {
		int len = s.length();
		vector<vector<int>> dp(len, vector<int>(len, 0));
		int result = 0;
		for (int i = len - 1; i >= 0; i--) {
			for (int j = i; j < len ; j++) {
				if (s[i] == s[j]) {
					if ((j - i) <= 2) { dp[i][j] = 1; result++; }
					else if (dp[i + 1][j - 1] == 1) { dp[i][j] = 1; result++; }
				}
			}
		}
		return result;        
    }
};