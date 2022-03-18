class Solution {
public:
    bool isAnagram(string s, string t) {
        int size = s.length();
        if (size != t.length()) return false;
        vector<int> map_s(128);
        vector<int> map_t(128);
        for (int i = 0; i < size; i++) {
            map_s[s[i] - 'a']++;
            map_t[t[i] - 'a']++;
        }
        return map_s == map_t;
    }
};