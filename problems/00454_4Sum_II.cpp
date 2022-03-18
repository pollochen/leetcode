// https://www.cnblogs.com/grandyang/p/6073317.html
class Solution {
public:
	int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
		unordered_map<int, int> m;
		int result = 0;
		// create map for <sum(A[i], B[j]), count>
		for (int i = 0; i < nums1.size(); i++) {
			for (int j = 0; j < nums2.size(); j++) {
                int sum = nums1[i] + nums2[j];
				m[sum] += 1;
			}
		}
		// check -sum(C[i], D[j]) has hashed value in the map
		for (int i = 0; i < nums3.size(); i++) {
			for (int j = 0; j < nums4.size(); j++) {
				int sum = nums3[i] + nums4[j];
				result += m[-sum];
			}
		}
		return result;
	}
};

void test_454_4Sum_II(void)
{
	Solution s;
	printf("%d\n", s.fourSumCount(vector<int>{1, 2}, vector<int>{-2, -1}, vector<int>{-1, 2}, vector<int>{0, 2}));
}