int cmpfunc(const void * a, const void * b) {
	return (*(int*)a - *(int*)b);
}

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
	int i;

	// put S2 to tail of S1
	for (i = 0; i < n; i++) {
		nums1[i + m] = nums2[i];
	}
	// quick sort S1
	qsort(nums1, m+n, sizeof(int), cmpfunc);
}