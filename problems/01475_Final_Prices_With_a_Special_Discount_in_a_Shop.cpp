class Solution {
public:
	vector<int> finalPrices(vector<int>& prices) {
		vector<int> result;
		stack<int> stk;
		for (int i = prices.size() - 1; i >= 0; i--) {
			int price = prices[i];
			while ((stk.empty() == false) && (price < stk.top())) {
				stk.pop();
			}
			if (stk.empty() == true) result.push_back(price);
			else result.push_back(price - stk.top());
			stk.push(price);
		}
		reverse(result.begin(), result.end());
		return result;
	}
};

void test_1475_Final_Prices_With_a_Special_Discount_in_a_Shop(void)
{
	Solution s;
	print_vector_int(s.finalPrices(vector<int>{8, 4, 6, 2, 3}));
	print_vector_int(s.finalPrices(vector<int>{1, 2, 3, 4, 5}));
	print_vector_int(s.finalPrices(vector<int>{10, 1, 1, 6}));
}