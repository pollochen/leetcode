// Runtime: 89 ms, faster than 80.07 % of C online submissions for Move Zeroes.
// Memory Usage : 15 MB, less than 98.81 % of C online submissions for Move Zeroes.
void moveZeroes(int* nums, int numsSize){
	if ((nums == NULL) || (numsSize == 0)) {
		return;
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
	return;
}