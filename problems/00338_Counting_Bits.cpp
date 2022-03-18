// https://www.cnblogs.com/grandyang/p/5294255.html
class Solution {
public:
	vector<int> countBits(int n) {
		vector<int> result(n + 1, 0);
		for (int i = 1; i <= n; i++) {
			int idx = i & (i - 1);
			result[i] = result[idx] + 1;
		}
		return result;
	}
};