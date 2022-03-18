// https://www.cnblogs.com/grandyang/p/5138212.html
class Solution {
public:
    bool isPowerOfThree(int n) {
		if (n <= 0) return false;
		if ((1162261467 % n) == 0) return true;
		else return false;  
    }
};