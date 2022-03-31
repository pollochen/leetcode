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
// Runtime: 11 ms, faster than 46.71% of C++ online submissions for Letter Case Permutation.
// Memory Usage: 9.9 MB, less than 79.54% of C++ online submissions for Letter Case Permutation.
class Solution {
public:
    bool is_digit(char ch)
    {
        return ch >= '0' && ch <= '9';
    }
    bool is_uppercase(char ch)
    {
        return ch >= 'A' && ch <= 'Z';
    }
    bool is_lowercase(char ch)
    {
        return ch >= 'a' && ch <= 'z';
    }
    void letter_case_permutation_x(string s, int pos, vector<string> &result)
    {
        if (pos >= s.length()) {
            result.push_back(s);
            return;
        }
        // no loop here....
        char ch = s[pos];
        letter_case_permutation_x(s, pos+1, result);
        if (is_digit(ch) == true) return;
        if (is_uppercase(ch) == true) {
            s[pos] = ch - 'A' + 'a';
        } else {
            s[pos] = ch - 'a' + 'A';
        }
        letter_case_permutation_x(s, pos+1, result);
    }
    vector<string> letterCasePermutation(string s) {
        vector<string> result;
        letter_case_permutation_x(s, 0, result);
        return result;
    }
};

// Runtime: 124 ms, faster than 5.11% of C++ online submissions for Letter Case Permutation.
// Memory Usage: 11.4 MB, less than 43.14% of C++ online submissions for Letter Case Permutation.
class Solution {
public:
    bool is_digit(char ch)
    {
        return ch >= '0' && ch <= '9';
    }
    bool is_uppercase(char ch)
    {
        return ch >= 'A' && ch <= 'Z';
    }
    bool is_lowercase(char ch)
    {
        return ch >= 'a' && ch <= 'z';
    }
    void letter_case_permutation_x(string s, int pos, string out, vector<string> &result)
    {
        if (out.length() == s.length()) {
            result.push_back(out);
            return;
        }
        char ch;
        for (int i = pos; i < s.length(); i++) {
            ch = s[i];
            if (is_digit(ch) == true) {
                letter_case_permutation_x(s, i+1, out + string(1, ch), result);
            } else {
                letter_case_permutation_x(s, i+1, out + string(1, ch), result);
                if (is_uppercase(ch) == true) {
                    ch = ch - 'A' + 'a';
                } else {
                    ch = ch - 'a' + 'A';
                }
                letter_case_permutation_x(s, i+1, out + string(1, ch), result);
            }
        }
    }
    vector<string> letterCasePermutation(string s) {
        vector<string> result;
        string out;
        letter_case_permutation_x(s, 0, out, result);
        return result;
    }
};