	// TLE version
	int subarraySum(vector<int>& nums, int k) {
		int n = nums.size();
		int result = 0;
		if (n == 1) {
			if (nums[0] == k) return 1;
			else return 0;
		}
		vector <int> dp(n);
		// init sum for row 0
		int sum = 0;
		for (int i = 0; i < n; i++) {
			sum += nums[i];
			dp[i] = sum;
			if (dp[i] == k) result++;
		}
		for (int i = 1; i < n; i++) {
			if (nums[i] == k) result++;
			for (int j = i + 1; j < n; j++) {
				int x = dp[j] - dp[i-1]; // sum (i, j) = sum (0, j) - sum(0, i)
				if (x == k) result++;
			}
		}
		return result;
	}

// https://leetcode.com/problems/subarray-sum-equals-k/solution/	
// Runtime: 116 ms, faster than 46.62 % of C++ online submissions for Subarray Sum Equals K.
// Memory Usage : 36.1 MB, less than 86.02 % of C++ online submissions for Subarray Sum Equals K.
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
		int n = nums.size();
		int result = 0;
		if (n == 1) {
			if (nums[0] == k) return 1;
			else return 0;
		}
		unordered_map<int, int> umap; // map [sum -> count]

		umap[0] = 1; // sum 0 -> count 1 by default
		int sum = 0;
		for (int i = 0; i < n; i++) {
			sum += nums[i];
			int prev_sum = sum - k; // if we see (sum - k) happened, then it means we can step from it
			if (umap.count(prev_sum) > 0) {
				// if (sum -k) happens more times... 
				result += umap[prev_sum];
			}
			// record count for current sum
			if (umap.count(sum) > 0) {
				umap[sum]++;
			} else {
				umap[sum] = 1;
			}
		}
		return result;
    }
};

void test_560_Subarray_Sum_Equals_K(void)
{
	Solution s;
	printf("%d\n", s.subarraySum(vector<int>{1, 1, 1}, 2));
	printf("%d\n", s.subarraySum(vector<int>{1, 2, 3}, 3));
}