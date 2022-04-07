// slinding window with frequency of characters
// Runtime: 14 ms, faster than 77.27% of C++ online submissions for Find All Anagrams in a String.
// Memory Usage : 8.7 MB, less than 38.06 % of C++ online submissions for Find All Anagrams in a String.
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> m1(128), m2(128);
        vector<int> result;
        int n1 = p.length();
        int n2 = s.length();

        if (n1 > n2) { return result; }

        for (int i = 0; i < n1; i++) {
            m1[p[i]]++; m2[s[i]]++;
        }

        if (m1 == m2) {
            result.push_back(0);
        }

        for (int i = n1; i < n2; i++) {
            m2[s[i]]++;
            m2[s[i-n1]]--;
            if (m1 == m2) result.push_back(i-n1+1);
        }
        return result;
    }
};