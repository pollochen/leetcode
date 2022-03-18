int strStr(char * haystack, char * needle) {
	if ((needle == NULL) || (haystack == NULL)) {
		return -1;
	}
	
	int len_needle = strlen(needle);
	int len_haystack = strlen(haystack);
	if (len_needle == 0) {
		return 0;
	}

	if (len_haystack == 0) {
		return -1;
	}
	
	int i, j;
	for (i = 0; i < len_haystack; i++) {
		if (haystack[i] == needle[0]) {
			// match first char
			if ((len_haystack - i) >= len_needle) {
				// only match when remain haystack size is large enough
				for (j = 0; j < len_needle; j++) {
					if (haystack[j + i] != needle[j]) {
						break;
					}
				}
				if (j == len_needle) {
					return i;
				}
			}
		}
	}

	return -1;
}