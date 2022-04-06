// https://leetcode.com/problems/first-missing-positive/discuss/1900255/Time-Complexity%3A-O(n)-oror-Space-Complexity%3A-O(1)-oror-C%2B%2B
// array re-mapping and check visited
// Runtime: 259 ms, faster than 19.93% of C online submissions for First Missing Positive.
// Memory Usage: 30 MB, less than 76.87% of C online submissions for First Missing Positive.
int firstMissingPositive(int* nums, int numsSize) {
    // remove negtive value and set to 0
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] < 0) nums[i] = 0;
    }

    // if the element in nums is marked as negtive,
    // then the (index+1) of it is visited
    
    int pos;
    for (int i = 0; i < numsSize; i++) {
        // get the index of this element points to
        pos = abs(nums[i]);
        // the index must be in range [1, n] since it maps to [0, n-1]
        if (pos <= numsSize && pos > 0) {
            pos--;
            if (nums[pos] > 0) {
                // if the index > 0, just mark is as negtive
                nums[pos] = -nums[pos];
            } else if (nums[pos] == 0) {
                // 0 index means it doesn't point to any element.
                // set it as negtive very large value
                nums[pos] = -INT_MAX;
            } else {
                // negtive value means we have visited it before
            }
        }
    }
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] >= 0) {
            return i + 1;
        }
    }
    return numsSize + 1;
}

void test_00041_First_Missing_Positive(void)
{
    int nums1[] = {1, 2, 0};
    int nums2[] = { 3, 4, -1, 1 };
    int nums3[] = { 7, 8, 9, 11, 12 };
    int nums4[] = { 1 };
    int nums5[] = { 3, 3, 1, 4, 0 };
    printf("%d\n", firstMissingPositive(nums5, 5)); // 2
    printf("%d\n", firstMissingPositive(nums1, 3));
    printf("%d\n", firstMissingPositive(nums2, 4));
    printf("%d\n", firstMissingPositive(nums3, 5));
    printf("%d\n", firstMissingPositive(nums4, 1)); // 2
}