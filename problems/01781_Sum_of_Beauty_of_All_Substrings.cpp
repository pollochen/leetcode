class Solution {
public:
    int bsum(unordered_map<int, int> &m)
    {
        int f_min = INT_MAX;
        int f_max = INT_MIN;

        auto iter = m.begin();
        while (iter != m.end()) {
            f_min = min(iter->second, f_min);
            f_max = max(iter->second, f_max);
            iter++;
        }
        return f_max - f_min;
    }
    int beautySum(string s) {
        int size = s.length();
        int result = 0;
        for (int i = 0; i < size; i++) {
            unordered_map<int, int> m;
            for (int j = i; j < size; j++) {
                char x = s[j];
                m[x]++;
                result += bsum(m);
            }
        }
        return result;
    }
};