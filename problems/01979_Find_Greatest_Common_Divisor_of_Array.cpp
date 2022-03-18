class Solution {
public:
	int get_lcm(int n1, int n2) {
		// maximum number between n1 and n2 is stored in max
		int max = (n1 > n2) ? n1 : n2;

		while (1) {
			if (max % n1 == 0 && max % n2 == 0) {
				break;
			}
			++max;
		}
		return max;
	}
	int findGCD(vector<int>& nums) {
		int x_min = INT_MAX;
		int x_max = INT_MIN;
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] < x_min) x_min = nums[i];
			if (nums[i] > x_max) x_max = nums[i];
		}
		int product = x_min * x_max;
		int gcm = get_lcm(x_min, x_max);
		return product / gcm;
	}
};