// stack
// Runtime: 7 ms, faster than 95.24 % of C++ online submissions for Evaluate Reverse Polish Notation.
// Memory Usage : 11.9 MB, less than 89.01 % of C++ online submissions for Evaluate Reverse Polish Notation.
class Solution {
public:
	int evalRPN(vector<string>& tokens) {
		stack<int> stk;

		for (int i = 0; i < tokens.size(); i++) {
			string s = tokens[i];
			if (s == "+") {
				int y = stk.top(); stk.pop();
				int x = stk.top(); stk.pop();
				stk.push(x + y);
			} else if (s == "-") {
				int y = stk.top(); stk.pop();
				int x = stk.top(); stk.pop();
				stk.push(x - y);
			} else if (s == "*") {
				int y = stk.top(); stk.pop();
				int x = stk.top(); stk.pop();
				stk.push(x * y); 
			} else if (s == "/") {
				int y = stk.top(); stk.pop();
				int x = stk.top(); stk.pop();
				stk.push(x / y);
			} else {
				int x = strtol(s.c_str(), NULL, 10);
				stk.push(x);
			}
		}
		int result = stk.top(); stk.pop();
		return result;
	}
};