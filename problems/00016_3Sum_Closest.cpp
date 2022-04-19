// Runtime: 24 ms, faster than 48.48% of C++ online submissions for 3Sum Closest.
// Memory Usage: 10 MB, less than 89.09% of C++ online submissions for 3Sum Closest.
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int sum;
        int diff_min = INT_MAX;
        int result = INT_MAX;
        for (int i = 0; i < n - 2; i++) {
            int left  = i + 1;
            int right = n - 1;
            while (left < right) {
                sum = nums[i] + nums[left] + nums[right];
                if (abs(target - sum) < diff_min) {
                    diff_min = abs(target - sum);
                    result = sum;
                }
                if (sum == target) {
                    return target;
                } else if (sum < target) {
                    left++;
                } else {
                    right--;
                }
            }
        }
        return result;
    }
};