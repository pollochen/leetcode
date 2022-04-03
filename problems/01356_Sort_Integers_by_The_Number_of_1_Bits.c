// https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits/discuss/1892914/C-Easy-Qsort-O(nlogn)-90
// Runtime: 19 ms, faster than 92.22% of C online submissions for Sort Integers by The Number of 1 Bits.
// Memory Usage: 8.1 MB, less than 37.78% of C online submissions for Sort Integers by The Number of 1 Bits.
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void swap_int(int *x, int *y)
{
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

int bit_1_count(int num)
{
    int result = 0;
    while (num > 0) {
        if (num & 1) result++;
        num = num >> 1;
    }
    return result;
}

void quick_sort(int *bits, int *result, int left, int right)
{
    if (left >= right) return;
    int pivot = bits[right];
    int idx = left-1;
    for (int i = left; i < right; i++) {
        // bit count is smaller or (bit count is same and number is smaller)
        if ((bits[i] < pivot) || ((bits[i] == pivot) && (result[i] < result[right]))) {
            idx++;
            swap_int(&bits[idx], &bits[i]);
            swap_int(&result[idx], &result[i]);
        }
    }

    idx++;
    swap_int(&bits[idx], &bits[right]);
    swap_int(&result[idx], &result[right]);
    quick_sort(bits, result, left, idx-1);
    quick_sort(bits, result, idx+1, right);
}

int* sortByBits(int* arr, int arrSize, int* returnSize){
    int *result = (int *)malloc(sizeof(int) * arrSize);
    int *bits   = (int *)malloc(sizeof(int) * arrSize);
    *returnSize = arrSize;

    memcpy(result, arr, sizeof(int) * arrSize);
    // calculate bits for each element
    for (int i = 0; i < arrSize; i++) {
        bits[i] = bit_1_count(arr[i]);
    }
    // sort by bits
    quick_sort(bits, result, 0, arrSize - 1);
    free(bits);
    return result;
}

void test_01356_Sort_Integers_by_The_Number_of_1_Bits(void)
{
    int nums1[] = {0,1,2,3,4,5,6,7,8};
    int nums2[] = {1024,512,256,128,64,32,16,8,4,2,1};
    int ret;
    print_int_array(sortByBits(nums1, sizeof(nums1)/sizeof(int), &ret), sizeof(nums1)/sizeof(int));
    print_int_array(sortByBits(nums2, sizeof(nums2)/sizeof(int), &ret), sizeof(nums2)/sizeof(int));
}