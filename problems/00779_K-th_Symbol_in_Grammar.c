int kthGrammar(int n, int k) {
	if (n == 1) return 0;
	if (n == 2) {
		if (k == 1) return 0;
		else return 1;
	}
	if (n == 3) {
		switch (k) {
		case 1: return 0;
		case 2: return 1;
		case 3: return 1;
		case 4: return 0;
		default: return 0;
		}
	}
	long num = pow(2, n - 1);
	if ((k-1) < (num / 2)) return kthGrammar(n-1, k);
	else {
		int i = kthGrammar(n - 1, k - (num / 2));
		if (i == 0) i = 1;
		else i = 0;
		return i;
	}
}