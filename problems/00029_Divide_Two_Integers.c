// https://www.cnblogs.com/grandyang/p/4431949.html
int divide(int dividend, int divisor){
	if ((dividend == INT_MIN) && (divisor == -1)) return INT_MAX; // INT_MIN(-1)/(-1) --> INT_MAX
	int sign1 = (dividend >= 0)? 1 : -1;
	int sign2 = (divisor >= 0) ? 1 : -1;
	int sign = 1;
	if ((sign1 == -1) && (sign2 == 1)) sign = -1;
	if ((sign1 == 1) && (sign2 == -1)) sign = -1;

	if (divisor == 1) return dividend;
	if (divisor == -1) return -dividend;

	long int m = labs(dividend);
	long int n = labs(divisor);

	int result = 0;

	while (m >= n) {
		long int nx = n;
		long int q = 1;
		// m / n^q
		while (m >= (nx << 1)) {
			nx = nx << 1; // nx = nx * 2
			q = q << 1;   // q = q * 2
		}
		result += q;
		m = m - nx;
	}	
	if (sign < 0) result = -result;
	return result;
}