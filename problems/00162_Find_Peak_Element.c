// https://leetcode.com/problems/find-peak-element/solution/
// Runtime: 11 ms, faster than 6.73% of C online submissions for Find Peak Element.
// Memory Usage: 5.8 MB, less than 48.93% of C online submissions for Find Peak Element.
int findPeakElement(int* nums, int numsSize){
    int l = 0;
    int r = numsSize - 1;
    while (l < r) {
        int mid = (l + r) / 2;
        if (nums[mid] < nums[mid+1]) {
            l = mid + 1;
        } else {
            r = mid;
        }        
    }    
    return l;
}