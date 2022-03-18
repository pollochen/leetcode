int get_exist(char *pattern, char *word)
{
	char *s = strstr(word, pattern);
	if (s != NULL) return 1;
	else return 0;
}

int numOfStrings(char ** patterns, int patternsSize, char * word) {
	int result = 0;
	for (int i = 0; i < patternsSize; i++) {
		result += get_exist(patterns[i], word);
	}
	return result;
}