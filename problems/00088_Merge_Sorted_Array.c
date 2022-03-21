 
int cmpfunc(const void * a, const void * b) {
	return (*(int*)a - *(int*)b);
}

// append and quick sort
// Runtime: 10 ms, faster than 12.81 % of C online submissions for Merge Sorted Array.
// Memory Usage : 6.3 MB, less than 32.09 % of C online submissions for Merge Sorted Array.
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
	int i;

	// put S2 to tail of S1
	for (i = 0; i < n; i++) {
		nums1[i + m] = nums2[i];
	}
	// quick sort S1
	qsort(nums1, m+n, sizeof(int), cmpfunc);
}

// merge directly
// Runtime: 0 ms, faster than 100.00 % of C online submissions for Merge Sorted Array.
// Memory Usage : 6.1 MB, less than 76.52 % of C online submissions for Merge Sorted Array.
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
	int size = nums1Size;
	int* tmp = (int*)malloc(sizeof(int) * size);

	int l1 = 0;
	int l2 = 0;
	int r1 = m;
	int r2 = n;
	int idx = 0;

	// merge 2 arrays
	while (l1 < r1 && l2 < r2) {
		if (nums1[l1] < nums2[l2]) {
			tmp[idx++] = nums1[l1++]; // use array 1
		} else {
			tmp[idx++] = nums2[l2++]; // use array 2
		}
	}
	// put remaining in array 1
	while (l1 < r1) tmp[idx++] = nums1[l1++];
	// put remaining in array 2
	while (l2 < r2) tmp[idx++] = nums2[l2++];

	// copy tmp back to nums1
	for (int i = 0; i < size; i++) {
		nums1[i] = tmp[i];
	}
	free(tmp);
}