// https://www.cnblogs.com/grandyang/p/4800552.html
// https://www.cnblogs.com/grandyang/p/5138186.html
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
		if (amount == 0) return 0;
		vector<int> dp(amount+1, amount+5);
		dp[0] = 0;
		for (int i = 0; i <= amount; i++) {
			// step 1 position (0 - n)
			for (int j = 0; j < coins.size(); j++) {
				// update position [i + coin[0]], [i + coin[1]], [i + coin[2]], [i + coin[3]] .... [i + coin[n-1]]
				// for example dp[i + 4] should be from dp[i] in most cases
				long val = coins[j];
				if ((i + val) <= amount) {
					dp[i + val] = min(dp[i + val], dp[i] + 1);
				}
			}
		}
		if (dp[amount] > amount + 1) return -1;
		return dp[amount];
    }
};

void test_322_Coin_Change(void)
{
	Solution s;
	printf("%d\n", s.coinChange(vector<int>{1, 2, 5}, 11));
	printf("%d\n", s.coinChange(vector<int>{2}, 3));
	printf("%d\n", s.coinChange(vector<int>{1}, 0));
	printf("%d\n", s.coinChange(vector<int>{2147483647}, 2));
	
}
