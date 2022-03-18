int lengthOfLastWord(char * s) {
	int length = strlen(s);
	int i;
	int count = 0;
	if ((s == NULL) || (length == 0)) {
		return 0;
	}
	for (i = length - 1; i >= 0; i--) {
		if (s[i] != ' ') {
			count++;
		} else {
			if (count != 0) {
				break;
			}
		}
	}
	return count;
}