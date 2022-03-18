// https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/discuss/1850237/C%2B%2B-oror-2-Appraches-oror-Explained-With-Algorithm-oror-Easy-and-Simple
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int count = 0;
        int cnt_to_remove = 0;
        string result;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') count++;
            if (s[i] == ')') {
                count--;
                if (count < 0) {
                    s[i] = '#';
                    count = 0;
                }
            }
        }

        count = 0;
        for (int i = s.length() - 1; i >= 0; i--) {
            if (s[i] == ')') count++;
            if (s[i] == '(') {
                count--;
                if (count < 0) {
                    s[i] = '#';
                    count = 0;
                }
            }
        }

        for (int i = 0; i < s.length(); i++) {
            if (s[i] != '#') {
                result += string(1, s[i]);
            }
        }

        return result;
    }
};

void test_01249_Minimum_Remove_to_Make_Valid_Parentheses(void)
{
    Solution s;
    printf("%s\n", s.minRemoveToMakeValid("lee(t(c)o)de)").c_str());
    printf("%s\n", s.minRemoveToMakeValid("a)b(c)d").c_str());
    printf("%s\n", s.minRemoveToMakeValid("))((").c_str());
}