int minimumMoves(char * s) {
	int len = strlen(s);
	int idx = 0;
	int count = 0;
	while (idx < len) {
		if (s[idx] == 'X') {
			// "XXX"
			// "XOO"
			// "XXO"
			// "XOX"
			count++;
			idx += 3;
		} else {
			idx++;
		}
	}
	return count;
}