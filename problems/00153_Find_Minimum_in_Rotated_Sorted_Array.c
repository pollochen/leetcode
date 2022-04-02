// binary search
// Runtime: 5 ms, faster than 35.92% of C online submissions for Find Minimum in Rotated Sorted Array.
// Memory Usage: 5.9 MB, less than 95.71% of C online submissions for Find Minimum in Rotated Sorted Array.
int findMin(int* nums, int numsSize){
    int l = 0;
    int r = numsSize - 1;
    int mid;
    while (l <= r) {
        if (l == r) return nums[l];
        mid = (l + r) / 2;
        if (nums[mid] > nums[r]) {
            // right side, step 1 since nums[mid] is not smallest
            l = mid + 1;
        } else {
            r = mid; // no step 1 since nums[mid] mab bye smallest     
        }
    }
    return 0;
}