// Runtime: 186 ms, faster than 71.71% of C online submissions for Monotonic Array.
// Memory Usage: 13.8 MB, less than 73.68% of C online submissions for Monotonic Array.
bool isMonotonic(int* nums, int numsSize){
    if (numsSize <= 2) return true;
    int dir = 0;
    int diff;
    for (int i = 1; i <numsSize; i++) {
        diff = nums[i] - nums[i-1];
        if (diff == 0) continue;
        if (diff < 0) {
            // decreasing
            if (dir == 0) dir = -1;
            else if (dir == 1) return false;
        } else {
            // increasing
            if (dir == 0) dir = 1;
            else if (dir == -1) return false;
        }
    }
    return true;
}

// https://leetcode.com/problems/monotonic-array/solution/
// Runtime: 237 ms, faster than 33.55% of C online submissions for Monotonic Array.
// Memory Usage: 13.9 MB, less than 51.32% of C online submissions for Monotonic Array.
bool isMonotonic(int* nums, int numsSize){
    bool decreasing = true;
    bool increasing = true;
    for (int i = 1; i <numsSize; i++) {
        if (nums[i] > nums[i-1]) decreasing = false;
        if (nums[i] < nums[i-1]) increasing = false;
    }
    return decreasing | increasing;
}