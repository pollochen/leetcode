class Solution {
public:
	bool is_prime(int n) {
		return (n == 2 || n == 3 || n == 5 || n == 7 || n == 11 || n == 13 || n == 17 || n == 19);
	}

	int countPrimeSetBits(int left, int right) {
		int result = 0;
		for (int i = left; i <= right; i++) {
			int cnt = 0;
			int x = i;
			while (x != 0) {
				if ((x & 1) == 1) cnt++;
				x = x >> 1;
			}
			if (is_prime(cnt)) result++;
		}
		return result;
	}
};