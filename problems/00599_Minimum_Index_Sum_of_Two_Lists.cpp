class Solution {
public:
	int string_hash(string s) {
		hash<string> hasher;
		return hasher(s);
	}
	vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
		vector<int> l1, l2;
		for (int i = 0; i < list1.size(); i++) {
			l1.push_back(string_hash(list1[i]));
		}
		for (int i = 0; i < list2.size(); i++) {
			l2.push_back(string_hash(list2[i]));
		}

		int min_x = INT_MAX;
		vector<string> result;
		for (int i = 0; i < list1.size(); i++) {
			for (int j = 0; j < list2.size(); j++) {
				if (l1[i] == l2[j]) {
					int dist = (i + j);
					if (min_x > dist) {
						min_x = dist;
						result.clear();
						result.push_back(list1[i]);
					} else if (min_x == dist) {
						result.push_back(list1[i]);
					}
				}
			}
		}
		return result;
	}
};