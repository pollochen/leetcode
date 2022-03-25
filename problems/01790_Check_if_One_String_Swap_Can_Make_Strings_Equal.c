// check count = 2, and compare swapable
// Runtime: 0 ms, faster than 100.00% of C online submissions for Check if One String Swap Can Make Strings Equal.
// Memory Usage: 5.7 MB, less than 17.32% of C online submissions for Check if One String Swap Can Make Strings Equal.
bool areAlmostEqual(char * s1, char * s2){
    int count = 0;
    int pair[6];
    while (*s1 != '\0') {
        if (*s1 != *s2) {
            pair[count*2]   = *s1;
            pair[count*2+1] = *s2;
            count++;
            if (count > 2) return false;
        }
        s1++;
        s2++;
    }
    if (count == 0) return true;
    if (count == 2) {
        if (pair[0] == pair[3] && pair[1] == pair[2]) {
            return true;
        } else {
            return false;
        }
    }
    return false;
}

void test_01790_Check_if_One_String_Swap_Can_Make_Strings_Equal(void)
{
    printf("%d\n", areAlmostEqual("bank", "kanb"));
    printf("%d\n", areAlmostEqual("attack", "defend"));
    printf("%d\n", areAlmostEqual("kelb", "kelb"));
    printf("%d\n", areAlmostEqual("abcd", "dcba")); // false
}