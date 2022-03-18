void moveZeroes(int* nums, int numsSize){
	if ((nums == NULL) || (numsSize == 0)) {
		return 0;
	}

	int i;
	int count = 0;
	for (i = 0; i < numsSize; i++) {
		if (nums[i] != 0) {
    		nums[count++] = nums[i];
		}
	}
    for (i = count; i < numsSize; i++) {
        nums[i] = 0;
    }
	return count;
}