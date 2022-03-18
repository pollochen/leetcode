class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
		string result = "";
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i][i] == '0') {
				result += "1";
			} else {
				result += "0";
			}
		}
		return result;
    }
};

https://leetcode.com/problems/find-unique-binary-string/discuss/1418687/Detailed-Explanation-O(N)-Java-C++-Python-short-concise-code-Cantor's-Diagonalization