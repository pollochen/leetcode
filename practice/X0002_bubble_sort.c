void bubble_sort(int* nums, int size)
{
	// i is [0 - size - 2]
	for (int i = 0; i < size - 1; i++) {
		// j is also [0 - size - 2]
		for (int j = 0; j < (size - 1 - i); j++) {
			if (nums[j] > nums[j + 1]) {
				// swap
				swap_int(&nums[j], &nums[j + 1]);
			}
		}
	}
}

void test_X0002_bubble_sort()
{
	int nums_1[] = { 4, 3, 2, 1, 0 };
	int size_1 = sizeof(nums_1) / sizeof(int);
	print_vector_int(nums_1, size_1);
	bubble_sort(nums_1, size_1);
	print_vector_int(nums_1, size_1);
}