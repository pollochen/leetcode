void reverseString(char* s, int sSize) {
	char *l = s;
	char *r = s + sSize - 1;
	while (l < r) {
		char tmp = *l;
		*l++ = *r;
		*r-- = tmp;
	}
}
char * reverseWords(char * s) {
	char *result = (char *)malloc(strlen(s) + 1);
	strcpy(result, s);
	char *l = result;
	while (*l != '\0') {
		char *r = l;
		while ((*r != '\0') && (*r != ' ')) {
			r++;
		}
		// do reverse
		reverseString(l, r-l);
		l = r;
		if (*l != '\0') l++;
	}
	return result;
}
