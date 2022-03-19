void insertion_sort(int *nums, int size)
{
	int key;
	int j;
	// pick from [i, size - 1]
	for (int i = 1; i < size; i++) {
		// select num[i]
		key = nums[i];
		// check [i - 1, 0]
		j = i - 1;
		while (j >= 0 && nums[j] > key) {
			// if nums[j] is larger than key
			// we need to move num[j] to num[j+1]
			nums[j + 1] = nums[j];
			j--;
		}
		// target index would be [j+1]
		nums[j + 1] = key;
	}
}

void insertion_sort(int *nums, int size)
{
	int key;
	int i;
	int j;
	for (i = 1; i < size; i++) {
		key = nums[i];
		j = i - 1;
		for (j = i - 1; j >= 0; j--) {
			if (nums[j] > key) {
				nums[j + 1] = nums[j];
			} else {
				// reaching here means end
				break;
			}
		}
		nums[j + 1] = key;
	}
}

void test_X0004_insertion_sort()
{
	int nums_1[] = { 4, 3, 2, 1, 0 };
	int size_1 = sizeof(nums_1) / sizeof(int);
	print_vector_int(nums_1, size_1);
	insertion_sort(nums_1, size_1);
	print_vector_int(nums_1, size_1);
}