class Solution {
public:
	int calPoints(vector<string>& ops) {
		stack<int> stk;
		int x, y;
		for (int i = 0; i < ops.size(); i++) {
			char ch = ops[i][0];
			switch (ch) {
			case 'D':
				x = stk.top() * 2;
				stk.push(x);
				break;
			case 'C':
				stk.pop();
				break;
			case '+':
				x = stk.top(); stk.pop();
				y = stk.top();
				stk.push(x);
				stk.push(x+y);
				break;
			default:
				stk.push(std::stoi(ops[i]));
				break;
			}
		}
		int result = 0;
		while (stk.empty() == false) {
			result = result + stk.top();
			stk.pop();
		}
		return result;
	}
};