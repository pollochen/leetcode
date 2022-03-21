// Runtime: 142 ms, faster than 69.87% of C online submissions for Squares of a Sorted Array.
// Memory Usage: 20 MB, less than 87.91% of C online submissions for Squares of a Sorted Array.
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortedSquares(int* nums, int numsSize, int* returnSize)
{
	int* result = (int*)malloc(sizeof(int) * numsSize);

	*returnSize = numsSize;

	// find a numer >= 0
	int pos;
	int idx = 0;
	int idx_l;
	int idx_r;
	// pos must be [0, numsSize - 1]
	for (pos = 0; pos < numsSize - 1; pos++) {
		if (nums[pos] >= 0) break;
	}

	// adjust pos for like [-1, 2]
	while ((pos - 1) >= 0) {
		if (abs(nums[pos - 1]) < nums[pos]) {
			pos--;
		} else {
			break;
		}
	}

	// fill pos 0
	result[idx++] = nums[pos] * nums[pos];
	idx_l = pos - 1;
	idx_r = pos + 1;
	// check left or right pos
	while (idx_l >= 0 && idx_r < numsSize) {
		if (abs(nums[idx_l]) < nums[idx_r]) {
			result[idx++] = nums[idx_l] * nums[idx_l];
			idx_l--;
		} else {
			result[idx++] = nums[idx_r] * nums[idx_r];
			idx_r++;
		}
	}
	// fill remaining left part
	while (idx_l >= 0) { result[idx++] = nums[idx_l] * nums[idx_l]; idx_l--; }
	// fill remaining right part
	while (idx_r < numsSize) { result[idx++] = nums[idx_r] * nums[idx_r]; idx_r++; }

	return result;
}

void test_00977_Squares_of_a_Sorted_Array(void)
{
	int nums_1[] = {-4, -1, 0, 3, 10};
	int size_1   = sizeof(nums_1) / sizeof(int);
	int result_size;
	int *result = sortedSquares(nums_1, size_1, &result_size);
	print_vector_int(result, result_size);
	free(result);

	int nums_2[] = { -7, -3, 2, 3, 11 };
	int size_2 = sizeof(nums_2) / sizeof(int);
	result_size;
	result = sortedSquares(nums_2, size_2, &result_size);
	print_vector_int(result, result_size);
	free(result);

	int nums_3[] = { 1, 2, 3, 4, 5 };
	int size_3 = sizeof(nums_3) / sizeof(int);
	result_size;
	result = sortedSquares(nums_3, size_3, &result_size);
	print_vector_int(result, result_size);
	free(result);

	int nums_4[] = { -5, 2, 2};
	int size_4 = sizeof(nums_4) / sizeof(int);
	result_size;
	result = sortedSquares(nums_4, size_4, &result_size);
	print_vector_int(result, result_size);
	free(result);

	int nums_5[] = { -1 };
	int size_5 = sizeof(nums_5) / sizeof(int);
	result_size;
	result = sortedSquares(nums_5, size_5, &result_size);
	print_vector_int(result, result_size);
	free(result);

	int nums_6[] = { -1, 2, 2 };
	int size_6 = sizeof(nums_6) / sizeof(int);
	result_size;
	result = sortedSquares(nums_6, size_6, &result_size);
	print_vector_int(result, result_size);
	free(result);

}
