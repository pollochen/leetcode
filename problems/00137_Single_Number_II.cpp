class Solution {
public:
    int singleNumber(vector<int>& nums) {
		int size = nums.size();
		int result = 0;
		for (int i = 0; i < 32; i++) {
			int sum = 0;
			for (int j = 0; j < size; j++) {
				sum += (nums[j] >> i) & 1;
			}
			sum = sum % 3;
			result += sum << i;
		}
		return result;        
    }
};