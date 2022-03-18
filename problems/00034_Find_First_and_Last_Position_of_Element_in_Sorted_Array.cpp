class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		int i = 0;
		int j = nums.size() - 1;
		while (i <= j) { // not it must be  <=, not <
			int mid = (i + j) / 2;
			if (nums[mid] == target) {
				// found
				int l = mid;
				int r = mid;
				while ((l > 0) && (nums[l-1] == target)) l--;
				while ((r < nums.size()-1) && (nums[r+1] == target)) r++;
				return{ l, r };
			} else if (target > nums[mid]) {
				i = mid + 1;
			} else {
				j = mid - 1;
			}
		}
		return{ -1, -1 };
	}
};