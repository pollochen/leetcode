// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
	int firstBadVersion(int n) {
		unsigned int i = 1;
		unsigned int j = n;
		while (i <= j) {
			unsigned int mid = (i + j) / 2;
			bool x1 = isBadVersion(mid);
			if (x1 == true) {
				// check if x0 is false
				if (mid == 1) {
					return 1;
				} else if ((mid > 1) && (isBadVersion(mid - 1) == false)) {
					return mid;
				} else {
					j = mid - 1;
				}
			} else {
				// check if x2 is true
				if (isBadVersion(mid + 1) == true) {
					return mid + 1;
				} else {
					i = mid + 1;
				}
			}
		}
		return 0;
	}
};