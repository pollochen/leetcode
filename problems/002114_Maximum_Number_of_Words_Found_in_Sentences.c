

int get_word_count(char *sentence) {
	int count = 0;
	int idx = 0;
	int i = 0;
	while (sentence[i] != '\0') {
		if (sentence[i] == ' ') {
			if (idx != 0) {
				count++;
				idx = 0;
			} else {
				// empty token
			}
		} else {
			idx++;
		}
		i++;
	}

	if (idx != 0) {
		//printf("%s idx %d\n", token, idx);
		count++;
	}

	return count;
}

int mostWordsFound(char ** sentences, int sentencesSize) {
	int result = 0;
	for (int i = 0; i < sentencesSize; i++) {
		int count = get_word_count(sentences[i]);
		if (count > result) {
			result = count;
		}
	}
	return result;
}