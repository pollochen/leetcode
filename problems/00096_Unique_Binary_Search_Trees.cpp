// https://www.cnblogs.com/grandyang/p/4299608.html
// https://zh.wikipedia.org/wiki/卡塔兰数
class Solution {
public:
    int numTrees(int n) {
		// calculate c(2n,n) / (n+1)!, c(2n,n) = (2n)!/(n)! = (2n)! / ((n+1)! * (n)!)
		long result = 1;
		for (int i = n + 1; i <= 2 * n; i++) {
			result = result * i / (i - n); // divided by (1 ~ n)
		}
		return result / (n + 1); // divided by (n+1)
    }
};