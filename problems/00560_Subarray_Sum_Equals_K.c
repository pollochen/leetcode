
// https://leetcode.com/problems/subarray-sum-equals-k/solution/
// Using Cumulative Sum (TLE)
int subarraySum(int* nums, int numsSize, int k){
    int result = 0;
    int *sum = (int *)malloc(sizeof(int) * (numsSize + 1));
    sum[0] = 0;
    for (int i = 1; i <= numsSize; i++) {
        sum[i] = sum[i-1] + nums[i-1];
    }
    for (int start = 0; start < numsSize; start++) {
        for (int end = start + 1; end <= numsSize; end++) {
            if ((sum[end] - sum[start]) == k) {
                result++;
            }
        }
    }
    free(sum);
    return result;
}

// Approach 3: Without Space (TLE)
int subarraySum(int* nums, int numsSize, int k){
    int result = 0;
    int sum;
    for (int start = 0; start < numsSize; start++) {
        sum = 0;
        for (int end = start; end < numsSize; end++) {
            sum += nums[end];
            if (sum == k) {
                result++;
            }
        }
    }
    return result;
}