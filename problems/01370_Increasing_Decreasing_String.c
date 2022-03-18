
char * sortString(char * s) {
	int map[26] = { 0 };
	int len = strlen(s);
	char *result = (char *)malloc(sizeof(char) * len + 1);
	for (int i = 0; i < len; i++) {
		map[s[i] - 'a']++;
	}
	int i = 0;
	int count = 0;
	while (count < len) {
		if ((i & 1) == 0) {
			// left to right
			for (int k = 0; k < 26; k++) {
				if (map[k] > 0) {
					result[count] = k+'a';
					count++;
					map[k]--;
				}
			}
		} else {
			// right to left
			for (int k = 25; k >= 0; k--) {
				if (map[k] > 0) {
					result[count] = k+'a';
					count++;
					map[k]--;
				}
			}
		}
		i++;
	}
	result[count] = 0;
	return result;
}