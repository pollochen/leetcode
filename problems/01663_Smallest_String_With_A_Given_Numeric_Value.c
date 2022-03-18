// https://www.cnblogs.com/cnoodle/p/14344275.html
char * getSmallestString(int n, int k){
	char *result = (char *)malloc(sizeof(char) * (n+1));
	memset(result, 'a', sizeof(char) * (n));
	result[n] = '\0';
	k -= n;
	for (int i = n - 1; i >= 0; i--) {
		int x = (k > 25) ? 25 : k;
		result[i] += x;
		k -= x;
		if (k == 0) break;
	}
	return result;
}