int searchInsert(int* nums, int numsSize, int target) {
	if ((nums == NULL) || (numsSize == 0)) {
		return 0;
	}

	int idx_lb = 0, idx_ub = numsSize - 1;
	int index = -1;
	while (idx_lb <= idx_ub) {
		index = (idx_lb + idx_ub) / 2;
		if (nums[index] == target) {
			return index;
		} else if (nums[index] < target) {
			idx_lb = index + 1;
		} else {
			idx_ub = index - 1;
		}
	}
	return idx_lb;
}