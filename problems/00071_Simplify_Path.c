bool is_letter(char ch) {
    return ch >= 'a' && ch <= 'z';
}

char * simplifyPath(char * path){
    int len = strlen(path);
    char *result = (char *)malloc(sizeof(char) * len + 1);
    char *tmp    = (char *)malloc(sizeof(char) * len + 1);
    int level = 0;
    int idx_result = 0;
    int idx_path = 0;
    int idx_tmp = 0;
    char ch_prev = '\0';


    while (idx_path < len) {
        char ch = path[idx_path];

        if (ch != '/') {
            // copy dir name into tmp
            tmp[idx_tmp++] = ch;
            tmp[idx_tmp] = '\0';
        }

        if ((ch == '/') || (idx_path == len - 1)) {
            if ((ch_prev != '/') || (idx_path == len - 1)) {
                if ((idx_tmp == 1) && (tmp[0] == '.')) {
                    // stay at current dir
                } else if ((idx_tmp == 2) && (tmp[0] == '.') && (tmp[1] == '.')) {
                    // back to parent dir if not root
                    if (level > 1) {
                        level--;
                        // back find '/'
                        while ((idx_result > 0) && (result[idx_result] != '/')) {
                            idx_result--;
                        }
                        result[idx_result] = '\0';
                        if (idx_result == 0) result[idx_result++] = '/';
                    }
                } else {
                    level++;
                    if ((idx_result == 0) || (idx_result > 0 && result[idx_result-1] != '/')) {
                        result[idx_result++] = '/';
                        result[idx_result] = '\0';
                    }
                    // put dir name
                    if (idx_tmp != 0) {
                        for (int i = 0; i < idx_tmp; i++) {
                            result[idx_result++] = tmp[i];
                        }
                        result[idx_result] = '\0';
                        idx_tmp = 0;
                    }
                }
                idx_tmp = 0;

            } else {
                // "//" case, no action
            }
        }

        idx_path++;
        ch_prev = ch;
    }

    if (idx_result > 1) {
        // remove last '/'
        if (result[idx_result-1] == '/') {
            idx_result--;
        }
    }

    result[idx_result] = '\0';

    free(tmp);
    return result;
}

void test_00071_Simplify_Path(void)
{
    printf("%s\n", simplifyPath("/.././GVzvE/./xBjU///../..///././//////T/../../.././zu/q/e"));
    printf("%s\n", simplifyPath("/home//foo/../"));
    printf("%s\n", simplifyPath("/..."));
    printf("%s\n", simplifyPath("/home/"));
    printf("%s\n", simplifyPath("/../"));
    printf("%s\n", simplifyPath("/home//foo/"));
    printf("%s\n", simplifyPath("/a/./b/../../c/"));
    printf("%s\n", simplifyPath("/a//b////c/d//././/.."));

}