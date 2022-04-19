// https://leetcode.com/problems/different-ways-to-add-parentheses/discuss/1899164/c%2B%2B-recursive-oror-divide-and-conquer-with-comment
// divide and conquer
// Runtime: 3 ms, faster than 77.35% of C++ online submissions for Different Ways to Add Parentheses.
// Memory Usage: 11.5 MB, less than 40.39% of C++ online submissions for Different Ways to Add Parentheses.
class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        char ch;
        int len = expression.length();
        vector<int> result;
        for (int i = 0; i < len; i++) {
            ch = expression[i];
            if (ch == '+' || ch == '-' || ch == '*') {
                string ls = expression.substr(0, i);
                string rs = expression.substr(i+1, len - i - 1);
                vector<int> res1 = diffWaysToCompute(ls);
                vector<int> res2 = diffWaysToCompute(rs);
                for (int j = 0; j < res1.size(); j++) {
                    for (int k = 0; k < res2.size(); k++) {
                        if (ch == '+') result.push_back(res1[j] + res2[k]);
                        if (ch == '-') result.push_back(res1[j] - res2[k]);
                        if (ch == '*') result.push_back(res1[j] * res2[k]);
                    }
                }
            }
        }
        if (result.empty() == true) {
            int x = stoi(expression);
            result.push_back(x);
        }
        return result;
    }
};