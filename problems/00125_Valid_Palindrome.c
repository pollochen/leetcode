
char convert(char ch)
{
    char cret = ch;
    if (('A' <= ch) && (ch <= 'Z')) {
        // convert to lower case
        cret = ch - 'A' + 'a';
    }
    return cret;
}

bool isletter(char ch) {
    if ((('a' <= ch) && (ch <= 'z')) || (('0' <= ch) && (ch <= '9'))) {
        return true;
    }
    return false;
}

bool isPalindrome(char * s){
    int len = strlen(s);
    char *tail = &s[len-1];
    char *head = s;
    while ((*head != '\0') || (tail != s)) {
        char ch_s = convert(*head);
        char ch_e = convert(*tail);
        if (!isletter(ch_s)) {
            if (*head != 0) head++;
            if (!isletter(ch_e)) {
                if (tail != s) tail--;
            }
        } else if (!isletter(ch_e)) {
            if (tail != s) tail--;
        } else if (ch_s != ch_e) {
            return false;
        } else {
            if (*head != 0) head++;
            if (tail != s) tail--;
        }
    }
    return true;
}