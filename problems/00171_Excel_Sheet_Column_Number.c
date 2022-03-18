
int titleToNumber(char * columnTitle) {
	int len = strlen(columnTitle);
	int idx = len - 1;
	int base = 26;
	long exp = 1;
	int result = 0;

	while (idx >= 0) {
		char ch = columnTitle[idx];
		int  n = exp * (ch - 'A' + 1);
		result += n;
		exp = exp * base;
		idx--;
	}

	return result;
}