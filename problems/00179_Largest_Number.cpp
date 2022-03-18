// https://leetcode.com/problems/largest-number/discuss/1793570/Custom-Comparator-Function-C%2B%2B
bool comp_largest_number_func(int a, int b) {
	string str_a = to_string(a);
	string str_b = to_string(b);
	return str_a + str_b > str_b + str_a;
}
class Solution {
public:
	string largestNumber(vector<int>& nums) {
		sort(nums.begin(), nums.end(), comp_largest_number_func);
		string result = "";
        if(nums[0] == 0) {return "0";}
		for (int i = 0; i < nums.size(); i++) {
			result += to_string(nums[i]);
		}
        return result;
	}
};

void test_179_Largest_Number(void) {
	Solution s;
	printf("%s\n", s.largestNumber(vector<int>{ 0, 0 }).c_str());
	printf("%s\n", s.largestNumber(vector<int>{10, 2}).c_str());
	printf("%s\n", s.largestNumber(vector<int>{ 3, 30, 34, 5, 9 }).c_str());
}