// Runtime: 3 ms, faster than 95.12 % of C++ online submissions for Multiply Strings.
// Memory Usage : 6.3 MB, less than 98.14 % of C++ online submissions for Multiply Strings.
class Solution {
public:
	void update(string &s, int idx, int n)
	{
		int carry = 0;
		while ((n > 0) || (carry > 0)) {
			while (idx > s.length() - 1) {
				s.push_back('0');
			}
			int sum = s[idx] - '0' + n % 10 + carry;
			carry = sum / 10;
			s[idx] = sum % 10 + '0';
			n = n / 10;
			idx++;
		}
	}
	void reverse_str(string &s)
	{
		int l = 0;
		int r = s.length() - 1;
		while (l < r) {
			char tmp = s[l];
			s[l++] = s[r];
			s[r--] = tmp;
		}
	}
	string multiply(string num1, string num2) {
		string result = "0";
		int idx_last = 0;
		for (int i = num2.length() - 1; i >= 0 ; i--) {
			int x = num2[i] - '0';
			int carry = 0;
			for (int j = num1.length() - 1; j >= 0 ; j--) {
				int idx = num2.length() - 1 - i + num1.length() - 1 - j;
				int z = num1[j] - '0';
				int y = x * z;
				update(result, idx, y);
			}
		}
		reverse_str(result);
		return result;
	}
};

void test_00043_Multiply_Strings(void)
{
	Solution s;
	printf("%s\n", s.multiply("2262293577402756", "4496246430").c_str());
	printf("%s\n", s.multiply("2", "3").c_str());
	printf("%s\n", s.multiply("123", "456").c_str());
	printf("%s\n", s.multiply("99", "99").c_str());
	printf("%s\n", s.multiply("99", "9999").c_str());
}