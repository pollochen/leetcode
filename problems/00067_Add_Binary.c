
char* reverseString(char *s)
{
	int head = 0, tail = strlen(s) - 1;
	while (head < tail) {
		char tmp = s[head];
		s[head] = s[tail];
		s[tail] = tmp;

		head++;
		tail--;
	}

	return s;
}

inline int str_to_bin(char ch) {
	static int x[] = { 0, 1 };
	return x[ch - '0'];
}

char * addBinary(char * a, char * b) {
	int len_a = strlen(a);
	int len_b = strlen(b);
	int len_result;
	if (len_a > len_b) len_result = len_a + 2;
	else len_result = len_b + 2;

	char *result = (char *)malloc(sizeof(char) * len_result);

	int idx_a = len_a - 1;
	int idx_b = len_b - 1;
	int idx_result = 0;
	int flag_carry = 0;
	
	while (idx_a >= 0 || idx_b >= 0) {
		int val_a = 0;
		int val_b = 0;
		if (idx_a >= 0) val_a = str_to_bin(a[idx_a]);
		if (idx_b >= 0) val_b = str_to_bin(b[idx_b]);
		int val = val_a + val_b + flag_carry;
		flag_carry = 0;
		if (val >= 2) {
			flag_carry = 1;
			val -= 2;
		}

		result[idx_result++] = val + '0';
		idx_a--;
		idx_b--;
	}
	
	if (flag_carry == 1) {
		result[idx_result++] = '1';
	}

	result[idx_result] = 0;

	reverseString(result);

	return result;
}