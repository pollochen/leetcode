// Runtime: 7 ms, faster than 7.13 % of C online submissions for Length of Last Word.
// Memory Usage : 5.6 MB, less than 73.15 % of C online submissions for Length of Last Word.
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