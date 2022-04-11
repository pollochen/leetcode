// Runtime: 6 ms, faster than 11.19 % of C++ online submissions for Letter Combinations of a Phone Number.
// Memory Usage : 6.5 MB, less than 59.44 % of C++ online submissions for Letter Combinations of a Phone Number.
class Solution {
public:
	void dfs(string digits, int pos, string out, vector<string> &result) {
		static int idx_pos[8] = {0, 3, 6, 9, 12, 15, 19, 22};
		static int idx_size[8] = {3, 3, 3, 3,  3,  4,  3,  4};
		char idx = (digits[pos] - '2');
		int ch = 'a' + idx_pos[idx];
		int size = idx_size[idx];
		if (pos == (digits.length() - 1)) {
			// last 
			for (int i = 0; i< size; i++) {
				result.push_back(out + string(1, ch+i)); // 'a', 'b', 'c' for '2'
			}
			return;
		}

		pos++;
		for (int i = 0; i< size; i++) {
			dfs(digits, pos, out + string(1, ch+i), result);
		}
	}

	vector<string> letterCombinations(string digits) {
		vector<string> result;
		if (digits.length() == 0) return result;
		dfs(digits, 0, "", result);
		return result;
	}
};

// refined version
// Runtime: 2 ms, faster than 41.79 % of C++ online submissions for Letter Combinations of a Phone Number.
// Memory Usage : 6.6 MB, less than 35.43 % of C++ online submissions for Letter Combinations of a Phone Number.
class Solution {
public:
	void dfs(string digits, int pos, string out, vector<string>& result) {
		static vector<vector<char>> table = {
			{'a', 'b', 'c'},
			{'d', 'e', 'f'},
			{'g', 'h', 'i'},
			{'j', 'k', 'l'},
			{'m', 'n', 'o'},
			{'p', 'q', 'r', 's'},
			{'t', 'u', 'v'},
			{'w', 'x', 'y', 'z'}
		};

		if (pos == digits.size()) {
			result.push_back(out);
			return;
		}

		int idx = (digits[pos] - '2');
		vector<char> &x = table[idx];
		for (int i = 0; i < x.size(); i++) {
			out.push_back(x[i]);
			dfs(digits, pos + 1, out, result);
			out.pop_back();
		}
	}
	vector<string> letterCombinations(string digits) {
		vector<string> result;
		if (digits.length() == 0) return result;
		dfs(digits, 0, "", result);
		return result;
	}
};