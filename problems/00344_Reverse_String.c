// slow version
void reverseString(char* s, int sSize){
    int l = 0;
    int r = sSize - 1;
    while (l < r) {
        char tmp = s[l];
        s[l] = s[r];
        s[r] = tmp;
        l++;
        r--;
    }
}

// faster version
void reverseString(char* s, int sSize){
    char *l = s;
    char *r = s + sSize - 1;
    while (l < r) {
        char tmp = *l;
        *l++ = *r;
        *r-- = tmp;
    }
}