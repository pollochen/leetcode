class Solution {
public:
	bool backspaceCompare(string s, string t) {
		stack<char> stk1, stk2;
		reduce(s, stk1);
		reduce(t, stk2);
		if (stk1.size() != stk2.size()) return false;
		while (stk1.empty() == false) {
			if (stk1.top() != stk2.top()) return false;
			stk1.pop();
			stk2.pop();
		}
		return true;
	}
	void reduce(string s, stack<char> &stk) {
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '#') {
				if (stk.size() > 0) stk.pop();
			}
			else stk.push(s[i]);
		}
		return;
	}
};