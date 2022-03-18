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