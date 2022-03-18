	int minSwaps(char * s) {
		int cnt = 0;
		int open = 0;
		while (*s != '\0') {
			if (*s == '[') {
				cnt++;
			} else if (*s == ']') {
				if (cnt == 0) open++;
				else cnt--;
			}
			s++;
		}
		if (cnt < 0) open += abs(cnt);
		return open / 2 + open % 2;
	}