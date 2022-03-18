class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> result;
		int k = 0;
		int size = nums.size();
		if (size < 3) return result;
		sort(nums.begin(), nums.end());
		for (k = 0; k < size - 2; k++) {
			if (nums[k] > 0) break;
			if (k != 0 && nums[k] == nums[k - 1]) continue;
			int target = 0 - nums[k];
			int i = k + 1;
			int j = size - 1;
			while (i < j) {
				int x = nums[i] + nums[j];
				if (x == target) {
					// found
					result.push_back(vector<int>{nums[i], nums[j], nums[k]});
					// step i (+1) if same value
					while ((i < j) && (nums[i] == nums[i + 1])) i++;
					// step j (-1) if same value
					while ((i < j) && (nums[j] == nums[j - 1])) j--;
					i++; // step i (+1)
					j--; // step j (-1)
				} else if (x < target) {
					i++; // step i (+1) to have greater (i+j)
				} else { 
					j--; // step j (-1)  to have smaller (i+j)
				}
			}
		}
		return result;        
    }
};