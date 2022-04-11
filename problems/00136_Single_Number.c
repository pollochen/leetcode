// a number XOR itself will be 0
// Runtime: 27 ms, faster than 50.64% of C online submissions for Single Number.
// Memory Usage: 7.3 MB, less than 29.40% of C online submissions for Single Number.
int singleNumber(int* nums, int numsSize){
    int result = 0;
    for (int i = 0; i < numsSize; i++) {
        result = result ^ nums[i];
    }
    return result;
}
