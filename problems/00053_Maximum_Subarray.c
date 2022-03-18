// https://en.wikipedia.org/wiki/Maximum_subarray_problem
// Runtime: 119 ms, faster than 77.19% of C online submissions for Maximum Subarray.
// Memory Usage: 12.3 MB, less than 72.66% of C online submissions for Maximum Subarray.
int max(int x, int y) {
    if (x > y) return x;
    else return y;
}
int maxSubArray(int* nums, int numsSize){
    int result = INT_MIN;
    int sum = 0;
    for (int i = 0; i < numsSize; i++) {
        // if (sum + [i]) < [i], it means restarting from i will have greater sum
        // otherwise it is part of subarray
        sum = max(nums[i], nums[i] + sum);
        result = max(sum, result);
    }
    return result;
}