bool isPalindrome(int x) {
	long reverse = 0;
	int num = x;
	int remain;

	if (x < 0) {
		return false;
	}

	if (x < 10) {
		return true;
	}

	while (x > 0) {
		remain = x % 10;
		reverse = reverse * 10 + remain;
		x = x / 10;
	};

	if (num == reverse) {
		return true;
	}
	else {
		return false;
	}
}