// Runtime: 166 ms, faster than 21.56% of C online submissions for Product of Array Except Self.
// Memory Usage: 19 MB, less than 43.90% of C online submissions for Product of Array Except Self.
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* productExceptSelf(int* nums, int numsSize, int* returnSize){
    long x = 1;
    *returnSize = numsSize;
    int *result = malloc(sizeof(int) * numsSize);
    // multiple: [n-2 ~ 1] 
    for (int i = numsSize - 1; i >= 1; i--) {
        x *= nums[i];
        result[i-1] = x;
    }
	// multiple: [1 ~ n -1] 
    x = 1;
    for (int i = 1; i < numsSize; i++) {
        x *= nums[i-1];
        result[i] = x * result[i];
    }
    result[numsSize - 1] = x;
    return result;
}