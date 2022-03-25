// Runtime: 4 ms, faster than 69.20% of C++ online submissions for Find Minimum in Rotated Sorted Array.
// Memory Usage: 10.1 MB, less than 71.79% of C++ online submissions for Find Minimum in Rotated Sorted Array.
class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;
        while (l <= r) {
            if (l == r) return nums[l];
            int mid = (l + r) / 2;
            if (nums[mid] < nums[r]) {
                // left side
                r = mid;
            } else {
                // right side
                l = mid + 1;
            }
        }
        return 0;
    }
};

void test_00153_Find_Minimum_in_Rotated_Sorted_Array(void)
{
    Solution s;
    vector<int> num_1{ 3, 4, 5, 1, 2 };
    vector<int> num_2{ 4,5,6,7,0,1,2 };
    vector<int> num_3{ 11,13,15,17 };
    vector<int> num_4{ 1 };
    printf("%d\n", s.findMin(num_1));
    printf("%d\n", s.findMin(num_2));
    printf("%d\n", s.findMin(num_3));
    printf("%d\n", s.findMin(num_4));
}
