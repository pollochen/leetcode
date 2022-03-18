// https://leetcode.com/problems/find-peak-element/discuss/1818838/java-or-binary-search-or-0ms
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
		int left = 0;
		int right = nums.size() - 1;
		int result = 0;
		while (left < right) {
			int mid = (left + right) / 2;
			if (nums[mid] < nums[mid + 1]) {
				left = mid + 1;
			} else if (nums[mid] > nums[mid + 1]){
				right = mid;
			}
		}

		return left;
    }
};

void test_162_Find_Peak_Element(void)
{
	Solution s;
	printf("%d\n", s.findPeakElement(vector<int>{1, 2, 3, 1}));
	printf("%d\n", s.findPeakElement(vector<int>{1, 2, 1, 3, 5, 6, 4 }));
}