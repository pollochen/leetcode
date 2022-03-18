class Solution {
public:
    string toLowerCase(string s) {
        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];
            if ((ch <= 'Z') && (ch >= 'A')) {
                ch = ch - 'A' + 'a';
                s[i] = ch;
            }
        }
        return s;
    }
};