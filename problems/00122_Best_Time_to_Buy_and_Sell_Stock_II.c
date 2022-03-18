int maxProfit(int* prices, int pricesSize) {
	int max = 0;
	for (int i = 0; i < (pricesSize-1); i++) {
		int profit = prices[i + 1] - prices[i];
		if (profit > 0) {
			max += profit;
		}
	}
	return max;
}
