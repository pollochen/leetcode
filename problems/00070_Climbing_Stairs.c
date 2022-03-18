int climbStairs(int n) {

	int f[46];
	int i;

	if (n == 0) {
		return 0;
	}

	if (n == 1) {
		return 1;
	}
	if (n == 2) {
		return 2;
	}

	f[2] = 2;
	f[1] = 1;
	for (i = 3; i <= n; i++) {
		f[i] = f[i - 1] + f[i - 2];
	}
	return f[n];
}