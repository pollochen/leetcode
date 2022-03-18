int bitwiseComplement(int n) {
	long x = 1;
	// create bit mask
	while (x < n) {
		x = (x << 1) + 1;
	}
	return x ^ n;
}