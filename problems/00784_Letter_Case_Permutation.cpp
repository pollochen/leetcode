class Solution {
public:
	void dfs(string s, int size, int pos, string out, vector<string> &result) {
		if (pos == size) {
			result.push_back(out);
			return;
		}
		char ch = s[pos];
		dfs(s, size, pos + 1, out + ch, result);
		if (ch >= 'a' && ch <= 'z') {
			dfs(s, size, pos + 1, out + string(1, ch - 'a' + 'A'), result);
		} else if (ch >= 'A' && ch <= 'Z') {
			dfs(s, size, pos + 1, out + string(1, ch - 'A' + 'a'), result);
		}
	}
	vector<string> letterCasePermutation(string s) {
		vector<string> result;
		dfs(s, s.length(), 0, "", result);
		return result;
	}
};