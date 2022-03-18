// TLE version
class Solution {
public:
	double myPow(double x, int n) {
		double result = 1;
		int sign_1 = x < 0 ? 0 : 1;
		int sign_2 = n < 0 ? 0 : 1;
		int sign = sign_1 ^ sign_2;
		for (int i = 0; i < abs(n); i++) {
			result *= x;
		}
		if (n < 0) result = 1.00/result;
		return result;
	}
};

// 100% faster version
class Solution {
public:
	double myPowX(double x, double n) {
		if (n == 0) return 1; // x^0
		if (n == 1) return x;
		double result = x;
		double m = 2;
		while (n >= m) {
			result = result * result; // (x*x) n=2, (x*x) * (x*x) n=4, ...
			m *= 2;
		}
		n -= m / 2;
		return result * myPowX(x, n);
	}
	double myPow(double x, int n) {
		double result;
		double nn = n;
		result = myPowX(x, labs(nn));
		if (n < 0) result = 1.00 / result;
		return result;
	}
};

void test_00050_Pow_x_n(void)
{
	Solution s;
	printf("%f\n", s.myPow(2.00000, 10));
	printf("%f\n", s.myPow(2.10000, 3));
	printf("%f\n", s.myPow(2.00000, -2));
	printf("%f\n", s.myPow(-2.00000, -2)); // 0.25
	printf("%f\n", s.myPow(-2.00000, 2)); // 4
	printf("%f\n", s.myPow(1.00000, 2147483647)); // TLE, 1
	printf("%f\n", s.myPow(1.00000, 0xFFFFFFFF)); // int overflow, 1
}