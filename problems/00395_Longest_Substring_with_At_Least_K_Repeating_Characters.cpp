// https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters/solution/
class Solution {
public:
    int divide(string s, int left, int right, int k)
    {
        if ((right - left + 1) < k) return 0;
        if ((right == left) && (k == 1)) return 1;

        int freqs[26];
        memset(freqs, 0, sizeof(freqs));
        // calculate freqs for each char
        for (int i = left; i <= right; i++) {
            freqs[s[i] - 'a']++;
        }

        // scan from left to right
        for (int m1 = left; m1 <= right; m1++) {
            int idx  = s[m1] - 'a';
            int freq = freqs[idx];
            // check the frequency of this character
            if (freq < k) {
                int m2;
                // the freq is smaller than k, we should divide from it
                // step next to skip characters with small frequency
                for (m2 = m1+1; m2 <= right; m2++) {
                    idx  = s[m2] - 'a';
                    freq = freqs[idx];
                    if (freq >= k) {
                        break;
                    }
                }
                return max(divide(s, left, m1-1, k), divide(s, m2, right, k));
            }
        }

        // going here means we have match for whole string
        return right - left + 1;
    }

    int longestSubstring(string s, int k) {
        return divide(s, 0, s.length() - 1, k);
    }
};

void test_395_Longest_Substring_with_At_Least_K_Repeating_Characters(void)
{
    Solution s;
    printf("%d\n", s.longestSubstring("aaabb", 3));
    printf("%d\n", s.longestSubstring("ababbc", 2));
    printf("%d\n", s.longestSubstring("aaabb", 1));
    printf("%d\n", s.longestSubstring("b", 2));
}