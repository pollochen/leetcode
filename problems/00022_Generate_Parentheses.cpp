// https://www.cnblogs.com/grandyang/p/4444160.html
class Solution {
public:
	void dfs(int l, int r, string out, vector<string> &result) {
		if (l > r) return;// invalid case, '(' < ')' like ())
		if (l == 0 && r == 0) {
			// valid case
			result.push_back(out);
			return;
		}
		if (l > 0) dfs(l - 1, r, out + string(1, '('), result);
		if (r > 0) dfs(l, r - 1, out + string(1, ')'), result);
	}
	vector<string> generateParenthesis(int n) {
		vector<string> result;
		dfs(n, n, "", result);
		return result;
	}
};