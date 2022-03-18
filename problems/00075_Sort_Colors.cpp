// https://www.cnblogs.com/grandyang/p/4341243.html
class Solution {
public:
    void sortColors(vector<int>& nums) {
		int freqs[3] = { 0, 0, 0 };
		for (int i = 0; i < nums.size(); i++) {
			freqs[nums[i]]++;
		}
		int idx = 0;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < freqs[i]; j++) {
				nums[idx++] = i;
			}
		}    
    }
};