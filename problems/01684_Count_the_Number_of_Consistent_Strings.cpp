class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
		vector<int> map(26, 0);
		int result = words.size();
		for (int i = 0; i < allowed.length(); i++) {
			map[allowed[i] - 'a'] = 1;
		}
		for (int i = 0; i < words.size(); i++) {
			string s = words[i];
			for (int j = 0; j < s.length(); j++) {
				if (map[s[j] - 'a'] == 0) {
					result--;
					break;
				}
			}
		}
		return result;        
    }
};