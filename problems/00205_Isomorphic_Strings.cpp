// brute force
// Runtime: 3 ms, faster than 97.19% of C++ online submissions for Isomorphic Strings.
// Memory Usage: 7 MB, less than 76.05% of C++ online submissions for Isomorphic Strings.
class Solution {
public:
   bool isIsomorphic(string s, string t) {
        int char_map[128]; // map from s[i] to t[i]
        bool char_used[128]; // char used for t[i]
        memset(char_map, -1, sizeof(char_map));
        memset(char_used, false, sizeof(char_used));

        for (int i = 0; i < s.length(); i++) {
            char ch_s = s[i];
            char ch_t = t[i];
            if (char_map[ch_s] == -1) {
                if (char_used[ch_t] == false) {
                    // s[i] is not 
                    // create char map from s[i] to t[i]
                    char_map[ch_s] = ch_t;
                    char_used[ch_t] = true;
                } else {
                    return false;
                }
            } else {
                // char map from s[i] to t[i] exists
                // check if ch_t matches again
                if (char_map[ch_s] != ch_t) {
                    return false;
                }
            }
        }
        return true;
    }
};

void test_00205_Isomorphic_Strings(void)
{
    Solution s;
    printf("%d\n", s.isIsomorphic("egg", "add"));
    printf("%d\n", s.isIsomorphic("foo", "bar"));
    printf("%d\n", s.isIsomorphic("paper", "title"));
    printf("%d\n", s.isIsomorphic("badc", "baba")); // false
}