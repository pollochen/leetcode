class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> result;
        int len = s.length();
        int start = 0;
        int end = 0;

        if (len == 1) {
            result.push_back(1);
            return result;
        }

        unordered_map<char, int> umap;

        // build map for each character's last position
        for (int i = s.length() - 1; i >= 0; i--) {
            if (umap.count(s[i]) == 0) {
                umap[s[i]] = i;
            }
        }

        while (start < len) {
            // get last position of s[start]
            int end = umap[s[start]];
            if (start == end) {
                // we have one char like 'a'
            } else {
                for (int i = start + 1; i < end; i++) {
                    int pos = umap[s[i]];
                    if (pos > end) {
                        // expand end position
                        end = pos;
                    }
                }
            }
            result.push_back(end - start + 1);
            start = end + 1;
        }
        return result;
    }
};

void print_int_array(int *arr, int size)
{
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d, ", arr[i]);
    }
    printf("]\n");
}

void test_00763_Partition_Labels(void)
{
    Solution s;
    print_vector_int(s.partitionLabels("ababcbacadefegdehijhklij"));
    print_vector_int(s.partitionLabels("eccbbbbdec"));
    print_vector_int(s.partitionLabels("eaaaabaaec"));
}