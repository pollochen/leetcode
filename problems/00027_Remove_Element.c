int removeElement(int* nums, int numsSize, int val){
	if ((nums == NULL) || (numsSize == 0)) {
		return 0;
	}

	int i;
	int count = 0;
	for (i = 0; i < numsSize; i++) {
		if (nums[i] != val) {
    		nums[count++] = nums[i];
		}
	}
	return count;
}