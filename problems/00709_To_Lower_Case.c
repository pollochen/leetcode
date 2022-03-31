// Runtime: 0 ms, faster than 100.00% of C online submissions for To Lower Case.
// Memory Usage: 5.7 MB, less than 62.44% of C online submissions for To Lower Case.
char * toLowerCase(char * s){
    char *result = s;
    while (*s != '\0') {
        if ((*s >= 'A') && (*s <= 'Z')) {
            *s = *s - 'A' + 'a';
        }
       s++;
    }
    return result;
}