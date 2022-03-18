class Solution {
public:
	bool isHappy(int n) {
		bool bret = false;
		for (int i = 0; i < 10000; i++) {
			n = HappyNumberNext(n);
			if (n == 1) {
				bret = true;
				break;
			} else {
				if (n == 4) break;
			}
		}
		return bret;
	}
	int HappyNumberNext(int n) {
		int nret = 0;
		while (n > 0) {
			int x = n % 10;
			nret += (x * x);
			n = n / 10;
		}
		return nret;
	}
};