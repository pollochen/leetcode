int maximumDifference(int* nums, int numsSize) {
	int min = INT_MAX;
	int max = INT_MIN;
	for (int i = 0; i < numsSize; i++) {
		if (nums[i] < min) {
			min = nums[i];
		} else {
			int diff = nums[i] - min;
			if ((diff > 0) && (diff > max)) {
				max = diff;
			}
		}
	}
	if (max < 0) {
		max = -1;
	}
	return max;
}