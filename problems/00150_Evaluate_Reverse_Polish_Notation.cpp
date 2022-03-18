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