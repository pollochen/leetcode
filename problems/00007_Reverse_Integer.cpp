class Solution {
public:
    int reverse(int x) {
		int result = 0;
		int max = INT_MAX;
		int min = INT_MIN;
		while (x != 0) {
			int pop = x % 10;
			x = x / 10;
			//if (result > INT_MAX / 10 || (result == INT_MAX / 10 && pop > 7)) return 0;
			//if (result < INT_MIN / 10 || (result == INT_MIN / 10 && pop < -8)) return 0;
			if (result > INT_MAX / 10) return 0;
			if (result < INT_MIN / 10) return 0;
			result = result * 10 + pop;
		}
		return result;        
    }
};