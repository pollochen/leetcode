// https://www.cnblogs.com/grandyang/p/4309345.html
// iteration
// Runtime: 4 ms, faster than 52.77 % of C++ online submissions for Subsets.
// Memory Usage : 7.1 MB, less than 64.77 % of C++ online submissions for Subsets.
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
		vector<vector<int>> result;
		result.push_back(vector<int>{});
		for (int i = 0; i < nums.size(); i++) {
			int sz = result.size();
			for (int j = 0; j < sz; j++) {
				vector<int> x = result[j];
				x.push_back(nums[i]);
				result.push_back(x);
			}
		}
		return result; 
    }
};
// https://leetcode.com/problems/subsets/solution/
// backtrack
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Subsets.
// Memory Usage : 7.1 MB, less than 64.77 % of C++ online submissions for Subsets.
class Solution {
public:
    void backtrack(vector<int>& nums, int start, int len, vector<int>& out, vector<vector<int>>& result)
    {
        if (out.size() == len) {
            result.push_back(out);
            return;
        }

        for (int i = start; i < nums.size(); i++) {
            out.push_back(nums[i]);
            backtrack(nums, i + 1, len, out, result);
            out.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> out;
        vector<vector<int>> result;
        // len is [0 - n]
        for (int len = 0; len <= nums.size(); len++) {
            backtrack(nums, 0, len, out, result);
        }
        return result;
    }
};