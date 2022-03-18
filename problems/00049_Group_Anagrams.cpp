class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        int size = strs.size();
        unordered_map<string, vector<string>> m;
        vector<vector<string>> result;
        for (int i = 0; i < size; i++) {
            vector<int> freq(26, 0);
            string s = strs[i];
            for (int j = 0; j < s.length(); j++) {
                freq[s[j]-'a']++;
            }

            // creating the map for this frequency
            string tmp_s = "";
            for (int k = 0; k < 26; k++) {
                int x = freq[k];
                if (x != 0) {
                    tmp_s += string(1, k +'a');
                    tmp_s += to_string(static_cast<long double>(x));
                }
            }
            m[tmp_s].push_back(s);
        }

        auto iter = m.begin();
        while (iter != m.end()) {
            result.push_back(iter->second);
            iter++;
        }

        return result;
    }
};