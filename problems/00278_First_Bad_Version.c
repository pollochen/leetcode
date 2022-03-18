
// Runtime: 0 ms, faster than 100.00% of C online submissions for First Bad Version.
// Memory Usage: 5.4 MB, less than 98.74% of C online submissions for First Bad Version.
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

int firstBadVersion(int n) {
    long l = 1; // n <= 2^(31-1), we must use long, not int
    long r = n; // n <= 2^(31-1), we must use long, not int
    while (l <= r) {
        long mid = (l + r) / 2; // n <= 2^(31-1), we must use long, not int
        bool x_mid = isBadVersion(mid);
        if (x_mid == true && isBadVersion(mid - 1) == false) return mid;
        if (x_mid == true) {
            // mid is bad
            r = mid - 1;
        } else {
            // mid is good
            l = mid + 1;
        }
    }
    return l;
}