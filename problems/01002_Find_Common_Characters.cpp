class Solution {
public:
	vector<string> commonChars(vector<string>& words) {
		int map[26];
		int map_new[26];
		memset(map, 0, sizeof(map));
		string s = words[0];
		// generate base
		for (int i = 0; i < s.length(); i++) {
			map[s[i]-'a']++;
		}
		if (words.size() > 1) {
			for (int i = 1; i < words.size(); i++) {
				s = words[i];
				memset(map_new, 0, sizeof(map_new));
				// generate map
				for (int j = 0; j < s.length(); j++) {
					map_new[s[j]-'a']++;
				}
				// generate min map
				for (int i = 0; i < 26; i++) {
					map[i] = min(map[i], map_new[i]);
				}
			}
		}

		// generate result
		vector<string> result;
		for (int i = 0; i < 26; i++) {
			while (map[i] != 0) {
				result.push_back(string(1, i + 'a'));
				map[i]--;
			}
		}
		return result;
	}
};