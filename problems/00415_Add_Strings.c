// Runtime: 3 ms, faster than 64.10% of C online submissions for Add Strings.
// Memory Usage : 5.8 MB, less than 98.72 % of C online submissions for Add Strings.
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

char * addStrings(char * num1, char * num2) {
	int len_1 = strlen(num1);
	int len_2 = strlen(num2);
	int len_result;

	if (len_1 > len_2) len_result = len_1 + 2;
	else len_result = len_2 + 2;

	char *result = (char *)malloc(sizeof(char) * len_result);
	int idx_1 = len_1-1;
	int idx_2 = len_2-1;
	int idx_result = 0;
	int flag_carry = 0;

	while ((idx_1 >= 0) || (idx_2 >= 0)) {
		int val_a = 0;
		int val_b = 0;
		
		if (idx_1 >= 0) val_a = num1[idx_1] - '0';
		if (idx_2 >= 0) val_b = num2[idx_2] - '0';

		int val = val_a + val_b + flag_carry;
		flag_carry = 0;
		if (val >= 10) {
			val -= 10;
			flag_carry = 1;
		}
		result[idx_result++] = val + '0';
		idx_1--;
		idx_2--;
	}
	if (flag_carry == 1) {
		result[idx_result++] = '1';
	}
	result[idx_result] = 0;

	reverseString(result);
	return result;
	
}