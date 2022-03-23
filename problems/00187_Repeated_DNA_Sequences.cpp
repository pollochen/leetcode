// hash version
// Runtime: 82 ms, faster than 60.05% of C++ online submissions for Repeated DNA Sequences.
// Memory Usage: 23.4 MB, less than 48.59% of C++ online submissions for Repeated DNA Sequences.
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> umap;
        int len = s.length();
        vector<string> result;
        for (int i = 0; (i + 9) < len; i++) { // should be (i+9), not (i+10)
            string tmp = s.substr(i, 10);
            if (umap.count(tmp) == 0) {
                umap[tmp] = 1;
            } else {
                umap[tmp]++;
                if (umap[tmp] == 2) result.push_back(tmp);
            }
        }
        return result;
    }
};

void test_00187_Repeated_DNA_Sequences(void)
{
    Solution s;
    vector<string> result = s.findRepeatedDnaSequences("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT");
    print_vector_string(result);

    result = s.findRepeatedDnaSequences("AAAAAAAAAAAAA");
    print_vector_string(result);

    result = s.findRepeatedDnaSequences("AAAAAAAAAAA");
    print_vector_string(result);

}