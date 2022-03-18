int removeDuplicates(int* nums, int numsSize){
	int i;
	int result = 0;
	int value_cur;
	int idx_cur;

	if ((nums == NULL) || (numsSize == 0)) {
		return 0;
	}

	value_cur = nums[0];
	idx_cur = 0;

	for (i = 1; i < numsSize; i++) {
		if (nums[i] != value_cur) {
			value_cur = nums[i];
			idx_cur++;
			nums[idx_cur] = value_cur;
		}
	}
	return idx_cur + 1;
}