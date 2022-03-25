// quick sort + check (a + b > c)
// Runtime: 42 ms, faster than 77.30% of C online submissions for Largest Perimeter Triangle.
// Memory Usage: 7 MB, less than 97.16% of C online submissions for Largest Perimeter Triangle.
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
            swap_int(&nums[idx], &nums[i]);
        }
    }
    idx++;
    swap_int(&nums[idx], &nums[right]);
    quick_sort(nums, left, idx-1);
    quick_sort(nums, idx+1, right);
}

// https://leetcode.com/problems/largest-perimeter-triangle/solution/
int largestPerimeter(int* nums, int numsSize){
    int result = 0;
    quick_sort(nums, 0, numsSize - 1);
    for (int i = numsSize - 3; i >= 0; i--) {
        if (nums[i] + nums[i+1] > nums[i+2]) {
            result = nums[i] + nums[i+1] + nums[i+2];
            break;
        }
    }
    return result;
}