/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** fizzBuzz(int n, int* returnSize){
	char **result = (char **)malloc(n * sizeof(char *));
	static char *s1 = "FizzBuzz";
	static char *s2 = "Fizz";
	static char *s3 = "Buzz";
	for (int i = 1; i <= n; i++) {
		if ((i % 5) == 0 && (i % 3) == 0) result[i-1] = s1;
		else if ((i % 3) == 0) result[i-1] = s2;
		else if ((i % 5) == 0) result[i-1] = s3;
		else {
			char *s = (char *)malloc(6 * sizeof(char));
			sprintf(s, "%d", i);
			result[i-1] = s;
		}
	}
	*returnSize = n;
	return result;
}