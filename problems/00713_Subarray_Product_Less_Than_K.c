// https://leetcode.com/problems/subarray-product-less-than-k/solution/
// sliding window O(N) time 
// Runtime: 118 ms, faster than 47.27% of C online submissions for Subarray Product Less Than K.
// Memory Usage: 9.5 MB, less than 96.36% of C online submissions for Subarray Product Less Than K.
int numSubarrayProductLessThanK(int* nums, int numsSize, int k){
    int production = 1;
    int left = 0;
    int result = 0;

	// the k could not be 1 or 0 (strictly less than k and nums[i] >= 1)
    if (k <= 1) return 0;
    
    for (int right = 0; right < numsSize; right++) {
        production = production * nums[right];
        while (production >= k) { 
            production /= nums[left++];
        }
		// right is new added
		// for [2, 5]
		// if current is [2] and new added is [5]
		// then new subarrays would be [2, 5] and [5]
		// so the count would be (right - left + 1) = (1 - 0 + 1) = 2
        result += (right - left + 1); // please chec explanation about why it is...
    }
    return result;
}