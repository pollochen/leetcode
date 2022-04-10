// https://leetcode.com/problems/permutations-ii/solution/
// recursion (unique numbers with frequency (variant of unique numbers with visited map)
// Runtime: 0 ms, faster than 100.00 % of C++ online submissions for Permutations II.
// Memory Usage : 8.6 MB, less than 77.74 % of C++ online submissions for Permutations II.
class Solution {
public:
	void permuteUniqueX(vector<int> &unique_nums, int target, unordered_map<int, int> &umap, vector<int> &out, vector<vector<int>> &result)
	{
		if (out.size() == target) {
			result.push_back(out);
			return;
		}

		for (int i = 0; i < unique_nums.size(); i++) {
			int num = unique_nums[i];
			if (umap[num] == 0) continue; // no element in nums

			// decrase count for num
			umap[num]--;

			// push this element
			out.push_back(num);

			permuteUniqueX(unique_nums, target, umap, out, result);

			// pop this element
			out.pop_back();
			// increase count for num
			umap[num]++;
		}
	}
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		vector<vector<int>> result;
		vector<int> out;
		unordered_map<int, int> umap;
		vector<int> unique_nums;

		// creat map for each number
		for (int i = 0; i < nums.size(); i++) {
			int num = nums[i];
			if (umap.count(num) == 0) {
				umap[num] = 1;
				unique_nums.push_back(num);
			} else {
				umap[num]++;
			}
		}

		permuteUniqueX(unique_nums, nums.size(), umap, out, result);
		return result;
	}
};

void test_00047_Permutations_II(void)
{
	Solution s;
	print_matrix_int(s.permuteUnique(vector<int>{1, 1, 2}));
	print_matrix_int(s.permuteUnique(vector<int>{1, 2, 3}));
}