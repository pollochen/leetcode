// https://leetcode.com/problems/daily-temperatures/solution/
// Approach 1: Monotonic Stack, 52.39% faster
class Solution {
public:
	vector<int> dailyTemperatures(vector<int>& temperatures) {
		int n = temperatures.size();
		vector<int> result(n, 0);
		stack<int> stk;

		for (int i = 0; i < n; i++) {
			int t_cur = temperatures[i];
			if (stk.empty() != true) {
				while (stk.empty() == false) {
					int idx = stk.top();
					int t_prev = temperatures[idx];
					if (t_prev < t_cur) {
						// hit
						result[idx] = i - idx;
						// pop it
						stk.pop();
					} else {
						// no more candidates in stack match
						break;
					}
				}
			}
			// push current index
			stk.push(i);
		}

		return result;
	}
};

// TLE version
class Solution {
public:
	vector<int> dailyTemperatures(vector<int>& temperatures) {
		int n = temperatures.size();
		vector<int> result(n, 0);
		for (int i = 0; i < n; i++) {
			int t1 = temperatures[i];
			for (int j = i + 1; j < n; j++) {
				int t2 = temperatures[j];
				if (t1 < t2) {
					result[i] = j - i;
					break;
				}
			}
		}
		return result;
	}
};

void test_00739_Daily_Temperatures(void)
{
	Solution s;
	print_vector_int(s.dailyTemperatures(vector<int>{73, 74, 75, 71, 69, 72, 76, 73}));
	print_vector_int(s.dailyTemperatures(vector<int>{30, 40, 50, 60}));
	print_vector_int(s.dailyTemperatures(vector<int>{30, 60, 90}));
}
