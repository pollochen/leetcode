char *parse_month(char *s)
{
    switch (s[0]) {
    case 'J':
        if (s[1] == 'a') { return "01"; } // Jan
        else if (s[2] == 'l') {return "07"; } // Jul
        else { return "06"; } // Jun
    case 'F': return "02"; // Feb
    case 'M':
        if (s[2] == 'r') return "03"; // Mar
        else return "05"; // May
    case 'A':
        if (s[1] == 'p') return "04"; // Apr
        else return "08"; // Aug
    case 'S': return "09"; // Sep
    case 'O': return "10"; // Oct
    case 'N': return "11"; // Nov
    default: return "12"; // Dec
    }
}

char * reformatDate(char * date){
    char *ch = date;
    char *result = (char *)malloc(11);
    char *mon_str;
    int cnt = 0;

    result[4] = result[7] = '-';
    result[10] = 0;

    while (*ch != '\0') {
        if (*ch == ' ') {
            switch (cnt) {
                case 0:
                    // day
                    if (ch - date == 3) { result[8] = '0'; result[9] = *(ch-3);}
                    else { result[8] = *(ch-4); result[9] = *(ch-3);}
                    break;
                case 1:
                    // month
                    mon_str = parse_month(ch - 3);
                    result[5] = mon_str[0];
                    result[6] = mon_str[1];
                    break;
                default: break;
            }
            cnt++;
        }
        ch++;
    }

    // year
    memcpy(result, ch-4, 4); // year

    return result;
}