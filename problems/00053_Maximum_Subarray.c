int maxSubArray(int* nums, int numsSize){
	int i;
	int result = INT_MIN, sum = 0;

	if ((numsSize == 0) || (nums == NULL)) {
		return 0;
	}

	for (i = 0; i < numsSize; i++) {
		sum = sum + nums[i];
		if (sum < nums[i] ) {
			sum = nums[i];
		}
		if (sum > result) {
			result = sum;
		}
	}

	return result;
}