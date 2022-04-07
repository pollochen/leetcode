// https://www.cnblogs.com/grandyang/p/5194599.html
// Runtime: 94 ms, faster than 60.71% of C online submissions for Increasing Triplet Subsequence.
// Memory Usage: 22.1 MB, less than 44.64% of C online submissions for Increasing Triplet Subsequence.

bool increasingTriplet(int* nums, int numsSize){
    int m1 = INT_MAX;
    int m2 = INT_MAX;
    int x;
    for (int i = 0; i < numsSize; i++) {
        x = nums[i];
        if (m1 >= x) m1 = x; // reset m1
        else if (m2 >= x) m2 = x; // reset m2
        else return true; // going here means we have m1 < m2 < x or m2 < m1 < x
    }
    return false;
}