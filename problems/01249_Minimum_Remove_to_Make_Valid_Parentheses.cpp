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

// stack version
// Runtime: 29 ms, faster than 54.57% of C++ online submissions for Minimum Remove to Make Valid Parentheses.
// Memory Usage: 13.1 MB, less than 10.02% of C++ online submissions for Minimum Remove to Make Valid Parentheses.
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<pair<char, int>> stk; // 
        int ch;
        
        // store unmatch pair in stack
        for (int i = 0; i < s.length(); i++) {
            ch = s[i];
            if (ch == '(') {
                stk.push({ch, i});
            } else if (ch == ')') {
                if (stk.empty() == false && stk.top().first == '(') {
                    // match, pop it
                    stk.pop();
                } else {
                    stk.push({ch, i});
                }
            }
        }
        
        string result;
        for (int i = s.length() - 1; i >= 0; i--) {
            if (stk.empty() == false) {
                if (stk.top().second != i) {
                    result += s[i];
                } else {
                    stk.pop();
                }                
            } else {
                result += s[i];
            }
        }
        reverse(result.begin(), result.end());
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