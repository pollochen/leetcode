// https://www.cnblogs.com/cnoodle/p/14344275.html
// Runtime: 12 ms, faster than 100.00 % of C online submissions for Smallest String With A Given Numeric Value.
// Memory Usage : 15.5 MB, less than 37.50 % of C online submissions for Smallest String With A Given Numeric Value.
char * getSmallestString(int n, int k){
	char *result = (char *)malloc(sizeof(char) * (n+1));
	memset(result, 'a', sizeof(char) * (n)); // the initial value would be 'aaaaaaa...aaa'
	result[n] = '\0';
	k -= n; // decrease n since we have 'aaaaaa...aaa'
	for (int i = n - 1; i >= 0; i--) {
		int x = (k > 25) ? 25 : k; // increase from last element
		result[i] += x;
		k -= x;
		if (k == 0) break;
	}
	return result;
}