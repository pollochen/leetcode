class Solution {
public:
    bool isPowerOfFour(int n) {
		if (n <= 0) return false;
		unsigned int x = n;
		unsigned int y = n;
		x = (x & x - 1);
		if (x == 0) {
			if ((y & 0x55555555) == y) return true;
		}
		return false;      
    }
};