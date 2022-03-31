// Runtime: 0 ms, faster than 100.00% of C online submissions for Goal Parser Interpretation.
// Memory Usage: 5.5 MB, less than 65.25% of C online submissions for Goal Parser Interpretation.
char * interpret(char * command){
    char *tmp = command;
    char *s = command;
    while (*s != '\0') {
        if (*s == ')') {
            if ((*(s-1)) == '(') {
                *tmp++ = 'o';    
            } else {
                *tmp++ = 'a';    
                *tmp++ = 'l';    
            }
        } else if (*s == 'G') {
            *tmp++ = 'G';
        }
        s++;
    }
    *tmp = '\0';
    return command;
}