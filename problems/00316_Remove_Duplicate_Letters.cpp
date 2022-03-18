class Solution {
public:
	string removeDuplicateLetters(string s) {
		stack<char> stk;
		bool map_exist[26];
		int  map_count[26];

		memset(map_exist, false, sizeof(map_exist));
		memset(map_count, false, sizeof(map_count));

		for (int i = 0; i < s.length(); i++) {
			map_count[s[i] - 'a']++;
		}

		for (int i = 0; i < s.length(); i++) {
			char ch = s[i];
			int  idx_cur = ch - 'a';

			map_count[idx_cur]--;

			// if the char exists in the stack, skip it
			if (map_exist[idx_cur] == true) {
				continue;
			}
			// only pop stack when:
			// 1. stack is not empty
			// 2. stack.top() > current char
			// 3. the count of stack.top() > 0 (means we have chance to push it later)
			while ((stk.empty() == false) && (stk.top() > ch) && map_count[stk.top() - 'a'] > 0) {
				map_exist[stk.top() - 'a'] = false; // mark this letter as not picked
				stk.pop();
			}

			// push this character
			stk.push(ch);
			map_exist[idx_cur] = true; // mark this letter as picked
		}

		string result = "";
		while (stk.empty() == false) {
			result = string(1, stk.top()) + result;
			stk.pop();
		}
		return result;
	}
};

void test_316_Remove_Duplicate_Letters(void)
{
	Solution s;
	printf("%s\n", s.removeDuplicateLetters("abacb").c_str());
	printf("%s\n", s.removeDuplicateLetters("cbacdcbc").c_str());
	printf("%s\n", s.removeDuplicateLetters("bcabc").c_str());
}