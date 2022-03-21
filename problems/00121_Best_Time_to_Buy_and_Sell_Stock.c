// Runtime: 254 ms, faster than 13.60 % of C online submissions for Best Time to Buyand Sell Stock.
// Memory Usage : 13.1 MB, less than 37.88 % of C online submissions for Best Time to Buyand Sell Stock.
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

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/discuss/1735493/JavaC%2B%2B-best-ever-EXPLANATION-could-possible
// Runtime: 295 ms, faster than 5.60 % of C online submissions for Best Time to Buyand Sell Stock.
// Memory Usage : 13.2 MB, less than 14.49 % of C online submissions for Best Time to Buyand Sell Stock.
int maxProfit(int* prices, int pricesSize) {
	// we can only choose one day to buy and sell in the future
	// 1. pick smallest value
	// 2. calculate profit with current smallest value
	int result = 0;
	int smallest = INT_MAX;
	for (int i = 0; i < pricesSize; i++) {
		if (prices[i] < smallest) {
			smallest = prices[i]; // pick smallest value
		}
		int profit = prices[i] - smallest; // calculate profit with current smallest value
		if (profit > result) {
			result = profit; // update result if profit is greater
		}
	}
	return result;
}
// don't use local variable (profit)
// Runtime: 138 ms, faster than 78.34 % of C online submissions for Best Time to Buyand Sell Stock.
// Memory Usage : 13 MB, less than 56.52 % of C online submissions for Best Time to Buyand Sell Stock.
int maxProfit(int* prices, int pricesSize) {
	// we can only choose one day to buy and sell in the future
	// 1. pick smallest value
	// 2. calculate profile with current smallest value
	int result = 0;
	int smallest = INT_MAX;
	int profit;
	for (int i = 0; i < pricesSize; i++) {
		if (prices[i] < smallest) {
			smallest = prices[i]; // pick smallest value
		}
		profit = prices[i] - smallest; // calculate profile with current smallest value
		if (profit > result) {
			result = profit; // update result if profit is greater
		}
	}
	return result;
}