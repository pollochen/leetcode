// quick sort n log(n)
// Runtime: 4 ms, faster than 50.74% of C online submissions for Sort Colors.
// Memory Usage: 6 MB, less than 72.73% of C online submissions for Sort Colors.
void swap_int(int* x, int* y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

void quick_sort(int *nums, int l, int r)
{
    if (l >= r) return;
    int pivot = nums[r];
    int idx = l;
    for (int i = l; i < r; i++) {
        if (nums[i] < pivot) {
            swap_int(&nums[i], &nums[idx]);
            idx++;
        }
    }
    swap_int(&nums[r], &nums[idx]);
    quick_sort(nums, l, idx-1);
    quick_sort(nums, idx+1, r);
}

void sortColors(int* nums, int numsSize){
    quick_sort(nums, 0, numsSize -1);
}

// use frequency
// Runtime: 4 ms, faster than 50.74% of C online submissions for Sort Colors.
// Memory Usage: 6.3 MB, less than 5.92% of C online submissions for Sort Colors.
void sortColors(int* nums, int numsSize){
    int freqs[3] = {0, 0, 0};
    for (int i = 0; i < numsSize; i++) {
        freqs[nums[i]]++;
    }
    int idx = 0;
    for (int i = 0; i < 3; i++) {
        while (freqs[i] != 0) {
            nums[idx++] = i;
            freqs[i]--;
        }
    }
}

void swap_int(int* x, int* y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}
// https://leetcode.com/problems/sort-colors/discuss/1904297/c%2B%2B-or-100-faster-easy-solution-using-dutch-national-flag-algorithm
// Runtime: 4 ms, faster than 50.74% of C online submissions for Sort Colors.
// Memory Usage: 6.2 MB, less than 24.95% of C online submissions for Sort Colors.
void sortColors(int* nums, int numsSize){
    int idx = 0; // idx for last 0
    int l = 0;
    int r = numsSize - 1;
    while (l <= r) {
        if (nums[l] == 0) {
            // 0 means we need to swap with idx
            // step 1 for both l and idx
            swap_int(&nums[l], &nums[idx]);
            l++;
            idx++;
        } else if (nums[l] == 1) {
            // 1 means we just step 1 for l
            l++;
        } else {
            // 2 means we just need to swap l and r
            swap_int(&nums[l], &nums[r]);
            r--;
        }
    }
}