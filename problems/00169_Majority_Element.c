// https://leetcode.com/problems/majority-element/solution/
// Boyer-Moore Voting Algorithm
// Runtime: 16 ms, faster than 97.30% of C online submissions for Majority Element.
// Memory Usage: 7.8 MB, less than 68.25% of C online submissions for Majority Element.
int majorityElement(int* nums, int numsSize){
    int result = nums[0];
    int cnt = 1;
    for (int i = 1; i < numsSize; i++) {
        if (result != nums[i]) cnt--;
        else cnt++;

        if (cnt == 0) {
            result = nums[i];
            cnt++;
        }
    }
    return result;
}