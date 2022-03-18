// https://leetcode.com/problems/score-of-parentheses/solution/
class Solution {
public:
    int scoreOfParentheses(string s) {
        int result = 0;
        int level = 0;
        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];
            if (ch == '(') {
                level++;
            } else {
                level--;
                if (s[i - 1] == '(') {
                    result += 1 << level;
                }
            }
        }
        return result;
    }
};

void test_00856_Score_of_Parentheses(void)
{
    Solution s;
    printf("%d\n", s.scoreOfParentheses("()"));
    printf("%d\n", s.scoreOfParentheses("(())"));
    printf("%d\n", s.scoreOfParentheses("()()"));
    printf("%d\n", s.scoreOfParentheses("(()())"));
}