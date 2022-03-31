// https://leetcode.com/problems/minimum-size-subarray-sum/solution/
// 2 pointers
// Runtime: 14 ms, faster than 38.28% of C online submissions for Minimum Size Subarray Sum.
// Memory Usage: 7.1 MB, less than 59.33% of C online submissions for Minimum Size Subarray Sum.
int min_int(int x, int y)
{
	if (x < y) return x;
	else return y;
}
int minSubArrayLen(int target, int* nums, int numsSize){
    int sum = 0;
    int left = 0;
    int result = INT_MAX;
    for (int i = 0; i < numsSize; i++) {
        sum += nums[i];
        while (sum >= target) {
            result = min_int(result, i + 1 - left);
            sum -= nums[left++];
        }
    }
    if (result == INT_MAX) return 0;
    return result;
}