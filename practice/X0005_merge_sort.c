int min(int x, int y)
{
	if (x < y) return x;
	else return y;
}

void merge_sort_iteration(int* nums, int size)
{
	int* a = nums;
	int* b = (int *)malloc(sizeof(int) * size);
	// merge 1, 2, 4, 8,... elements in the array
	for (int seg = 1; seg < size; seg = seg * 2) {
		for (int start = 0; start < size; start += seg * 2) {
			int low  = start;
			int mid  = min(start + seg, size);
			int high = min(start + seg * 2, size);
			int l1 = low;
			int r1 = mid; // list 1 [low, mid-1]
			int l2 = mid;
			int r2 = high; // list 2 [mid, high-1]
			int pos = start;
			// merge list 1 and list 2
			while (l1 < r1 && l2 < r2) {
				if (a[l1] > a[l2]) {
					b[pos++] = a[l2++];
				} else{
					b[pos++] = a[l1++];
				}
			}
			// merge remains in list 1
			while (l1 < r1) {
				b[pos++] = a[l1++];
			}
			// merge remains in list 2
			while (l2 < r2) {
				b[pos++] = a[l2++];
			}
		}
		// swap a and b
		int* tmp = a;
		a = b;
		b = tmp;
	}
	// we need to return nums but the result may be in nums or allocated memory
	if (a != nums) {
		// a points to allocated memory, them b points to nums
		// need to copy a to nums
		for (int i = 0; i < size; i++) {
			nums[i] = a[i];
		}
		// assign b to allocated memory (a)
		b = a;
	}
	free(b);
}

void test_X0005_merge_sort_recursive()
{
	int nums_1[] = { 4, 3, 2, 1, 0 };
	int size_1 = sizeof(nums_1) / sizeof(int);
	print_vector_int(nums_1, size_1);
	int* reg = (int*)malloc(sizeof(int) * size_1);
	merge_sort_recursive(nums_1, reg, 0, size_1 - 1);
	free(reg);
	print_vector_int(nums_1, size_1);
}

void test_X0005_merge_sort_iteration(void)
{
	int nums_1[] = { 4, 3, 2, 1, 0 };
	int size_1 = sizeof(nums_1) / sizeof(int);
	print_vector_int(nums_1, size_1);
	merge_sort_iteration(nums_1, size_1);
	print_vector_int(nums_1, size_1);
}

void test_X0005_merge_sort()
{
	test_X0005_merge_sort_recursive();
	test_X0005_merge_sort_iteration();
}