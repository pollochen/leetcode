// 40.11% faster (long int version)
class Solution {
    bool is_digit(char ch)
    {
        return ch <= '9' && ch >= '0';
    }    
public:
#define STAGE_0 0 // wait for + or -
#define STAGE_1 1 // read next digits
#define STAGE_2 2 // end
#define STAGE_EXIT 3 // exit
	int myAtoi(string s) {
		long result = 0;
		int sign = 0;
		int stage = STAGE_0;
		for (int i = 0; i < s.length(); i++) {
			char ch = s[i];
			if (s[i] == ' ') {
				if (stage == STAGE_1) {
					stage = STAGE_2;
                    break;
				}
                continue;
			}
			if ((s[i] == '-') && (stage == STAGE_0)) {
				sign = 1;
				stage = STAGE_1;
			} else if ((s[i] == '+') && (stage == STAGE_0)) {
				sign = 0;
				stage = STAGE_1;
			} else if ((is_digit(ch) == true) && (stage == STAGE_1 || stage == STAGE_0)) {
				stage = STAGE_1;
				if (sign == 1) {
					result = result * 10 - (ch - '0');
				} else {
					result = result * 10 + (ch - '0');
				}
				if (result > 0x7FFFFFFF) {
					return INT_MAX;
				}

				if (result < INT_MIN) {
					return INT_MIN;
				}
            } else {
				if (stage == STAGE_0) {
					return 0;
				} else {
					stage = STAGE_2;
                    break;
				}
			}
		}
		if (result > 0x7FFFFFFF) {
			return INT_MAX;
		}

		if (result < INT_MIN) {
			return INT_MIN;
		}
		return (int)result;
	}
};

void test_00008_String_to_Integer(void)
{
	Solution s;
	printf("%d\n", s.myAtoi("42"));
	printf("%d\n", s.myAtoi("   -42"));
	printf("%d\n", s.myAtoi("4193 with words"));
	printf("%d\n", s.myAtoi("4294967295"));
	printf("%d\n", s.myAtoi("-1"));
	printf("%d\n", s.myAtoi("-2147483647"));
	printf("%d\n", s.myAtoi("-2147483648"));
	printf("%d\n", s.myAtoi("-2147483649"));
	printf("%d\n", s.myAtoi("words and 987"));
	printf("%d\n", s.myAtoi("3.14159"));
	printf("%d\n", s.myAtoi("   +0 123"));	
	printf("%d\n", s.myAtoi("20000000000000000000"));
}