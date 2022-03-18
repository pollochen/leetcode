char findTheDifference(char * s, char * t) {
	if (s[0] == '\n') return *t;
	int x = 0;
	int y = 0;
	while (*s != 0) {
		x += (*t - *s); s++; t++;
	}
	x += *t;
	return x;
}