void reduce(char * s)
{
    int idx = 0;
    int i = 0;
    char ch;
    while (s[i] != '\0') {
        ch = s[i];
        if (ch == '#') {
            // backspace
            if (idx > 0) {
                idx--;
            }
        } else {
            s[idx++] = ch;
        }
        i++;
    }
    s[idx] = '\0';    
}

bool backspaceCompare(char * s, char * t){
    reduce(s);
    reduce(t);
    if (strcmp(s, t) == 0) return true;
    else return false;
}