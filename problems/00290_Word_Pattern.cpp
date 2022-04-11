// 2 maps
// Runtime: 4 ms, faster than 20.41% of C++ online submissions for Word Pattern.
// Memory Usage: 6.5 MB, less than 52.03% of C++ online submissions for Word Pattern.
class Solution {
public:
    vector<string> split(string s, string delimiter)
    {
        size_t end;
        size_t start = 0;
        vector<string> ret;
        while ((end = s.find(delimiter, start)) != string::npos) {
            string token = s.substr(start, end - start);
            ret.push_back(token);
            start = end + 1;
        }
        // last token
        ret.push_back(s.substr(start));
        return ret;
    }
    bool wordPattern(string pattern, string s) {
        unordered_map<string, char> umap;
        unordered_map<char, int> pattern_umap;
        vector<string> tokens = split(s, " ");
        if (pattern.length() != tokens.size()) return false;
        char px;
        for (int i = 0; i < tokens.size(); i++) {
            px = pattern[i];
            if (umap.count(tokens[i]) == 0) {
                if (pattern_umap.count(px) != 0) return false;

                umap[tokens[i]] = px;
                pattern_umap[px] = 1;
            } else {
                if (umap[tokens[i]] != px) return false;
            }
        }
        return true;
    }
};

void test_00290_Word_Pattern(void)
{
    Solution s;
    printf("%d\n", s.wordPattern("abba", "dog cat cat dog"));
    printf("%d\n", s.wordPattern("abba", "dog cat cat fish"));
    printf("%d\n", s.wordPattern("aaaa", "dog cat cat dog"));
    printf("%d\n", s.wordPattern("jquery", "jquery"));
}