class Solution {
public:
    int findDuplicate(vector<int>& nums) {
		int size = nums.size();
		int result = 0;
		for (int i = 0; i < 32; i++) {
			int bit = (1 << i);
			int cnt1 = 0;
			int cnt2 = 0;
			for (int j = 0; j < size; j++) {
				if (j & bit) cnt1++;
				if (nums[j] & bit) cnt2++;
			}
			if (cnt2 > cnt1) result += bit;
		}
		return result;        
    }
};