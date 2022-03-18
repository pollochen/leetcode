class Solution {
public:
	int numSplits(string s) {
		if (s.length() == 1) return 0;
		if (s.length() == 2) return 1;
		vector<int> mapr(26, 0);
		vector<int> mapl(26, 0);
		int result = 0;
		int dr_num = 0;
		int dl_num = 0;
		for (int i = 0; i < s.length(); i++) {
			int idx = s[i] - 'a';
			if (mapr[idx] == 0) {
				dr_num++;
			}
			mapr[idx]++;
		}
		for (int i = 0; i < s.length(); i++) {
			int idx = s[i] - 'a';
			// check left side
			if (mapl[idx] == 0) {
				dl_num++;
			}
			mapl[idx]++;
			// check right side
			mapr[idx]--;
			if (mapr[idx] == 0) {
				dr_num--;
			}
			if (dl_num == dr_num) {
				result++;
			}
		}

		return result;
	}
};