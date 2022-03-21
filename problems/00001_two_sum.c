/**
* Note: The returned array must be malloced, assume caller calls free().
*/

// brute force
// Runtime: 116 ms, faster than 65.83 % of C online submissions for Two Sum.
// Memory Usage : 6.6 MB, less than 27.49 % of C online submissions for Two Sum.
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {

	int i, j;
	int *result_array = (int *)malloc(sizeof(int) * 2);

	*returnSize = 0;

	if ((nums != NULL) && (numsSize >= 2)) {
		for (i = 0; i < (numsSize - 1); i++) {
			for (j = (i + 1); j < numsSize; j++) {
				if ((nums[i] + nums[j]) == target) {
					result_array[0] = i;
					result_array[1] = j;
					*returnSize = 2;
					return result_array;
				}
			}
		}
	}
	return result_array;
}