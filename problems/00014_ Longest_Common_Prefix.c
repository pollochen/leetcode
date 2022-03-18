char * longestCommonPrefix(char ** strs, int strsSize) {
	if ((strsSize == 0) || (strs == NULL)) {
		return "";
	}

	if (strsSize == 1) {
		return strs[0];
	}

	int i;
	int j;
	int result = 0;
	char *s0 = strs[0];
	char *s_ret = (char *)malloc(strlen(s0)+1);
	strcpy(s_ret, s0);

	for (i = 1; i < strsSize; i++) {
		// for each string, scan it
		char *sx = strs[i];
		int length = strlen(sx);
		for (j = 0; j < length; j++) {
			if (s0[j] != sx[j]) {
				break;
			}
		}
		if (j > 0) {
			if (result == 0) {
				result = j;
			} else if (result > j) {
				result = j;
			}			
		}
		else {
			return "";
		}
	}
	
	s_ret[result] = 0;
	return s_ret;
}