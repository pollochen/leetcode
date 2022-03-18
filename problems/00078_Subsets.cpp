// https://www.cnblogs.com/grandyang/p/4309345.html
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