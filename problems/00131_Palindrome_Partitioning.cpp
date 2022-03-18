// https://www.cnblogs.com/grandyang/p/7404777.html
class Solution {
public:
	bool is_palindrome(vector<vector<bool>> &dp, int i, int j) {
		return dp[i][j];
	}
	void partition_dfs(string s, int pos, vector<vector<bool>> &dp, vector<string> &out, vector<vector<string>> &result) {
		int len = s.length();

		if (pos >= len) {
			result.push_back(out);
			return;
		}
		int start = pos;
		for (int i = pos; i < len; i++) {
			if (is_palindrome(dp, start, i) == true) {
				out.push_back(s.substr(start, i - start + 1));
				partition_dfs(s, i+1, dp, out, result);
				out.pop_back();
			}
		}
	}
	vector<vector<string>> partition(string s) {
		int len = s.length();
		vector<vector<string>> result;
		// find all palindrome results of substring
		vector<vector<bool>> dp(len, vector<bool>(len, false));
		for (int i = len - 1; i >= 0; i--) {
			for (int j = i; j < len; j++) {
				if (s[i] == s[j]) {
					if ((j - i) <= 2) { dp[i][j] = true;}
					else if (dp[i + 1][j - 1] == 1) { dp[i][j] = true; }
				}
			}
		}
		vector<string> out;
		partition_dfs(s, 0, dp, out, result);
		return result;
	}
};