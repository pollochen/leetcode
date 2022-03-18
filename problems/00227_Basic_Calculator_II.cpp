// https://leetcode.com/problems/basic-calculator-ii/solution/
class Solution {
public:
	bool is_digit(char ch) {
		return (ch <= '9') && (ch >= '0');
	}
	int calculate(string s) {
		int pos = 0;
		long x = 0;
		long y;
		char operation = '+'; // first operation is +
		stack<long> stk;
		while (s[pos] != '\0') {
			char ch = s[pos];
			if (is_digit(ch) == true) {
				x = x * 10 + ch - '0';
			}

			if ((is_digit(ch) == false && ch != ' ') || (pos == s.length() - 1)) {
				// process
				switch (operation) { // check current operation
				case '+': stk.push(x); break;
				case '-': stk.push(-x); break;
				case '*':
					y = stk.top();
					stk.pop();
					stk.push(y * x);
					break;
				case '/':
					y = stk.top();
					stk.pop();
					stk.push(y / x);
					break;
				default:
					break;
				}
				operation = ch; // save next operation
				x = 0;
			} else {
				
			}
			pos++;
		}
		int result = 0;
		// sum all values in stack
		while (stk.empty() == false) {
			result += stk.top();
			stk.pop();
		}
		return result;
	}
};

void test_227_Basic_Calculator_II(void)
{
	Solution s;
	printf("%d\n", s.calculate("3+2*2"));
	printf("%d\n", s.calculate("3 /2 "));
	printf("%d\n", s.calculate(" 3+5 / 2 "));
}