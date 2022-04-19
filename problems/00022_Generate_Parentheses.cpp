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
// https://leetcode.com/problems/generate-parentheses/solution/
// Approach 2: Backtracking
// Runtime: 4 ms, faster than 73.33% of C++ online submissions for Generate Parentheses.
// Memory Usage: 11.4 MB, less than 80.67% of C++ online submissions for Generate Parentheses.
class Solution {
public:
    void x(int open_cnt, int close_cnt, int n, string &out, vector<string> &result)
    {
        if (out.length() == 2 * n) {
            result.push_back(out);
            return;
        }

        // start from open parenthese
        if (open_cnt < n) {
            out.push_back('(');
            x(open_cnt + 1, close_cnt, n, out, result);
            out.pop_back();
        }

        // check if close_cnt < open_cnt
        if (close_cnt < open_cnt) {
            out.push_back(')');
            x(open_cnt, close_cnt + 1, n, out, result);
            out.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        string out;
        vector<string> result;
        x(0, 0, n, out, result);
        return result;
    }
};