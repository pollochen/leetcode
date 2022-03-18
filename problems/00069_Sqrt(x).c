int mySqrt(int x) {

    if ((x == 0)) {
        return 0;
    }
	if ((x < 2)) {
		return 1;
	}

	long long idx_lb = 1, idx_ub = x/2 - 1;
	long long ll_value;
	long long index = -1;
	while (idx_lb <= idx_ub) {
		index = (idx_lb + idx_ub) / 2;
		ll_value = index * index;
		if (ll_value == x) {
			return index;
		} else if (ll_value < x) {
			if (((index + 1) * (index + 1)) > x) {
				return index;
			} else {
				idx_lb = index + 1;
			}
		} else {
			idx_ub = index - 1;
		}
	}
	return idx_lb;
}