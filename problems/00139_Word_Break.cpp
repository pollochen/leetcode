// https://www.cnblogs.com/grandyang/p/4257740.html
	bool wordBreak(string s, vector<string>& wordDict) {
		unordered_set<string> uset(wordDict.begin(), wordDict.end());
		vector<int> dp(s.length() + 1, false);
		dp[0] = true;
		for (int i = 0; i <= s.length(); i++) {
			for (int pos = 0; pos < i; pos++) {
				// interval [0 - pos] match found
				if (dp[pos] == true) {
					// find if interval [pos - i] match
					string ss = s.substr(pos, i - pos);
					if (uset.count(ss) != 0) {
						dp[i] = true;
						break;
					}
				}
			}
		}
		return dp.back();
	}

class Solution {
public:
	bool work_break_dp(string s, int pos, unordered_set<string> &uset, vector<int> &dp)
	{
		if (pos >= s.length()) return true;
		if (dp[pos] != -1) return dp[pos];
		for (int j = pos; j < s.length(); j++) {
			string ss = s.substr(pos, j - pos + 1);
			if (uset.count(ss) > 0) {
				bool result = work_break_dp(s, j + 1, uset, dp);
				if (result == true) {
					dp[pos] = true;
					return result;
				}
			}
		}
		dp[pos] = 0;
		return false;
	}

	bool wordBreak(string s, vector<string>& wordDict) {
		unordered_set<string> uset(wordDict.begin(), wordDict.end());
		vector<int> dp(s.length()+1, -1);
		return work_break_dp(s, 0, uset, dp);
	}
};

void test_139_Word_Break(void)
{
	Solution s;
	printf("%d\n", s.wordBreak("catsandog", vector<string>{"cats", "dog", "sand", "and", "cat"}));
	printf("%d\n", s.wordBreak("leetcode", vector<string>{"leet", "code"}));
	printf("%d\n", s.wordBreak("applepenapple", vector<string>{"apple", "pen"}));
}