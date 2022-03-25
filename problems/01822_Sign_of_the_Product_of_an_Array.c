// use multiply
// Runtime: 12 ms, faster than 21.97% of C online submissions for Sign of the Product of an Array.
// Memory Usage: 6.3 MB, less than 42.42% of C online submissions for Sign of the Product of an Array.
int arraySign(int* nums, int numsSize){
    int result = 1;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == 0) return 0;
        if (nums[i] < 0) result *= -1;
    }
    return result;
}

// use - operation
// Runtime: 4 ms, faster than 89.02% of C online submissions for Sign of the Product of an Array.
// Memory Usage: 6.2 MB, less than 42.42% of C online submissions for Sign of the Product of an Array.
int arraySign(int* nums, int numsSize){
    int result = 1;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == 0) return 0;
        if (nums[i] < 0) result = -result;
    }
    return result;
}