

bool isSubsequence(char * s, char * t){
    if (s == NULL) return true;
    if (t == NULL) return false;
    while (*s != '\0' && *t != '\0') {
        if (*s == *t) {
            s++;
            t++;            
        } else {
            t++;
        }
    }
    if (*s == '\0') return true;
    else return false;
}