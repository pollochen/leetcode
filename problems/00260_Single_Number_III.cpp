class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
		int size = nums.size();
		vector<int> result;
		unsigned int sum = 0;
		for (int i = 0; i < size; i++) {
			sum = sum ^ nums[i];
		}

		// need to get mask for 2 different vales (don't know how...)
		sum &= (-sum);
		result.push_back(0);
		result.push_back(0);
		for (int i = 0; i < size; i++) {
			int a = nums[i];
			if (a & sum) {
				result[0] ^= a;
			} else {
				result[1] ^= a;
			}
		}
		return result;
    }
};