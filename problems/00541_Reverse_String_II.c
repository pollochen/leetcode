void reverseString(char* s, int sSize) {
	char *l = s;
	char *r = s + sSize - 1;
	while (l < r) {
		char tmp = *l;
		*l++ = *r;
		*r-- = tmp;
	}
}

char * reverseStr(char * s, int k) {
	int len = strlen(s);
	char *result = (char *)malloc(len + 1);
	strcpy(result, s);
	char *l = result;
	char *end = result + len;
	while (l < end) {
		// revert first k chars
		if ((l + k) < end) {
			// length ok
			reverseString(l, k);
			l += k;
		} else {
			reverseString(l, end - l);
			l += (end - l);
			break;
		}
		// step k chars
		if ((l + k) < end) {
			// length ok
			l += k;
		} else {
			l += (end - l);
		}
	}
	return result;
}