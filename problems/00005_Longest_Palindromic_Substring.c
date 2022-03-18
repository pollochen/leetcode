int expand_check(char *s, int left, int right, int len) {
	if (s[left] != s[right]) return 0;
	if (right >= len) return 0;
	int ret = right - left + 1;

	left--;
	right++;

	while ((left >= 0 && right < len) && (s[left] == s[right]))  {
		left--;
		right++;
		ret += 2;
	}
	return ret;
}

char * longestPalindrome(char * s) {
	int len = strlen(s);
	int max = INT_MIN;
	int l, r;

	if (len == 1) return s;

	char *sret = (char *)malloc((len+1) * sizeof(char));
	memcpy(sret, s, len+1);

	for (int i = 0; i < len; i++) {
		int x1 = expand_check(s, i, i, len);
		int x2 = expand_check(s, i, i+1, len);
		if (x1 > max) {
			l = i - (x1 / 2);
			r = l + x1;
			max = x1;
		}
		if (x2 > max) {
			l = i - ((x2 / 2) - 1);
			r = l + x2;
			max = x2;
		}
	}
	sret[r] = 0;
	return &sret[l];
}