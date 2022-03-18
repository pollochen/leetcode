// Runtime: 11 ms, faster than 34.77% of C++ online submissions for Remove Duplicates from Sorted Array II.
// Memory Usage: 10.9 MB, less than 75.44% of C++ online submissions for Remove Duplicates from Sorted Array II.
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int result = 0;
        int idx_copy = 0;
        int idx_cur = 0;
        int count;

        count = 1;
        idx_cur++;
        idx_copy++;

        while (idx_cur < nums.size()) {
            int x = nums[idx_cur];
            if (nums[idx_cur] == nums[idx_cur - 1]) {
                // previous and current values are the same
                count++;
                if (count >= 3) {
                    // skip these duplicated numbers
                } else {
                    nums[idx_copy++] = nums[idx_cur];
                }
            } else {
                nums[idx_copy++] = nums[idx_cur];
                count = 1;
            }
            idx_cur++;
        }
        result = idx_copy;
        return result;
    }
};

void test_00080_Remove_Duplicates_From_Sorted_Array_II(void)
{
    Solution s;
    int nums_1[] = {1,1,1,2,2,3};
    int nums_2[] = {0,0,1,1,1,1,2,3,3};
    vector<int> x1 = int_array_to_vector(nums_1, sizeof(nums_1)/sizeof(int));
    vector<int> x2 = int_array_to_vector(nums_2, sizeof(nums_2)/sizeof(int));
    printf("%d", s.removeDuplicates(x1));
    print_vector_int(x1);
    printf("%d", s.removeDuplicates(x2));
    print_vector_int(x2);
}