void selection_sort(int* nums, int size)
{
	// i is [0, size - 2]
	for (int i = 0; i < size - 1; i++) {
		int min_idx = i;
		// j is [i + 1, size -1]
		// find minimal value in [i + 1, size - 1]
		for (int j = i + 1; j < size; j++) {
			if (nums[j] < nums[min_idx]) {
				min_idx = j;
			}
		}
		// swap [i]  and [min_idx]
		swap_int(&nums[i], &nums[min_idx]);
	}
}
void test_X0003_selection_sort()
{
	int nums_1[] = { 4, 3, 2, 1, 0 };
	int size_1 = sizeof(nums_1) / sizeof(int);
	print_vector_int(nums_1, size_1);
	selection_sort(nums_1, size_1);
	print_vector_int(nums_1, size_1);
}