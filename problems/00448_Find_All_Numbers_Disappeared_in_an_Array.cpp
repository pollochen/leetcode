class Solution {
public:
	vector<int> findDisappearedNumbers(vector<int>& nums) {
		int size = nums.size();
		vector<int> result;
		// if the number appears in index[n], mark it as negative
		for (int i = 0; i < size; i++) {
			int idx = abs(nums[i]) - 1;
			if (nums[idx] > 0) nums[idx] = -nums[idx];
		}
		
		for (int i = 0; i < size; i++) {
			if (nums[i] > 0) result.push_back(i+1);
		}
		return result;
	}
};