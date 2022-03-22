// string copy version
// Runtime: 16 ms, faster than 25.22 % of C online submissions for Reverse Words in a String III.
// Memory Usage : 7.6 MB, less than 5.92 % of C online submissions for Reverse Words in a String III.
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

// no strcpy version
// Runtime: 0 ms, faster than 100.00 % of C online submissions for Reverse Words in a String III.
// Memory Usage : 7.1 MB, less than 16.45 % of C online submissions for Reverse Words in a String III.
char* reverseWords(char* s) {
	char* result = s;
	char* l = result;
	while (*l != '\0') {
		char* r = l;
		while ((*r != '\0') && (*r != ' ')) {
			r++;
		}
		// do reverse
		reverseString(l, r - l);
		l = r;
		if (*l != '\0') l++;
	}
	return result;
}
