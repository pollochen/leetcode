// DP version
// Runtime: 0 ms, faster than 100.00 % of C++ online submissions for Decode Ways.
// Memory Usage : 6.2 MB, less than 72.85 % of C++ online submissions for Decode Ways.
class Solution {
public:
	bool is_valid(string s) {
		if (s[0] == '0') return false;
		if (s.length() == 2) {
			if (s[0] > '2') return false;
			if ((s[0] == '2') && (s[1] > '6')) return false;
		}
		return true;
	}
	int numDecodings(string s) {
		int result = 0;
		int len = s.length();
		vector<int> dp(len + 1, 0);
		// dp[i] = dp[i-1] if "s[i-1]" valid, else 0
		//         +
		//         dp[i-2] if "s[i-2] + s[i-1]" valid, else 0
		// dp[0] = 1
		// dp[1] = 1 if not s0] != 0
		// the result is in dp[len]
		dp[0] = 1;
		if (s[0] != '0') dp[1] = 1;
		for (int i = 2; i <= len; i++) {
			bool x = is_valid(string(1, s[i-1]));
			if (x == true) { dp[i] += dp[i - 1]; }
			x = is_valid(string(1, s[i-2]) + string(1, s[i-1]));
			if (x == true) { dp[i] += dp[i - 2]; }
		}
		return result = dp[len];
	}
};

// TLE version with memorization
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Decode Ways.
// Memory Usage : 7.6 MB, less than 11.72 % of C++ online submissions for Decode Ways.
class Solution {
public:
	bool is_valid(string s) {
		if (s[0] == '0') return false;
		if (s.length() == 2) {
			if (s[0] > '2') return false;
			if ((s[0] == '2') && (s[1] > '6')) return false;
		}
		return true;
	}
	int decode(string s, int length, int pos, vector<int>& mem) {
		if (pos >= length) {
			return 1;
		}

		if (mem[pos] != -1) return mem[pos];

		int res = 0;

		// take 1 char
		bool x = is_valid(string(1, s[pos]));
		if (x == true) {
			res += decode(s, length, pos + 1, mem);
		}
		// take 2 chars
		if ((pos + 1) <= (length - 1)) {
			x = is_valid(string(1, s[pos]) + string(1, s[pos + 1]));
			if (x == true) {
				res += decode(s, length, pos + 2, mem);
			}
		}
		// memory this position
		mem[pos] = res;
		return res;
	}

	int numDecodings(string s) {
		vector<int> mem(s.length(), -1);
		return decode(s, s.length(), 0, mem);
	}
};

// LTE version
class Solution {
public:
	bool is_valid(string s) {
		if (s[0] == '0') return false;
		if (s.length() == 2) {
			if (s[0] > '2') return false;
            if ((s[0] == '2') && (s[1] > '6')) return false;
		}
		return true;
	}    
	void decode(string s, int length, int pos, int &result) {
		if (pos >= length) {
			result++;
			return;
		}
		// take 1 char
		bool x = is_valid(string(1, s[pos]));
		if (x == true) {
			decode(s, length, pos + 1, result);
		}
		// take 2 chars
		if ((pos + 1) <= (length - 1)) {
			x = is_valid(string(1, s[pos]) + string(1, s[pos+1]));
			if (x == true) {
				decode(s, length, pos + 2, result);
			}
		}
	}

	int numDecodings(string s) {
		int result = 0;
		decode(s, s.length(), 0, result);
		return result;
	}
};