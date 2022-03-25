// sort and check
// Runtime: 5 ms, faster than 53.91% of C online submissions for Can Make Arithmetic Progression From Sequence.
// Memory Usage: 6.3 MB, less than 49.22% of C online submissions for Can Make Arithmetic Progression From Sequence.
void swap_int(int *x, int *y)
{
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

void quick_sort(int *nums, int left, int right)
{
    if (left >= right) return;

    // pick right as pivot
    int pivot = nums[right];
    int idx = left - 1;
    for (int i = left; i < right; i++) {
        if (nums[i] < pivot) {
            idx++;
            swap_int(&nums[i], &nums[idx]);
        }
    }
    idx++;
    swap_int(&nums[right], &nums[idx]);
    quick_sort(nums, left, idx - 1);
    quick_sort(nums, idx + 1, right);
}

bool canMakeArithmeticProgression(int* arr, int arrSize){
    quick_sort(arr, 0, arrSize - 1);

    int diff = arr[1] - arr[0];
    for (int i = 2; i < arrSize; i++) {
        if ((arr[i] - arr[i-1]) != diff) {
            return false;
        }
    }
    return true;
}

void test_01502_Can_Make_Arithmetic_Progression_From_Sequence(void)
{
    int nums1[] = {3, 5, 1};
    int nums2[] = {1, 2, 4};
    printf("%d\n", canMakeArithmeticProgression(nums1, 3));
    printf("%d\n", canMakeArithmeticProgression(nums2, 3));
    printf("%d\n", canMakeArithmeticProgression(nums2, 2));
}
