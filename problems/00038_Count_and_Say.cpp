class Solution {
public:
    string convert_say(string s) {
        int len = s.length();
        int idx = 0;
        char prev;
        int cnt = 0;
        string sret = "";
        while (idx < len) {
            if (idx == 0) {
                prev = s[0];
                cnt = 1;
            } else {
                if (s[idx] == prev) {
                    cnt++;
                } else {
                    // output string
                    sret += to_string(static_cast<long long>(cnt));
                    sret += string(1, prev);
                    cnt = 1;
                    prev = s[idx];
                }
            }
            idx++;
        }
        // output string for last char
        sret += to_string(static_cast<long long>(cnt));
        sret += string(1, prev);
        return sret;
    }
    string countAndSay(int n) {
        string s = "1";
        //printf("1 --> ");
        for (int i = 2; i <= n; i++) {
            s = convert_say(s);
            //printf("%s --> ", s.c_str());
        }
        //printf("\n");
        return s;
    }
};