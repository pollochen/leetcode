// binary search
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Valid Perfect Square.
// Memory Usage: 6 MB, less than 17.88% of C++ online submissions for Valid Perfect Square.
class Solution {
public:
    bool isPerfectSquare(int num) {

        long l = 0;
        long r = 0x7FFFFFFF / 2;
        while (l <= r) {
            long mid = (l + r) / 2;
            long x = mid * mid;
            if (x == num) return true;
            if (num > x) l = mid + 1;
            else r = mid - 1;
        }
        return false;
    }
};