// https://www.cnblogs.com/grandyang/p/4310964.html
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