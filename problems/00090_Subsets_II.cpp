// https://www.cnblogs.com/grandyang/p/4310964.html
// Runtime: 4 ms, faster than 69.21 % of C++ online submissions for Subsets II.
// Memory Usage : 7.4 MB, less than 96.86 % of C++ online submissions for Subsets II.
class Solution {
public:
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		vector<vector<int>> result;
		result.push_back(vector<int>{});
        sort(nums.begin(), nums.end());
		int size = 1;
		int last = nums[0];
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] != last) {
				// use whole result
				last = nums[i];
				size = result.size();
			}
			int sz = result.size();
			for (int j = sz - size; j < sz; j++) {
				vector<int> x = result[j];
				x.push_back(nums[i]);
				result.push_back(x);
			}
		}
		return result;
	}
};

// https://leetcode.com/problems/subsets-ii/discuss/1926527/C%2B%2B-Solution-using-Recursion-and-Backtracking
// backtrack
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Subsets II.
// Memory Usage : 7.5 MB, less than 89.49 % of C++ online submissions for Subsets II.
class Solution {
public:

	void backtrack(vector<int>& nums, int start, int len, vector<int>& out, vector<vector<int>>& result)
	{
		if (out.size() == len) {
			result.push_back(out);
		}
		for (int i = start; i < nums.size(); i++) {
			if (i > start && nums[i] == nums[i - 1]) {
				// we just pick first same number and ignore later same numbers
				// the next same number will be picked inside later backtrack()
				continue;
			}
			out.push_back(nums[i]);
			backtrack(nums, i + 1, len, out, result);
			out.pop_back();
		}
	}

	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		vector<vector<int>> result;
		vector<int> out;
		sort(nums.begin(), nums.end());
		for (int len = 0; len <= nums.size(); len++) {
			backtrack(nums, 0, len, out, result);
		}
		return result;
	}
}; A