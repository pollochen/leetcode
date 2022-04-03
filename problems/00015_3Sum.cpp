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

// https://www.code-recipe.com/post/three-sum
// Runtime: 76 ms, faster than 89.24% of C++ online submissions for 3Sum.
// Memory Usage: 20.1 MB, less than 52.23% of C++ online submissions for 3Sum.
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int idx1;
        int idx2;
        int idx3;
        int sum;
        int n = nums.size();
        vector<vector<int>> result;
        vector<int> out;
        for (idx1 = 0; idx1 < n; idx1++) {
            // check duplication for idx1
            if ((idx1 > 0) && (nums[idx1] == nums[idx1-1])) {
                continue;
            }
            idx2 = idx1 + 1;
            idx3 = n - 1;
            while (idx2 < idx3) {
                sum = nums[idx1] + nums[idx2] + nums[idx3];
                if (sum == 0) {
                    out.clear();
                    out.push_back(nums[idx1]);
                    out.push_back(nums[idx2]);
                    out.push_back(nums[idx3]);
                    result.push_back(out);
                    idx3--; // reduce idx3 by 1
                    // need to check duplication, idx3 must >= 0
                    while (idx3 >= 0 && nums[idx3] == nums[idx3+1]) idx3--;
                } else if (sum > 0) {
                    idx3--; // reduce idx3 by 1
                    // need to check duplication, idx3 must >= 0
                    while (idx3 >= 0 && nums[idx3] == nums[idx3+1]) idx3--;
                } else {
                    idx2++;
                }
            }
        }
        return result;
    }
};