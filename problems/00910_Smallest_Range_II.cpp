// https://leetcode.com/problems/smallest-range-ii/solution/
// Runtime: 38 ms, faster than 18.93% of C++ online submissions for Smallest Range II.
// Memory Usage: 15.5 MB, less than 69.41% of C++ online submissions for Smallest Range II.
class Solution {
public:
    int smallestRangeII(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int result = nums[n-1] - nums[0]; // max difference is [n-1] - [0] since it is sorted
        int v_max = nums[n-1] - k; // min upper bound
        int v_min = nums[0] + k;   // min lower bound
        for (int i = 0; i < n - 1; i++) {
            int a = nums[i];
            int b = nums[i+1];
            int high = max(a + k, v_max); // low  value may have larger value than min upper bound (+k)
            int low  = min(b - k, v_min); // high value may have smaller value than min lower bound (-k)
            result = min(result, high - low);
        }
        return result;
    }
};