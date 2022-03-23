// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Count Odd Numbers in an Interval Range.
// Memory Usage: 5.8 MB, less than 74.06% of C++ online submissions for Count Odd Numbers in an Interval Range.
class Solution {
public:
    int countOdds(int low, int high) {
        int len = high - low + 1;
        int result = 0;

        // we have n numbers
        if ((low & 0x01) == 1) {
            // start from odd
            result = 1 + ((len - 1) / 2);
        } else {
            // start from even
            result = 0 + (len / 2);
        }
        return result;
    }
};