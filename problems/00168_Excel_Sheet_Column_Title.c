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

char * convertToTitle(int columnNumber) {
	char *result = (char *)malloc(sizeof(char)*100);
	int base = 26;
	int x = columnNumber;
	int idx = 0;

	while (x != 0) {
		int a = x % base;
		if (a == 0) {
			x = (x / base) - 1;
			result[idx++] = 'Z';
		} else {
			x = x / base;
			result[idx++] = a + 'A' - 1;
		}
	}

	result[idx] = 0;

	// reverse string
	reverseString(result);

	return result;
}
