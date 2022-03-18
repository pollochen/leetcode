void quicksort_partition(int *nums, int left, int right)
{
    if (left >= right) return;

    int pivot = nums[right]; // pick end as pivot
    int i = left - 1;
    int j;
    int tmp;
    for (j = left; j <= right - 1; j++) {
        if (nums[j] < pivot) {
            // step i
            i++;
            // swap [i, j]
            tmp = nums[i];
            nums[i] = nums[j];
            nums[j] = tmp;
        }
    }

    // step i
    i++;
    // swap pivot with nums[i]
    tmp = nums[right];
    nums[right] = nums[i];
    nums[i]   = tmp;
    // position i is position of pivot
    quicksort_partition(nums, left, i-1); // sort [left] to [pivot -1]
    quicksort_partition(nums, i+1,  right); // sort [pivot + 1] to [right]

}

void quicksort(int *nums, int size)
{
    quicksort_partition(nums, 0, size - 1);
}

void test_quicksort(void)
{
    int nums_1[] = {4, 3, 2, 1, 0};
    int size_1 = sizeof(nums_1) / sizeof(int);
    print_int_array(nums_1, size_1);
    quicksort(nums_1, size_1);
    print_int_array(nums_1, size_1);
}