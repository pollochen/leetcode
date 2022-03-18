bool hasAlternatingBits(int n){
		long x = (long)n + ((long)n >> 1);
		long y = x + 1;
		if ((x & y) == 0) return true;
		else return false;
}