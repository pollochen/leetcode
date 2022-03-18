
bool isLongPressedName(char * name, char * typed) {
	char pre = '\0';
	while (*name != '\0' || *typed != '\0') {
		if (*name == *typed) {
			pre = *name;
			name++;
			typed++;
		} else {
			if (pre != '\0') {
				if (pre == *typed) {
					typed++;
				} else {
					return false;
				}
			} else {
				return false;
			}
		}
	}
	if ((*name == '\0') && (*typed == '\0')) return true;
	
	return false;
}