class Solution {
public:
	bool is_digit(char ch) {
		return (ch >= '0' && ch <= '9');
	}
	bool is_letter(char ch) {
		return (ch >= 'a' && ch <= 'z');
	}
	string get_string(stack<string> &stk)
	{
		string s = "";
		while ((stk.empty() == false) && (is_letter(stk.top()[0]) == true)) {
			s = stk.top() + s;
			stk.pop();
		}
		return s;
	}
	string decodeString(string s) {
		int len = s.length();
		int idx = 0;
		int x_int = 0;
		int level = 0;
		string result = "";
		string x_str;
		stack<string> stk;
		while (idx < len) {
			char ch = s[idx];
			if (is_digit(ch) == true) {
				// digit
				x_int = x_int * 10 + ch - '0';
			} else if (is_letter(ch) == true) {
				// leter 
				stk.push(string(1, ch));
			} 

			if (ch == '[') {
				level++;
				stk.push(to_string(x_int));
				x_int = 0;
			} 
			
			if (ch == ']') {
				level--;
				// stack pop
				string target_str = get_string(stk);
				string tmp_x = stk.top(); stk.pop();
				int t = strtoul(tmp_x.c_str(), NULL, 10);
				string str_push;
				for (int i = 0; i < t; i++) {
					str_push += target_str;
				}
				stk.push(str_push);
			}
			idx++;
		}
		result += get_string(stk);
		return result;
	}
};

void test_00394_Decode_String(void)
{
	Solution s;
	printf("%s\n", s.decodeString("3[a]2[bc]").c_str());
	printf("%s\n", s.decodeString("3[a2[c]]").c_str());
	printf("%s\n", s.decodeString("abc3[cd]xyz").c_str());
	printf("%s\n", s.decodeString("2[abc]3[cd]ef").c_str());
	printf("%s\n", s.decodeString("3[z]2[2[y]pq4[2[jk]e1[f]]]ef").c_str());

}