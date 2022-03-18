// https://www.cnblogs.com/grandyang/p/4244123.html
class Solution {
public:
    int compareVersion(string version1, string version2) {
        char *s1 = (char *)version1.c_str();
        char *s2 = (char *)version2.c_str();
        char *p1 = s1;
        char *p2 = s2;
        int  val1, val2;
        while (*p1 != '\0' || *p2 != '\0') {
            if (*p1 == '\0') {
                val1 = 0;
            } else {
                val1 = strtoul(p1, &p1, 10);
            }
            if (*p2 == '\0') {
                val2 = 0;
            } else {
                val2 = strtoul(p2, &p2, 10);
            }

            if (val1 < val2) {
                return -1;
            } else if (val1 > val2) {
                return 1;
            } else {
                if (*p1 != '\0') p1++;
                if (*p2 != '\0') p2++;
            }
        }
        return 0;
    }
};