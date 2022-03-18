inline bool is_letter(char ch)
{
	if ((ch >= 'a') && (ch <= 'z')) {
		return true;
	}
	return false;
}

int is_valid_word(char *s)
{
	int len = strlen(s);
	int i = 0;
	int count_hyphen = 0;
	int count_punc = 0;
	while (i < len) {
		if (('0' <= s[i]) && (s[i] <= '9')) {
			return 0;
		}

		if (s[i] == '-') {
			if (count_hyphen == 1) return 0;
			count_hyphen++;
			if ((i == (len - 1)) || (i == 0)) {
				// it must be surrounded by lowercase characters ("a-b" is valid, but "-ab" and "ab-" are not valid).
				return 0;
			}
			if ((is_letter(s[i - 1]) == false) || (is_letter(s[i + 1]) == false)) {
				return false;
			}
		}
		if ((s[i] == '!') || (s[i] == '.') || (s[i] == ',')) {
			if (count_punc == 1) return 0;
			count_punc++;
			if (i != (len - 1)) {
				return 0;
			}
		}
		i++;
	}
	return 1;
}

int countValidWords(char * sentence) {
	char token[1001];
	int count = 0;

	int len = strlen(sentence);
	int idx = 0;
	int i = 0;
	while (sentence[i] != '\0') {
		if (sentence[i] == ' ') {
			if (idx != 0) {
				token[idx] = 0;
				count += is_valid_word(token);
				idx = 0;
			} else {
				// empty token
			}
		} else {
			token[idx++] = sentence[i];
		}
		i++;
	}

	if (idx != 0) {
		//printf("%s idx %d\n", token, idx);
		token[idx] = 0;
		count += is_valid_word(token);
	}

	return count;
}