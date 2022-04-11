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

// hash amp (slow version)
// Runtime: 132 ms, faster than 9.72% of C++ online submissions for Group Anagrams.
// Memory Usage: 29 MB, less than 8.52% of C++ online submissions for Group Anagrams.
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        int size = strs.size();
        // map from "aet" to ["ate", "eat", .... ]
        unordered_map<string, vector<string>> m;
        vector<vector<string>> result;
        // build the frequency map for this string
        for (int i = 0; i < size; i++) {
            vector<int> freq(26, 0);
            string s = strs[i];
            for (int j = 0; j < s.length(); j++) {
                freq[s[j]-'a']++;
            }

            // creating the ordered identical string for this string ('ate' to 'aet')
            string tmp_s = "";
            for (int k = 0; k < 26; k++) {
                int x = freq[k];
                if (x != 0) {
                    tmp_s += string(1, k +'a');
                    tmp_s += to_string(static_cast<long double>(x));
                }
            }
            // push the string into the map
            m[tmp_s].push_back(s);
        }

        // iterate the map and the result is in second (value) element of the map
        auto iter = m.begin();
        while (iter != m.end()) {
            result.push_back(iter->second);
            iter++;
        }

        return result;
    }
};

// hash amp (faster version)
// https://leetcode.com/problems/group-anagrams/discuss/1921454/c%2B%2B-easy-understanding-solution-using-hashmap
// Runtime: 29 ms, faster than 93.66% of C++ online submissions for Group Anagrams.
// Memory Usage: 19.5 MB, less than 84.79% of C++ online submissions for Group Anagrams.
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        int size = strs.size();
        // map from "aet" to ["ate", "eat", .... ]
        unordered_map<string, vector<string>> m;
        vector<vector<string>> result;
        // build the frequency map for this string
        for (int i = 0; i < size; i++) {
            string s = strs[i];
            // sort to create the ordered identical string for this string ('ate' to 'aet')
            sort(s.begin(), s.end());

            // push the string into the map
            m[s].push_back(strs[i]);
        }

        // iterate the map and the result is in second (value) element of the map
        auto iter = m.begin();
        while (iter != m.end()) {
            result.push_back(iter->second);
            iter++;
        }

        return result;
    }
};