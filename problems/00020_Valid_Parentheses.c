
// stack
// Runtime: 0 ms, faster than 100.00 % of C online submissions for Valid Parentheses.
// Memory Usage : 5.5 MB, less than 78.63 % of C online submissions for Valid Parentheses.
bool isValid(char * s){
	int length = strlen(s);
	char stack[10000];
	char ch_pop;
	int idx_stack = 0;
	int i;
	for (i = 0; i < length; i++) {
		switch (s[i]) {
		case '[':
		case '{':
		case '(':
			// push
			stack[idx_stack] = s[i];
			idx_stack++;
			break;
		case ']':
		case '}':
		case ')':
			// pop
			if (idx_stack == 0) {
				return false;
			}
			else {
				ch_pop = stack[idx_stack-1];
				idx_stack--;
				if ((ch_pop == '[') && (s[i] != ']')) {
					return false;
				}
				if ((ch_pop == '{') && (s[i] != '}')) {
					return false;
				}
				if ((ch_pop == '(') && (s[i] != ')')) {
					return false;
				}
			}
			break;
		default:
			break;
		}
	}
	// check if there is any left
	if (idx_stack != 0) {
		return false;
	}
    return true;
}