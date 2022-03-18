int lengthOfLongestSubstring(char * s){
	if (s == NULL) return 0;    
    if (*s == '\0') return 0;
	int map[128];
	memset(map, 0, sizeof(map));
	int l = 0;
	int r = 0;
	int result = 1;
	while (s[r] != '\0') {
		char ch = s[r];
		if (map[ch] == 1) {
			// slide l to first position of ch
			while (s[l] != ch) {
				map[s[l]]--;
				l++;
			}
			l++;
		} else {
			map[ch]++;
			// calculate length
			int x = r - l + 1;
			if (x > result) result = x;
		}
		r++;
	}
	return result;
}