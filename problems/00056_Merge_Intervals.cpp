class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
		vector<vector<int>> result;
		sort(intervals.begin(), intervals.end());
		int s = intervals[0][0];
		int e = intervals[0][1];
		for (int i = 1; i < intervals.size(); i++) {
			vector<int> interval = intervals[i];
			if (e >= interval[0]) {
				// overlaping
				e = max(e, interval[1]);
			} else {
				// no overlaping
				result.push_back(vector<int>{s,e});
				s = interval[0];
				e = interval[1];
			}
		}
		// push last
		result.push_back(vector<int>{s, e});
		return result;
    }
};