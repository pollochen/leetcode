int maxProfit(int* prices, int pricesSize) {
	int i;
	int min = INT_MAX;
	int max = INT_MIN;
	for (i = 0; i < pricesSize; i++) {
		if (prices[i] < min) {
			// buy on day i?
			min = prices[i];
		} else {
			// sell on day j?
			int sell_price = prices[i];
			int profit = sell_price - min;
			if (profit > 0) {
				if (profit > max) {
					max = profit;
				}
			}
		}			
	}
	if (max < 0) {
		max = 0;
	}
	return max;
}