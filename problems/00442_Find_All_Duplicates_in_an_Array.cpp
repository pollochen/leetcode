class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
		int size = nums.size();
		vector<int> result;
		for (int i = 0; i < size; i++) {
			int idx = abs(nums[i]) - 1;
			if (nums[idx] > 0) {
				// sorted array [idx] has value
				nums[idx] = -nums[idx];
			} else {
				// duplicate
				result.push_back(idx+1);
			}
		}
		return result;        
    }
};