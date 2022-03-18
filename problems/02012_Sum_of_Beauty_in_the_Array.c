

int max(int x, int y)
{
	if (x > y) return x;
	else return y;
}

int min(int x, int y)
{
	if (x > y) return y;
	else return x;
}

int sumOfBeauties(int* nums, int numsSize) {
	int *prefix = (int *)malloc(sizeof(int) * numsSize); // max value before i
	int *sufix  = (int *)malloc(sizeof(int) * numsSize); // min value after i
	int idx;
	prefix[0] = 0;
	sufix[numsSize - 1] = 2000001;

	for (int i = 1; i < (numsSize - 1); i++) {
		// calculate max value before i
		// f(n) = max(f(n-1), nums[i-1])
		prefix[i] = max(prefix[i - 1], nums[i-1]);

		// calculate min value after i (in reverse order)
		// f(n) = min(f(n+1), nums[i+1])
		idx = numsSize - i - 1;
		sufix[idx] = min(sufix[idx+1], nums[idx+1]);
	}

	// calculate value for each node
	int result = 0;
	for (int i = 1; i < (numsSize - 1); i++) {
		if ((prefix[i] < nums[i]) && (nums[i] < sufix[i])) {
			result += 2;
		} else if ((nums[i - 1] < nums[i]) && (nums[i] < nums[i + 1])) {
			result += 1;
		}
	}

	free(prefix);
	free(sufix);
	return result;
}