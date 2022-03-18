// https://www.cnblogs.com/grandyang/p/5139057.html
class Solution {
public:
	void wiggleSort(vector<int>& nums) {
		vector<int> x = nums;
		sort(x.begin(), x.end());
		int r = x.size() - 1;
		int l = r / 2;
		for (int i = 0; i < nums.size(); i++) {
			if ((i % 2) == 0) {
				nums[i] = x[l--];
			} else {
				nums[i] = x[r--];
			}
		}
	}
};

void test_00324_Wiggle_Sort_II(void)
{
	Solution s;

	vector<int> nums_1 = { 1, 5, 1, 1, 6, 4 };
	vector<int> nums_2 = { 1, 3, 2, 2, 3, 1 };
	vector<int> nums_3 = { 1, 3, 2, 2, 3, 6, 8 };
	s.wiggleSort(nums_1);
	s.wiggleSort(nums_2);
	s.wiggleSort(nums_3);
	print_vector_int(nums_1);
	print_vector_int(nums_2);
	print_vector_int(nums_3);
}
